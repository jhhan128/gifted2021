/*
 * lib/hash.h
 * Created by jhhan128.
 *
 *
 * A Hash Table implementation for gifted2021 project.
 *
 * Just include this header, and you can use hash table without doing anything.
 * DO NOT use Node structure or hash function outside this file.
 * With changing TABLE_SZ and MAX_KEY_SZ, this source can be used in other project.
 *
 */

#ifndef GIFTED2021_HASH_H
#define GIFTED2021_HASH_H


#include <stdlib.h>
#include <string.h>


#define TABLE_SZ (509)  // Hash Table size (Should be a prime number)
#define MAX_KEY_SZ (46) // Max key size + 1


typedef struct _Node {
    char key[MAX_KEY_SZ];   // Key
    int value;              // Value (Should not be negative)
    struct _Node *next;
} Node;


Node *table[TABLE_SZ];  // Hash Table


// Hash function
int hash(const char *str) {
    int ret = 499;
    const char *pt = str;

    while (*pt != '\0') {
        ret = ((ret << 4) + (int)(*pt));
        ret %= TABLE_SZ;
        pt++;
    }

    ret %= TABLE_SZ;
    return ret;
}


// Initialize Hash Table.
void hash_init(void) {
    for (int i = 0; i < TABLE_SZ; i++) {
        Node *cur = table[i];
        Node *tmp;

        while (cur != NULL) {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }

        table[i] = NULL;
    }
}


// Add (key, val) to Hash Table.
void hash_add(const char *key, const int value) {
    Node *add = (Node*)malloc(sizeof(Node));

    strcpy(add->key, key);
    add->value = value;
    add->next = NULL;

    const int idx = hash(key);

    if (table[idx] == NULL) {
        table[idx] = add;
    } else {
        Node *cur = table[idx];

        while (cur != NULL) {
            if (strcmp(cur->key, key) == 0) {
                cur->value = value;
                return;
            }

            cur = cur->next;
        }

        add->next = table[idx];
        table[idx] = add;
    }
}


// Delete value for given key if key exist.
void hash_delete(const char *key) {
    const int idx = hash(key);
    if (table[idx] == NULL) return;

    if (strcmp(table[idx]->key, key) == 0) {
        Node *fir = table[idx];
        free(fir);

        table[idx] = table[idx]->next;
    } else {
        Node *cur = table[idx]->next;
        Node *prev = table[idx];

        while (cur != NULL && strcmp(cur->key, key) != 0) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == NULL) return;

        prev->next = cur->next;
        free(cur);
    }
}


// Return value for given key.
int hash_find(const char *key) {
    const int idx = hash(key);
    Node *cur = table[idx];

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            return cur->value;
        }

        cur = cur->next;
    }

    return -1;
}


#endif // GIFTED2021_HASH_H
