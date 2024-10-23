#include <iostream>

using namespace std;

void PrintAllPairs(int arr[], int size);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = (sizeof(arr) / sizeof(int));
    PrintAllPairs(arr, size);
}

void PrintAllPairs(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        int x = arr[i];
        for(int j = i+1 ; j < size ; j++){
            int y = arr[j];
            cout << "X : " << x << "  Y : " << y << endl;
        }
    }
}