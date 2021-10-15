/*
 * src/data_structures/hash.c
 * Created by jhhan128.
 *
 *
 * An implementaion of hash table.
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "hash"


// Initialize Hash Table.
void hash_init(void) {
    table.clear();
}


// Add (key, val) to Hash Table.
void hash_add(const std::string &key, const int value) {
    table.insert(std::make_pair(key, value));
    inTable.push_back(key);
}


// Delete value for given key if key exist.
void hash_delete(const std::string &key) {
    if (table.find(key) != table.end()) {
        table.erase(key);
    }
}


// Return value for given key.
int hash_find(const std::string &key) {
    if (table.find(key) != table.end()) {
        return table[key];
    }

    return -1;
}
