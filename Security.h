//
//  Security.h
//  Security
//
//  Created by Margaret Patrick on 5/29/16.
//  Copyright © 2016 Margaret Patrick. All rights reserved.
//

#ifndef Security_h
#define Security_h

#include <fstream>
#include "Table.h"

using namespace std;

class Security: private Table{
    public:
        void print(){
            Table::print();
        }
        Security();
        void add(string key, string value);
        bool authenticate(string key, string value)const;
    private:
        unsigned int numMembers = 0;
        long shift(string x)const;
    
};



#endif /* Security_h */
