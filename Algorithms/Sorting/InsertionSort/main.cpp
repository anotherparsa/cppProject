#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size);
void showArray(int arr[], int size);

int main(){
    int arr[] = {1, 9, 4, 2, 3, 6, 8, 7, 5};
    int size = (sizeof(arr) / sizeof(int));
    cout << "Before Insertion sorting: " << endl;
    showArray(arr, size);
    InsertionSort(arr,size);
    cout << "After Insertion sorting: " << endl;
    showArray(arr, size);

}

void InsertionSort(int arr[], int size){
    for (int i = 1 ; i < size ; i++){
        int currentNumber = arr[i];
        int previous = i - 1;
        while (previous >= 0 && arr[previous] > currentNumber){
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = currentNumber;
    }
}

void showArray(int arr[], int size){
    cout << "Array Items : " << endl;
    for (int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl;
}