#include "Student.h"
#include <iostream>

void Student::setter(int r, string s) {
    rollNo = r;
    name = s;
}

void Student::getter() {
    cout << "Roll No: " << rollNo << "\n";
    cout << "Name: " << name << "\n";
}