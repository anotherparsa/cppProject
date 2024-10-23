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
    for (int i = 0 ; i <= size - 1 ; i++){
        int current = arr[i];
        int previous = i - 1;
        while (previous >= 0 && arr[previous] > current){
            arr[previous + 1] = arr[previous];
            previous = previous - 1;
        }
        arr[previous + 1] = current;
    }
}

void showArray(int arr[], int size){
    cout << "Array Items : " << endl;
    for (int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl;
}