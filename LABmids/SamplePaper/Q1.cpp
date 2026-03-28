#include <iostream>
#include<string>
using namespace std;
class Member {
    private:
        const int membershipID;
        string name;
        int trainingSessions;
        static int totalMembers;
        static int totalsessions;
    public:
        Member (int id, string n, int tsess) : membershipID(id), name(n), trainingSessions(tsess) {
            totalMembers++;
            totalsessions+=tsess;
        }
        void displayDetails() {
            cout << "Membership ID: " << membershipID << endl;
            cout << "Name: " << name << endl;
            cout << "Training sessions: " << trainingSessions << endl;
        }
        int sessions() const {
            return trainingSessions;
        }
        static void display() {
            cout << "Total members: " << totalMembers << endl;
            cout << "Total number of sessions: " << totalsessions << endl;
        }
};

int Member::totalMembers=0;
int Member::totalsessions=0;

int main () {
    Member m[3] = {{201, "Sara Ali", 5}, {202, "Omer Shah", 3}, {203, "Aisha Khan", 4}};
    for(int i=0; i<3; i++) {
        cout << "Displaying details of member: " << i+1 << endl;
        m[i].displayDetails();
    }
    Member::display();
}
