#ifndef FRACTION_UTILS_H
#define FRACTION_UTILS_H

#include <iostream>
#include <utility>
#include "bigint.h"


using Fraction = std::pair<bigint, bigint>;
std::ostream& operator<<(std::ostream& os, Fraction& fraction);
// bool operator==(pair<bigint, bigint>& fraction1, pair<bigint, bigint>& fraction2);
Fraction product(Fraction fraction1, Fraction fraction2);
Fraction sum(Fraction fraction1, Fraction fraction2);
#endif // FRACTION_UTILS_H
