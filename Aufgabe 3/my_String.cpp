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