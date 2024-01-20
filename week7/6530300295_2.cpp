#include <iostream>
using namespace std;

struct Node{
    int value;
    int height;
    struct Node *right;
    struct Node *left;
};

int findHeight(struct Node *p){
    if (p == NULL){
        return -1;
    }else{
        return p -> height;
    }
}

struct Node *insert(struct Node *tree, int data){
    if(tree == NULL){
        tree = new struct Node;
        tree -> value = data;
        tree -> height = 0;
        tree -> right = NULL;
        tree -> left = NULL;
    }else{
        if(data < tree -> value){
            tree -> left = insert(tree -> left, data);
        }else{
            tree -> right = insert(tree -> right, data);
        }
    }
    tree -> height = (max(findHeight(tree -> left), findHeight(tree -> right)) + 1);

    return tree;
};

void printInorder(struct Node *tree){
    if(tree == NULL){
        return;
    }else{
        printInorder(tree -> left);
        cout << tree -> value << " ";
        printInorder(tree -> right);
    }
    return;
}

void printMenu(void){
    cout << endl << "=============MENU=============" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print Inorder" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct Node *tree = NULL;
    int choice, data;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter : ";
            cin >> data;
            tree = insert(tree, data);
            if((findHeight(tree -> left) - findHeight(tree -> right)) == 2){
                cout << "\nYou have to rotate trees!\n";
                return 0;
            }else{
                if ((findHeight(tree -> right) - findHeight(tree -> left)) == 2){
                    cout << "\nYou have to rotate trees!\n";
                    return 0;
                }else{
                    cout << "\nSuccess!\n";
                }
            }
            break;
        case 2:
            cout << "Inorder : ";
            printInorder(tree);
            cout << endl << endl;
            break;
        case 3:
            cout << endl << "Thank you!
            break;
        default:
            cout << endl << "Please, try again." << endl;
            break;
        }
    }while (choice != 3);

    return 0;
}
