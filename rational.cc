#include "rational.hh"
#include <typeinfo>
#include<iostream>

using namespace std;

int main(){

    Rational r1;
    Rational r2(5);
    Rational r3(5, 3);

    cout << r1.num() << r1.denom() << endl;
    cout << r2.num() << r2.denom() << endl;
    cout << r3.num() << r3.denom() << endl;

    Rational r4(15, 5);
    Rational r5(3, 15);
    Rational r6(48, 60);

    cout << r4.num() << " " << r4.denom() << endl;
    cout << r5.num() << " " << r5.denom() << endl;
    cout << r6.num() << " " << r6.denom() << endl;

    Rational r7(5, -3);
    Rational r8(-5, -3);

    cout << r7.num() << " " << r7.denom() << endl;
    cout << r8.num() << " " << r8.denom() << endl;

    Rational r(5);

    r += Rational(-3);
    cout << r.num() << " " << r.denom() << endl;    


    return 0;
}