//
//  table.h
//  W19 - Lab04
//
#ifndef table_h
#define table_h

#include "entry.h"
#include <vector>

typedef std::vector<Entry> Entries;

class Table {
public:
    Table(unsigned int max_entries = 100);
    Table(unsigned int entries, std::istream& input);
    ~Table();
    void put(unsigned int key, std::string data);
    void put(Entry e);
    std::string get(unsigned int key) const;
    bool remove(unsigned int key);
    Entries::iterator find(unsigned int key, Entries e) const;
private:
    unsigned int size = 0;
    Entries* entries;
    unsigned int hash(unsigned int key) const;
};

std::ostream& operator<< (std::ostream& out, const Table& t);




#endif /* table_h */
