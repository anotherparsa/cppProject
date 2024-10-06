#include <iostream>
using namespace std;

int Factoriel(int number);

int main(){
    cout << Factoriel(5) << endl;
}

int Factoriel(int number){
    if (number == 1){
        return 1;
    }else {
        return number * Factoriel(number - 1);
    }
}