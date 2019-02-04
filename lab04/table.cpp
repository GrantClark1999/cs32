#include "table.h"

#include <iostream>

Table::Table(unsigned int max_entries) {
    size = max_entries;
    entries = new Entries[size];
}

Table::Table(unsigned int entries, std::istream& input){
    size = entries;
    this->entries = new Entries[size];
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
    entries[hashedKey].push_back(newEntry);
}

void Table::put(Entry e){
    unsigned int hashedKey = hash(e.get_key());
    entries[hashedKey].push_back(e);
}

std::string Table::get(unsigned int key) const{
    unsigned int hashedKey = hash(key);
    Entries e = entries[hashedKey];
    Entries::iterator it = find(key, e);
    if(it != e.end()) {
        return it->get_data();
    }
    // Below executes if the key is not found.
    std::cerr << "Key: " << key << " not found.";
    exit(1);
}

bool Table::remove(unsigned int key){
    Entries e = entries[hash(key)];
    Entries::iterator it = find(key, e);
    if(it != e.end()) {
        e.erase(it);
    }
    return false;
}

Entries::iterator Table::find(unsigned int key, Entries e) const {
    Entries::iterator it = e.begin();
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
    return (key%(entries->size()));
}

std::ostream& operator<< (std::ostream& out, const Table& t){
    
}