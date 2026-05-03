#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string vehicleNumber;
    string ownerName;
    float serviceCost;

public:
    virtual void calculateService() = 0;

    float getCost() {
        return serviceCost;
    }

    friend void display(Vehicle* v);
};

// Friend Function
void display(Vehicle* v) {
    cout << "Service Cost: " << v->getCost() << endl;
}

// Derived Classes
class Car : public Vehicle {
public:
    Car(string v, string o) {
        vehicleNumber = v;
        ownerName = o;
    }

    void calculateService() {
        serviceCost = 3000;
    }
};

class Bike : public Vehicle {
public:
    Bike(string v, string o) {
        vehicleNumber = v;
        ownerName = o;
    }

    void calculateService() {
        serviceCost = 1500;
    }
};

class Truck : public Vehicle {
public:
    Truck(string v, string o) {
        vehicleNumber = v;
        ownerName = o;
    }

    void calculateService() {
        serviceCost = 5000;
    }
};

// Operator Overloading
float operator+(Vehicle& v1, Vehicle& v2) {
    return v1.getCost() + v2.getCost();
}

int main() {
    try {
        Vehicle* v1 = new Car("ABC123", "Ali");
        Vehicle* v2 = new Truck("XYZ789", "Sara");

        v1->calculateService();
        v2->calculateService();

        if (v1->getCost() < 0 || v2->getCost() < 0)
            throw "Invalid service cost!";

        display(v1);
        display(v2);

        float total = *v1 + *v2;
        cout << "Total Service Cost: " << total << endl;

        ofstream file("service.txt");
        if (!file)
            throw "File opening error!";

        file << "Total Service Cost: " << total;
        file.close();

        cout << "\nService Completed Successfully\n";
        cout << "Record Saved Successfully\n";
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}