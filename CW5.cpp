#include <iostream>
#include <vector>
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
    auto toDeleteVector = find(v.begin(), v.end(), *max_element(v.begin(), v.end()));

    auto toDeleteList = find(lists.begin(), lists.end(), *max_element(lists.begin(), lists.end()));

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
    set<int> uniq_val_list(lists.begin(), lists.end());
    for(auto it = uniq_val_list.begin(); it != uniq_val_list.end(); ++it){
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
//------------------------------------------
enum PlantType{Fruit, Vegetable};

struct Plant{
    PlantType type;
    string name;
    bool operator<(const Plant& p2) const{
        if (type < p2.type) {
            return true;
        } else if (type > p2.type) {
            return false;
        } else {
            return name < p2.name;
        }
    };
};
typedef set<Plant> Basket;

//Zadanie 8
ostream& operator<<(ostream& out, const Plant& plant) {
    if(plant.type == 0){
        out << "Typ: Fruit" << " Nazwa: " << plant.name << endl;
    }else if(plant.type == 1){
        out << "Typ: Vegetable" << " Nazwa: " << plant.name << endl;
    }
    return out;
};

ostream& operator<<(ostream& out, const Basket& basket) {
    for (auto it = basket.begin(); it != basket.end(); ++it) {
        out << *it << " ";
    }
    return out;
};



//Zadanie 9
bool is_there_a_pear(const Basket& basket) {
    auto it = find_if(basket.begin(), basket.end(), [](const Plant& plant) {
        return plant.name == "gruszka";
    });

    return it != basket.end();
};

//Zadanie 10
bool are_there_only_fruits(const Basket& basket) {
    return all_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Fruit; } );
}

bool are_there_only_vegetable(const Basket& basket) {
    return all_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Vegetable; } );
}

bool are_there_no_fruit(const Basket& basket) {
    return none_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Fruit; } );
}

bool are_there_no_vegetable(const Basket& basket) {
    return none_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Vegetable; } );
}

bool are_there_more_than_one_fruit(const Basket& basket) {
    return any_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Fruit; } );
}

bool are_there_more_than_one_vegetable(const Basket& basket) {
    return any_of(basket.begin(), basket.end(),
                       [](const Plant& plant) { return plant.type == PlantType::Vegetable; } );
}

//Zadanie 11
int count_fruits(const Basket& basket) {
    return count_if(basket.begin(), basket.end(), [](const Plant& plant) {
        return plant.type == Fruit;
    });
}

int count_vegetables(const Basket& basket) {
    return count_if(basket.begin(), basket.end(), [](const Plant& plant) {
        return plant.type == Vegetable;
    });
}
// Zadanie 12
void remove_plants_from_a(Basket &basket) {
    for (auto it = basket.begin(); it != basket.end();) {
        if (it->name[0] == 'A' || it->name[0] == 'a') {
            it = basket.erase(it);
        } else {
            ++it;
        }
    }
}
//Zadanie 13

void Gocha(){
    Basket basket;

    cout << "Ile owocow chcesz wsadzic do koszczyka? " << endl;
    int count;
    cin >> count;
    string typeFruit;
    string nameFruit;

    for(int i = 0; i < count; i++){
        cout << "Podaj czy jest to owoc czy warzywo: " << endl;
        cin >> typeFruit;
        cout << "Podaj nazwe owoca lub warzywa: " << endl;
        cin >> nameFruit;

        if(typeFruit == "warzywo"){
            basket.insert({PlantType::Vegetable, nameFruit});
        }else if(typeFruit == "owoc"){
            basket.insert({PlantType::Fruit, nameFruit});
        }else{
            cout << "Nie poprawne dane." << endl;
        }

    }

    cout << basket << endl;
    bool hasPear = is_there_a_pear(basket);
    bool test = are_there_no_vegetable(basket);
    cout << test;
    cout << endl;
    //Zadanie 11
    int fruitCount = count_fruits(basket);
    int vegetableCount = count_vegetables(basket);

    cout << "Liczba owocow: " << fruitCount << endl;
    cout << "Liczba warzyw: " << vegetableCount << endl;


    Basket martaBasket;
    cout << "Uzupelniamy koszyk Marty." << endl;
    cout << "Podaj ile chcesz wsadzic owocow." << endl;
    cin >> count;
    for(int i = 0; i < count; i++){
        cout << "Podaj czy jest to owoc czy warzywo: " << endl;
        cin >> typeFruit;
        cout << "Podaj nazwe owoca lub warzywa: " << endl;
        cin >> nameFruit;

        if(typeFruit == "warzywo"){
            basket.insert({PlantType::Vegetable, nameFruit});
        }else if(typeFruit == "owoc"){
            basket.insert({PlantType::Fruit, nameFruit});
        }else{
            cout << "Nie poprawne dane." << endl;
        }

    }

    //Zadanie 13
    cout << "Usuwanie zawartosci koszyka dla owocow na litere A" << endl;
    remove_plants_from_a(martaBasket);
    cout << "Wyswietlenie z usunietymi owocami: " << endl;
    cout << martaBasket;
    //Zadanie 14
    Basket common_basket;

    set_intersection(basket.begin(), basket.end(), martaBasket.begin(), martaBasket.end(), inserter(common_basket, common_basket.end()));
    cout << "Elementy wspolne w dwuch koszykach." << endl;
    cout << common_basket << endl;

    //Zadanie 15
    Basket bigBasket;
    set_union(basket.begin(), basket.end(),martaBasket.begin(), martaBasket.end(),inserter(bigBasket, bigBasket.end()));
    cout << "Zlaczone koszyki: " << endl;
    cout << bigBasket;
    cout << endl;
};


int main(){
    int exNumber;
    do{
        cout << "Pick the number of exercise from 1 to 15:" << endl;
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
            case 7: {
                Gocha();

                break;
            }
        }
    }while(true);
}
