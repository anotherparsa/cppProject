#include <iostream>

using namespace std;

int Fibonacci(int number);
int Fibonacci2(int number);

int main(){
    cout << Fibonacci(8) << endl;
    cout << Fibonacci2(8) << endl;
}

int Fibonacci(int number){
    if (number == 0){
        return 0;
    }else if (number == 1){
        return 1;
    }else{
        return Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}

int Fibonacci2(int number){
    if (number == 1 || number == 0){
        return number;
    }else {
        return Fibonacci2(number - 1) + Fibonacci2(number - 2);
    }
}