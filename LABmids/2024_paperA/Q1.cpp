#include<iostream>
using namespace std;

class Employee {
    int salary;
    string name;
    int ID;
    static int nextEmployeeID;
    const int MAX_SALARY=60000;
    public:
        Employee(string n, int s) : name(n) {
            ID = nextEmployeeID++;
            setSalary(s);
        }

        static int generateEmployeeID() {
            return nextEmployeeID;
        } 

        void setSalary(int s) {
            if (s > MAX_SALARY) salary =  MAX_SALARY;
            else salary = s;
            return;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Salary: " << salary << endl;
        }

};
int Employee::nextEmployeeID=0;
int main () {
    Employee e1("Ali", 45000);
    int id1 = Employee::generateEmployeeID();
    cout << id1 << endl;
    Employee e2("Raza", 890000);
    int id2 = Employee::generateEmployeeID();
    cout << id2 << endl;
    e1.display();
    e2.display();

}