#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct he{
    struct record *hh;
    struct record *ee;
};

struct he insert(struct record *head, struct record *end, int data){
    struct record *p;
    struct he box;
    if(data != -1){
        if(head == NULL){
            head = new struct record;
            head -> value = data;
            head -> next = NULL;
            end = head;
            box.hh = head;
            box.ee = end;
        }else{
            p = new struct record;
            p -> value = data;
            p -> next = NULL;
            end -> next = p;
            end = p;
            box.hh = head;
            box.ee = end;
        }
    }

    return box;
};

void printAllData(struct record *head){
    struct record *p;
    p = head;
    cout << endl << "List : ";
    while(p != NULL){
        cout << p -> value << " ";
        p = p -> next;
    }
}

int main(){
    struct record *head = NULL, *end = NULL;
    struct he box;
    int data;

    cout << "Input : ";
    while(data != -1){
        cin >> data;

        if(data != -1){
            box = insert(head, end, data);
            head = box.hh;
            end = box.ee;
        }
    }

    printAllData(head);
}
