#include<iostream>
using namespace std;
class ElectricityBill {
    string customerID;
    string customerName;
    int unitsConsumed=1;
    float ratePerUnit=0.1;
    public:
        ElectricityBill() {}
        ElectricityBill(string id, string name, int unit, float rate) {
            customerID=id;
            customerName=name;
            if (unit<=0) throw "Units less than 0. Units set to 1\n";
            else unitsConsumed=unit;
            if(rate<0) throw "Rates per unit cannot be negative\n";
            else ratePerUnit = rate;  
        }
        void setcustomerID(string id) {
            customerID = id;
        }
        void setcustomerName(string name) {
            customerName = name;
        }
        void setUnitsConsumed(int u) {
            //unitsConsumed = u;
            if (u<=0) throw "Units less than 0. Units set to 1\n";
            else unitsConsumed=u;
        }
        void setratePerUnit(float rate) {
            if(rate<0) throw "Rates per unit cannot be negative\n";
            else ratePerUnit = rate;  
        }
        string getID() {
            return customerID;
        }
        string getname() {
            return customerName;
        }
        int getUnitsConsumed() {
            return unitsConsumed;
        }
        float getratePerUnit() {
            return ratePerUnit;
        }

        void inputDetails() {
            string name, id;
            int unit;
            float rate;
            cout << "Enter name: ";
            cin >> name;
            setcustomerName(name);
            cout << "Enter ID: ";
            cin >> id;
            setcustomerID(id);
            cout << "Enter units consumed: ";
            cin >> unit;
            setUnitsConsumed(unit);
            cout << "Enter rate per unit: ";
            cin >> rate;
            setratePerUnit(rate);
        }
        void display() {
            cout << "Name: " << customerName << " | ID: " << customerID << " | Units Consumed: " << unitsConsumed << " | Rate per Units: " << ratePerUnit << endl;
        }

        void calculateBill() {
            cout << "Bill Generated Successfully\n";
            cout << "Total Amount: " << ratePerUnit*unitsConsumed << endl;
        }
        ~ElectricityBill() {
            cout << "Object Destroyed\n";
        }
};

int main () {
    try {
        ElectricityBill e1("90op", "Ali", 9, -9);
        e1.calculateBill();
    } 
    catch (const char* mes) {
        cout << mes;
    }

    
}