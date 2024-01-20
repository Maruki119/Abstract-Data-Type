#include <iostream>
using namespace std;

//global var
int time;

struct record{
    int value;
    struct record *next;
};

struct box{
    struct record *head;
    struct record *end;
};

struct status{
    int pass[9];
    int d[9];
    int f[9];
    int newf[9];
    int pred[9];
    int tree;
};

struct box insert(struct box Box, int data){
    struct record *head, *end, *p;
    head = Box.head;
    end = Box.end;
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
    Box.head = head;
    Box.end = end;

    return Box;
}

struct record *insert2(struct record *head, int data){
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
        while(p != NULL){
            if(p -> next == NULL){
                p -> next = node;
                break;
            }
            p = p -> next;
        }
    }

    return head;
};

struct status DFS_Visit(struct box Box[], struct status status, int u){
    struct record *p;
    int v;

    status.pass[u] = 1;
    status.d[u] = ++time;
    p = Box[u].head;
    while(p != NULL){
        v = p -> value;
        if(status.pass[v] == 0){
            status.pred[v] = u;
            status = DFS_Visit(Box, status, v);
        }
        p = p -> next;
    }
    status.pass[u] = 1;
    status.f[u] = ++time;

    return status;
}

struct status DFS(struct box Box[], struct status status, int vertex){
    int u;
    time = 0;
    status.tree = 0;

    for(int u = 0; u < 9; u++){
        status.pass[u] = 0;
        status.pred[u] = -1;
        status.d[u] = -1;
        status.f[u] = -1;
    }
    u = vertex;
    status = DFS_Visit(Box, status, u);
    for(int u = 0; u < 9; u++){
        if(status.pass[u] == 0){
            status = DFS_Visit(Box, status, u);
        }
    }
    for(int i = 0; i < 9; i++){
        if(status.pred[i] == -1){
            status.tree++;
        }
    }

    return status;
}

void printAdjacencyList(struct box Box[]){
    struct record *p;
    cout << endl;
    for(int i = 0; i < 9; i++){
        p = Box[i].head;
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
    for(int i = 0; i < 9; i++){
        cout << status.d[i] << " ";
    }

    cout << endl << "f : ";
    for(int i = 0; i < 9; i++){
        cout << status.f[i] << " ";
    }

    cout << endl << "pred : ";
    for(int i = 0; i < 9; i++){
        cout << status.pred[i] << " ";
    }
    cout << endl;
}

void printTopologicalSort(struct status status){
    struct record *head = NULL, *end, *p;
    struct box Box;
    int temp;
    string uniform[9] = {"Undershort", "Pants", "Belt", "Shirt", "Tie", "Jacket", "Socks", "Shoes", "Watch"};
    for(int i = 0; i < 9; i++){
        status.newf[i] = status.f[i];
    }
    cout << endl;
    for(int i = 8; i >= 0; i--){
        for(int j = 8; j >= 0; j--){
            if(status.newf[i] < status.newf[j]){
                temp = status.newf[i];
                status.newf[i] = status.newf[j];
                status.newf[j] = temp;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(status.newf[i] == status.f[j]){
                head = insert2(head, j);
            }
        }
    }
    p = head;
    while(p != NULL){
        cout << p -> value << " ";
        p = p -> next;
    }

    p = head;
    cout << endl;
    while(p != NULL){
        cout << uniform[p -> value] << " ";
        p = p -> next;
    }
    cout << endl;

}

void printMenu(){
    cout << endl << "=======================" << endl;
    cout << "          MENU         " << endl;
    cout << "=======================" << endl;
    cout << "1) Insert Graph" << endl;
    cout << "2) Topological sort" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct record *p;
    struct box adj[9];
    struct status status;
    int choice, i, j, data;
    int vertex;

    for(i = 0; i < 9; i++){
        adj[i].head = NULL;
        adj[i].end = NULL;
    }

    do{

        printMenu();
        cin >> choice;
        switch(choice){
        case 1:
            cout << endl;
            for(i = 0; i < 9; i++){
                cout << "Enter #" << i << " : ";
                do{
                    cin >> data;
                    if(data != -1){
                        adj[i] = insert(adj[i], data);
                    }
                }while(data != -1);
            }
            cout << endl << "ADJACENCY LIST" << endl;
            printAdjacencyList(adj);
            break;
        case 2:
            cout << "Input source vertex : ";
            cin >> vertex;
            status = DFS(adj, status, vertex);
            printStatus(status);
            printTopologicalSort(status);
            break;
        case 3:
            cout << endl << "Thank you!";
            break;
        default:
            cout << endl << "Please, try again.";
        }
    }while(choice != 3);
}
