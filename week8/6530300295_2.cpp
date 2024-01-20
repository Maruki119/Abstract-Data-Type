#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head, int data){
    struct record *end, *p;
    while(data != -1){
        cin >> data;
        if(data != -1){
            if(head == NULL){
                head = new struct record;
                head -> value = data;
                head -> next = NULL;
                end = head;
            }else{
                p = new struct record;
                p -> value = data;
                p -> next = NULL;
                end -> next = p;
                end = p;
            }
        }
    }

    return head;
};

void printAdjacencyList(struct record *adj[]){
    struct record *p;
    cout << endl << "ADJACENCY LIST" << endl;
    for(int i = 0; i < 6; i++){
        p = adj[i];
        cout << "#" << i << ": ";
        while(p != NULL){
            cout << p -> value << " ";
            p = p -> next;
        }
    cout << endl;
    }
}

void printAdjacencyMatrix(struct record *adj[]){
    struct record *p;
    int now = 0;
    cout << endl << "ADJACENCY MATRIX" << endl;
    cout << "-------------------------" << endl;
    for(int i = 0; i < 6; i++){
        p = adj[i];
        for(int j = 0; j < 6; j++){
            if(p -> value == j){
                cout << "1 ";
            }else{
                cout << "0 ";
                continue;
            }
            if(p -> next != NULL){
                p = p -> next;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printSelfloop(struct record *adj[]){
    struct record *p;
    cout << endl << "Selfloop : ";
    for(int i = 0; i < 6; i++){
        p = adj[i];
        while(p != NULL){
            if(p -> value == i){
                cout << p -> value << " ";
            }
            p = p -> next;
        }
    }
    cout << endl;
}

void printMenu(){
    cout << endl << "===========MENU==========" << endl;
    cout << "1) Input adjacency list" << endl;
    cout << "2) Input adjacency matrix" << endl;
    cout << "3) Show self loop from adjacency list" << endl;
    cout << "4) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct record *head = NULL;
    struct record *adj[6];
    int data, choice;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl;
                for(int i = 0; i < 6; i++){
                    cout << "Enter #" << i << ": ";
                    adj[i] = insert(head, data);
                }
                printAdjacencyList(adj);
                break;
            case 2:
                cout << endl;
                for(int i = 0; i < 6; i++){
                    cout << "Enter #" << i << ": ";
                    adj[i] = insert(head, data);
                }
                printAdjacencyMatrix(adj);
                break;
            case 3:
                printSelfloop(adj);
                break;
            case 4:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again.";
        }

    }while(choice != 4);
}
