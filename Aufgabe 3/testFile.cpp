
#include "myString.h"

void testEmpty();
void testSingleChar();
void testCharPointer();
void testCount();
void testStringObject();
void passedMessage();
void failedMessage();

ostream& operator<< (ostream &out, String &s) {
    for(int i=0; i<s.size; i++) {
        out << s.str[i];
    }
    
    return out;
}


// Test the class in the main method by calling each corresponding test.
int main() {
    testEmpty();
    testSingleChar();
    testCharPointer();
    testCount();
    testStringObject();
}

/*
 #################### Testing ###############
 */

void testEmpty() {
    cout << "##Test simple String initialization" << endl;
    
    String* s1 = new String();
    
    cout << "Check if string could be created: ";
    if(s1 != NULL) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}


void testSingleChar() {
    cout << "\n\n##Test String Initialization with single char" << endl;
    String s1('H'), s2('t');
    
    cout << "Check if one-character String is initialized correctly: ";
    if((*s1.getString()) == 'H')
        passedMessage();
    else {
        failedMessage();
    }
    
    cout << "Check for lower-case letters: ";
    if((*s2.getString()) == 't')
        passedMessage();
    else {
        failedMessage();
    }
}


void testCharPointer() {
    cout << "\n\n##Test String Initialization with char pointer" << endl;
    
    char c1[] = "Hello";
    char c2[] = "World";
    char c3[] = "Hello World";
    String s1(c1), s2(c2), s3(c3);
    
    cout << "Compare newly created String with original char-array: ";
    if(strcmp(s1.getString(), "Hello") == 0) {
        passedMessage();
    } else {
        failedMessage();
    }
    
    cout << "Test space seperated strings: ";
    if(strcmp(s3.getString(), "Hello World") == 0) {
        passedMessage();
    } else {
        failedMessage();
    }
    
    cout << "Test newly created string with original string: ";
    if(strcmp(s3.getString(), c3) == 0) {
        passedMessage();
    } else {
        failedMessage();
    }
    
}

void testCount() {
    cout << "\n\n##Test Size of Strings" << endl;
    String s1('H');
    
    cout << "Check String length (1 Character): ";
    if(s1.getSize() == 1) {
        passedMessage();
    } else {
        failedMessage();
    }
    
    char c2[] = "Hello";
    char c3[] = "World";
    String s2(c2), s3(c3);
    
    cout << "Compare to different strings with same size: ";
    if(s2.getSize() == s3.getSize()) {
        passedMessage();
    } else {
        failedMessage();
    }
}

void testStringObject() {
    cout << "\n\n##Test String initialization with string object" << endl;
    
    char c[] = "Hello World";
    String s1(c);
    String s2(s1);
    
    cout << "Check if copied String has the same size as the original one: ";
    if(s2.getSize() == s1.getSize()) {
        passedMessage();
    } else {
        failedMessage();
    }
    
    cout << "Check if the string was copied corretly: ";
    if(strcmp(s2.getString(), "Hello World") == 0 ) {
        passedMessage();
    } else {
        failedMessage();
    }
    
    cout << "Check, if the two Strings are different, by checking their adresses: ";
    if(s2.getString() != s1.getString()) {
        passedMessage();
    } else {
        failedMessage();
    }
}


void passedMessage() {
    cout << "PASSED" << endl;
}

void failedMessage() {
    cout << "FAILED" << endl;
}
