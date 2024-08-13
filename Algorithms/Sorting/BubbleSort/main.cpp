#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size);
void swapping(int arr[], int a, int b);
void showArray(int arr[], int size);

int main(){
    int arr[] = {1, 9, 4, 2, 3, 6, 8, 7, 5};
    int size = (sizeof(arr) / sizeof(int));
    cout << "Before bubble sorting: " << endl;
    showArray(arr, size);
    bubbleSort(arr,size);
    cout << "After bubble sorting: " << endl;
    showArray(arr, size);

}

void bubbleSort(int arr[], int size){
    for (int i = 1 ; i <= size - 1; i++){
        for (int j = 0 ; j < size - i; j++){
            if (arr[j] > arr[j + 1]){
                swapping(arr, j, j+ 1);
            }
        }
    }
}

void swapping(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void showArray(int arr[], int size){
    cout << "Array Items : " << endl;
    for (int i = 0 ; i < size ; i++ ){
        cout << arr[i] << " " ;
    }
    cout << endl;
}