#include <iostream>

using namespace std;

int Fibonacci(int number);
int main(){
    for (int i = 0 ; i < 10 ; i++){
        cout << "Fibonacci " << i << " = " << Fibonacci(i) << endl; 
    }
}

int Fibonacci(int number){
    if (number == 1 || number == 0){
        return number;
    }else {
        return Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}