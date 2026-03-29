#include <iostream>
#include<iterator>
using namespace std;
class Items {
    string s;
    public:
        Items(string g) {
            s=g;
        }
        bool operator== (Items& i) {
            if (s==i.s) return true;
            else return false;
        }
};

class room {
    public:
        bool hasRealtion(Items arr1[], int size1, Items arr2[], int size2) {
            bool flag = true;
            bool found =  false;
            for (int i=0; i<size1; i++) {
                bool found = false;
                for (int j=0; j<size2; j++) {
                    if (*(arr1+i)==*(arr2+j)) {
                        found = true;
                        break;
                    }
                }
                if (found==false) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) return false;
            else return true;

        }
};

int main () {
    Items room1[] = {Items("Fridge"), Items("TV"), Items("Sofa")};
    int size1 = size(room1);
    Items room2[] = {Items("Pencil"), Items("TV"), Items("Fridge"), Items("Sofa")};
    int size2 = size(room2);
    room r3;
    if (r3.hasRealtion(room1, size1, room2, size2)) {
        cout << "It exists\n";
    }
    else cout << "It doesn't exist\n";
}