#include <iostream>
#include <memory>

using namespace std;

//Zadanie 1
struct VerboseObject{
    string nazwaObiektu;
    VerboseObject(string nazwa) : nazwaObiektu(nazwa){
        cout << "Konstruktor wywolany"<< " " << nazwaObiektu<< endl;
    }

    ~VerboseObject(){
        cout << "Destruktor wywolany" << " " << nazwaObiektu << endl;
    }

    void wyswietl(){
        cout << "Metoda na strukturze" << " " << nazwaObiektu << endl;
    }

    //Kontruktory tworzą obiekty według kolejnosci lecz destruktory zwalniaja pamięć na podstawie kolejności w stercie i stosie.
};

//Zadanie 2
struct BinomialSolver{
    double wspolA;
    double wspolB;
    double wspolC;
    BinomialSolver (int a, int b, int c) : wspolA(a), wspolB(b), wspolC(c){};


    double zwrocA() const{
        return wspolA;
    }

    double zwrocB() const{
        return wspolB;
    }

    double zwrocC() const{
        return wspolC;
    }


};

//Zadanie 8
class BSTree{
    int val;
    BSTree *left;
    BSTree *right;
public:
    BSTree();
    ~BSTree();
    bool isEmpty();
    void insert(int);
    bool contains(int);
    void clean();
    void printInOrder();

};

BSTree::BSTree() {};
BSTree::~BSTree(){};
bool BSTree::isEmpty(){

};
void BSTree::insert(int) {};
bool BSTree::contains(int) {};
void BSTree::clean() {};
void BSTree::printInOrder(){};

//Zadanie 13
class Sorting {
public:
    Sorting();
    void bubbleSort(int[], int);
    void heapSort(int[], int);
    void quickSort(int[], int, int);
    void display(int [], int);
};

Sorting::Sorting() {}

void Sorting::bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
};

void Sorting::display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void heapify(int arr[], int size, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
};

void Sorting::heapSort(int arr[], int size){
    for(int i = size / 2 - 1; i >=0; i--)
        heapify(arr, size, i);
    for(int j = size - 1; j >= 0; j--){
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
};

int partition(int arr[],int start, int end){
    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++){
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
};


void Sorting::quickSort(int arr[], int start, int end){
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
};

int main(){
    int nrZadania;

    do{
        cout << "Podaj numer zadania: " << endl;
        cin >> nrZadania;

        switch(nrZadania){
            case 1:{

                cout << "Podaj nazwe obiektu: " << endl;
                string nazwa;
                cin >> nazwa;
                VerboseObject obiekt1(nazwa);
                obiekt1.wyswietl();

                unique_ptr<VerboseObject> obiekt2( new VerboseObject(nazwa));
                obiekt2->wyswietl();

                VerboseObject * obiekt3 = new VerboseObject(nazwa);
                obiekt3->wyswietl();
                delete obiekt3;


                break;
            }
            case 8:{
                break;
            }

            case 13:{
                int range = 1000;
                int size = 300;

                Sorting sort;

                for (int i = 0; i < range; ++i) {
                    int* arr = new int[size];
                    for (int j = 0; j < size; ++j) {
                        arr[j] = rand() % range;
                    }
                    sort.display(arr, size);
                    cout << endl;
                    sort.heapSort(arr, size);
                    sort.bubbleSort(arr, size);
                    sort.quickSort(arr, size-1, 0);
                    sort.display(arr,size);
                    delete[] arr;
                }
                return 0;
                break;
            }
        }
    }while(true);

}