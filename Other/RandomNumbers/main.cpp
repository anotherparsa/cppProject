#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int RandomNumber1 = rand();
    cout << RandomNumber1 << endl;
    //it will generate a random number based on a mathematical formula which is why the number is the same
    //we have to seed a number into the formula
    srand(5);
    int RandomNumber2 = rand();
    cout << RandomNumber2 << endl;
    //it will print a different number but it still not random because the seeding is the same
    //we have too seed a random number into the formula
    srand(time(0));
    int RandomNumber3 = rand();
    cout << RandomNumber3 << endl;
    //now we get a different random number
    int RandomNumber4 = rand() %100;
    cout << RandomNumber4 << endl;
    // now we get a smaller random number
    int RandomNumber5 = rand() % (7); //(max - min - 1) + 1
    cout << RandomNumber5 << endl;
    //now we can get a random number in a rage
}