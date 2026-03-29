#include<iostream>
using namespace std;

class Victim {
    protected:
        string name;
        string victim_history;
        string role;
    public:
        Victim(string n, string v, string r) : name(n), victim_history(v), role(r) {}
};

class Lawyer {
    protected:
        int licence_number;
        string specialization;
        int years_of_practice;
        string victim_evidence;

    public:
        Lawyer (int n, string s, int y, string v) : licence_number(n), specialization(s), years_of_practice(y), victim_evidence(v) {}
};

class Judge {
    protected:
        int judicialID;
        int years_of_experience;
        string specialization_judge;

    public:
        Judge(int id, int y, string s) : judicialID(id), years_of_experience(y), specialization_judge(s) {}
};

class Admin: public Victim, public Lawyer, public Judge {
    public:
        int room_number;
        int capacity;
        bool availabilty;

        Admin (string n, string v, string r, int num, string st, int y, string ve, int id, int ye, string sp, int rno, int cap, bool a) : Victim(n, v, r), Lawyer(num, st, y, ve), Judge(id, ye, sp) {
            room_number = rno;
            capacity = cap;
            availabilty = a;
        } 
        void Decision() {
            cout << "Judges's decison is: ";
            if (victim_evidence=="valid" && victim_history=="innocent") {
                cout << "Innocent!\n";
            }
            else cout << "Guilty\n";
        }
};

int main () {
    Admin a("Ali", "innocent", "Guilty", 3, "criminology", 5, "valid", 67, 56, "criminology", 57, 80, "true");
    a.Decision();
}