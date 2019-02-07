//  Grant Clark, 5224308
//
//  table.h
//  W19 - Lab04
//
#ifndef table_h
#define table_h

#include "entry.h"
#include <vector>

typedef std::vector<Entry> EntryVec;

class Table {
public:
    // Member Functions
    Table(unsigned int max_entries = 100);
    Table(unsigned int entries, std::istream& input);
    ~Table();
    void put(unsigned int key, std::string data);
    void put(Entry e);
    std::string get(unsigned int key) const;
    bool remove(unsigned int key);
    EntryVec::iterator find(unsigned int key, EntryVec e) const;

    // Non-Member Functions
    friend std::ostream& operator<< (std::ostream& out, const Table& t);
    friend void printTable(const Table& t);
private:
    unsigned int size = 0;
    // Dynamically allocated array storing vector objects.
    EntryVec* entries;

    // Helper Functions
    unsigned int hash(unsigned int key) const;
};

struct ExtEntry {
public:
    ExtEntry(Entry e, EntryVec::iterator it, unsigned int hashedKey);
    ExtEntry(const ExtEntry &e);
    Entry get_entry() const;
    EntryVec::iterator get_iterator() const;
    unsigned int get_hashedKey() const;
    // operator conversion function simplifies comparisons
    operator unsigned int () const;
    ExtEntry& operator = (const ExtEntry& other);
private:
    Entry entry;
    EntryVec::iterator iterator;
    unsigned int hashedKey;
};

typedef std::vector<ExtEntry> ExtEntryVec;



#endif /* table_h */
