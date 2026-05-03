#include <iostream>
using namespace std;

class ElectricityBill {
private:
    int customerID;
    string customerName;
    float unitsConsumed;
    float ratePerUnit;

public:
    // Default Constructor
    ElectricityBill() {
        customerID = 0;
        customerName = "NA";
        unitsConsumed = 0;
        ratePerUnit = 0;
    }

    // Parameterized Constructor
    ElectricityBill(int id, string name, float units, float rate) {
        setCustomerID(id);
        setCustomerName(name);
        setUnits(units);
        setRate(rate);
    }

    // Destructor
    ~ElectricityBill() {}

    // Setters
    void setCustomerID(int id) {
        customerID = id;
    }

    void setCustomerName(string name) {
        customerName = name;
    }

    void setUnits(float units) {
        if (units > 0)
            unitsConsumed = units;
        else
            throw "Units must be greater than zero!";
    }

    void setRate(float rate) {
        if (rate > 0)
            ratePerUnit = rate;
        else
            throw "Rate must be positive!";
    }

    // Getters
    int getCustomerID() { return customerID; }
    string getCustomerName() { return customerName; }
    float getUnits() { return unitsConsumed; }
    float getRate() { return ratePerUnit; }

    // Input
    void input() {
        cout << "Enter Customer ID: ";
        cin >> customerID;

        cout << "Enter Customer Name: ";
        cin >> customerName;

        cout << "Enter Units Consumed: ";
        cin >> unitsConsumed;

        cout << "Enter Rate Per Unit: ";
        cin >> ratePerUnit;

        if (unitsConsumed <= 0 || ratePerUnit <= 0)
            throw "Invalid input values!";
    }

    float calculateBill() {
        return unitsConsumed * ratePerUnit;
    }

    void display() {
        cout << "\nBill Generated Successfully\n";
        cout << "Total Amount: " << calculateBill() << endl;
    }
};

int main() {
    try {
        ElectricityBill e;
        e.input();
        e.display();
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}