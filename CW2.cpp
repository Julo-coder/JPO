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

class Function{
public:
    Function() = default;
    virtual ~Function() = default;
    virtual float calculate(float x) = 0;
};

class LinearFunction : public Function{
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

//Zadanie 4
class Rim{
private:
    double weight, rim_width, rim_diameter;
public:
    Rim(double weight_, double rim_width_, double rim_diameter_) : weight(weight_), rim_width(rim_width_), rim_diameter(rim_diameter_){}
    ~Rim(){}

    double getRimWeight(){
        return weight;
    }

    double getRimWidth(){
        return rim_width;
    }

    double getRimDiameter(){
        return rim_diameter;
    }
};

class Tire{
private:
    double weight, tire_width, tire_diameter;
public:
    Tire(double weight_, double tire_width_, double tire_diameter_) : weight(weight_), tire_width(tire_width_), tire_diameter(tire_diameter_){}
    ~Tire(){}

    double getTireWeight(){
        return weight;
    }

    double getTireWidth(){
        return  tire_width;
    }

    double getTireDiameter(){
        return tire_diameter;
    }

};

class Wheel{
private:
    Rim* rim;
    Tire* tire;
    double wheel_weight;
public:
    Wheel() : tire(nullptr), rim(nullptr), wheel_weight(0.0) {}

    void setWheelWeight(){
        wheel_weight = 0.0;
        if (rim != nullptr) wheel_weight += rim->getRimWeight();
        if (tire != nullptr) wheel_weight += tire->getTireWeight();
    }

    void put_on_Rim(Rim& r){
        rim = &r;
        setWheelWeight();
    }

    void mount_Tire(Tire& t){
        if(t.getTireDiameter() != rim->getRimDiameter() || abs(rim->getRimDiameter() - t.getTireDiameter()) > 10){
            cout << "Niestety nie mozna zamontowac opony na felge." << endl;
        }else{
            tire = &t;
            setWheelWeight();
            cout << "Opona zamontowana na felge." << endl;
        }
    }

    double total_mass(){
        return wheel_weight;
    }

    double rolling_friction(Rim& r, Tire& t, double N){
        N -= total_mass();
        double f = 0.8;
        return (f*N) / (r.getRimDiameter()+t.getTireDiameter());
    }
};

void func5(){
    Rim rim(5.5, 200, 16);
    Tire tire(10.0, 205, 16);

    Wheel wheel;

    wheel.put_on_Rim(rim);
    wheel.mount_Tire(tire);
    cout << wheel.rolling_friction(rim, tire, 1800) << endl;

}
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
                func5();
                break;
            }
        }
    }while(true);
}