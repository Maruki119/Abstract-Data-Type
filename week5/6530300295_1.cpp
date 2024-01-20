#include <iostream>
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
        cout << "Empty Stack!!!" << endl;
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

int countOpen(struct Node *S){
    struct Node *temp;
    int countOpen;
    temp = S;
    temp = temp -> next;
    while(temp != NULL){
        if(temp -> value == '{' || temp -> value == '[' || temp -> value == '(' || temp -> value == '<')
            countOpen++;
        temp = temp -> next;
    }
    return countOpen;
}

void printOpen(struct Node *S){
    struct Node *temp;
    int countChar, countRnd, rnd;
    if(IsEmpty(S)){
        cout << "Empty Stack!!!" << endl;
    }else{
        temp = S;
        temp = temp -> next;
        while(temp != NULL){
            countChar++;
            temp = temp -> next;
        }

        countRnd = countChar;
        while(rnd < countRnd){
            temp = S;
            temp = temp -> next;
            for(int i = 0; i < countChar - 1; i++){
                temp = temp-> next;
            }
            if(temp -> value == '{' || temp -> value == '[' || temp -> value == '(' || temp -> value == '<')
                cout << temp -> value << endl;
            countChar--;
            rnd++;
        }

        cout << endl;
    }
}

int main(){
    struct Node *S = NULL;
    char data[30];
    int count;

    S = CreateStack();

    cout << "Input : ";

    while(data[0] != '.'){
        cin >> data[0];
        Push(data[0], S);
        count++;
    }
    Pop(S);
    cout << endl;

    printOpen(S);

    cout << "Open = " << countOpen(S);
}
