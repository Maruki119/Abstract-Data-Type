#include <iostream>
using namespace std;

struct Node{
    char value;
    struct Node *next;
};

struct Symbol{
    int Open1;
    int Open2;
    int Open3;
    int Open4;
    int Close1;
    int Close2;
    int Close3;
    int Close4;
}Sym;

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

struct Symbol countSym(struct Symbol Sym, struct Node *S){
    struct Node *temp;
    temp = S;
    temp = temp -> next;
    while(temp != NULL){
        if(temp -> value == '{'){
            Sym.Open1++;
        }else if(temp -> value == '['){
            Sym.Open2++;
        }else if(temp -> value == '('){
            Sym.Open3++;
        }else if(temp -> value == '<'){
            Sym.Open4++;
        }else if(temp -> value == '}'){
            Sym.Close1++;
        }else if(temp -> value == ']'){
            Sym.Close2++;
        }else if(temp -> value == ')'){
            Sym.Close3++;
        }else if(temp -> value == '>'){
            Sym.Close4++;
        }else{

        }

        temp = temp -> next;

    }

    return Sym;
}

void checkSymbol(struct Symbol Sym){
    if(Sym.Open1 == Sym.Close1 && Sym.Open2 == Sym.Close2 && Sym.Open3 == Sym.Close3
       && Sym.Open4 == Sym.Close4){
        cout << endl << "Complete!" << endl;
    }else{
        cout << endl << "Expected ";

        if(Sym.Open1 > Sym.Close1)
            cout << "} ";
        if(Sym.Open1 < Sym.Close1)
            cout << "{ ";
        if(Sym.Open2 > Sym.Close2)
            cout << "] ";
        if(Sym.Open2 < Sym.Close2)
            cout << "[ ";
        if(Sym.Open3 > Sym.Close3)
            cout << ") ";
        if(Sym.Open3 < Sym.Close3)
            cout << "( ";
        if(Sym.Open4 > Sym.Close4)
            cout << "> ";
        if(Sym.Open4 < Sym.Close4)
            cout << "< ";
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

    Sym = countSym(Sym, S);
    checkSymbol(Sym);
}
