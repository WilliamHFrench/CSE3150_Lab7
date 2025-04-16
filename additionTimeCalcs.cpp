#include <iostream>
#include "fraction.cpp"
#include <chrono>

using namespace std;


int main(){
    int limit = 10000;

    auto startBig = chrono::high_resolution_clock::now();
    bigint a = 1;
    bigint b = 2;
    for(int i = 0; i < limit; i ++){
        bigint c = a + b;
    }
    auto endBig = chrono::high_resolution_clock::now();
    auto durationBig = chrono::duration_cast<chrono::microseconds>(endBig - startBig);

    auto start = chrono::high_resolution_clock::now();
    int c = 1;
    int d = 2;
    for(int i = 0; i < limit; i ++){
        int d = c + d;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    auto startLong = chrono::high_resolution_clock::now();
    long int e = 1;
    long int f = 2;
    for(int i = 0; i < limit; i ++){
        long int g = e + f;
    }

    auto endLong = chrono::high_resolution_clock::now();
    auto durationLong = chrono::duration_cast<chrono::microseconds>(endLong - startLong);

    cout << "Int Time: " << duration.count() << " microseconds" << endl;
    cout << "BigInt Time: " << durationBig.count() << " microseconds" << endl;
    cout << "LongInt Time: " << durationLong.count() << " microseconds" << endl;

    return 0;
}