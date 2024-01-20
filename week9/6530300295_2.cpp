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
    int pass[8];
    int d[8];
    int f[8];
    int pred[8];
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

    for(int u = 0; u < 8; u++){
        status.pass[u] = 0;
        status.pred[u] = -1;
        status.d[u] = -1;
        status.f[u] = -1;
    }
    u = vertex;
    status = DFS_Visit(Box, status, u);
    for(int u = 0; u < 8; u++){
        if(status.pass[u] == 0){
            status = DFS_Visit(Box, status, u);
        }
    }
    for(int i = 0; i < 8; i++){
        if(status.pred[i] == -1){
            status.tree++;
        }
    }

    return status;
}

void printAdjacencyList(struct box Box[]){
    struct record *p;
    cout << endl;
    for(int i = 0; i < 8; i++){
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
    cout << "3) Transpose graph" << endl;
    cout << "4) Decompose strongly connected graph" << endl;
    cout << "5) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct record *p;
    struct box adj[8];
    struct box transposeAdj[8];
    struct status status;
    struct status transposeStatus;
    int choice, i, j, data;
    int vertex = 0, now = 0;

    for(i = 0; i < 8; i++){
        adj[i].head = NULL;
        adj[i].end = NULL;
        transposeAdj[i].head = NULL;
        transposeAdj[i].end = NULL;
    }

    do{

        printMenu();
        cin >> choice;
        switch(choice){
        case 1:
            for(i = 0; i < 8; i++){
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
            break;
        case 3:
            cout << endl << "ADJACENCY LIST" << endl;
            printStatus(status);
            for(i = 0; i < 8; i++){
                for(j = 0; j < 8; j++){
                    p = adj[j].head;
                    while(p != NULL){
                        if(p -> value == i){
                            transposeAdj[i] = insert(transposeAdj[i], j);
                        }
                        p = p -> next;
                    }
                }
            }
            cout << endl << "ADJACENCY LIST TRANSPOSE" << endl;
            printAdjacencyList(transposeAdj);
            transposeStatus = DFS(transposeAdj, transposeStatus, 0);
            printStatus(transposeStatus);
            break;
        case 4:
            for(i = 1; i <= time; i++){
                if(transposeStatus.pred[i-1] == -1 && i-1 < 8){
                    vertex = i-1;
                    cout << "( ";
                }

                if(vertex == now){
                    cout << ")" << endl;
                }

                for(j = 0; j < 8; j++){
                    if(i == transposeStatus.d[j]){
                        cout << j << " ";
                        now = j;
                        continue;
                    }
                }

                for(j = 0; j < 8; j++){
                    if(i == transposeStatus.f[j]){
                        cout << j << " ";
                        now = j;
                        continue;
                    }
                }
            }
            break;
        case 5:
            cout << endl << "Thank you!";
            break;
        default:
            cout << endl << "Please, try again.";
        }
    }while(choice != 5);
}
