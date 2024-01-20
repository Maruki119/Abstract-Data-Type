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

struct ht deleteData(struct record *head, struct record *tail, int data){
    struct record *node, *p, *tempfree;
    struct ht box;
    node = head;
    if(data == head -> value){
        if(head -> next == NULL){
            tempfree = head;
            delete(tempfree);
            head = NULL;
            box.hh = head;
            box.tt = tail;

        }else{
            tempfree = head;
            head = head -> next;
            head -> prev = NULL;
            delete(tempfree);
            box.hh = head;
            box.tt = tail;
        }

    }else if(data == tail -> value){
        if(tail -> prev == NULL){
            tempfree = tail;
            delete(tempfree);
            tail = NULL;
            box.hh = head;
            box.tt = tail;

        }else{
            tempfree = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            delete(tempfree);
            box.hh = head;
            box.tt = tail;
        }

    }else{
        while(node != NULL){
            if(data == node -> next -> value){
                tempfree = node -> next;
                node -> next = tempfree -> next;
                tempfree -> next -> prev = tempfree -> next -> prev -> prev;
                delete(tempfree);
                box.hh = head;
                box.tt = tail;
                break;
            }else{
                node = node -> next;
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
        cout << endl << "List : ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printMenu(){
    cout << endl << "========MENU=======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Delete" << endl;
    cout << "3) Print" << endl;
    cout << "4) Exit" << endl;
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
                cout << "Delete : ";
                cin >> data;
                box = deleteData(head, tail, data);
                cout << "Success" << endl;
                head = box.hh;
                tail = box.tt;
                break;
            case 3:
                printAllData(head);
                break;
            case 4:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please try again";
        }

    }while(choice != 4);
}
