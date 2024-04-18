#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//------------------Zadanie1------------------------------------------------------------------------------------------------------------------------------------------
class Bryla_z_Kwadratu {
protected:
    int a{ 0 };
    double objetosc{ 0 };
public:
    Bryla_z_Kwadratu(int a_) : a(a_) {}
    virtual ~Bryla_z_Kwadratu() {}
    virtual double oblicz_objetosc() = 0;

};

class Stozki_przez_Obrot : public Bryla_z_Kwadratu{
    double wysokosc{ 0 };
public:
    Stozki_przez_Obrot(int a_) : Bryla_z_Kwadratu(a_) {
        wysokosc = ((a_ * sqrt(2)) / 2);
    }

    ~Stozki_przez_Obrot() {}

    double oblicz_objetosc() {
        return 2 * ((1.0/3.0)*3.14*pow((a * sqrt(2) / 2),2)) *wysokosc;
    }

    Stozki_przez_Obrot operator+=(double proc) {
        return wysokosc += wysokosc * (proc / 100);
    }

    friend ostream& operator<<(ostream& s, Stozki_przez_Obrot& stozek) {
        return s << "Dlugosc boku szescianu: " << stozek.a << "\n Wysokosc stozka: " << stozek.wysokosc << "\n Objetosc bryly: " << stozek.oblicz_objetosc() << "\n";
    }
};


void func1() {
    Stozki_przez_Obrot stozek(7);

    cout << stozek;

    stozek += 2;

    cout << "Stozek po zwiekszeniu: " << endl << stozek;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------


//------------------Zadanie2------------------------------------------------
class Pojemnik_Bryl {
public:
    map <int, Stozki_przez_Obrot*> bryly;
    Pojemnik_Bryl() {}
    ~Pojemnik_Bryl() {}
};

void func2() {
    ifstream file;
    string line;
    file.open("./dane.txt");
    Pojemnik_Bryl pojemnik;

    while (getline(file, line)) {
        Stozki_przez_Obrot* stozek = new Stozki_przez_Obrot(stoi(line));
        int i = 0;
        while (true) {
            if (pojemnik.bryly.find(ceil(stozek->oblicz_objetosc()) + i) != pojemnik.bryly.end()) {
                i++;
            }
            else {
                pojemnik.bryly.insert({ ceil(stozek->oblicz_objetosc()) + i, stozek });
                break;
            }
        }
        delete stozek;
    }

    file.close();
    for (auto it = pojemnik.bryly.begin(); it != pojemnik.bryly.end(); it++) {
        cout << it->first << endl;
    }

//-------------------------------Zadanie3-------------------------------------------------
    bool found = false;

    for (auto it = pojemnik.bryly.begin(); it != pojemnik.bryly.end(); ++it) {
        if (it->second->oblicz_objetosc() >= 100) {
            found = true;
            break;
        }
    }

    if (!found) {
        //throw runtime_error("Nie znaleziono bryły z objętością większą lub równą 100.");
    }
    else {
        cout << "Znaleziono bryle z wieksza objetascia" << endl;
    }

    vector<Stozki_przez_Obrot*> bryly_do_operacji;
    for (auto it = pojemnik.bryly.begin(); it != pojemnik.bryly.end(); ++it) {
        if (it->second->oblicz_objetosc() >= 100) {
            bryly_do_operacji.push_back(it->second);
        }
    }

    for (auto& bryla : bryly_do_operacji) {
        *bryla += 30;
    }


    sort(bryly_do_operacji.begin(), bryly_do_operacji.end(),
         [](Stozki_przez_Obrot* a, Stozki_przez_Obrot* b) {
             return ceil(a->oblicz_objetosc()) < ceil(b->oblicz_objetosc());
         });
    for (auto& bryla : bryly_do_operacji) {
        cout << *bryla << endl;
    }
}



int main() {
    do {
        int exNum{0};
        cout << "Wybierz zadanie od 1 do 2: " << "\n";
        cin >> exNum;
        switch (exNum)
        {
            case 1: {
                func1();
                break;
            }
            case 2: {
                try {
                    func2();
                }
                catch (const exception& e) {
                    cerr << "Wyjatek: " << e.what() << endl;
                }

                break;
            }
            default:
                break;
        }
    } while (true);
}
