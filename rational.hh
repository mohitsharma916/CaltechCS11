#include <cstdlib>
#include<stdexcept>
// #include<iostream>


class Rational{

private:
    int numerator;
    int denominator;

    // Reduces the 
    static void reduce(Rational& _rational, int n, int d){
        int gcd = Rational::get_gcd(std::abs(n),std::abs(d));

        _rational.numerator = _rational.numerator/gcd;
        _rational.denominator = _rational.denominator/gcd;
    }

    static int get_gcd(int a,int b){
        if(b==0){
            return a;
        } else{
            return get_gcd(b,a%b);
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

        Rational::reduce(*this,numerator,denominator);
    }

    // Get the numerator of the rational number: Const version
    const int num() const{
        return this->numerator;
    }

    
    // Get the denominator of the rational number: Const version
    const int denom() const{
        return this->denominator;
    }


    // Get the Reciprocal of a Rational Number
    Rational reciprocal() const {
        if(numerator ==0){
            throw std::runtime_error("Error: Reciprocal not defined.");
        }

        Rational _reciprocal(denominator,numerator);

        return _reciprocal;
    }

    /**
        Overload the compound assignment operators
    **/

    /**
        Rational += Rational
    **/
    Rational& operator+=( const Rational& _rational_1);

    /**
        Rational *= Rational
    **/
    Rational& operator*=( const Rational& _rational_1);

    /**
        Rational -= Rational
    **/
    Rational& operator-=( const Rational& _rational_1);

    /**
        Rational /= Rational
    **/
    Rational& operator/=( const Rational& _rational_1);

    /**
        Overloading pre and post increment and decrement opeators
    **/

    /**
        ++Rational
    **/
    Rational& operator++();

    /**
        Rational++
    **/
    Rational& operator++(int);

    /**
        --Rational
    **/
    Rational& operator--();

    /**
        Rational--
    **/
    Rational& operator--(int);

    /**
        Overloading Unary negation operator
    **/
    Rational& operator-();

    /**
        Overloading the float() typecast
    **/
    operator float(){
        return (float)(this->num()*1.0/this->denom());
    }

    /**
        Overloading the double() typecast
    **/
    operator double(){
        return (double)(this->num()*1.0/this->denom());
    }

};

/**
    Declaration for all the non-member operator overload methods
**/

Rational& operator+(const Rational & _rational_1,const Rational & _rational_2 );
Rational& operator-(const Rational& _rational_1, const Rational& _rational_2);
Rational& operator*(const Rational& _rational_1, const Rational& _rational_2);
Rational& operator/(const Rational& _rational_1, const Rational& _rational_2);
bool operator>(const Rational& _rational_1,const Rational& _rational_2);
bool operator<(const Rational& _rational_1, const Rational& _rational_2);
bool operator==(const Rational& _rational_1, const Rational& _rational_2);
bool operator>=(const Rational& _rational_1, const Rational& _rational_2);
bool operator<=(const Rational& _rational_1, const Rational& _rational_2);
bool operator!=(const Rational& _rational_1, const Rational& _rational_2);

/**

    Implementing simple addition, subtraction, multiplication and division as non-member function

**/

/** 
    Overloading the addition operator

    Rational + Rational
**/
Rational& operator+(const Rational& _rational_1, const Rational& _rational_2){

    int numerator = _rational_1.num() * _rational_2.denom() + _rational_2.num() * _rational_1.denom();
    int denominator = _rational_1.denom()* _rational_2.denom();

    Rational *sum = new Rational(numerator,denominator);

    return *sum;
}

/**
    Overloading the subtraction operator
    
    Multiply _rational_2 by -1/1 and then add to the _rational_1
**/
Rational& operator-(const Rational& _rational_1, const Rational& _rational_2){

    Rational minus_1(-1);

    return _rational_1 + (minus_1 * _rational_2);

}

/** 
    Overloading the multiplication operator

    Rational * Rational
**/
Rational& operator*(const Rational& _rational_1, const Rational& _rational_2){

    int numerator = _rational_1.num()*_rational_2.num();
    int denominator = _rational_1.denom() * _rational_2.denom();

    Rational *product = new Rational(numerator,denominator);

    return (Rational &)product;
}

/** 
    Overloading the division operator 

    Rational / Rational
**/
Rational& operator/(const Rational& _rational_1, const Rational& _rational_2){

    Rational _rational_2_reciprocal = _rational_2.reciprocal();

    return _rational_1*_rational_2_reciprocal;
}

/**
    Overloading the Compund Assignment Operators
**/

/**
    Rational += Rational
**/
Rational& Rational::operator+=( const Rational& _rational_1){
    
    Rational result = *this + _rational_1;
    this->numerator = result.num();
    this->denominator = result.denom();

    return *this;
}


/**
    Rational -= Rational
**/
Rational& Rational::operator-=( const Rational& _rational_1){
    
    *this = (*this) - _rational_1;

    return (Rational &) (*this);   
}


/**
    Rational *= Rational
**/
Rational& Rational::operator*=( const Rational& _rational_1){
    
    *this = (*this) * _rational_1;

    return (Rational &) (*this);
}


/**
    Rational /= Rational
**/
Rational& Rational::operator/=( const Rational& _rational_1){
    
    *this = (*this) / _rational_1;

    return (Rational &) (*this);
}

/**
    Overloading Prefix and Postfix increment operators
**/

/**
    ++Rational
**/
Rational& Rational::operator++(){
    Rational plus_one(1);

    *this = *this + plus_one;

    return (Rational &) (*this);
}

/**
    Rational++
**/
Rational& Rational::operator++(int){
    Rational *current_rational = new Rational(this->num(),this->denom());

    Rational plus_one(1);

    *this = *this + plus_one;

    return (Rational &)(*current_rational);
}

/**
    --Rational
**/
Rational& Rational::operator--(){
    Rational minus_one(-1);

    *this = *this + minus_one;

    return (Rational &)(*this);
}

/**
    Rational--
**/
Rational& Rational::operator--(int){
    Rational *current_rational = new Rational(this->num(),this->denom());

    Rational minus_one(-1);

    *this = *this + minus_one;

    return (Rational &)(*current_rational);
}

/**
    Overloading Unary Negation Operator
**/
Rational& Rational::operator-(){
    Rational *negation = new Rational(-1 * this->num(),this->denom());

    return (Rational &) (*negation);

}

/**
    Implementation for methods overloading the comparison operators
**/

/**
    Rational > Rational
**/
bool operator>(const Rational& _rational_1,const Rational& _rational_2){

    return float(_rational_1 - _rational_2) > 0;
}

/**
    Rational < Rational
**/
bool operator<(const Rational& _rational_1, const Rational& _rational_2){

    return (float)(_rational_1 - _rational_2) < 0;
}

/**
    Rational == Rational
**/
bool operator==(const Rational& _rational_1, const Rational& _rational_2){

    return (_rational_1.num() == _rational_2.num()) && (_rational_1.denom() == _rational_2.denom());
}

/**
    Rational >= Rational
**/
bool operator>=(const Rational& _rational_1, const Rational& _rational_2){

    return float(_rational_1 - _rational_2) >= 0;
}


/**
    Rational <= Rational
**/
bool operator<=(const Rational& _rational_1, const Rational& _rational_2){

    return float(_rational_1 - _rational_2) <= 0;
}


/**
    Rational != Rational
**/
bool operator!=(const Rational& _rational_1, const Rational& _rational_2){

    return float(_rational_1 - _rational_2) != 0;
}