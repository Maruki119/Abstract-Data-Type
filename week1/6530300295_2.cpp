#include <iostream>
using namespace std;

int main(){
    int input, checkPrime = 0;

    cout << "input : ";
    cin >> input;

    if(input >= 2){
        for(int i = 1; i <= input; i++){
            if(input % i == 0){
                checkPrime++;
            }
        }
        if(checkPrime == 2){
            cout << "Prime";
        }else{
            cout << "Not prime";
        }
    }else{
        cout << "Not prime";
    }
}
