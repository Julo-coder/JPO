#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <random>
#include <algorithm>
#include <set>

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
    auto highestVal = v.begin();

    for(auto i = v.begin(); i != v.end(); i++){
        if(*highestVal < *i){
            highestVal = i;
        }
    }
    v.erase(highestVal);

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

    auto highestVal = lists.begin();
    for(auto i = lists.begin(); i != lists.end(); i++){
        if(*highestVal < *i){
            highestVal = i;
        }
    }
    lists.erase(highestVal);
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
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów: " << endl;

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }


    cout << endl << "Usuwanie największego skladnika z tablicy : ";
    auto highestValVec = max_element(v.begin(), v.end());
    auto toDeleteVector = find(v.begin(), v.end(), *highestValVec);

    auto highestValList = max_element(lists.begin(), lists.end());
    auto toDeleteList = find(lists.begin(), lists.end(), *highestValList);

    v.erase(toDeleteVector);
    lists.erase(toDeleteList);

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
    set<int> uniq_val(v.begin(), v.end());
    for(auto i = uniq_val.begin(); i != uniq_val.end(); i++){
        int count_2 = count(v.begin(), v.end(), *i);
        cout << "Liczba " << *i << " występuje " << count_2 << endl;
    }
    cout << "Wyświetlenie zawartość występowania liczb w tablicy typu list: " << endl;
    auto it = unique(lists.begin(), lists.end());
    lists.erase(it, lists.end());
    for(auto it = lists.begin(); it != lists.end(); ++it){
        int count_2 = count(lists.begin(), lists.end(), *it);
        cout << "Liczba " << *it<< " występuje " << count_2 << endl;
    }
    cout << endl;
}

void func6(){
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
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów PRZED SORTOWANIEM: " << endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów PRZED SORTOWANIEM: " << endl;
    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }
    //Sortowanie
    sort(v.begin(), v.end());
    lists.sort();

    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów PO SOROTWANIU: " << endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów PO SORTOWANIU: " << endl;
    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }
//Sortowanie malejąco
    sort(v.begin(), v.end(), greater<>());
    lists.sort(greater<>());

    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów PO SOROTWANIU MALEJĄCO: " << endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów PO SORTOWANIU MALEJĄCO: " << endl;
    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }
//Sortowanie od najmniejszej do największej warotści bezwzględnej
    sort(v.begin(), v.end(), [](int a, int b) {
        return abs(a) > abs(b);
    });

    lists.sort([](int a, int b) {
        return abs(a) > abs(b);
    });
    cout << endl << "Wyświetlenie tablicy typu vector z wykorzystaniem iteratorów PO SOROTWANIU PO WARTOŚCI BEZWZGLĘDNEJ: " << endl;
    for(auto i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl << "Wyświetlenie tablicy typu list z wykorzystaniem iteratorów PO SORTOWANIU PO WARTOŚCI BEZWZGLĘDNEJ: " << endl;
    for(auto i = lists.begin(); i != lists.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
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
                func6();
                break;
            }
        }
    }while(true);
}
