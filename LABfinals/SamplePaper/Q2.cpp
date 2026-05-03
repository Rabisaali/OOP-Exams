#include<iostream>
using namespace std;
class Subject {
    public:
        string name;
        Subject() {
            name = "random";
        }
        Subject(string n) {
            if (n=="") throw "Subject name cannot be empty\n";
            name = n;
        }
};
class Teacher {
    protected:
    string name;
    string ID;
    public:
        Teacher (string n, string id) {
            this->name = n;
            this->ID = id;
        }
};
class SeniorTeacher: public Teacher {
    public:
        Subject subject;
        char section;
        int roomNumber;
        static int TotalSeniorTeacher;
        SeniorTeacher() : Teacher("", ""), subject("random") , section('\0'), roomNumber(0) {}
        SeniorTeacher(string n, string id, Subject s, char sec, int num) : Teacher(n, id) {
            subject = s;
            section = sec;
            roomNumber = num;
            TotalSeniorTeacher++;
        }

        void assignClass(char sec) {
            section = sec;
        } 

        void assignClass(char sec, int num) {
            section = sec;
            roomNumber = num;
        }
};

int SeniorTeacher::TotalSeniorTeacher=0;
int main () {
    try {
        int max_Size = 10;
        int size;
        cout << "Enter the size of array: ";
        cin >> size;
        if (size > 10) throw "Size exceeded\n";
        SeniorTeacher arr[10];
        for (int i=0; i<size; i++) {
            cout << "Enter name: ";
            string name;
            cin >> name;
            cout << "Enter id: ";
            string id;
            cin >> id;
            cout << "Enter subject: ";
            string s;
            cin >> s;
            Subject subj(s);
            cout << "Enter section: ";
            char sec;
            cin >> sec;
            cout << "Enter room number: ";
            int room;
            cin >> room;
            arr[i] = SeniorTeacher(name, id, subj, sec, room);
        }
        cout << "teachers assigned successfully\n";
    }
    catch(const char* msg) {
        cout << msg;
    }
    cout << SeniorTeacher::TotalSeniorTeacher << "\n";
    return 0;
    
}