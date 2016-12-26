#include <cstdlib>
#include<stdexcept>


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

        Rational::reduce((Rational &)(*this),numerator,denominator);
    }

    // Get the numerator of the rational number
    int num(){
        return this->numerator;
    }

    // Get the denominator of the rational number
    int denom(){
        return this->denominator;
    }

    // Get the Reciprocal of a Rational Number
    Rational reciprocal(){
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
    Rational& operator+=( Rational& _rational_1);

    /**
        Rational += Scalar
    **/
    Rational& operator+=(const int& _scalar);

    /**
        Rational *= Rational
    **/
    Rational& operator*=( Rational& _rational_1);

    /**
        Rational *= Scalar
    **/
    Rational& operator*=(const int& _scalar);

    /**
        Rational -= Rational
    **/
    Rational& operator-=( Rational& _rational_1);

    /**
        Rational -= Scalar
    **/
    Rational& operator-=(const int& _scalar);

    /**
        Rational /= Rational
    **/
    Rational& operator/=( Rational& _rational_1);

    /**
        Rational /= Scalar
    **/
    Rational& operator/=(const int& _scalar);

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

Rational& operator+(Rational& _rational_1,Rational& _rational_2);
Rational& operator+(const int _scalar, Rational& _rational_1);
Rational& operator+(Rational& _rational_1, const int _scalar);
Rational& operator-(Rational& _rational_1, Rational& _rational_2);
Rational& operator*(Rational& _rational_1, Rational& _rational_2);
Rational& operator*(Rational& _rational_1, const int _scalar);
Rational& operator*(const int _scalar, Rational& _rational_1);
Rational& operator/( Rational& _rational_1,const int _scalar);
Rational& operator/(Rational& _rational_1, Rational& _rational_2);
Rational& operator/(const int _scalar, Rational& _rational_1);
bool operator>(Rational& _rational_1,Rational& _rational_2);
bool operator>(Rational& _rational_1, const int _scalar);
bool operator>(const int _scalar, Rational& _rational_1);
bool operator<(Rational& _rational_1, Rational& _rational_2);
bool operator<(Rational& _rational_1, const int _scalar);
bool operator<(const int _scalar, Rational& _rational_1);
bool operator==(Rational& _rational_1, Rational& _rational_2);
bool operator==(Rational& _rational_1, const int _scalar);
bool operator==(const int _scalar, Rational& _rational_1);
bool operator>=(Rational& _rational_1, Rational& _rational_2);
bool operator>=(Rational& _rational_1, const int _scalar);
bool operator>=(const int _scalar, Rational& _rational_1);
bool operator<=(Rational& _rational_1, Rational& _rational_2);
bool operator<=(Rational& _rational_1, const int _scalar);
bool operator<=(const int _scalar, Rational& _rational);
bool operator!=(Rational& _rational_1, Rational& _rational_2);
bool operator!=(Rational& _rational_1, const int _scalar);
bool operator!=(const int _scalar, Rational& _rational_1);



/**

    Implementing simple addition, subtraction, multiplication and division as non-member function

**/

/** 
    Overloading the addition operator

    Rational + Rational
**/
Rational& operator+(Rational& _rational_1,Rational& _rational_2){

    int numerator = _rational_1.num() * _rational_2.denom() + _rational_2.num() * _rational_1.denom();
    int denominator = _rational_1.denom()* _rational_2.denom();

    Rational *sum = new Rational(numerator,denominator);

    return (Rational &)sum;
}

/**
    Overloading the Addition Operator

    Scalar + Rational
**/

Rational& operator+(const int _scalar, Rational& _rational_1){
    
    Rational _rational_2(_scalar);

    return _rational_1 + _rational_2;
}

/**
    Overloading Addition Operator

    Rational + Scalar
**/
Rational& operator+(Rational& _rational_1, const int _scalar){
    
    Rational _rational_2(_scalar);

    return _rational_1 + _rational_2;
}

/**
    Overloading the subtraction operator
    
    Multiply _rational_2 by -1/1 and then add to the _rational_1
**/
Rational& operator-(Rational& _rational_1, Rational& _rational_2){

    Rational minus_1(-1);

    return _rational_1 + (minus_1 * _rational_2);

}

/** 
    Overloading the multiplication operator

    Rational * Rational
**/
Rational& operator*(Rational& _rational_1, Rational& _rational_2){

    int numerator = _rational_1.num()*_rational_2.num();
    int denominator = _rational_1.denom() * _rational_2.denom();

    Rational *product = new Rational(numerator,denominator);

    return (Rational &)product;
}

/** 
    Overloading the multiplication operator

    Rational * Scalar
**/
Rational& operator*(Rational& _rational_1, const int _scalar){
    
    Rational _rational_2(_scalar);

    return _rational_1 * _rational_2;
}

/** 
    Overloading the multiplication operator

    Scalar * Rational
**/
Rational& operator*(const int _scalar, Rational& _rational_1){
    
    Rational _rational_2(_scalar);

    return _rational_1 * _rational_2;
}

/** 
    Overloading the division operator 

    Rational / Rational
**/
Rational& operator/(Rational& _rational_1, Rational& _rational_2){

    Rational _rational_2_reciprocal = _rational_2.reciprocal();

    return _rational_1*_rational_2_reciprocal;
}

/**
    Overloading the division operator 

    Rational / Scalar
**/
Rational& operator/( Rational& _rational_1,const int _scalar){
   
    Rational _rational_2(_scalar);

    return _rational_1 / _rational_2;
}

/** 
    Overloading the division operator

    Scalar / Rational
**/
Rational& operator/(const int _scalar, Rational& _rational_1){
    
    Rational _rational_2(_scalar);

    return _rational_2/_rational_1;
}

/**
    Overloading the Compund Assignment Operators
**/

/**
    Rational += Rational
**/
Rational& Rational::operator+=( Rational& _rational_1){
    
    *this =  (*this) + _rational_1;

    return (Rational &) (*this);
}

/**
    Rational += Scalar
**/
Rational& Rational::operator+=(const int& _scalar){
    
    Rational _rational_1(_scalar);
    *this = (*this) + _rational_1;

    return (Rational &) (*this);
}

/**
    Rational -= Rational
**/
Rational& Rational::operator-=( Rational& _rational_1){
    
    *this = (*this) - _rational_1;

    return (Rational &) (*this);   
}

/**
    Rational -= Scalar
**/
Rational& Rational::operator-=(const int& _scalar){
    
    Rational _rational_1(_scalar);
    *this = (*this) - _rational_1;

    return (Rational &) *this;
}

/**
    Rational *= Rational
**/
Rational& Rational::operator*=( Rational& _rational_1){
    
    *this = (*this) * _rational_1;

    return (Rational &) (*this);
}

/**
    Rational *= Scalar
**/
Rational& Rational::operator*=(const int& _scalar){

    Rational _rational_1(_scalar);
    *this = (*this) * _rational_1;

    return (Rational &) (*this);
}

/**
    Rational /= Rational
**/
Rational& Rational::operator/=( Rational& _rational_1){
    
    *this = (*this) / _rational_1;

    return (Rational &) (*this);
}

/**
    Rational /= Scalar
**/
Rational& Rational::operator/=(const int& _scalar){

    Rational _rational_1(_scalar);
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
bool operator>(Rational& _rational_1,Rational& _rational_2){

    return float(_rational_1 - _rational_2) > 0;
}

/**
    Rational > Scalar
**/
bool operator>(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return (float)(_rational_1 - _rational_2) > 0;
}

/**
    Scalar > Rational
**/
bool operator>(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return (float)(_rational_2 - _rational_1) > 0;
}

/**
    Rational < Rational
**/
bool operator<(Rational& _rational_1, Rational& _rational_2){

    return (float)(_rational_1 - _rational_2) < 0;
}
/**
    Rational < Scalar
**/
bool operator<(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return (float)(_rational_1 - _rational_2) < 0;

}

/**
    Scalar < Rational
**/
bool operator<(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return (float)(_rational_2 - _rational_1) < 0;
}

/**
    Rational == Rational
**/
bool operator==(Rational& _rational_1, Rational& _rational_2){

    return (_rational_1.num() == _rational_2.num()) && (_rational_1.denom() == _rational_2.denom());
}

/**
    Rational == Scalar
**/
bool operator==(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return (_rational_1.num() == _rational_2.num()) && (_rational_1.denom() == _rational_2.denom());
}

/**
    Scalar == Rational
**/
bool operator==(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return (_rational_1.num() == _rational_2.num()) && (_rational_1.denom() == _rational_2.denom());
}

/**
    Rational >= Rational
**/
bool operator>=(Rational& _rational_1, Rational& _rational_2){

    return float(_rational_1 - _rational_2) >= 0;
}

/**
    Rational >= Scalar
**/
bool operator>=(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return float(_rational_1 - _rational_2) >= 0;
}

/**
    Scalar >= Rational
**/
bool operator>=(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return float(_rational_2 - _rational_1) >= 0;
}

/**
    Rational <= Rational
**/
bool operator<=(Rational& _rational_1, Rational& _rational_2){

    return float(_rational_1 - _rational_2) <= 0;
}

/**
    Rational <= Scalar
**/
bool operator<=(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return float(_rational_1 - _rational_2) <= 0;
}

/**
    Scalar <= Rational
**/
bool operator<=(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return float(_rational_2 - _rational_1) <= 0;
}

/**
    Rational != Rational
**/
bool operator!=(Rational& _rational_1, Rational& _rational_2){

    return float(_rational_1 - _rational_2) != 0;
}

/**
    Rational != Scalar
**/
bool operator!=(Rational& _rational_1, const int _scalar){

    Rational _rational_2(_scalar);

    return float(_rational_1 - _rational_2) != 0;
}

/**
    Scalar != Rational
**/
bool operator!=(const int _scalar, Rational& _rational_1){

    Rational _rational_2(_scalar);

    return float(_rational_1 - _rational_2) != 0;
}