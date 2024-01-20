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

void firstChoice(struct Node *S){
    struct Node *temp;
    char data[30], opt;
    int number, firstData = 1;

    cout << endl << "Infix : ";
    while(data[0] != '.'){
        cin >> data;

        if(firstData == 1){
            cout << "Postfix : ";
            firstData = 0;
        }

        if(data[0] >= '0' && data[0] <= '9'){
            number = atoi(data);
            cout << number << " ";
        }else{
            if(data[0] != '.'){
                if(IsEmpty(S)){
                    Push(data[0], S);
                    opt = Top(S);
                }else{
                    if(data[0] == '*' || data[0] == '/'){
                        if(opt == '+' || opt == '-'){
                            Push(data[0], S);
                            opt = Top(S);
                        }else{
                            while(S -> next != NULL){
                                cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(opt, S);
                        }
                    }else if(data[0] == '+' || data[0] == '-'){
                        if(opt == '*' || opt == '/'){
                            while(S -> next != NULL){
                                cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(data[0], S);
                            opt = Top(S);
                        }else{
                            while(S -> next != NULL){
                                cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(data[0], S);
                            opt = Top(S);
                        }
                    }
                }
           }else{
               temp = S;
               temp = temp -> next;
                while(temp != NULL){
                    cout << temp -> value << " ";
                    temp = temp -> next;
                }
           }
        }
    }
}

void secondChoice(struct Node *S){
    struct Node *temp;
    char data[30], opt, optNew;
    int number, firstData = 1;

    cout << endl << "Infix : ";
    while(data[0] != '.'){
        cin >> data;

        if(firstData == 1){
            cout << "Postfix : ";
            firstData = 0;
        }

        if(data[0] >= '0' && data[0] <= '9'){
            number = atoi(data);
            cout << number << " ";
        }else{
            if(data[0] != '.'){
                if(IsEmpty(S)){
                    Push(data[0], S);
                    opt = Top(S);
                }else{
                    if(data[0] == '*' || data[0] == '/'){
                        if(opt == '+' || opt == '-'){
                            Push(data[0], S);
                            opt = Top(S);
                        }else{
                            while(S -> next != NULL){
                                if(Top(S) != '(')
                                    cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(opt, S);
                        }
                    }else if(data[0] == '+' || data[0] == '-'){
                        if(opt == '*' || opt == '/'){
                            while(S -> next != NULL){
                                if(Top(S) != '(')
                                    cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(data[0], S);
                            opt = Top(S);
                        }else{
                            while(S -> next != NULL){
                                if(Top(S) != '(')
                                    cout << Top(S) << " ";
                                Pop(S);
                            }
                            Push(data[0], S);
                            opt = Top(S);
                        }
                    }else if(data[0] == '('){
                        Push(data[0], S);

                    }else if(data[0] == ')'){
                        optNew = Top(S);

                        if (optNew == '('){
                            Pop(S);
                        }
                    }
                }
           }else{
               temp = S;
               temp = temp -> next;
                while(temp != NULL){
                    cout << temp -> value << " ";
                    temp = temp -> next;
                }
           }
        }
    }
}

void printMenu(){
    cout << endl << "=======MENU======" << endl;
    cout << "1.Infix" << endl;
    cout << "2.Infix ()" << endl;
    cout << "Please choose > ";
}

int main(){
    struct Node *S;
    char data[30];
    int number, choice, count;

    S = CreateStack();

    printMenu();
    cin >> choice;

    switch(choice){
        case 1:
            firstChoice(S);
            break;
        case 2:
            secondChoice(S);
            break;
    }
}
