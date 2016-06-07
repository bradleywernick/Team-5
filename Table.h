//
//  Table.hpp
//  Security
//
//  Created by Margaret Patrick on 5/29/16.
//  Copyright © 2016 Margaret Patrick. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>


#include <iostream>
using namespace std;

class Table{
    public:
    
        //TESTING FUNCTION
        void print(){
            cout << "capacity = " << capacity << endl;
            cout << "size = " << size << endl;
            for (int i = 0; i < capacity; ++i){
                if (table[i]){
                    cout << table[i]->k << " " << table[i]->v << endl;
                }
                else cout << "empty\n";
            }
        }
        // END OF TESTING FUNCTION
        
        // CONSTRUCTOR,PAIR STRUCTURE, DESTRUCTOR, CP constructor.
        Table();
        ~Table();
        Table( const Table &obj);
        // END CONSTRUCTOR,PAIR STRUCTURE, DESTRUCTOR.
        
        // METHODS
        
        /*  adds a given key and value pair to the table
        *@param K: given key to be added to table
        *@param V: given Value to be added to table
        */
        void addToTable(long k, long v);
        
        /* finds an entry, if any, of that matches itemA within 'table'
        * compares itemB to that entrys 'b'
        *@param itemA: key to be found
        *@param itemB: value to be compared
        *returns true if itemB matches value, false otherwise.
        */
        bool find(long itemA, long itemB)const;
        
    protected:
        /* a Key and value Pair
        *
        */
        template <typename T>
        class Pair{
            public:
                T k;
                T v;
        };
        
        /* Adds a given Pair to table
        *@Param pair: given pair to add to table
        */
        void addPair(Pair<long>* pair);
        
        /* creates a Pair containing a and b
        *@param a: key value for pair
        *@param b: value for pair
        * returns packaged pair
        */
        Pair<long>* pack(long k, long v)const;
        // END METHODS
    private:
        /* Hash table that holds pointers to Pairs
        * Hashed by Key % capacity
        */
        Pair<long>** table;
        //number of elements in table
        int size = 0;
        //number of elements the table can hold, expanded if need be
        int capacity = 11;
        
        /*
        * expands the table when capacity is 75% full or greater
        * expands capacity to capacity*2+1
        */
        void expand();
        
        
};




#endif /* Table_hpp */
