//Rational class. Performed basic math operation with rational numbers: addition, subtraction, multiplication, division and equality check.
//Numbers can be entered and output using operators << >>

#include <iostream>
#include <string>
#include <sstream> 
#include<stdexcept>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) 
    {
        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        Rational::numerator = numerator/gcd(numerator, denominator);
        Rational::denominator = denominator/gcd(numerator, denominator);
    }
    ~Rational()
    {

    }
    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
    int gcd(int numerator, int denominator)
    {
        numerator = abs(numerator);
        denominator = abs(denominator);
        while (numerator > 0 && denominator > 0)
        {
            if (numerator > denominator)
            {
                numerator %= denominator;
            }
            else
            {
                denominator %= numerator;
            }
        }
        return numerator + denominator;
    }
};


bool operator==(const Rational& r, const Rational& y)
{
    return r.Numerator() == y.Numerator() && r.Denominator() == y.Denominator();
}

Rational operator+(const Rational& r, const Rational& y)
{
    int numerator = r.Numerator()*y.Denominator()+r.Denominator()*y.Numerator();
    int denominator = r.Denominator()* y.Denominator();
    return Rational(numerator, denominator);
}

Rational operator-(const Rational& r, const Rational& y)
{
    int numerator = r.Numerator() * y.Denominator() - r.Denominator() * y.Numerator();
    int denominator = r.Denominator() * y.Denominator();
    return Rational(numerator, denominator);
}

Rational operator*(const Rational& r, const Rational& y)
{
    int numerator = r.Numerator() * y.Numerator();
    int denominator = r.Denominator() * y.Denominator();
    return Rational(numerator, denominator);
}

Rational operator/(const Rational& r, const Rational& y)
{
    int numerator = r.Numerator() * y.Denominator();
    int denominator = r.Denominator() * y.Numerator();
    if (denominator == 0)
    {
        throw domain_error("Division by zero");
    }
    return Rational(numerator, denominator);
}

istream& operator>>(istream& input, Rational& r)
{
    int numerator;
    int denominator;
    if (input >> numerator)
    {
        input.ignore(1);
        input >> denominator;
        r = Rational(numerator, denominator);
    }
    return input;
}

ostream& operator<<(ostream& output, const Rational& r)
{
    output << r.Numerator() << '/' << r.Denominator() << endl;
    return output;
}


bool operator<(const Rational& r, const Rational& y)
{
    return r.Numerator() * y.Denominator() < r.Denominator() * y.Numerator();
}



int main() {

    char slash;
    int numerator, denominator, numerator1, denominator1;
    char operation;
    cin >> numerator >> slash >> denominator >> operation >> numerator1 >> slash >> denominator1;
    try
    {
        Rational x(numerator, denominator);
        Rational y(numerator1, denominator1);
        Rational z;

    try 
    {
        switch (operation)
        {
        case '+': z = x + y;
            break;
        case '-': z = x - y;
            break;
        case '*': z = x * y;
            break;
        case '/': z = x / y;
            break;
        default: break;
        }
        cout << z;
    }
    catch(domain_error& ex)
    {
        cout << ex.what() << endl;
        return 0;
    }
    }
    catch (invalid_argument& ex)
    {
        cout << ex.what() << endl;
        return 0;
    }
    return 0;
}