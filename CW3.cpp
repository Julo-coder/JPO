#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//Zadanie 1
class Shape {
protected:
    std::string name;
public:
    Shape(string name_) : name(name_) {}
    virtual ~Shape() {}

    void setName(std::string val) {
        name = val;
    }

    std::string getName() {
        return name;
    }

    virtual double area() = 0;
    virtual double perimeter()  = 0;
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(string name_, double width_, double height_) : Shape(name_), width(width_), height(height_) {}
    ~Rectangle() {}
    double area() {
        return width * height;
    }
    double perimeter(){
        return 2 * (width + height);
    }
};

class Square : public Rectangle {
public:
    Square(string name_, double width_) : Rectangle(name_, width_, width_) {}
    ~Square() {}

    double area(){
        return width * width;
    }
    double perimeter(){
        return 4 * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string name_, double radius_) : Shape(name_), radius(radius_) {}
    ~Circle() {}

    double area(){
        return M_PI * radius * radius;
    }
    double perimeter(){
        return 2 * M_PI * radius;
    }
};

class Ellipse : public Shape {
private:
    double semi_major_axis, semi_minor_axis;
public:
    Ellipse(string name_, double semi_major_axis_, double semi_minor_axis_) : Shape(name_), semi_major_axis(semi_major_axis_), semi_minor_axis(semi_minor_axis_) {}
    ~Ellipse() {}

    double area() {
        return M_PI * semi_major_axis * semi_minor_axis;
    }
    double perimeter(){
        return M_PI * (3 * (semi_major_axis + semi_minor_axis) - sqrt((3 * semi_major_axis + semi_minor_axis) * (semi_major_axis + 3 * semi_minor_axis)));
    }
};

class ShapeContainer {
private:
    vector<Shape*> shapes;
public:
    ShapeContainer() {}
    ~ShapeContainer() {
        for (Shape* shape : shapes)
            delete shape;
    }

    void add(Shape* shape) {
        shapes.push_back(shape);
    }

    void displayAll()  {
        for (const auto& shape : shapes)
            cout << shape->getName() << " - Area: " << shape->area() << endl;
    }

    double totalArea() {
        double total = 0.0;
        for (Shape* shape : shapes)
            total += shape->area();
        return total;
    }

    vector<Shape*> getGreaterThan(double area) {
        vector<Shape*> greater;
        for (Shape* shape: shapes) {
            if (shape->area() > area)
                greater.push_back(shape);
        }
        return greater;
    }
};

void func1(){
    double recA, recB, sqW, circR, elipMajA, elipMinA;
    cout << "Podaj wysokosc i szerokoscc prostokata: " << endl;
    cin >> recA >> recB;
    cout << "Podaj dlugosc boku kwadratu: " << endl;
    cin >> sqW;
    cout << "Podaj promien kola: " << endl;
    cin >> circR;
    cout << "Podaj dluzsza przekotna: " << endl;
    cin >> elipMajA;
    cout << "Podaj krotsza przekatna: " << endl;
    cin >> elipMinA;

    ShapeContainer container;
    container.add(new Rectangle("Rectangle", recA, recB));
    container.add(new Square("Square", sqW));
    container.add(new Circle("Circle", circR));
    container.add(new Ellipse("Ellipse", elipMajA, elipMinA));

    container.displayAll();

    cout << "Total area: " << container.totalArea() << endl;

    cout << "Podaj liczbe do sprawdzenia wartsci: " << endl;
    int number;
    cin >> number;
    vector<Shape*> greaterThan5 = container.getGreaterThan(number);
    cout << "Shapes with area greater than :" << number << endl;
    for (Shape* shape : greaterThan5)
        cout << shape->getName() << endl;

};
//Zadanie 2
class Function {
public:
    Function() = default;
    virtual ~Function() = default;
    virtual double calculateFun(double x) = 0;
};

class LinearFunction : public Function {
private:
    double a, b;
public:
    LinearFunction(double a_, double b_) : a(a_), b(b_) {}
    virtual ~LinearFunction() {}
    double calculateFun(double x) override {
        return a * x + b;
    }
};

class NumericalAlgorithm {
protected:
    Function* function;
    double epsilon;
public:
    NumericalAlgorithm(Function* function_, double epsilon_ = 0.01) : function(function_), epsilon(epsilon_) {}
    virtual ~NumericalAlgorithm() = default;
    void setEpsilon(double val) {
        epsilon = val;
    }
    virtual double calculate() const = 0;
};

class ZeroOfFunction : public NumericalAlgorithm {
private:
    double a = -1.0;
    double b = 1.0;
public:
    ZeroOfFunction(Function* function_) : NumericalAlgorithm(function_) {}
    void setRange(double A, double B) {
        a = A;
        b = B;
    }
    double calculate() const override {
        double a_val = a;
        double b_val = b;
        while ((b_val - a_val) >= epsilon) {
            double c = (a_val + b_val) / 2;
            if (function->calculateFun(c) == 0.0)
                return c;
            if (function->calculateFun(c) * function->calculateFun(a_val) < 0)
                b_val = c;
            else
                a_val = c;
        }
        return (a_val + b_val) / 2;
    }
};

class Derivative : public NumericalAlgorithm {
private:
    double x = 0.0;
public:
    Derivative(Function* function_) : NumericalAlgorithm(function_) {}
    void setX(double x_val) {
        x = x_val;
    }
    double calculate() const{
        return (function->calculateFun(x + epsilon) - (function->calculateFun(x))) / epsilon;
    }

    double getX(){
        return x;
    }
};

void func2() {
    double X,Y, low, high, setX;
    cout << "Podaj wartosc x do funckji liniowej: " << endl;
    cin >> X;
    cout << "Podaj wspolczynnik y do funkcji liniowej: " << endl;
    cin >> Y;

    LinearFunction my_linear_function(X, Y);
    ZeroOfFunction zero_of_function(&my_linear_function);
    Derivative derivative(&my_linear_function);
    cout << "Podaj gorna wartosc do przedzialu przeszukiwania: " << endl;
    cin >> high;
    cout << "Podaj dolna wartosc do przedzialu przeszukiwania: " << endl;
    cin >> low;
    zero_of_function.setRange(low, high);

    double zero = zero_of_function.calculate();
    cout << "Podaj wartosc x do sprawdzenia pochodnej: " << endl;
    cin >> setX;
    derivative.setX(setX);
    double derivative_value = derivative.calculate();

    cout << "Zero of the function: " << zero << endl;
    cout << "Derivative at x = " << derivative.getX() << " : " << derivative_value << endl;
};


class Matrices{
private:
    int height, width;

};


int main(){
    int exNumber;
    do{
        cout << "Pick the number of exercise: 1,2,4 or 6" << endl;
        cin >> exNumber;
        switch (exNumber) {
            case 1:{
                func1();
                break;
            }
            case 2:{
                func2();
                break;
            }
            case 4:{
                //func4();
                break;
            }
            case 6:{
                //func6();
                break;
            }
        }
    }while(true);
}