#include <iostream>
using namespace std;

struct Node{
    int value;
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

void Push(int data, struct Node *S){
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

int Top(struct Node *S){
    if(!IsEmpty(S)){
        return S -> next -> value;
    }
    cout << "Empty Stack!!!" << endl;

    return 0;
}

void printAllData(struct Node *S){
    struct Node *temp;
    if(IsEmpty(S)){
        cout << "Empty Stack!!!" << endl;
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

void printMenu(){
    cout << endl << "=======MENU=======" << endl;
    cout << "1)Push" << endl;
    cout << "2)Pop" << endl;
    cout << "3)Top" << endl;
    cout << "4)Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct Node *S = NULL;
    int choice, data;

    S = CreateStack();

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl << "Push : ";
                cin >> data;
                Push(data, S);
                cout << endl << "Success!" << endl;
                printAllData(S);
                break;
            case 2:
                if(!IsEmpty(S)){
                    cout << endl << "Pop : " << Top(S);
                    Pop(S);
                    cout << endl;
                }else{
                    cout << endl;
                    Pop(S);
                }
                break;
            case 3:
                if(!IsEmpty(S)){
                    cout << endl << "Top : " << Top(S) << endl;
                }else{
                    cout << endl;
                    Top(S);
                }
                break;
            case 4:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please try again.";
        }
    }while(choice != 4);
}
