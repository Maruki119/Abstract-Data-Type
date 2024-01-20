#include <iostream>
using namespace std;

int heapsize;

int parent(int i){
    return i / 2;
}

int left(int i){
    return 2 * i;
}

int right(int i){
    return (2 * i) + 1;
}

void exchange(int A[], int i, int largest){
    int temp;

    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
}

void Heapify(int A[], int i){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= heapsize && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }

    if(r <= heapsize && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        exchange(A, i, largest);
        Heapify(A, largest);
    }
}

void Build_heap(int A[]){
    int length = heapsize;
    for(int i = length/2; i >= 1; i--){
        Heapify(A, i);
    }
}

void Heapsort(int A[]){
    int heapsizeFix = heapsize;
    int length = heapsizeFix;
    Build_heap(A);
    for(int i = length; i >= 2; i--){
        exchange(A, 1, i);
        heapsize = heapsize - 1;
        Heapify(A, 1);
    }
}

void Heap_Insert(int A[], int key){
    heapsize = heapsize + 1;
    int i = heapsize;
    while(i > 1 && A[parent(i)] < key){
        A[i] = A[parent(i)];
        i = parent(i);
        A[i] = key;
    }
}

int Heap_Exact_Max(int A[]){
    int max;
    if(heapsize < 1){
        cout << endl << "Heap underflow!";
    }

    max = A[1];
    A[1] = A[heapsize];
    heapsize = heapsize - 1;
    Heapify(A, 1);

    return max;
}

void printHeap(int A[]){
    for(int i = 1; i <= heapsize; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void printMenu(){
    cout << endl << "=========Menu=========" << endl;
    cout << "1) Insert data to array" << endl;
    cout << "2) Build Heap" << endl;
    cout << "3) Heap Sort" << endl;
    cout << "4) Heap Insert" << endl;
    cout << "5) Priority Queue" << endl;
    cout << "6) Extract Max" << endl;
    cout << "7) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    int A[30];
    int choice, data, key;

    do{

        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl << "Input : ";
                for(int i = 1; i <= 10; i++){
                    cin >> data;
                    A[i] = data;
                    heapsize++;
                }
                break;
            case 2:
                Build_heap(A);
                cout << endl << "Heap : ";
                printHeap(A);
                break;
            case 3:
                Heapsort(A);
                cout << endl << "Heap Sort : ";
                heapsize = 10;
                printHeap(A);
                break;
            case 4:
                cout << endl << "Insert : ";
                cin >> key;
                A[heapsize + 1] = key;
                heapsize++;
                cout << endl << "Array : ";
                printHeap(A);

                heapsize--;
                Heap_Insert(A, key);
                cout << endl << "Heap : ";
                printHeap(A);
                break;
            case 5:
                cout << endl << "Priority Queue Heap : ";
                printHeap(A);
                break;
            case 6:
                cout << endl << "Max = " << Heap_Exact_Max(A) << endl;
                cout << endl << "Heap : ";
                printHeap(A);
                break;
            case 7:
                cout << endl << "Thank you!";
                break;
            default:
                cout << "Please, Try again.";
        }

    }while(choice != 7);

    return 0;
}
