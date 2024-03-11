#include <iostream>
#include <cmath>

using namespace std;

//Zadanie 1
class Shape{
protected:
    string name;
public:
    Shape(string name_) : name(name_){
        cout << "Shape constructor." << endl;
    }
    ~Shape(){
        cout << "Shape destructor." << endl;
    }

    void setName(string val){
        name = val;
    }

    string getName(){
        return name;
    }

    virtual double area() = 0;
};

class Rectangle : public Shape{
protected:
    double width, height;
public:
    Rectangle(string name_, double width_, double height_) : Shape(name_), width(width_), height(height_){
        cout << "Rectangle constructor." << endl;
    }
    ~Rectangle(){
        cout << "Rectangle destructor." << endl;
    }
    double area(){
        return width*height;
    }
};

class Square : public Rectangle{
public:
    Square(string name_, double width_) : Rectangle(name_, width_, width_){
        cout << "Square constructor." << endl;
    }
    ~Square(){
        cout << "Square destructor." << endl;
    }

    double area(double val){
        return val*val;
    }

};

void func1(){
    //a
    Shape* shape1 = new Rectangle("Rectangle", 3, 4);
    Shape* shape2 = new Square("Square", 5);

    cout << "Area of " << shape1->getName() << " is " << shape1->area() << endl;
    cout << "Area of " << shape2->getName() << " is " << shape2->area() << endl;
    delete shape1;
    delete shape2;

    //b
    Rectangle rect("Rectangle", 2, 4);
    Square sq("Square", 4);

    Shape& shape3 = rect;
    Shape& shape4 = sq;

    cout << "Area of " << shape3.getName() << " is " << shape3.area() << endl;
    cout << "Area of " << shape4.getName() << " is " << shape4.area() << endl;

    //Zadziałały destruktory klas oprócz klasy Square. W przykładzie 'A' żaden destruktor nie zadziałał.

    //c

    Shape* shape5 = &rect;
    Shape* shape6 = &sq;

    cout << "Area of " << shape5->getName() << " is " << shape5->area() << endl;
    cout << "Area of " << shape6->getName() << " is " << shape6->area() << endl;
    //Nie pojawił się destruktor klasy Square. Żadnych innych zmian nie zaobserwowałem w porównaniu do podpunktu 'B'.

    //d
//Po zmianie dzieczenia na protected kod działa nie prawidłowo. Kompilator nie może wydobyć wartości z klasy rodzica.
};

//Zadanie 2
class Circle:public Shape{
    double radius, diameter;
public:
    Circle(string name, double radius_):Shape(name), radius(radius_){
        diameter = 2 * radius;
        cout<<"Circle constuctor "<<getName()<<endl;

    }
    ~Circle(){
        cout<<"Circle destructor "<<getName()<<endl;
    }
    double area(){
        return M_PI * radius * radius;
    }
    double getRadius(){
        return radius;
    }

};

class Cylinder: public Circle{
    double height;
public:
    Cylinder(string name, double radius_, double height_):Circle(name,radius_), height(height_){
        cout<<"Cylinder constructor "<<getName()<<endl;
    }
    ~Cylinder(){
        cout<<"Cylider destructor "<<getName()<<endl;
    }
    double volume(){
        return M_PI * height * getRadius() * getRadius();
    }

    double area(){
        return (2*M_PI*getRadius()*height) + (2*M_PI*getRadius() * getRadius());
    }

};

void func2(){
    Circle c1("cir1", 5);
    cout<<"Area of: "<<c1.area()<<endl;
    Cylinder cy1("cyli1", 5, 10);
    cout<<"Area of: "<<cy1.area()<<" volume of cylider is: "<<cy1.volume()<<endl;
}

//Zadanie 3

class Funtion{
public:
    Funtion() = default;
    virtual ~Funtion() = default;
    virtual float calculate(float x) = 0;
};

class LinearFunction : public Funtion{
private:
    float a, b;
public:
    LinearFunction(float a_, float b_) : a(a_), b(b_){}
    virtual ~LinearFunction(){}
    float calculate(float x) {
        return a * x + b;
    }
};

void func3(){
    float A, B, X;
    cout << "Values of A and B is: " << endl;
    cin >> A >> B ;

    LinearFunction linear(A, B);

    cout << "Value of X is : " << endl;
    cin >> X;

    cout << "Result is:  "<< linear.calculate(X) << endl;

};


int main(){
    int exNumber;
    do{
        cout << "Pick the number of exercise: 1,2,3 or 5" << endl;
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
            case 3:{
                func3();
                break;
            }
            case 5:{
                break;
            }
        }
    }while(true);
}