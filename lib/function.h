/*
 * lib/header/functions.h
 * Created by jhhan128.
 *
 *
 * Declare of functions.
 */

#ifndef __FUNCTION__
#define __FUNCTION__


#include <stdio.h>
#include <stdbool.h>


// first_exec
void outputAll(FILE *);
void firstExec(void);


// today
void run(void);
bool isInsideList(int);


// hash
void hash_init(void);
void hash_add(const char *, const int);
void hash_delete(const char *);
int hash_find(const char *);


// make_data
void generateHash(void);
void generateEdge(void);


// graphs
void makeGraph(void);
void addEdge(int, int);


#endif