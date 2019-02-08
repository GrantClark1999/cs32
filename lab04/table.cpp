//  Grant Clark, 5224308

#include "table.h"

void printTable(const Table& t) {
    for(unsigned int i = 0; i < t.size; i++) {
        EntryVec e = t.entries[i];
        std::cout << i << ": ";
        EntryVec::iterator it = e.begin();
        while(it != e.end()) {
            std::cout << *it << "\t|\t";
            it++;
        }
        std::cout << std::endl;
    }
}

Table::Table(unsigned int max_entries) {
    size = max_entries;
    // Assigns the dynamically allocated array to be a new array of EntryVec (std::vector<Entry>)
    entries = new EntryVec[size];
}

Table::Table(unsigned int entries, std::istream& input){
    size = entries;
    this->entries = new EntryVec[size];
    std::string inputString, keyString, dataString;
    while(!input.eof()) {
        std::getline(input, inputString);
        keyString = inputString.substr(0, inputString.find("\t"));
        dataString = inputString.substr(inputString.find("\t"), inputString.length()-1);
        put(std::stoi(keyString), dataString);
    }
}

Table::~Table() {
    delete [] entries;
}

void Table::put(unsigned int key, std::string data){
    Entry newEntry(key, data);
    unsigned int hashedKey = hash(key);
    entries[hashedKey].insert(std::lower_bound(entries[hashedKey].begin(), entries[hashedKey].end(), newEntry), newEntry);
}

void Table::put(Entry e){
    unsigned int hashedKey = hash(e.get_key());
    entries[hashedKey].insert(std::lower_bound(entries[hashedKey].begin(), entries[hashedKey].end(), e), e);
}

std::string Table::get(unsigned int key) const{
    unsigned int hashedKey = hash(key);
    EntryVec e = entries[hashedKey];
    EntryVec::iterator it = find(key, e);
    if(it != e.end()) {
        return it->get_data();
    }
    // Below executes if the key is not found.
    std::cerr << "Key: " << key << " not found.";
    exit(1);
}

bool Table::remove(unsigned int key){
    unsigned int hashedKey = hash(key);
    EntryVec e = entries[hashedKey];
    EntryVec::iterator it = find(key, e);
    if(it != e.end()) {
        e.erase(it);
        return true;
    }
    return false;
}

EntryVec::iterator Table::find(unsigned int key, EntryVec e) const {
    EntryVec::iterator it = e.begin();
    while(it != e.end()) {
        if(it->get_key() == key) {
            return it;
        } else {
            it++;
        }
    }
    return e.end();
}

unsigned int Table::hash(unsigned int key) const {
    return (key%size);
}

std::ostream& operator<< (std::ostream& out, const Table& t){
    // Vector storing objects of ExtEntry type. Will be a sorted vector (sorted by key) of the first elements of each
    // of the vectors containing Entry objects in EntryVec in Table. If the first element is erased from the vector, it
    // will try to add the next element from the original EntryVec that the erased element originated from.
    ExtEntryVec outVector;

    // Stores all first Entry objects into outVector (in sorted order)
    for(unsigned int i = 0; i < t.size; i++) {
        EntryVec e = t.entries[i];
        if(!e.empty()) {
            // Entry object, iterator to the place in the original vector for the Entry object, hashedKey/index
            ExtEntry extE(e[0], 0, i);

            ExtEntryVec::iterator extEntryIt = std::lower_bound(outVector.begin(), outVector.end(), extE);
            outVector.insert(extEntryIt, extE);
        }
    }

    // Loop continues until there are no more Entry objects in the original table that it hasn't printed out.
    while(!outVector.empty()) {
        // Gets the iterator to the original EntryVec for the object that will be erased from the temporary outVector.
        unsigned int nextToInsert = outVector[0].get_origPos() + 1;
        unsigned int hashedKey = outVector[0].get_hashedKey();
        EntryVec origVec = t.entries[hashedKey];

        // Writes the lowest key to the output.
        Entry outEntry = outVector[0].get_entry();
        out << outEntry << std::endl;

        outVector.erase(outVector.begin());
        EntryVec::iterator end = t.entries[hashedKey].end();

        if(nextToInsert != origVec.size()) {
            ExtEntry extE(origVec[nextToInsert], nextToInsert, hashedKey);

            ExtEntryVec::iterator extEntryIt = std::lower_bound(outVector.begin(), outVector.end(), extE);
            outVector.insert(extEntryIt, extE);
        }
    }

    return out;
}








ExtEntry::ExtEntry(Entry e, unsigned int oPos, unsigned int hKey) {
    entry = e;
    origPos = oPos;
    hashedKey = hKey;
}

ExtEntry::ExtEntry(const ExtEntry &e) {
    entry = e.get_entry();
    origPos = e.get_origPos();
    hashedKey = e.get_hashedKey();
}

Entry ExtEntry::get_entry() const {
    return entry;
}
unsigned int ExtEntry::get_origPos() const {
    return origPos;
}
unsigned int ExtEntry::get_hashedKey() const {
    return hashedKey;
}

ExtEntry::operator unsigned int () const {
    return get_entry().get_key();
}

ExtEntry& ExtEntry::operator = (const ExtEntry &other) {
    if(&other == this) {
        return *this;
    }
    this->entry = other.get_entry();
    this->origPos = other.get_origPos();
    this->hashedKey = other.get_hashedKey();
    return *this;
}