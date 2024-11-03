#include <iostream>

using namespace std;

void BubbleSort(int arr[], int size);
void ShowArray(int arr[], int size);
void Swapping(int arr[], int a, int b);

int main(){
    int arr[] = {1, 9, 4, 2, 3, 6, 8, 7, 5};
    int size = (sizeof(arr) / sizeof(int));
    cout << "Before Bubble Sorting: " << endl;
    ShowArray(arr, size);
    cout << "After Bubble Sorting: " << endl;
    BubbleSort(arr, size);
    ShowArray(arr, size);
}

void BubbleSort(int arr[], int size){
    for (int i = 1 ; i < size - 2 ; i++){
        for (int j = 0 ; j < size - i ; j++){
            if (arr[j] > arr[j + 1]){
                Swapping(arr, j, j + 1);
            }
        }
    }
}

void ShowArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void Swapping(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}