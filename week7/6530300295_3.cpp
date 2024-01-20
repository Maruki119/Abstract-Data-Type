#include <iostream>
using namespace std;

struct Node{
    string value;
    struct Node *left;
    struct Node *right;
};

struct stack{
    struct Node *tree;
    struct stack *next;
};

struct stack *createStack(){
    struct stack *S;
    S = new struct stack;
    if (S == NULL){
        cout << "Out of space!!!\n";
    }else{
        S -> next = NULL;
    }
    return S;
}

void pop(struct stack *S){
    struct stack *firstCell;
    if(S -> next == NULL){
        cout << endl << "Empty Stack!!!\n";
    }else{
        firstCell = S -> next;
        S -> next = S -> next -> next;
        delete(firstCell);
    }
}

void push(struct stack *S, struct Node *T){
    struct stack *tmpCell;
    tmpCell = new struct stack;
    if (tmpCell == NULL){
        cout << "Out of space!!!\n";
    }else{
        tmpCell -> tree = T;
        tmpCell -> next = S -> next;
        S -> next = tmpCell;
    }
}
struct Node *top(struct stack *S){
    if (S -> next != NULL){
        return S -> next -> tree;
    }else{
        cout << "Empty Stack!!!\n";
        return NULL;
    }
}

struct Node *insert(struct stack *S, struct Node *tree, string data){
    struct Node *node = NULL, *tmpNode = NULL;
    if (tree == NULL){
        tree = new struct Node;
        tree -> value = data;
        tree -> left = NULL;
        tree -> right = NULL;
        push(S, tree);
    }else{
        node = new struct Node;
        if (data == "*" || data == "/" || data == "+" || data == "-"){
            node -> value = data;
            tmpNode = top(S);
            pop(S);
            node -> right = tmpNode;
            tmpNode = top(S);
            pop(S);
            node -> left = tmpNode;
            push(S, node);
        }else{
            node -> value = data;
            node -> left = NULL;
            node -> right = NULL;
            push(S, node);
        }
    }
    return tree;
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

void printTree(struct Node *tree){
    cout << "Inorder : ";
    printInorder(tree);
    cout << endl << endl;
    cout << "Postorder: ";
    printPostorder(tree);
    cout << endl << endl;
}

void printMenu(){
    cout << endl << "=============MENU=============" << endl;
    cout << "1) Insert postorder" << endl;
    cout << "2) Print Expression tree" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
}

int main()
{
    struct stack *S = createStack();
    struct Node *tree = NULL;
    int choice;
    string data;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Input : ";
            while (data != "."){
                cin >> data;
                if (data != "."){
                    tree = insert(S,tree, data);
                }
            }
            break;
        case 2:
            printTree(top(S));
            break;
        case 3:
            cout << "Thank you!";
            break;
        default:
            cout << "Invalid Input!!\n";
            break;
        }
    }while (choice != 3);

    return 0;
}
