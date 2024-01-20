#include <iostream>
using namespace std;

//global var
int time;

struct record{
    int value;
    struct record *next;
};

struct status{
    int pass[8];
    int d[8];
    int f[8];
    int pred[8];
    int tree;
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

struct status DFS_Visit(struct status status, struct record *adj[], int u){
    struct record *p;
    int v;

    status.pass[u] = 1;
    status.d[u] = ++time;
    p = adj[u];
    while(p != NULL){
        v = p -> value;
        if(status.pass[v] == 0){
            status.pred[v] = u;
            status = DFS_Visit(status, adj, v);
        }
        p = p -> next;
    }
    status.pass[u] = 1;
    status.f[u] = ++time;

    return status;
};

struct status DFS(struct status status, struct record *adj[], int vertex){
    int u;

    time = 0;
    for(u = 0; u < 8; u++){
        status.pass[u] = 0;
        status.pred[u] = -1;
        status.d[u] = -1;
        status.f[u] = -1;
    }

    u = vertex;
    status = DFS_Visit(status, adj, u);
    for(u = 0; u < 8; u++){
        if(status.pass[u] == 0){
            status = DFS_Visit(status, adj, u);
        }
    }

    for (int i = 0; i < 8; i++){
        if (status.pred[i] == -1){
            status.tree++;
        }
    }

    return status;
};

void printAdjacencyList(struct record *adj[]){
    struct record *p;
    cout << endl << "ADJACENCY LIST" << endl;
    for(int i = 0; i < 8; i++){
        p = adj[i];
        cout << "#" << i << ": ";
        while(p != NULL){
            cout << p -> value << " ";
            p = p -> next;
        }
    cout << endl;
    }
}

void printStatus(struct status status){
    cout << endl << "Trees = " << status.tree;

    cout << endl << "d : ";
    for(int i = 0; i < 8; i++){
        cout << status.d[i] << " ";
    }

    cout << endl << "f : ";
    for(int i = 0; i < 8; i++){
        cout << status.f[i] << " ";
    }

    cout << endl << "pred : ";
    for(int i = 0; i < 8; i++){
        cout << status.pred[i] << " ";
    }
    cout << endl;
}

void printMenu(){
    cout << endl << "==========MENU=========" << endl;
    cout << "1) Insert Graph" << endl;
    cout << "2) DFS" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct record *head = NULL;
    struct record *adj[8];
    struct status status;
    int data, choice, vertex;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl;
                for(int i = 0; i < 8; i++){
                    cout << "Enter #" << i << ": ";
                    adj[i] = insert(head, data);
                }
                printAdjacencyList(adj);
                break;
            case 2:
                cout << endl << "Input source vertex : ";
                cin >> vertex;
                status = DFS(status, adj, vertex);
                printStatus(status);
                break;
            case 3:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again.";
        }

    }while(choice != 3);
}
