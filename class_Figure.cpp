//Class basics. Use of initialization list, make_shared & shared_ptr, abstraction and inheritance.
//Example of implementation Figure class with types Triangle, Rect and Circle.
//Performed perimeter and square calculation

#include<iostream>
#include<string>
#include<cmath>
#include<memory>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;
class Figure 
{
public:
    virtual string Name() const = 0;
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};


class Triangle : public Figure
{
public:
    Triangle(const double a1, const double b1, const double c1) : a(a1),b(b1),c(c1) {}
    string Name() const override
    {
        return "TRIANGLE";
    }
    double Perimeter() const override
    {
        return a+b+c;
    }
    double Area() const override
    {
        double half_p = Triangle::Perimeter()/2;
        return sqrt(half_p*(half_p-a)*(half_p-b)*(half_p-c));
    }
private:
	const double a, b, c;
};

class Rect : public Figure
{
public:
    Rect(const double width1, const double height1) : width(width1), height(height1) {};
    string Name() const override
    {
        return "RECT";
    }
    double Perimeter() const override
    {
        return (width+height)*2;
    }
    double Area() const override
    {
        return width*height;
    }
private:
    const double width, height;
};

class Circle : public Figure
{
public:
    Circle(const double R1) : R(R1) {} 
    string Name() const override
    {
        return "CIRCLE";
    }
    double Perimeter() const override
    {
        return 2*pi*R;
    }
    double Area() const override
    {
        return pi*R*R;
    }
private:
    const double pi = 3.14;
    const double R;
};

shared_ptr<Figure> CreateFigure (istringstream& is)
{
    string name;
    double var;
    is >> name;
    if(name == "CIRCLE")
    {
        is >> var;
        return make_shared<Circle>(var);
    }
    double var2;
    if(name == "RECT")
    {
        is >> var >> var2;
        return make_shared<Rect>(var, var2);
    }
    double var3;
    if(name == "TRIANGLE")
    {
        is >> var >> var2 >> var3;
        return make_shared<Triangle>(var,var2,var3);
    }
    return 0;
}


