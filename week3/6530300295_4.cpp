#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *prev;
    struct record *next;
};

struct ht{
    struct record *hh;
    struct record *tt;
};

struct ht insert(struct record *head, struct record *tail, int data){
    struct ht box;
    struct record *node, *p;
    if(head == NULL){
        head = new struct record;
        head -> value = data;
        head -> prev = head -> next = NULL;
        tail = head;
        box.hh = head;
        box.tt = tail;
    }else{
        node = new struct record;
        node -> value = data;
        if(data < head -> value){
            node -> prev = NULL;
            node -> next = head;
            head ->prev = node;
            head = node;
            box.hh = head;
            box.tt = tail;
        }else{
            p = head;
            while(p -> next != NULL){
                if(data < p -> next -> value){
                    node -> next = p -> next;
                    node -> prev = p -> next -> prev;
                    p -> next -> prev = node;
                    p -> next = node;

                    box.hh = head;
                    box.tt = tail;
                    break;
                }else{
                    p = p -> next;
                }
            }
            if(p -> next == NULL){
                node -> next = NULL;
                node -> prev = tail;
                p -> next = node;
                tail = node;
                box.hh = head;
                box.tt = tail;
            }
        }
    }
    return box;
}

void printAllData(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "List = ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printMinMax(struct record *head){
    struct record *temp;
    cout << endl << "Min to max : ";
    temp = head;
    while(temp != NULL){
        cout << temp -> value << " ";
        temp = temp -> next;
    }
}

void printMaxMin(struct record *tail){
    struct record *temp;
    cout << endl << "Max to min : ";
    temp = tail;
    while(temp != NULL){
        cout << temp -> value << " ";
        temp = temp -> prev;
    }
}

void printMenu(){
    cout << endl << "========MENU=======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print min to max / max to min" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}



int main(){
    int choice, data;
    struct record *head=NULL,*tail=NULL;
    struct ht box;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter number : ";
                cin >> data;
                box = insert(head, tail, data);
                head = box.hh;
                tail = box.tt;
                printAllData(head);
                break;
            case 2:
                printMinMax(head);
                printMaxMin(tail);
                break;
            case 3:
                cout << endl << "Thank you!";
                break;
            default:
                cout << "Please try again";
        }

    }while(choice != 3);
}
