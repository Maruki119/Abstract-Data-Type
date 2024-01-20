#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;

struct record{
    long long int id;
    string name;
    struct record *next;
};

struct record *insert(struct record *head, long long int id, string name){
    struct record *node, *p;
    if(head == NULL){
        head = new struct record;
        head -> id = id;
        head -> name = name;
        head -> next = NULL;
    }else{
        node = new struct record;
        node -> id = id;
        node -> name = name;
        node -> next = NULL;
        p = head;
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = node;
    }

    return head;
};

int hashval(long long int key, int tableSize, int countRep){
    return (key + countRep) % tableSize;
}

int hashval2(long long int key, int tableSize){
    return 7 - (key % tableSize);
}

void readDatafile(long long int id[], string name[], int tableSize){
    struct record *dataSouce[tableSize], *p;
    int index = 0;
    ifstream readfile;

    readfile.open("ADT.txt");

    cout << endl;
    for(int i = 0; i < tableSize; i++){
        readfile >> id[i] >> name[i];
    }
    cout << "Souce Data" << endl;
    readfile.close();

}

void printData(struct record *data[], int tableSize){
    struct record *p;

    cout << endl << "Index\tID\t\tName" << endl << endl;

    for(int i = 0; i < tableSize; i++){
        cout << i << "\t";
        p = data[i];
        while(p != NULL){
            cout << p -> id << "\t" << p -> name << endl << "\t";
            p = p -> next;
        }
        cout << endl;
    }
}

void seperateChaining(long long int id[], string name[], int tableSize){
    struct record *separateChainingRec[tableSize];
    int index = 0;

    readDatafile(id, name, tableSize);
    for(int i = 0; i < tableSize; i++){
        cout << id[i] << " " << name[i] << endl;
    }

    for(int i = 0; i < tableSize; i++){
        separateChainingRec[i] = NULL;
    }

    for(int i = 0; i < tableSize; i++){
        index = hashval(id[i], tableSize, 0);
        separateChainingRec[index] = insert(separateChainingRec[index], id[i], name[i]);
    }

    printData(separateChainingRec, tableSize);
}

void linearProbling(long long int id[], string name[], int tableSize){
    struct record *linearProblingRec[tableSize];
    int index = 0, countRep = 0;

    readDatafile(id, name, tableSize);
    for(int i = 0; i < tableSize; i++){
        cout << id[i] << " " << name[i] << endl;
    }

    for(int i = 0; i < tableSize; i++){
        linearProblingRec[i] = NULL;
    }

    for(int i = 0; i < tableSize; i++){
        index = hashval(id[i], tableSize, 0);
        while(linearProblingRec[index] != NULL && countRep <= 100){
            countRep++;
            index = hashval(id[i], tableSize, countRep);
        }

        if(countRep > 100){
            cout << endl << "Error, can not insert data!" << endl;
            break;
        }
        linearProblingRec[index] = insert(linearProblingRec[index], id[i], name[i]);
        countRep = 0;
    }

    printData(linearProblingRec, tableSize);
}

void quardraticProbling(long long int id[], string name[], int tableSize){
    struct record *quardraticProblingRec[tableSize];
    int index = 0, countRep = 0;

    readDatafile(id, name, tableSize);
    for(int i = 0; i < tableSize; i++){
        cout << id[i] << " " << name[i] << endl;
    }

    for(int i = 0; i < tableSize; i++){
        quardraticProblingRec[i] = NULL;
    }

    for(int i = 0; i < tableSize; i++){
        index = hashval(id[i], tableSize, 0);
        while(quardraticProblingRec[index] != NULL && countRep <= 100){
            countRep++;
            index = hashval(id[i], tableSize, countRep * countRep);
        }

        if(countRep > 100){
            cout << endl << "Error, can not insert data!" << endl;
            break;
        }
        quardraticProblingRec[index] = insert(quardraticProblingRec[index], id[i], name[i]);
        countRep = 0;
    }

    printData(quardraticProblingRec, tableSize);
}

void doubleHashing(long long int id[], string name[], int tableSize){
    struct record *doubleHashingRec[tableSize];
    int index = 0, countRep = 0;

    readDatafile(id, name, tableSize);
    for(int i = 0; i < tableSize; i++){
        cout << id[i] << " " << name[i] << endl;
    }

    for(int i = 0; i < tableSize; i++){
        doubleHashingRec[i] = NULL;
    }

    for(int i = 0; i < tableSize; i++){
        index = hashval(id[i], tableSize, 0);
        while(doubleHashingRec[index] != NULL && countRep <= 100){
            countRep++;
            index = (hashval(id[i], tableSize, countRep) + countRep * hashval2(id[i], tableSize)) % tableSize;
        }

        if(countRep > 100){
            cout << endl << "Error, can not insert data!" << endl;
            break;
        }
        doubleHashingRec[index] = insert(doubleHashingRec[index], id[i], name[i]);
        countRep = 0;
    }

    printData(doubleHashingRec, tableSize);
}

void printMenu(){
    cout << endl << "===========MENU==========" << endl;
    cout << "1.Separate Chaining" << endl;
    cout << "2.Linear Probling" << endl;
    cout << "3.Quardratic Probling" << endl;
    cout << "4.Double Hashing" << endl;
    cout << "5.Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    int tableSize = 5;
    int choice;
    long long int id[tableSize];
    string name[tableSize];

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                seperateChaining(id, name, tableSize);
                break;
            case 2:
                linearProbling(id, name, tableSize);
                break;
            case 3:
                quardraticProbling(id, name, tableSize);
                break;
            case 4:
                doubleHashing(id, name, tableSize);
                break;
            case 5:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again." << endl;
        }
    }while(choice != 5);

}
