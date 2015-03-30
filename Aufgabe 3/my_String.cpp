//
//  String.cpp
//  Aufgabe 3
//
//  Created by Tobias Kerst on 03.03.15.
//  Copyright (c) 2015 Tobias Kerst. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "myString.h"
using namespace std;



String::String() {
    size = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(char c) {
    size = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

String::String(const char* c) {
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

String::String(const String& copyConstructor) { // This is my copy constructor
    
    size = copyConstructor.size;
    str = new char[size];
    for(int i = 0; i < size; i++) {
        str[i] = (char) copyConstructor.str[i];
    }
}

String::~String() {
    delete[] str;
}

int String::getSize() {
    return size;
}

char* String::getString() {
    return str;
}

// Points to the char at the given position, by simply adding the index to the adress (simple pointer arithmetic)
char& String::operator[](int index) {

    if(index < size && index >= 0) {
        return *(str + index);
    }
    
    // If the index is out of bounds, the point to the null-terminator
    return *(str + size);
}

String& String::operator=(String& s) {
    // free old string's memory
    delete[] str;
    
    // Create new copied String
    size = s.getSize();
    str = new char[size];
    for(int i = 0; i < size; i++) {
        str[i] = s[i];
    }
    return *this;
}

    return *this;
}
