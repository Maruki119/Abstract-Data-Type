#include <iostream>
using namespace std;

int main(){
    int input[10];

    cout << "Enter : ";
    for(int i = 0; i < 10; i++){
        cin >> input[i];
    }

    cout << endl << "Output : ";
    for(int i = 9; i >= 0; i--){
        cout << input[i] << " ";
    }
}
