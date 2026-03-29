#include<iostream>
using namespace std;

class Superman {
    const int health;
    const int power;
    public:
        Superman(int h, int p) : health(h), power(p) {}
        void displaySupermanInfo() {
            cout << "Helath: " << health << endl;
            cout << "Power: " << power << endl;
        }
        // void setHealth(int newHealth) {
        //     health = newHealth;
        // }
        // void setPower(int newPower) {
        //     power = newPower;
        // }
};

int main () {
    Superman s1(9, 10);
    s1.displaySupermanInfo();
    // s1.setHealth(79);
    // s1.setPower(80);
}