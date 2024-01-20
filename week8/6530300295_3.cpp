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

struct record *insert2(struct record *head, int data){
    struct record *node, *p;
    if(head == NULL){
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }else{
        node = new struct record;
        node -> value = data;
        node -> next = head;
        head = node;
    }

    return head;
};

struct record *enqueue(struct record *head, int data){
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
}

struct record *dequeue(struct record *head){
    struct record *tmpfree;
    if(head != NULL){
        tmpfree = head;
        head = head -> next;
        delete(tmpfree);
    }

    return head;
}

int queuesize(struct record *head){
    struct record *p;
    int qsize = 0;

    p = head;
    while(p != NULL){
        qsize++;
        p = p -> next;
    }

    return qsize;
}

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

void printBFS(int d[], int pred[]){
    cout << endl << "   |   d   |   pred" << endl;
    cout << "=========================" << endl;
    for(int i = 0; i < 8; i++){
        cout << i << "  |   " << d[i] << "  |   " << pred[i] << endl;
    }
}

struct record *searchPath(int pred[], int endPoint){
    struct record *path = NULL;
    int temp = endPoint;

    path = insert2(path, endPoint);
    while(pred[temp] != 2){
        path = insert2(path, pred[temp]);
        temp = pred[temp];
    }
    path = insert2(path, pred[temp]);

    return path;
};

void printMenu(){
    cout << endl << "===========MENU==========" << endl;
    cout << "1) Input adjacency list" << endl;
    cout << "2) BFS" << endl;
    cout << "3) Search path" << endl;
    cout << "4) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct record *head = NULL, *q = NULL, *node = NULL, *path = NULL, *p;
    struct record *adj[8];
    int data, choice, endPoint, distance, startNode = 2;
    int pass[8], d[8], pred[8];
    int u, v;

    for (int i = 0; i < 8; i++){
        adj[i] = NULL;
    }

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
                for(int i = 0; i < 8; i++){
                    pass[i] = 0;
                    d[i] = -1;
                    pred[i] = -1;
                }
                pass[startNode] = 1;
                d[startNode] = 0;
                pred[startNode] = 2;

                q = enqueue(q, startNode);
                while(queuesize(q) != 0){
                    u = q -> value;
                    node = adj[u];
                    while(node != NULL){
                        v = node -> value;
                        if(pass[v] == 0){
                            pass[v] = 1;
                            d[v] = d[u] + 1;
                            pred[v] = u;
                            q = enqueue(q, v);
                        }
                        node = node -> next;
                    }
                    q = dequeue(q);
                }
                printBFS(d, pred);
                break;
            case 3:
                cout << "Enter end point : ";
                cin >> endPoint;
                path = searchPath(pred, endPoint);
                p = path;
                cout << endl << "Path = ";

                while(p -> next != NULL){
                    cout << "(" << p -> value << "," << p -> next -> value << ")";
                    distance++;

                    if(p -> next -> next != NULL){
                        cout << " , ";
                    }
                    p = p -> next;
                }
                cout << endl << "Distance = " << distance << endl;
                break;
            case 4:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again.";
        }

    }while(choice != 4);
}
