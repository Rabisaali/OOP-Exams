#include<iostream>
using namespace std;

class Employees {
    protected:
        string name;
        int age;
        string joiningDate;

    public:
        Employees (string n, int a, string d) : name(n), age(a), joiningDate(d) {}
};
class Developers : virtual public Employees {
    protected:
        string devrole;
    public:
        Developers(string n, int a, string d, string r) : Employees(n, a, d) {
            devrole = r;
        }
};
class Debugger : virtual public Employees {
    protected:
        string debrole;
    public:
        Debugger(string n, int a, string d, string r) : Employees(n, a, d) {
            debrole = r;
        }
};
class TeamLead : public Developers, public Debugger {
    public:
        TeamLead(string n, int a, string d, string r1, string r2):Debugger(n, a, d, r2), Developers(n, a, d, r1), Employees(n, a, d) { }

        void display () {
            cout << "Name: " << name;
            cout << "\nAge: " << age << endl;
            cout << "Date of joining: " << joiningDate << endl;
            cout << "Role: " << devrole <<endl;
            cout << "Role: " << debrole << endl; 
        }
};


int main () {
    TeamLead t1("Ali", 25, "23-07-2016", "frontend developer", "auto debugger");
    t1.display();
}