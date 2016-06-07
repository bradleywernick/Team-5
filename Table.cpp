//
//  Table.cpp
//  Security
//
//  Created by Margaret Patrick on 5/29/16.
//  Copyright © 2016 Margaret Patrick. All rights reserved.
//

#include "Table.h"
#include <cmath>
#include <iostream>
using namespace std;


Table::Table(){
    table = new Pair<long>*[capacity];
    for (int i = 0; i < capacity; ++i){
        table[i] = nullptr;
    }
}

void Table::addToTable(long k, long v){
    Pair<long>* item = pack(k, v);
    addPair(item);
}

bool Table::find(long itemA, long itemB)const{
    int location = abs(itemA % capacity);
    while (table[location] != nullptr){
        if (table[location]->k == itemA){
            if (table[location]->v == itemB) return true;
        }
        if (location++ == capacity) location = 0;
    }
    return false;
}

void Table::expand(){
    size_t oldCap = capacity;
    capacity = capacity * 2 + 1;
    Pair<long>** oldTable = table;
    table = new Pair<long>*[capacity];
    for (int i = 0; i < capacity; ++i) table[i] = nullptr;
    size = 0;
    for (int i = 0; i < oldCap; ++i) if (oldTable[i] != nullptr) addPair(oldTable[i]);
    delete oldTable;
}

/* private
* allocates memory for a pair, initalizes all values
* returns ptr to newly allocated memory
*/
Table::Pair<long>* Table::pack(long k, long v)const{
    Pair<long>* pack = new Pair<long>;
    pack->k = k;
    pack->v = v;
    return pack;
}

/* Protected
*  Adds a given Pair to table
*@Param pair: given pair to add to table
*/
void Table::addPair(Pair<long>* pair){
    int i = 0;
    size_t location = abs(pair->k % capacity);
    while (table[location] != nullptr && i++ < size){
        if (++location == capacity) location = 0;
    }
    table[location] = pair;
    ++size;
    if ((double)size/capacity >= .75) expand();
}

Table::~Table(){
    for (int i = 0; i < capacity; ++i){
        if (table[i]){
            delete table[i];
        }
    }
    delete table;
}

Table::Table( const Table &obj){
    table = new Pair<long>*[capacity];
    for (int i = 0; i < capacity; ++i){
        table[i] = nullptr;
    }
    for (int i = 0; i < obj.capacity; ++i){
        if (obj.table[i]){
            this->addPair(this->pack(obj.table[i]->k, obj.table[i]->v));
        }
    }
}