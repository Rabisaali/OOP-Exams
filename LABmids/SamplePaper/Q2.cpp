#include<iostream>
#include<string>
using namespace std;


class MenuItem {
    public:
    string name;
    float price;
    public:
        MenuItem() {}
        MenuItem(string n, float p) : name(n), price(p) {}
        MenuItem(const MenuItem& m) {
            name = m.name;
            price = m.price;
        }
};

class Order {
    public:
    int orderID;
    MenuItem items[3];
    int itemCount=0;
    Order() {}
    Order(int n) {
        orderID = n;
    }
        Order (const Order& o) {
            orderID = o.orderID;
            itemCount = o.itemCount;
            for (int i=0; i<itemCount; i++) {
                items[i] = o.items[i];
            }

        }
        void addItem(MenuItem m) {
             if (itemCount<3) {
                items[itemCount] = m;
                itemCount++;
             }
             else cout << "Order limit exceeded\n";
        }
        int calculateOrderTotal() {
            int totalcost=0;
            for (int i=0; i<itemCount; i++) {
                totalcost += items[i].price;
            }
            return totalcost;
        }
};

class Table {
    public:
    int tableNumber;
    Order orders[4];
    int orderCount=0;
    public:
    Table () {}
    Table (int n) {
        tableNumber = n;
    }
        void addOrder(Order o) {
            if (orderCount>=4) {
                cout << "Order limit exceeded\n";
                return;;
            }
            orders[orderCount] = o;
            orderCount++;
        }
        int calculateTotalBill () {
            int total=0;
            for (int i=0; i<orderCount; i++) {
                total+=orders[i].calculateOrderTotal();
            }
            return total;
        }
        void display() {
            cout << "Table: "<< tableNumber << endl;
            for (int i=0; i<orderCount; i++) {
                cout << "Order: " << orders[i].orderID << ":\n";
                for (int j=0; j<orders[i].itemCount; j++) {
                    cout << orders[i].items[j].name << " - " << orders[i].items[j].price << endl;
                }
            }
            cout << "Total Bill for Table " << tableNumber << ": " << calculateTotalBill() << endl;
        }
};

int main () {
    Table t1;
    
    MenuItem burger("Burger", 12.5);
    MenuItem fries("Fries", 4.0);
    MenuItem Pizza ("Pizza", 18.0);
    Order o1(101);
    o1.addItem(burger);
    o1.addItem(fries);
    Order o2(102);
    o2.addItem(Pizza);
    t1.addOrder(o1);
    t1.addOrder(o2);
    t1.display();
}