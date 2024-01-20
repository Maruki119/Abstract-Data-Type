#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct fr{
    struct record *front;
    struct record *rear;
};

struct fr enQueue(struct fr q, int data){
    struct record *node;

    if(q.front == NULL){
        q.front = new struct record;
        q.front -> value = data;
        q.front -> next = NULL;
        q.rear = q.front;
    }else{
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        q.rear -> next = node;
        q.rear = node;
    }

    return q;
};

struct fr deQueue(struct fr q){
    struct record *tmpfree;
    if(q.front != NULL){
        tmpfree = q.front;
        q.front = q.front -> next;
        delete(tmpfree);
    }else{
        cout << endl << "Empty! Can't Dequeue" << endl;
    }

    return q;
};

void printFront(struct fr q){
    if(q.front != NULL){
        cout << q.front -> value;
    }
}

void printAllData(struct fr q){
    struct record *p;
    p = q.front;

    if(q.front == NULL){
        cout << endl << "Empty Queue";
    }else{
        while(p != NULL){
            cout << p -> value << " ";
            p = p -> next;
        }
    }
}

void printMenu(){
    cout << endl << "=======MENU======" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct fr q;
    int data, choice;

    q.front = NULL;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl << "Enter data: ";
                cin >> data;
                q = enQueue(q, data);
                cout << endl << "Success!" << endl;
                break;
            case 2:
                if(q.front != NULL){
                    cout << endl << "Dequeue ";
                    printFront(q);
                    cout << endl;
                }
                q = deQueue(q);
                break;
            case 3:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please try again.";
        }

    }while(choice != 3);

}
