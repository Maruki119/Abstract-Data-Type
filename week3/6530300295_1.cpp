#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head, int data){
    struct record *node, *p;
    if(head == NULL){
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }else{
        node = new struct record;
        node -> value = data;
        if(data < head -> value){
            node -> next = head;
            head = node;
        }else{
            p = head;
            while(p -> next != NULL){
                if(data < p -> next -> value){
                    node -> next = p -> next;
                    p -> next = node;
                    break;
                }else{
                    p = p -> next;
                }
            }
            if(p -> next == NULL){
                node -> next = NULL;
                p -> next = node;
            }
        }
    }

    return head;
}

struct record *deleteData(struct record *head, int data){
    struct record *node,*tmpfree;
    node = head;
    if(data == head -> value){
        tmpfree = head;
        head = head -> next;
        delete(tmpfree);
    }else{
        while(node){
            if(data == node -> next -> value){
                tmpfree = node -> next;
                node -> next = node -> next -> next;
                delete(tmpfree);
                break;
            }else{
                node = node -> next;
            }
        }
    }

    return head;
}

void printAllData(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "List = ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printMinMax(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "Min to Max : ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printMaxMin(struct record *head){
    struct record *temp, *node;
    if(head != NULL){
        printMaxMin(head->next);

        cout << head -> value << " ";

    }
}

void printOddNode(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "Odd node = ";
        temp = head;
        while(temp != NULL){
                cout << temp -> value << " ";
                if(temp -> next == NULL){
                    break;
                }
                temp = temp -> next -> next;

        }
        cout << endl;
    }
}

void menuPrint(){
    cout << endl;
    cout << "========MENU=======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Delete" << endl;
    cout << "3) Print min to max / max to min" << endl;
    cout << "4) Count node" << endl;
    cout << "5) Print only odd node" << endl;
    cout << "6) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    int choice, data, count;
    struct record *head = NULL;

    do{
        menuPrint();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl << "Insert : ";
                cin >> data;
                head = insert(head, data);
                count++;
                cout << "Success!" << endl;
                printAllData(head);
                break;
            case 2:
                cout << endl << "Delete : ";
                cin >> data;;
                head = deleteData(head, data);
                count--;
                cout << "Success!" << endl;
                printAllData(head);
                break;
            case 3:
                printMinMax(head);
                cout << "Max to Min : ";
                printMaxMin(head);
                break;
            case 4:
                cout << endl << "Number of node = " << count << endl;
                break;
            case 5:
                printOddNode(head);
                break;
            case 6:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please choose again." << endl;
                break;
        }
    }while(choice != 6);

}
