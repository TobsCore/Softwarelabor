//
//  String.cpp
//  Aufgabe 3
//
//  Created by Tobias Kerst on 03.03.15.
//  Copyright (c) 2015 Tobias Kerst. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;


class String {
private:
    // 'String' is represented internally as a plain C-style string.
    int size;
    char* str;
public:
    String() {
        size = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(char c) {
        size = 1;
        str = new char[2];
        str[0] = c;
        str[1] = '\0';
    }
    String(char* c) {
        size = 0;
        // Get the length of the passed string and set the object's parameter accordingly
        while( *(c + size) != '\0') {
            size++;
        }
        str = new char[size + 1];
        
        // Copy string
        int i;
        for(i = 0; i <= size; i++) {
            str[i] = c[i];
        }
    }
    ~String() {
        delete[] str;
    }
    int getSize() {
        return size;
    }
    char* getString() {
        return str;
    }
    
    // make friend, so we can access private members
    friend ostream& operator<< (ostream &out, String &s);
    
};

ostream& operator<< (ostream &out, String &s) {
    for(int i=0; i<s.size; i++) {
        out << s.str[i];
    }
    
    return out;
}

void testEmpty();
void testSingleChar();
void testCharPointer();
void testStringObject();


// Test the class in the main method by calling each corresponding test.
int main() {
    testEmpty();
    testSingleChar();
    testCharPointer();
    testStringObject();
}




/*
 #################### Testing ###############
 */

void testEmpty() {
    cout << "##Test simple String initialization" << endl;
    
    String* s1 = new String();
    if(s1 != NULL) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}


void testSingleChar() {
    cout << "\n\n##Test String Initialization with single char" << endl;
    String s1('H'), s2('t');
    
    if((*s1.getString()) == 'H')
        cout << "PASSED" << endl;
    else {
        cout << "FAILED" << endl;
    }
    
    if((*s2.getString()) == 't')
        cout << "PASSED" << endl;
    else {
        cout << "FAILED" << endl;
    }
}


void testCharPointer() {
    cout << "\n\n##Test String Initialization with char pointer" << endl;
    
    char c1[] = "Hello";
    char c2[] = "World";
    char c3[] = "Hello World";
    String s1(c1), s2(c2), s3(c3);
    
    if(strcmp(s1.getString(), "Hello") == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    
    if(strcmp(s3.getString(), "Hello World") == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    
    if(strcmp(s3.getString(), c3) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    
    cout << "Print s1 and s2: " << s1 << " " << s2 << endl;
}

void testStringObject() {
    cout << "\n\n##Test String initialization with string object" << endl;
    
    char c[] = "Hello World";
    String s1(c);
    String s2(s1);
    if(strcmp(s1.getString(), s2.getString()) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    
}