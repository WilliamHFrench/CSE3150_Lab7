#include <iostream>
#include "fraction.cpp"
#include <chrono>

using namespace std;


int main(){

    pair<bigint, bigint> fraction1("1", "2"), fraction2("3","4");
    pair<bigint, bigint> newFractionProduct = product(fraction1, fraction2);
    pair<bigint, bigint> newFractionSum = sum(fraction1, fraction2);

    cout << newFractionProduct << endl;
    cout << newFractionSum << endl;

    bigint myBigInt = 1;
    const bigint two("2");
    int myInt = 1;

    for (int i = 0; i < 35; i++){
        myInt*=2;
        myBigInt *= two;
        bigint compare(myInt);
        if(compare != myBigInt){
            cerr << "big int works but int overflows " << myBigInt << " where i = " << i << endl;
            break;
        }
    }
    cout << myBigInt << endl;
    cout << myInt << endl;


    return 0;
}