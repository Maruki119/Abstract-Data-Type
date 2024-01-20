#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node *right;
    struct Node *left;
};

struct Node *insert(struct Node *tree, int data){
    if(tree == NULL){
        tree = new struct Node;
        tree -> value = data;
        tree -> right = NULL;
        tree -> left = NULL;
    }else if(data < tree -> value){
        tree -> left = insert(tree -> left, data);
    }else if (data > tree -> value){
        tree->right = insert(tree -> right, data);
    }

    return tree;
};

void printInorder(struct Node *tree){
    if (tree == NULL){
        return;
    }else{
        printInorder(tree -> left);
        cout << tree -> value << " ";
        printInorder(tree -> right);
    }

    return;
}

void printLeave(struct Node *tree){
    if (tree == NULL){
        return;
    }else{
        printLeave(tree -> left);
        if (tree -> left == NULL && tree -> right == NULL){
            cout << tree -> value << " ";
        }
        printLeave(tree -> right);
    }
    return;
}

void printNonLeave(struct Node *tree){
    if (tree == NULL){
        return;
    }else{
        printNonLeave(tree -> left);
        if (tree -> left != NULL && tree -> right != NULL){
            cout << tree -> value << " ";
        }
        printNonLeave(tree -> right);
    }
    return;
}

struct Node *findMin(struct Node *tree){
    if(tree == NULL){
        return NULL;
    }else{
        if (tree -> left == NULL){
            return tree;
        }else{
            return findMin(tree -> left);
        }
    }
}

struct Node *deleteTree(struct Node *tree, int data){
    struct Node *tmpcell, *child;
    if (tree == NULL){
        cout << "No Node\n";
    }else{
        if (data < tree -> value){
            tree -> left = deleteTree(tree -> left, data);
        }else{
            if (data > tree -> value){
                tree -> right = deleteTree(tree -> right, data);
            }else{
                if(tree -> left != NULL && tree -> right != NULL){
                    tmpcell = findMin(tree -> right);
                    tree -> value = tmpcell -> value;
                    tree -> right = deleteTree(tree -> right, tree -> value);
                }else{
                    tmpcell = tree;
                    if (tree -> left == NULL){
                        child = tree -> right;
                    }else{
                        child = tree -> left;
                    }
                    delete(tmpcell);
                    return child;
                }
            }
        }
    }
    return tree;
}

int find(struct Node *tree, int data){
    if (tree == NULL){
        return 0;
    }else{
        if (tree -> value == data){
            return 1;
        }else{
            return find(tree -> left, data) + find(tree -> right, data);
        }

    }
}

void printAllData(struct Node *tree){
    cout << "Inorder : ";
    printInorder(tree);
    cout << endl << endl;
    cout << "Leave : ";
    printLeave(tree);
    cout << endl << endl;
    cout << "Nonleave : ";
    printNonLeave(tree);
    cout << endl << endl;
}

void printMenu(){
    cout << endl << "========MENU======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print Inorder, print leave node, print nonleave node" << endl;
    cout << "3) Delete" << endl;
    cout << "4) Find" << endl;
    cout << "5) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    struct Node *tree;
    int data, choice;

    tree = NULL;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter : ";
                cin >> data;
                tree = insert(tree, data);
                cout << endl << "Success!\n";
                break;
            case 2:
                printAllData(tree);
                break;
            case 3:
                cout << "Delete : ";
                cin >> data;
                tree = deleteTree(tree, data);
                cout << endl << "Success!\n";
                break;
            case 4:
                cout << "Search : ";
                cin >> data;
                if (find(tree, data) > 0){
                    cout << endl << "Found!\n";
                }else{
                    cout << endl << "Not Found!\n";
                }
                break;
            case 5:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again." << endl;
        }

    }while(choice != 5);

}
