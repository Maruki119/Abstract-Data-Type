#include <iostream>
using namespace std;

int main(){
    int input;

    cout << "input : ";
    cin >> input;

    for(int i = 1; i <= input; i++){
        for(int j = i; j <= input; j++){
            for(int k = i; k <= j; k++){
                cout << k;
            }

            cout << " ";
        }
        if(i == input){
            cout << input;
        }
        cout << endl;
    }
}
