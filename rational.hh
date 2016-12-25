class Rational{

private:
    int numerator;
    int denominator;

    // Reduces the 
    static void reduce(int n, int d){
        int gcd = Rational::get_gcd(std::abs(n),std::abs(d));

        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }

    static int get_gcd(int a,int b){
        if(b==0){
            return a;
        } else{
            return gcd(b,a%b);
        }
    }

public:

    // Constructor to initialize the rational number to 0
    Rational(){
        numerator = 0;
        denominator = 1;
    }

    // Constructor with only numerator specified
    Rational(int n){
        numerator = n;
        denominator = 1;
    }

    // Constructor with both numerator and denominator specified
    Rational(int n, int d){
        if(d==0){
            // Raise an exception
            throw std::invalid_argument("Error: Denominator can not be 0.");
        }

        if(d<0){
            numerator = -1*n;
            denominator = -1*d;
        } else{
            numerator = n;
            denominator = d;
        }

        Rational::reduce(numerator,denominator);
    }

    // Get the numerator of the rational number
    int num(){
        return numerator;
    }

    // Get the denominator of the rational number
    int denom(){
        return denominator;
    }

    // Get the Reciprocal of a Rational Number
    Rational& reciprocal(){
        if(numerator ==0){
            throw std::runtime_error('Error: Reciprocal not defined.')
        }

        Rational _reciprocal(denominator,numerator);

        return _reciprocal;
    }

};

/**

    Implementing simple addition, subtraction, multiplication and division as non-member function

**/

/** 
    Overloading the addition operator

    Rational + Rational
**/
const Rational& operator+(const Rational& _rational_1, const Rational& _rational_2){

    int numerator = _rational_1.num()*_rational_2.denom() + _rational_2.num()*_rational_1.denom();
    int denominator = _rational_1.denom()* _rational_2.denom();

    Rational sum(numerator,denominator);

    return sum;
}

/**
    Overloading the Addition Operator

    Scalar + Rational
**/

const Rational& operator+(const int _scalar,  const Rational& _rational_1){
    Rational _rational_2(_scalar);

    return _rational_1 + _rational_2;
}

/**
    Overloading Addition Operator

    Rational + Scalar
**/
const Rational& operator+(const Rational& _rational_1, const int _scalar){
    Rational _rational_2(_scalar);

    return _rationa_1 + _rational_2;
}

/**
    Overloading the subtraction operator
    
    Multiply _rational_2 by -1/1 and then add to the _rational_1
**/
Rational& operator-(const Rational& _rationa_1, const Rational& _rationa1_2){

    Rational minus_1(-1);

    return _rational_1 + (minus_1 * _rational_2);

}

/** 
    Overloading the multiplication operator

    Rational * Rational
**/
const Rational& operator*(const Rational& _rational_1, const Rational& _rational_2){

    int numerator = _rational_1.num()*_rational_2.numerator();
    int denominator = _rational_1.denom() * _rational_2.denom();

    Rational product(numerator,denominator);

    return product
}

/** 
    Overloading the multiplication operator

    Rational * Scalar
**/
const Raional& operator*(const Rational& _rational_1, const int _scalar){
    Rational _rational_2(_scalar);

    return _rational_1 * _rational_2;
}

/** 
    Overloading the multiplication operator

    Scalar * Rational
**/
const Rational& operator*(const int _scalar, Rational& _rational_1){
    Rational _rational_2(_scalar);

    return _rational_1 * _rational_2;
}

/** 
    Overloading the division operator 

    Rational / Rational
**/
const Rational& operator/(const Rational& _rational_1, const Rational& _rational_2){

    Rational _rational_2_reciprocal = _rational_2.reciprocal();

    return _rationa_1*_rational_2_reciprocal
}

/**
    Overloading the division operator 

    Rational / Scalar
**/
const Rational& operator/(const Rational& _rational_1,const int _scalar){
    Rational _rational_2(_scalar);

    return _rational_1 / _rational_2;
}

/** 
    Overloading the division operator

    Scalar / Rational
**/
const Rational& operator/(const int _scalar, const Rational& _rational_1){
    Rational _rational_2(_scalar);

    return _rational_2/_rational_1;
}