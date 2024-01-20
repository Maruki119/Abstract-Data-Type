#include <iostream>
#include <time.h>
#include <cstdlib>
#include<fstream>
using namespace std;

void CreateDataFile(int arrayLenght){
    srand(time(0));
    ofstream myfile("data.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << rand()%10000 << " ";
        cout << endl << "Success" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void SelectionSort(int a[], int arrayLenght){
    int min;
    int temp, index;

    for(int phase = 0; phase < arrayLenght; phase++){
        min = a[phase];
        for(int j = phase; j < arrayLenght; j++){
            if(a[j] <= min){
                min = a[j];
                index = j;
            }
        }
        temp = a[index];
        a[index] = a[phase];
        a[phase] = temp;

    }

    cout << endl << "Selection Sort : ";
    for(int i = 0; i < arrayLenght; i++){
        cout << a[i] << " ";
    }

    ofstream myfile("Selection.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
        cout << endl << endl << "Success!!" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void BubbleSort(int a[], int arrayLenght){
    int temp;
    for(int phase = 0; phase < arrayLenght; phase++){
        for(int j = arrayLenght - 1; j >= phase; j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

    cout << endl << "Bubble Sort : ";
    for(int i = 0; i < arrayLenght; i++){
        cout << a[i] << " ";
    }

    ofstream myfile("Bubble.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
        cout << endl << endl << "Success!!" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void InsertionSort(int a[], int arrayLenght){
    int phase, j, temp;
    for(phase = 0; phase < arrayLenght; phase++){
        temp = a[phase];
        for(j = phase; j > 0 && a[j-1] > temp; j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }

    cout << endl << "Insertion Sort : ";
    for(int i = 0; i < arrayLenght; i++){
        cout << a[i] << " ";
    }

    ofstream myfile("Insertion.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
        cout << endl << endl << "Success!!" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void ShellSort(int a[], int arrayLenght){
    int temp;
    for(int n = arrayLenght / 2; n > 0; n /= 2){
        for(int phase = n; phase < arrayLenght; phase++){
            int temp = a[phase];
            int j;
            for(j = phase; j >= n && a[j-n] > temp; j -= n){
                a[j] = a[j-n];
            }
            a[j] = temp;
        }
    }

    cout << endl << "Shell Sort : ";
    for(int i = 0; i < arrayLenght; i++){
        cout << a[i] << " ";
    }

    ofstream myfile("Shell.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
        cout << endl << endl << "Success!!" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void Merge(int a[], int tmparray[], int lpos, int rpos, int rightend){
    int i, leftend, numelements, tmppos;
    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    while(lpos <= leftend && rpos <= rightend){
        if(a[lpos] <= a[rpos]){
            tmparray[tmppos++] = a[lpos++];
        }else{
            tmparray[tmppos++] = a[rpos++];
        }
    }

    while(lpos <= leftend){
        tmparray[tmppos++] = a[lpos++];
    }

    while(rpos <= rightend){
        tmparray[tmppos++] = a[rpos++];
    }

    for(i = 0; i < numelements; i++, rightend--){
        a[rightend] = tmparray[rightend];
    }
}

void MergeSort(int a[], int tmparray[], int left, int right, int arrayLenght){
    int center;
    if(left < right){
        center = (left + right) / 2;
        MergeSort(a, tmparray, left, center, arrayLenght);
        MergeSort(a, tmparray, center + 1, right, arrayLenght);
        Merge(a, tmparray, left, center + 1, right);
    }

    ofstream myfile("Merge.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
    }else
        cout << "Unable to open file";
    myfile.close();
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = (low - 1);
    int temp;

    for(int j = low; j < high; j++){
        if(a[j] <= pivot){
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return (i + 1);
}

void QuickSort(int a[], int low, int high, int arrayLenght){
    int lenght = high + 1;
    int pivot;

	if (low < high) {
        pivot = partition(a, low, high);
        QuickSort(a, low, pivot - 1, arrayLenght);
        QuickSort(a, pivot + 1, high, arrayLenght);
    }

    ofstream myfile("Quick.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++)
            myfile << a[i] << " ";
    }else
        cout << "Unable to open file";
    myfile.close();
}

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
};

void RadixSort(int a[], int arrayLenght){
    struct record *arr[10], *p, *head = NULL;

    for(int i = 0; i < arrayLenght; i++){
        arr[i] = NULL;
    }

    for(int phase = 0; phase < 4; phase++){
        for(int i = 0; i < arrayLenght; i++){
            for(int j = 0; j < arrayLenght; j++){
                if(phase == 0){
                    if(a[j]%10 == i){
                        arr[i] = insert(arr[i], a[j]);
                    }
                }
            }
        }
    }

    cout << endl << "Radix Sort : ";
    for(int i = 0; i < arrayLenght; i++){
        p = arr[i];
        while(p != NULL){
            cout << p -> value << " ";
            p = p -> next;

        }
    }

    ofstream myfile("Radix.txt");

    if(myfile.is_open()){
        for(int i = 0; i < arrayLenght; i++){
            p = arr[i];
            while(p != NULL){
                myfile << p -> value << " ";
                p = p -> next;
            }
        }
    }else
        cout << "Unable to open file";
    myfile.close();
}

int heapsize;

void exchange(int A[], int i, int largest){
    int temp;

    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
}

void Heapify(int A[], int i){
    int l = 2 * i;
    int r = (2 * i) + 1;
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

void printHeap(int A[], int arrayLenght){
    heapsize = arrayLenght;
    cout << endl << "Heap Sort : ";
    for(int i = 1; i <= heapsize; i++){
        cout << A[i] << " ";
    }
}

void HeapSort(int A[], int arrayLenght){
    int heapsizeFix = heapsize;
    int length = heapsizeFix;
    Build_heap(A);
    for(int i = length; i >= 2; i--){
        exchange(A, 1, i);
        heapsize = heapsize - 1;
        Heapify(A, 1);
    }

    printHeap(A, arrayLenght);

    ofstream myfile("Heap.txt");

    if(myfile.is_open()){
        for(int i = 1; i <= heapsize; i++)
            myfile << A[i] << " ";
        cout << endl << endl << "Success!!" << endl;
    }else
        cout << "Unable to open file";
    myfile.close();
}

void printMenu(){
    cout << endl << "============Menu============" << endl;
    cout << "1) Create data file" << endl;
    cout << "2) Selection Sort" << endl;
    cout << "3) Bubble Sort" << endl;
    cout << "4) Insertion Sort" << endl;
    cout << "5) Shell Sort" << endl;
    cout << "6) Merge Sort" << endl;
    cout << "7) Quick Sort" << endl;
    cout << "8) Radix Sort" << endl;
    cout << "9) Heap Sort" << endl;
    cout << "10) Exit" << endl;
    cout << "Please choose > ";
}

int main(){
    int choice;
    int a[10], tmparray[10];
    int A[11];
    int arrayLenght = sizeof(a) / sizeof(int);
    ifstream readfile;

    do{
        printMenu();
        cin >> choice;

        switch(choice){
            case 1:
                CreateDataFile(arrayLenght);
                break;
            case 2:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                SelectionSort(a, arrayLenght);
                break;
            case 3:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                BubbleSort(a, arrayLenght);
                break;
            case 4:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                InsertionSort(a, arrayLenght);
                break;
            case 5:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                ShellSort(a, arrayLenght);
                break;
            case 6:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                MergeSort(a, tmparray, 0, arrayLenght, arrayLenght);
                cout << endl << "Merge Sort : ";
                for(int i = 0; i < 10; i++){
                    cout << a[i] << " ";
                }
                cout << endl << endl << "Success!!" << endl;
                break;
            case 7:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                QuickSort(a, 0, arrayLenght - 1, arrayLenght);

                cout << endl << "Quick Sort : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl << endl << "Success!!" << endl;
                break;
            case 8:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> a[i];
                }

                cout << "Data : ";
                for(int i = 0; i < arrayLenght; i++){
                    cout << a[i] << " ";
                }
                cout << endl;

                readfile.close();

                RadixSort(a, arrayLenght);
                break;
            case 9:
                readfile.open("data.txt");

                cout << endl;
                for(int i = 0; i < arrayLenght; i++){
                    readfile >> A[i+1];
                    heapsize++;
                }

                cout << "Data : ";
                for(int i = 1; i <= heapsize; i++){
                    cout << A[i] << " ";
                }
                cout << endl;

                readfile.close();

                HeapSort(A, arrayLenght);
                break;
            case 10:
                cout << endl << "Thank you!";
                break;
            default:
                cout << endl << "Please, try again." << endl;
        }

    }while(choice != 10);
}
