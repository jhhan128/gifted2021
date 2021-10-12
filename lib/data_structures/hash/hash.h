/*
 * lib/header/hash.h
 * Created by jhhan128.
 *
 *
 * A Header for hash table implementation.
 */

#ifndef __HASH__
#define __HASH__


#include <stdlib.h>
#include <string.h>


#define TABLE_SZ (509)       // Hash Table size (Should be a prime number)
#define MAX_KEY_SZ (151)     // Max key size + 1
#define NO_SUCH_ELEMENT (-1) // Error


typedef struct _Node {
    char key[MAX_KEY_SZ];   // Key
    int value;              // Value (Should not be negative)
    struct _Node *next;
} __Node;


__Node *table[TABLE_SZ];            // Hash Table
char inTable[TABLE_SZ][MAX_KEY_SZ]; // Inverse Hash Table


#endif
