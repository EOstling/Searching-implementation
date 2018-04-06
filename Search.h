#ifndef _SEARCH_H
#define _SEARCH_H

#include <iostream>
#include <string>
#include "Person.h"

bool SequentialSearch(Person folks[], int total, string target, int *position, int *pNumCompares);
bool BinarySearch(Person folks[], int total, string target, int *position, int *pNumCompares);
bool RunRecursiveSearch(Person folks[], int total, string target, int *position, int *pNumCompares);

#endif
