#include <iostream>

using namespace std;

int LinearSearch(int arr[], int size, int target);

int main(){
    int arr[] = {1, 9, 4, 2, 3, 6, 8, 7, 5};
    int size = (sizeof(arr) / sizeof(int));
    cout << LinearSearch(arr, size, 2) << endl;
}

int LinearSearch(int arr[], int size, int target){
    for (int i = 0 ; i < size ; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return - 1;
}