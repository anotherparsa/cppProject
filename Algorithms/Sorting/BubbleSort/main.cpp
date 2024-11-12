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
    BubbleSort(arr, size);
    cout << "After Bubble Sorting: " << endl;
    ShowArray(arr, size);
}

void BubbleSort(int arr[], int size){
    int totalChecks = 0;
    int totalSwaps = 0;

    for (int i = 0 ; i < size - 1; i++){
        bool swapped = false;
        for(int j = 0 ; j < size - i - 1 ; j++){
            totalChecks++;
            if (arr[j] > arr[j + 1]){
                swapped = true;
                totalSwaps++;
                Swapping(arr, j, j + 1);
            }
        }
        if (!swapped){
            break;
        }
    }
    cout << "Total Checks: " << totalChecks << " Total Swaps: " << totalSwaps << endl;
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