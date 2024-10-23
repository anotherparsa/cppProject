#include <iostream>

using namespace std;

void PrintAllSubArrays(int arr[], int size);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = (sizeof(arr) / sizeof(int));
    PrintAllSubArrays(arr, size);

}

void PrintAllSubArrays(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            for (int k = i; k <= j; k++) {
                cout << " ( " << arr[k] << " ) ";
            }
            cout << endl;
        }
    }
}