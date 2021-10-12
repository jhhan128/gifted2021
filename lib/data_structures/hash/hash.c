/*
 * src/data_structures/hash.c
 * Created by jhhan128.
 *
 *
 * An implementaion of hash table.
 */

#include <stdlib.h>
#include <string.h>

#include "hash.h"

// Hash function
int __hash(const char *str) {
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
        __Node *cur = table[i];
        __Node *tmp;

        while (cur != NULL) {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }

        table[i] = NULL;

        for (int j = 0; j < MAX_KEY_SZ; j++) {
            inTable[i][j] = '\0';
        }
    }
}


// Add (key, val) to Hash Table.
void hash_add(const char *key, const int value) {
    __Node *add = (__Node*)malloc(sizeof(__Node));

    strcpy(add->key, key);
    add->value = value;
    add->next = NULL;

    const int idx = __hash(key);

    if (table[idx] == NULL) {
        table[idx] = add;
    } else {
        __Node *cur = table[idx];

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

    strcpy(inTable[value], key);
}


// Delete value for given key if key exist.
void hash_delete(const char *key) {
    const int idx = __hash(key);
    if (table[idx] == NULL) return;

    if (strcmp(table[idx]->key, key) == 0) {
        __Node *fir = table[idx];
        free(fir);

        table[idx] = table[idx]->next;
    } else {
        __Node *cur = table[idx]->next;
        __Node *prev = table[idx];

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
    const int idx = __hash(key);
    __Node *cur = table[idx];

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            return cur->value;
        }

        cur = cur->next;
    }

    return NO_SUCH_ELEMENT;
}
