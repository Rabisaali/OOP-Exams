#include <iostream>
using namespace std;

// ================= DEPARTMENT =================
class Department {
    string name;
    static int totalDepartments;

public:
    Department(string n) : name(n) {
        totalDepartments++;
    }

    string getName() const {
        return name;
    }

    static int getTotalDepartments() {
        return totalDepartments;
    }

    ~Department() {
        totalDepartments--;
    }
};

int Department::totalDepartments = 0;


// ================= EMPLOYEE =================
class Employee {
    const string name;   // immutable
    int id;
    Department* dept;

    static int idCounter;

public:
    Employee(string n, Department* d) : name(n), dept(d) {
        id = ++idCounter;
    }

    void display() const {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Department: " << dept->getName() << endl;
    }

    static int getTotalEmployees() {
        return idCounter;
    }
};

int Employee::idCounter = 0;


// ================= MAIN =================
int main() {

    // Dynamic departments
    Department* d1 = new Department("HR");
    Department* d2 = new Department("IT");

    // Dynamic employees
    Employee* e1 = new Employee("Ali", d1);
    Employee* e2 = new Employee("Sara", d2);
    Employee* e3 = new Employee("Ahmed", d2);

    // Display employees
    e1->display();
    e2->display();
    e3->display();

    // Counts
    cout << "\nTotal Employees: " << Employee::getTotalEmployees() << endl;
    cout << "Total Departments: " << Department::getTotalDepartments() << endl;

    // Memory cleanup
    delete e1;
    delete e2;
    delete e3;

    delete d1;
    delete d2;

    return 0;
}