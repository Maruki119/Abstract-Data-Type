#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    char value;
    struct Node *next;
};

struct Node *CreateStack(void){
    struct Node *S;
    S = new struct Node;
    if(S == NULL){
        cout << "Out of space!!!" << endl;
    }
    S -> next = NULL;

    return S;
}

int IsEmpty(struct Node *S){

    return S -> next == NULL;
}

void Pop(struct Node *S){
    struct Node *firstCell;
    if(IsEmpty(S)){
        cout << endl << "Empty Stack!!!" << endl;
    }else{
        firstCell = S -> next;
        S -> next = S -> next -> next;
        delete(firstCell);
    }
}

void MakeEmpty(struct Node *S){
    if(S == NULL){
        cout << "Must use CreateStack first" << endl;
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Push(char data, struct Node *S){
    struct Node *tempCell;
    tempCell = new struct Node;
    if(tempCell == NULL){
        cout << "Out of space!!!";
    }else{
        tempCell -> value = data;
        tempCell -> next = S -> next;
        S -> next = tempCell;
    }
}

char Top(struct Node *S){
    if(!IsEmpty(S)){
        return S -> next -> value;
    }
    cout << "Empty Stack!!!" << endl;

    return 0;
}

void printAllData(struct Node *S){
    struct Node *temp;
    if(IsEmpty(S)){
        cout << endl << "Empty Stack!!!" << endl;
    }else{
        cout << endl << "Stack : ";
        temp = S;
        temp = temp -> next;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main(){
    struct Node *S = NULL;
    char data[30];
    int number, sum;

    S = CreateStack();

    cout << "Input : ";
    while(data[0] != '.'){
        cin >> data;
        if(data[0] >= '0' && data[0] <= '9'){
            number = atoi(data);
            sum += number;
            cout << number << "\tdigit" << endl;
        }

        else
           if(data[0] != '.'){
               Push(data[0], S);
               cout << Top(S) << "\tsymbol" << endl;
           }
    }

    cout << endl << "Output = " << sum << endl;
}
