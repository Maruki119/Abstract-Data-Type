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

void printPreorder(struct Node *tree){
    if(tree == NULL){
        return;
    }else{
        cout << tree -> value << " ";
        printPreorder(tree -> left);
        printPreorder(tree -> right);
    }

    return;
}

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

void printPostorder(struct Node *tree){
    if (tree == NULL){
        return;
    }else{
        printPostorder(tree -> left);
        printPostorder(tree -> right);
        cout << tree -> value << " ";
    }

    return;
}

struct Node *findMin(struct Node *tree){
    if (tree == NULL){
        return NULL;
    }else if (tree -> left == NULL){
        return tree;
    }else{
        return (findMin(tree -> left));
    }
}

void printMenu(){
    cout << endl << "========MENU======" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print" << endl;
    cout << "3) Find min" << endl;
    cout << "4) Exit" << endl;
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
                cout << endl << "Enter : ";
                cin >> data;
                tree = insert(tree, data);
                cout << endl << "Success!" << endl;
                break;
            case 2:
                cout << endl << "Preorder : ";
                printPreorder(tree);
                cout << endl;

                cout << endl << "Inorder : ";
                printInorder(tree);
                cout << endl;

                cout << endl << "Postorder : ";
                printPostorder(tree);
                cout << endl;
                break;
            case 3:
                cout << endl << "Min = " << findMin(tree) -> value << endl;
                break;
            case 4:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again." << endl;
        }

    }while(choice != 4);

}
