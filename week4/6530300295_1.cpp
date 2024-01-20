O#include <iostream>
using namespace std;

struct record{
    int value;
    int pow;
    struct record *next;
};

struct record *insert(struct record *head, int data, int count){
    struct record *node, *p, *temp;
    if(count % 2 == 1){
        if(head == NULL){
            head = new struct record;
            head -> value = data;
            head -> next = NULL;
        }else{
            node = new struct record;
            node -> value = data;
            node -> next = NULL;
            p = head;
            while (p != NULL){
                if (p -> next == NULL){
                    p -> next = node;
                    break;
                }
                p = p -> next;
            }
        }
    }else{
        temp = head;
        while(temp != NULL){
            if(temp -> next == NULL){
                temp -> pow = data;
                break;
            }else{
                temp = temp -> next;
            }
        }
    }

    return head;
};

void printAllData(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "List = ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            cout << temp -> pow << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printComb(struct record *headP1, struct record *headP2){
    struct record *tempP1, *tempP2;
    tempP1 = headP1;
    tempP2 = headP2;

    while(tempP1 != NULL || tempP2 != NULL){
        if(tempP1 == NULL){
            cout << tempP2 -> value;

            if(tempP2 -> pow == 0){

            }else if(tempP2 -> pow == 1){
                cout << "x";
            }else{
                cout << "x^";
                cout << tempP2 -> pow;
            }
            tempP2 = tempP2 -> next;
        }else if(tempP2 == NULL){
            cout << tempP1 -> value;

            if(tempP1 -> pow == 0){

            }else if(tempP1 -> pow == 1){
                cout << "x";
            }else{
                cout << "x^";
                cout << tempP1 -> pow;
            }
            tempP1 = tempP1 -> next;
        }else{
            if(tempP1 -> pow > tempP2 -> pow){
                cout << tempP1 -> value;

            if(tempP1 -> pow == 0){

            }else if(tempP1 -> pow == 1){
                cout << "x";
            }else{
                cout << "x^";
                cout << tempP1 -> pow;
            }
            tempP1 = tempP1 -> next;

            }else if(tempP1 -> pow < tempP2 -> pow){
                cout << tempP2 -> value;

                if(tempP2 -> pow == 0){

                }else if(tempP2 -> pow == 1){
                    cout << "x";
                }else{
                    cout << "x^";
                    cout << tempP2 -> pow;
                }
                tempP2 = tempP2 -> next;
            }else{
                cout << tempP1 -> value + tempP2 -> value;

                if(tempP1 -> pow == 0 && tempP2 -> pow == 0){

                }else if(tempP1 -> pow == 1 && tempP2 -> pow == 1){
                    cout << "x";
                }else{
                    cout << "x^";
                    cout << tempP1 -> pow;
                }
                tempP1 = tempP1 -> next;
                tempP2 = tempP2 -> next;
            }
        }

        if(tempP1 != NULL || tempP2 != NULL){
            cout << " + ";
        }
    }
}

int main(){
    struct record *headP1 = NULL;
    struct record *headP2 = NULL;
    int data, countP1, countP2;

    cout << "Input P1 : ";
    do{
        cin >> data;
        countP1++;
        if(data != -99){
            headP1 = insert(headP1, data, countP1);
        }
    }while(data != -99);

    cout << "Input P2 : ";
    do{
        cin >> data;
        countP2++;
        if(data != -99){
            headP2 = insert(headP2, data, countP2);
        }
    }while(data != -99);

    printComb(headP1, headP2);
}
