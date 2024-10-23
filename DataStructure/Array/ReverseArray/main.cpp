#include <iostream>

using namespace std;

void ReverseArray(int arr[], int size);
void ShowArray(int arr[], int size);
void Swapping(int arr[], int a, int b);
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = (sizeof(arr)/ sizeof(int));
    cout << "Original array: " << endl;
    ShowArray(arr, size);
    ReverseArray(arr, size);
    cout << "Reversed Array" << endl;
    ShowArray(arr, size);

}

void ReverseArray(int arr[], int size){
    int start = 0;
    int stop = size - 1;
    while (start < stop){
        Swapping(arr, start, stop);
        start++;
        stop--;
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
