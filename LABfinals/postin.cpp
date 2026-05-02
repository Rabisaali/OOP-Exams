#include<iostream>
using namespace std;
class A {
    public:
    int x;
    A(int y) : x(y) {}
    friend A operator++(A &a, int);

    // A& operator++ (int) {

    //     x++; 
    //     return *this;
    // }
};

A operator++ (A &a, int) {
    A temp = a;
    a.x++;
    return temp;
}

int main () {
    A s(7);
    s++;
    cout << s.x;
}
