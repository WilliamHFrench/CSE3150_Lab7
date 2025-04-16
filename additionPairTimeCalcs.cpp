#include <iostream>
#include "fraction.cpp"
#include <chrono>

using namespace std;


int main(){
    int limit = 10000;

    auto startBig = chrono::high_resolution_clock::now();
    pair<bigint, bigint> fraction1("1", "1"), fraction2("2","1");
    for(int i = 0; i < limit; i ++){
        pair<bigint, bigint> c = sum(fraction1, fraction2);
    }
    auto endBig = chrono::high_resolution_clock::now();
    auto durationBig = chrono::duration_cast<chrono::microseconds>(endBig - startBig);

    auto start = chrono::high_resolution_clock::now();
    pair<int, int> fraction3(1, 1), fraction4(2,1);
    for(int i = 0; i < limit; i ++){
        int numerator, denominator;
        if(fraction3.first == 0){
            numerator= fraction4.first;
            denominator = fraction4.second;
    }
         else if(fraction4.first == 0){
            numerator= fraction3.first;
            denominator = fraction3.second;
    }
        else{
            numerator = (fraction3.first * fraction4.second) + (fraction3.second *fraction4.first);
            denominator = fraction3.second * fraction4.second;
    }

        pair<int, int> intAddition(numerator, denominator);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    auto startLong = chrono::high_resolution_clock::now();
    pair<long int, long int> fraction5(1, 1), fraction6(2,1);
    for(int i = 0; i < limit; i ++){
        long int numerator, denominator;
        if(fraction5.first == 0){
            numerator= fraction6.first;
            denominator = fraction6.second;
    }
         else if(fraction6.first == 0){
            numerator= fraction5.first;
            denominator = fraction5.second;
    }
        else{
            numerator = (fraction5.first * fraction6.second) + (fraction5.second *fraction6.first);
            denominator = fraction5.second * fraction6.second;
    }

        pair<long int, long int> longAddition(numerator, denominator);
    }

    auto endLong = chrono::high_resolution_clock::now();
    auto durationLong = chrono::duration_cast<chrono::microseconds>(endLong - startLong);

    cout << "Int Time: " << duration.count() << " microseconds" << endl;
    cout << "BigInt Time: " << durationBig.count() << " microseconds" << endl;
    cout << "LongInt Time: " << durationLong.count() << " microseconds" << endl;

    return 0;
}