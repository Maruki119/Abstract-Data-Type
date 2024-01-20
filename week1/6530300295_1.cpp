#include <iostream>
using namespace std;

int main(){
    float temp_cel, temp_fah;

    cout << "Enter Celcius : ";
    cin >> temp_cel;

    temp_fah = (temp_cel * (9.0/5.0)) + 32;

    cout << endl << "Fahrenheit = " << temp_fah;
}
