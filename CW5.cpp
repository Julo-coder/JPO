#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

int randomNum(int min, int max){
    random_device rd;
    uniform_int_distribution<int> dist(min, max);
    return dist(rd);
}

void func1(){
    int max, min, quan;
    cout << "Podaj wielkość tablicy wektor: " << endl;
    cin >> quan;

    vector<int> v(quan);
    cout << "Podaj minimalną liczbę do zakresu generowania liczb: " << endl;
    cin >> min;
    cout << "Podaj maksymalną liczbę do zakresu generowania liczb: " << endl;
    cin >> max;

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        v[i] = randNumber;
    }

    cout << "Wyświetlenie tablicy typu vector za pomocą operatora indeksowania: " << endl;
    for(int i = 0; i < quan; i ++){
        cout << v[i] << ' ';
    }
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    cout << endl << "Usuwanie największego skladnika z tablicy : " << endl;

    auto toDelete = max_element(v.begin(), v.end());

    if(toDelete != v.end()){
        v.erase(toDelete);
    }

    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    cout << endl;
}


void func2(){
    int max, min, quan;
    cout << "Podaj wielkość kontenera list: " << endl;
    cin >> quan;

    list<int> lists;
    cout << "Podaj minimalną liczbę do zakresu generowania liczb: " << endl;
    cin >> min;
    cout << "Podaj maksymalną liczbę do zakresu generowania liczb: " << endl;
    cin >> max;

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        lists.push_back(randNumber);
    }
//    cout << "Wyświetlenie tablicy typu vector za pomocą operatora indeksowania: " << endl;
//    for(int i = 0; i < quan; i ++){
//        cout << lists[i] << ' ';
//    }
    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów: " << endl;

    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }

    cout << endl << "Znajdowanie największego i usuwanie go z tablicy: " << endl;

    auto toDelete = max_element(lists.begin(), lists.end());

    if(toDelete != lists.end()){
        lists.erase(toDelete);
    }


    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }

    cout << endl;
}

void func3(){
    int max, min, quan;
    cout << "Podaj wielkość kontenera list: " << endl;
    cin >> quan;

    list<int> lists;
    vector<int> v(quan);
    cout << "Podaj minimalną liczbę do zakresu generowania liczb: " << endl;
    cin >> min;
    cout << "Podaj maksymalną liczbę do zakresu generowania liczb: " << endl;
    cin >> max;

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        v[i] = randNumber;
    }
    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        lists.push_back(randNumber);
    }

    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów: " << endl;

    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }

    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    auto listMax = max_element(lists.begin(), lists.end());
    auto listMin = min_element(lists.begin(), lists.end());
    auto vectorMax = max_element(lists.begin(), lists.end());
    auto vectorMin = min_element(lists.begin(), lists.end());

    cout << endl << "Maksymalna wartość z listy: " << *listMax << endl << "Maksymalna wartość z vectora: " << *vectorMax << endl;
    cout << "Minimalna wartość z listy: " << *listMin << endl << "Minimalna wartość z vectora: " << *vectorMin << endl;


    cout << endl;
}

void func4(){
    int max, min, quan;
    cout << "Podaj wielkość tablicy wektor: " << endl;
    cin >> quan;

    vector<int> v(quan);
    cout << "Podaj minimalną liczbę do zakresu generowania liczb: " << endl;
    cin >> min;
    cout << "Podaj maksymalną liczbę do zakresu generowania liczb: " << endl;
    cin >> max;

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        v[i] = randNumber;
    }
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    int highestVal{0};

    for(auto i = v.begin(); i != v.end(); i++){
        if(highestVal < *i){
            highestVal = *i;
        }
    }

    cout << endl << "Usuwanie największego skladnika z tablicy : ";
    auto toDelete = find(v.begin(), v.end(), highestVal);

    if(toDelete != v.end()){
        v.erase(toDelete);
    }
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów po usuwaniu: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    cout << endl;
}

void func5(){
    int max, min, quan;
    cout << "Podaj wielkość tablicy wektor i listy: " << endl;
    cin >> quan;

    vector<int> v(quan);
    list<int> lists;
    cout << "Podaj minimalną liczbę do zakresu generowania liczb: " << endl;
    cin >> min;
    cout << "Podaj maksymalną liczbę do zakresu generowania liczb: " << endl;
    cin >> max;

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        v[i] = randNumber;
    }

    for(int i = 0; i < quan; i++){
        int randNumber = randomNum(min, max);
        lists.push_back(randNumber);
    }
    cout << "Wyświetlenie zawartość występowania liczb w tablicy typu wektor: " << endl;
    for(auto i = v.begin(); i != v.end(); i++){
        int count_2 = count(v.begin(), v.end(), *i);
        cout << "Liczba " << *i << " występuje " << count_2 << endl;
    }
    cout << "Wyświetlenie zawartość występowania liczb w tablicy typu list: " << endl;
    for(auto i = lists.begin(); i != lists.end(); i++){
        int count_2 = count(lists.begin(), lists.end(), *i);
        cout << "Liczba " << *i << " występuje " << count_2 << endl;
    }
    cout << endl;
}

void func6(){

}
int main(){
    int exNumber;
    do{
        cout << "Pick the number of exercise from 1 to 6:" << endl;
        cin >> exNumber;
        switch (exNumber) {
            case 1: {
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
            case 4:{
                func4();
                break;
            }
            case 5:{
                func5();
                break;
            }
            case 6:{
                //func6();
                break;
            }
        }
    }while(true);
}
