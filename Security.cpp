//
//  Security.cpp
//  Security
//
//  Created by Margaret Patrick on 5/29/16.
//  Copyright © 2016 Margaret Patrick. All rights reserved.
//

#include <stdio.h>

#include "Security.h"
#include <iostream>

using namespace std;


Security::Security(){
    
    ifstream infile;
    infile.open("read_me.bin" , ios::binary | ios::in);
    if (!infile.fail()){
        while (!infile.eof()){
            Pair<long>* unit = new Pair<long>;
            infile.read(reinterpret_cast<char *>(unit), sizeof(Pair<long>));
            if (unit->k && unit->v) addPair(unit); // the eof() has issues, runs extra time and pulls in a blank Pair
        }
    }
    
}

bool Security::authenticate(string key, string value) const{
    long k = shift(key);
    long v = shift(value);
    return find(k,v);
}

/*
* need to add pair of key value to both the text file and the table
*/
void Security::add(string key, string value){
    Pair<long>* item = pack(shift(key), shift(value));
    ofstream outfile;
    outfile.open("read_me.bin" , ios::binary | ios::app);
    outfile.write(reinterpret_cast<char *>(item), sizeof(Pair<long>));
    addPair(item);
    
    outfile.close();
}



/*private
* puts a string of 8 charaters or less into a long
*/
long Security::shift(string x) const{
    long shift = 0;
    for (int i = 0, key = 0; i < x.length(); ++i, key += 8){
        shift += (x[i]<<key);
    }
    return shift;
}
