#include <iostream>
using namespace std;

struct record{
    char value;
    struct record *next;
};

struct record *insert(struct record *head, char data)
{
    struct record *node, *p;

    if (head == NULL)
    {
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }
    else
    {
        node = new struct record;
        node -> value = data;
        node -> next = NULL;
        p = head;
        while (p != NULL)
        {
            if (p -> next == NULL)
            {
                p -> next = node;
                break;
            }
            p = p -> next;
        }
    }
    return head;
}



void printList(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "List : ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value;
            temp = temp -> next;
        }
        cout << endl;
    }
}

void printDecode(struct record *head){
    struct record *temp;
    temp = head;

    cout << endl << "Decode : ";
    temp = head;
    while(temp != NULL){
        cout << temp -> value;
        temp = temp -> next -> next;
    }
    cout << endl;
}

void menuPrint(){
    cout << endl << "========MENU=======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Decode" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    char data;
    int choice, i;
    struct record *head = NULL;

   do{
        menuPrint();
        cin >> choice;

        switch(choice){
            case 1:
                getchar();
                cout << "Enter code : ";
                do{
                    data = getchar();
                    if(data == '.'){
                        continue;
                    }else{
                        head = insert(head, data);
                    }

                }while(data != '.');

                printList(head);
                break;
            case 2:
                printDecode(head);
                break;
            case 3:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please try again.";
                break;
        }
   }while(choice != 4);
}
