#include <iostream>

using namespace std;

int Power(int base, int power);

int main(){
    cout << Power(2,5) << endl;
}

int Power(int base, int power){
    if (power == 0){
        return 1;
    }else{
        return base * Power(base, power - 1);
    }
}