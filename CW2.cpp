#include <iostream>

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
//    Shape* shape1 = new Rectangle("Rectangle", 3, 4);
//    Shape* shape2 = new Square("Square", 5);
//
//    cout << "Area of " << shape1->getName() << " is " << shape1->area() << endl;
//    cout << "Area of " << shape2->getName() << " is " << shape2->area() << endl;
//    delete shape1;
//    delete shape2;

    //b
//    Rectangle rect("Rectangle", 2, 4);
//    Square sq("Square", 4);
//
//    Shape& shape1 = rect;
//    Shape& shape2 = sq;
//
//    cout << "Area of " << shape1.getName() << " is " << shape1.area() << endl;
//    cout << "Area of " << shape2.getName() << " is " << shape2.area() << endl;

    //Zadziałały destruktory klas oprócz klasy Square. W przykładzie 'A' żaden destruktor nie zadziałał.

    //c
//    Rectangle rect("Rectangle", 2, 4);
//    Square sq("Square", 4);
//
//    Shape* shape1 = &rect;
//    Shape* shape2 = &sq;
//
//    cout << "Area of " << shape1->getName() << " is " << shape1->area() << endl;
//    cout << "Area of " << shape2->getName() << " is " << shape2->area() << endl;
//    //Nie pojawił się destruktor klasy Square. Żadnych innych zmian nie zaobserwowałem w porównaniu do podpunktu 'B'.

    //d
//Po zmianie dzieczenia na protected kod działa nie prawidłowo. Kompilator nie może wydobyć wartości z klasy rodzica.
};
int main(){
    int exNumber;
    do{
        cout << "Podaj numer zadania: 1,2,3 lub 5" << endl;
        cin >> exNumber;
        switch (exNumber) {
            case 1:{
                func1();
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 5:{
                break;
            }
        }
    }while(true);

    return 0;
}