#include<iostream>
#include<fstream>
using namespace std;

class Vehicle {
    public:
        int VehicleNumber;
        string ownerName;
        double serviceCost=1;
        virtual void calculateService() = 0;
    public:
        Vehicle (int num, string name, double cost) {
            VehicleNumber = num;
            ownerName = name;
            if (cost < 0) throw "Invlaid Service cost\n";
            else serviceCost = cost;
        }
        friend double operator+ (const Vehicle& v1, const Vehicle& v2);
        friend void display(Vehicle* v);
};

double operator+ (const Vehicle& v1, const Vehicle& v2) {
    return (v1.serviceCost + v2.serviceCost);
}

void display (Vehicle* v) {
    cout << "Vehicle number: " << v->VehicleNumber << endl;
    cout << "Owner name: " << v->ownerName << endl;
    cout << "Service cost: " << v->serviceCost << endl;
}

class Car : public Vehicle {
    public:
        Car (int num, string name, double cost) : Vehicle (num, name, cost) {}
        void calculateService() {
            cout << "Cost of serice for car: " << serviceCost << "\n";
        }
};

class Bike : public Vehicle {
    public:
        Bike (int num, string name, double cost) : Vehicle (num, name, cost) {}
        void calculateService() {
            cout << "Cost of serice for bike: " << serviceCost << "\n";
        }
};

class Truck : public Vehicle {
    public:
        Truck (int num, string name, double cost) : Vehicle (num, name, cost) {}
        void calculateService() {
            cout << "Cost of serice for truck: " << serviceCost << "\n";
        }
};

int main () {
    try {
        Vehicle* v1, *v2;
        Car c(23, "rabisa", 34);
        Bike b(45, "ali", 45);
        v1 = &c;
        v2 = &b;
        double cost = *v1 + *v2;
        cout << cost << "\n";
        fstream f("data.txt", ios::app);
        if (!f) throw "File opening error\n";
        f<< "Name: " <<(v1->ownerName);
        f<<" | Number: " << v1->VehicleNumber ;
        f<< " | Service cost: " << v1->serviceCost;


    } catch (const char* mesg) {
        cout << mesg << endl;
    }
}