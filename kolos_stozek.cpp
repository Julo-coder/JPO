#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;
//--------------------------Zadanie1------------------------------------------------------------------
class Przekroj_Stozka {
protected:
    int r{ 0 };
    int h{ 0 };
    double pole_powierzchni{ 0 };
public:
    Przekroj_Stozka(int r_, int h_) : r(r_), h(h_){}
    virtual ~Przekroj_Stozka() {}
    virtual double oblicz_pole() = 0;
};

class Przekroj_nad_Podstawa : public Przekroj_Stozka{
    double odleglosc{ 0 };
public:
    Przekroj_nad_Podstawa(int r_, int h_, double odl_) : Przekroj_Stozka(r_, h_), odleglosc(odl_) {}
    ~Przekroj_nad_Podstawa() {}
    double oblicz_pole() {
        pole_powierzchni = 3.14 * (pow(odleglosc,2)/pow(h,2)) * pow(r,2);
        return pole_powierzchni;
    }

    friend double operator-=(Przekroj_nad_Podstawa& p, double k) {
        if (k + p.odleglosc < p.h) {
            return p.odleglosc += k;
        }
        else {
            cout << "Odleglosc przekracza wysokosc stozka!!!!!!!" << endl;
            return p.odleglosc;
        }
    }

    friend ostream& operator<<(ostream& s, Przekroj_nad_Podstawa& p) {
        return s << "Promien: " << p.r << " Wysokosc: " << p.h << " Odleglosc: " << p.odleglosc << " Pole powierzchni: " << p.oblicz_pole() << endl;
    }
};


void func1() {
    Przekroj_nad_Podstawa przek(5, 8, 3.5);
    cout << przek;

    cout << "Modyfikacja odleglosci: " << endl;
    przek -= 2.4;

    cout << przek;
}

//----------------------Zadanie2-----------------------------------------

class Pojemnik_Figur {
public:
    map <double, Przekroj_nad_Podstawa*> figury;
    Pojemnik_Figur() {}
    ~Pojemnik_Figur() {}
};

void func2() {
    Pojemnik_Figur pojemnik;

    ifstream file;
    file.open("./dane.txt");
    string line;
    while (getline(file, line)) {

        istringstream ss(line);
        int prom, wys;
        double odl;
        ss >> prom >> wys >> odl;

        Przekroj_nad_Podstawa* przekroj = new Przekroj_nad_Podstawa(prom, wys, odl);

        int i = 0;
        double klucz = floor(przekroj->oblicz_pole()) - i + 1;

        while (pojemnik.figury.find(klucz) != pojemnik.figury.end()) {
            klucz = ceil(przekroj->oblicz_pole()) - i;
            i++;
        }

        if (klucz != 0) {
            pojemnik.figury.insert({ klucz, przekroj });
        }
        else {
            cout << "Klucz rowny 0, pomijam dodanie do mapy" << endl;
            delete przekroj;
        }


    }
    file.close();


    for (auto it = pojemnik.figury.begin(); it != pojemnik.figury.end(); it++) {
        cout << it->first <<  " " << *it->second << endl;
    }

}



int main()
{
    do {
        int exNum;
        cout << "Wprowadz numer zadania: 1 lub 2: " << endl;
        cin >> exNum;
        switch (exNum)
        {
            case 1: {
                func1();
                break;
            }
            case 2: {
                func2();
                break;
            }
            default:
                break;
        }
    } while (true);

}

//Logowanie do chata i google:
//login: chatchatowy3@gmail.com
//haslo: zaq1@WSX