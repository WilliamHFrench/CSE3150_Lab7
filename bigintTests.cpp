#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "fraction.cpp"
#include "./include/doctest.h"
#include <vector>

using namespace std;

TEST_CASE("Sum Test"){
    SUBCASE("Edge cases"){
        pair<bigint, bigint> fraction1("1", "1"), fraction2("0","1"), fraction3("1","2");
        pair<bigint, bigint> newFractionSum1 = sum(fraction1, fraction3);
        pair<bigint, bigint> newFractionSum2 = sum(fraction2, fraction3);
        bigint solution1("1"), solution2("2"), solution3("3"), solution4("4");

        CHECK(solution3 == newFractionSum1.first);
        CHECK(solution2 == newFractionSum1.second);

        CHECK(solution1 == newFractionSum2.first);
        CHECK(solution2 == newFractionSum2.second);
    }
    SUBCASE("Regular cases"){
        pair<bigint, bigint> fraction1("1", "2"), fraction2("3","4"), fraction3("5","6");
        pair<bigint, bigint> newFractionSum1 = sum(fraction1, fraction2);
        pair<bigint, bigint> newFractionSum2 = sum(fraction1, fraction3);
        pair<bigint, bigint> newFractionSum3 = sum(fraction2, fraction3);
        bigint solution1("5"), solution2("4"), solution3("3"), solution4("19"), solution5("12");
        CHECK(solution1 == newFractionSum1.first);
        CHECK(solution2 == newFractionSum1.second);

        CHECK(solution2 == newFractionSum2.first);
        CHECK(solution3 == newFractionSum2.second);

        CHECK(solution4 == newFractionSum3.first);
        CHECK(solution5 == newFractionSum3.second);

    }
}

TEST_CASE("Product Test"){
    SUBCASE("Edge cases"){
        pair<bigint, bigint> fraction1("1", "1"), fraction2("0","1"), fraction3("1","2");
        pair<bigint, bigint> newFractionProduct1 = product(fraction1, fraction3);
        pair<bigint, bigint> newFractionProduct2 = product(fraction2, fraction3);
        bigint solution0("0"), solution1("1"), solution2("2");

        CHECK(solution1 == newFractionProduct1.first);
        CHECK(solution2 == newFractionProduct1.second);

        CHECK(solution0 == newFractionProduct2.first);
        CHECK(solution1 == newFractionProduct2.second);
    }

    SUBCASE("Regular cases"){
        pair<bigint, bigint> fraction1("1", "2"), fraction2("3","4"), fraction3("5","6");
        pair<bigint, bigint> newFractionProduct1 = product(fraction1, fraction2);
        pair<bigint, bigint> newFractionProduct2 = product(fraction1, fraction3);
        pair<bigint, bigint> newFractionProduct3 = product(fraction2, fraction3);
        bigint solution1("3"), solution2("8"), solution3("5"), solution4("12");
        CHECK(solution1 == newFractionProduct1.first);
        CHECK(solution2 == newFractionProduct1.second);

        CHECK(solution3 == newFractionProduct2.first);
        CHECK(solution4 == newFractionProduct2.second);

        CHECK(solution3 == newFractionProduct3.first);
        CHECK(solution2 == newFractionProduct3.second);
}
}

TEST_CASE("Int Breaking Point"){
    bigint myBigInt = 1;
    const bigint two("2");
    int myInt = 1;
    int count = 0;

    for (int i = 0; i < 35; i++){
        myInt*=2;
        myBigInt *= two;
        bigint compare(myInt);
        if(compare != myBigInt){
            count = i;
            break;
        }
    }

    bigint solution("2147483648");
    CHECK(count == 30);
    CHECK(solution == myBigInt);
    CHECK(myInt != 2147483648);
    CHECK(myInt == -2147483648);

}