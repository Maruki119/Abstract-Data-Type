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

struct fr deQueue(struct fr q, int M){
    struct record *tmpfree;
    while(q.front != q.rear){
        for(int i = 0; i < M; i++){
            q.front = q.front -> next;
            q.rear = q.rear -> next;
        }
        tmpfree = q.front;
        q.front = q.front -> next;
        q.rear -> next = q.front;
        delete(tmpfree);
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
    int M, N;

    q.front = NULL;

    cout << "Input M: ";
    cin >> M;

    cout << endl << "Input N: ";
    cin >> N;

    for(int i = 1; i <= N; i++){
        q = enQueue(q, i);
    }

    q.rear -> next = q.front;

    q = deQueue(q, M);

    cout << endl << "Winner is : ";
    printFront(q);

}
