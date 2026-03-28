#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
    int rollNo;
    string name;
    public:
        void setter (int r, string s);
        void getter ();
};
#endif