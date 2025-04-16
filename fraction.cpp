#include <iostream>
#include <utility>
#include "bigint.h"

using namespace std;

ostream & operator<<(ostream & os, pair<bigint, bigint> & fraction){
    os << fraction.first << "/" << fraction.second;
    return os;
}

// bool operator==(pair<bigint, bigint>& fraction1, pair<bigint, bigint>& fraction2) {
//     bigint a = fraction1.first;
//     bigint b = fraction2.first;
//     bigint c = fraction1.second;
//     bigint d = fraction2.second;
//     return (a == b) && (c == d);
// }

pair<bigint, bigint>  product(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2){
    bigint numerator = fraction1.first * fraction2.first;
    bigint denominator = fraction1.second * fraction2.second;

    bigint myGcd = big_gcd(numerator, denominator);

    return pair<bigint, bigint>(numerator/ myGcd, denominator / myGcd);
}

pair<bigint, bigint>  sum(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2){
    bigint zed("0"); 
    bigint numerator, denominator;
    if(fraction1.first == zed){
        numerator= fraction2.first;
        denominator = fraction2.second;
    }
    else if(fraction2.first == zed){
        numerator= fraction1.first;
        denominator = fraction1.second;
    }
    else{
    numerator = (fraction1.first * fraction2.second) + (fraction1.second *fraction2.first);
    denominator = fraction1.second * fraction2.second;
    }

    bigint myGcd = big_gcd(numerator, denominator);

    return pair<bigint, bigint>(numerator/ myGcd, denominator / myGcd);
}

