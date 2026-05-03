#include <iostream>
using namespace std;

class Subject {
public:
    string subjectName;

    Subject(string name = "") {
        if (name == "") {
            cout << "Invalid subject name!\n";
            subjectName = "Unknown";
        } else {
            subjectName = name;
        }
    }
};

class Teacher {
protected:
    int id;
    string name;

public:
    Teacher(int i = 0, string n = "NA") {
        id = i;
        name = n;
    }
};

class SeniorTeacher : public Teacher {
private:
    Subject subject;   // Has-a relationship
    static int count;

public:
    SeniorTeacher(int i, string n, string sub) : Teacher(i, n), subject(sub) {
        count++;
    }

    // Function Overloading
    void assignClass(string section) {
        cout << "Assigned Section: " << section << endl;
    }

    void assignClass(string section, int room) {
        cout << "Section: " << section << ", Room: " << room << endl;
    }

    void display() {
        cout << "Teacher Name: " << this->name << endl; // using this pointer
        cout << "Subject: " << subject.subjectName << endl;
    }

    static void showCount() {
        cout << "Total Senior Teachers: " << count << endl;
    }
};

int SeniorTeacher::count = 0;

int main() {
    SeniorTeacher t[] = {
        SeniorTeacher(1, "Ali", "Math"),
        SeniorTeacher(2, "Sara", "Physics"),
        SeniorTeacher(3, "Ahmed", "Chemistry")
    };

    t[0].assignClass("A");
    t[1].assignClass("B", 101);

    for (int i = 0; i < 3; i++) {
        t[i].display();
    }

    cout << "\nTeacher Assigned Successfully\n";
    SeniorTeacher::showCount();
}