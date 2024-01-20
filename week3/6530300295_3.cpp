#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head, int data){
    struct record *node, *p;
    if(head == NULL){
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }else{
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        p = head;
        while (p != NULL)
        {
            if (p -> next == NULL)
            {
                p -> next = node;
                break;
            }
            p = p -> next;
        }
    }

    return head;
};

int countData(struct record *head){
    int count;
    struct record *node;
    node = head;
    while(node -> next -> next != NULL){
        count++;
        node = node -> next -> next;
    }
    if(node -> next -> next == NULL){
        count++;
    }

    return count;
}

void printLonger(struct record *head){
    struct record *temp;
    temp = head;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "Longer : ";
        while(temp != NULL){
            cout << temp -> value;
            if(temp -> next -> value == 0){

            }else if(temp -> next -> value == 1){
                cout << "x";
            }else{
                cout << "x^";
                cout << temp -> next -> value;
            }

            if(temp -> next -> next != NULL){
                cout << " + ";
            }

            temp = temp -> next -> next;
        }
    }
}

int main(){
    struct record *headP1 = NULL;
    struct record *headP2 = NULL;
    int data;

    cout << "Input P1 : ";
    do{
        cin >> data;
        if(data != -99){
            headP1 = insert(headP1, data);
        }
    }while(data != -99);

    cout << "Input P2 : ";
    do{
        cin >> data;
        if(data != -99){
            headP2 = insert(headP2, data);
        }
    }while(data != -99);

    if(countData(headP1) > countData(headP2)){
        printLonger(headP1);

    }else{
        printLonger(headP2);

    }
}
