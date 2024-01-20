#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};
struct record *p;

int main(){
    int data;

    cout << "Enter : ";
    cin >> data;

    p = new struct record;
    p -> value = data;
    cout << "Value=" << p -> value;
}
