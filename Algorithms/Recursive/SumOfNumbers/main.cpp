#include <iostream>

using namespace std;

int Sum(int number);

int main(){
    cout << Sum(5) << endl;
}

int Sum(int number){
    if (number == 1){
        return 1;
    }else{
        return number + Sum(number - 1);
    }
}