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

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(string name_, double width_, double height_) : Shape(name_), width(width_), height(height_) {}
    ~Rectangle() {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Square : public Rectangle {
public:
    Square(string name_, double width_) : Rectangle(name_, width_, width_) {}
    ~Square() {}

    double area() const override {
        return width * width;
    }
    double perimeter() const override {
        return 4 * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string name_, double radius_) : Shape(name_), radius(radius_) {}
    ~Circle() {}

    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Ellipse : public Shape {
private:
    double semi_major_axis, semi_minor_axis;
public:
    Ellipse(string name_, double semi_major_axis_, double semi_minor_axis_) : Shape(name_), semi_major_axis(semi_major_axis_), semi_minor_axis(semi_minor_axis_) {}
    ~Ellipse() {}

    double area() const override {
        return M_PI * semi_major_axis * semi_minor_axis;
    }
    double perimeter() const override {
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

    void displayAll() const {
        for (const auto& shape : shapes)
            cout << shape->getName() << " - Area: " << shape->area() << endl;
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto& shape : shapes)
            total += shape->area();
        return total;
    }

    vector<Shape*> getGreaterThan(double area) const {
        vector<Shape*> greater;
        for (const auto& shape : shapes) {
            if (shape->area() > area)
                greater.push_back(shape);
        }
        return greater;
    }
};

void func1(){
    ShapeContainer container;
    container.add(new Rectangle("Rectangle", 3, 4));
    container.add(new Square("Square", 5));
    container.add(new Circle("Circle", 2));
    container.add(new Ellipse("Ellipse", 3, 2));

    container.displayAll();

    cout << "Total area: " << container.totalArea() << std::endl;

    vector<Shape*> greaterThan5 = container.getGreaterThan(5);
    cout << "Shapes with area greater than 5:" << std::endl;
    for (const auto& shape : greaterThan5)
        cout << shape->getName() << std::endl;

};
//Zadanie 2
//class Function {
//public:
//    Function() = default;
//    virtual ~Function() = default;
//    virtual double calculate(double x) = 0;
//};
//
//class LinearFunction : public Function {
//private:
//    double a, b;
//public:
//    LinearFunction(double a_, double b_) : a(a_), b(b_) {}
//    virtual ~LinearFunction() {}
//    double calculate(double x) override {
//        return a * x + b;
//    }
//};
//
//class NumericalAlgorytm {
//protected:
//    Function* func;
//    double eps;
//public:
//    NumericalAlgorytm(Function* func_, double eps_ = 0.01) : func(func_), eps(eps_) {}
//    virtual ~NumericalAlgorytm() {}
//    void setEpsilon(double val) {
//        eps = val;
//    }
//    virtual double calculate(double a, double b, Function* func, double eps) = 0;
//};
//
//class ZeroOfFunction : public NumericalAlgorytm {
//protected:
//    double a = -1.0;
//    double b = 1.0;
//public:
//    ZeroOfFunction(double a_, double b_, Function* func_) : a(a_), b(b_), NumericalAlgorytm(func_) {}
//    ~ZeroOfFunction() {}
//    void setRange(double A, double B) {
//        a = A;
//        b = B;
//    }
//
//    double calculate(double a_val, double b_val, Function* func, double eps) override {
//        while ((b_val - a_val) >= eps) {
//            double c = (a_val + b_val) / 2;
//            if (func->calculate(c) == 0.0)
//                return c;
//            if (func->calculate(c) * func->calculate(a_val) < 0)
//                b_val = c;
//            else
//                a_val = c;
//        }
//        return (a_val + b_val) / 2;
//    }
//
//};
//
//class Derivative : public NumericalAlgorytm {
//protected:
//    double x = 0.0;
//public:
//    Derivative(double x_, Function* func_) : x(x_), NumericalAlgorytm(func_) {}
//    ~Derivative() {}
//
//    void setX(double x_val) {
//        x = x_val;
//    }
//
//    double calculate(double x_val, Function* func, double eps)  {
//        return (func->calculate(x_val + eps) - func->calculate(x_val)) / eps;
//    }
//};
//
//void func2() {
//    Function* linear = new LinearFunction(1.0, -5.0);
//    NumericalAlgorytm* derivative = new Derivative(2.0, linear);
//    NumericalAlgorytm* zeroFinder = new ZeroOfFunction(0.0, 10.0, linear);
//
//    double x = 2.0;
//    double derivativeValue = derivative->calculate(x, linear, 0.0001);
//    double a = 0.0, b = 10.0;
//    double epsilon = 0.0001;
//    double zeroValue = zeroFinder->calculate(a, b, linear, epsilon);
//
//    cout << "Derivative at x = " << x << " is: " << derivativeValue << endl;
//    cout << "Zero of the function in the interval [" << a << ", " << b << "] is approximately: " << zeroValue << endl;
//
//    delete linear;
//    delete derivative;
//    delete zeroFinder;
//
//}
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
                //func2();
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