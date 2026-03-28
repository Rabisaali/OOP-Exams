#include<iostream>
#include<string>
using namespace std;

class Device {
    public:
        string name;
        float power;
        float hours;
    public:
        Device() {}
        Device (string n, float p, float h) {
            name = n;
            power = p;
            hours = h;
        }
        Device (const Device& d) {
            name = d.name;
            power = d.power;
            hours = d.hours;
        }
        void display() {
            cout << name << "(" << power << "W, " << hours << " hours/day)\n";
        }
};

class Discount {
    float discountPercentage=0.1538;
    public:
        float applyDiscount(float totalCost) {
            return ((1-discountPercentage)*totalCost);
        }

};

class EntertainmentRoom:public Device, public Discount {
    int deviceCount=0;
    Device devices[5];

    public:
        void adddevice(Device d) {
            if (deviceCount<5) {
                devices[deviceCount]=d;
                deviceCount++;
            }
            else cout << "Device limit exceeded\n";
        }
        float calculateTotalEnergy() {
            if (deviceCount==0) cout << "No devices yet :(\n";
            else {
                float total=0;
                for (int i=0; i<deviceCount; i++) {
                    total+=(devices[i].power * devices[i].hours)/1000;
                }
                total*=2;
                return total;
            }
            return 0;
        }
        Device findHighestEnergyDevice() {
            float highest=0; int index=0;
            for (int i=0; i<deviceCount; i++) {
                if (devices[i].power > highest) {
                    highest = devices[i].power;
                    index = i;
                }
            }
            return devices[index];
        }
        void displayEnergySummary() {
            cout << "Entertainment Room Devices:\n";
            for (int i=0; i<deviceCount; i++) {
                devices[i].display();
            }
            cout << endl;
            float total = calculateTotalEnergy();
            cout << "Total energy Consumption:" << total << " kWh\n";
            float cost = total*0.15;
            cout << "Total Cost before discount: " << cost << endl;
            cout << "Total cost after discount: " << applyDiscount(cost) << endl;
            cout << "Highest Energy Consuming device: ";
            Device d = findHighestEnergyDevice();
            d.display();
        }
};

int main () {
    Device tv("TV", 100, 6);
    Device gamingconsole("Gaming Console", 200, 4);
    Device soundsystem("Sound System", 150, 5);

    EntertainmentRoom e1;
    e1.adddevice(tv);
    e1.adddevice(gamingconsole);
    e1.adddevice(soundsystem);

    e1.displayEnergySummary();
}