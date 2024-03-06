#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

//Zadanie 1
struct VerboseObject {
    string objectName;
    VerboseObject(string name) : objectName(name) {
        cout << "Konstruktor wywolany" << " " << objectName << endl;
    }

    ~VerboseObject() {
        cout << "Destruktor wywolany" << " " << objectName << endl;
    }

    void show() {
        cout << "Metoda na strukturze" << " " << objectName << endl;
    }

    //Kontruktory tworzą obiekty według kolejnosci lecz destruktory zwalniaja pamięć na podstawie kolejności w stercie i stosie.
};

//Zadanie 2
struct BinomialSolver {
    double factA, factB, factC;

    double x1, x2, x0;
    BinomialSolver(double a, double b, double c) : factA(a), factB(b), factC(c) {};


    double returnA() const {
        return factA;
    }

    double returnB() const {
        return factB;
    }

    double returnC() const {
        return factC;
    }

    double returnX1() {
        return x1;
    }

    double returnX2() {
        return x2;
    }

    double returnX0(){
        return x0;
    }

    void solveEquation() {
        double delta = factB * factB - 4 * factA * factC;
        if (delta > 0) {
            x1 = ((-factB + sqrt(delta))/ (2 * factA));
            x2 = ((-factB - sqrt(delta)) / (2 * factA));
        }
        else if (delta == 0) {
            x0 = -factB / (2 * factA);
        }
        else {
            x1 = NAN;
            x2 = NAN;
            x0 = NAN;
        }
    }

    double calculate(double x) {
        return factA * x * x + factB * x + factC;
    }


};

//Zadanie 3
struct Complex {
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {};

    double modulus() {
        return sqrt(real * real + imag * imag);
    }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    double getRe(){
        return real;
    }

    double getIm(){
        return imag;
    }

    void setRe(double val){
        real = val;
    }

    void setIm(double val){
        imag = val;
    }
};

//Zadanie 8
class BSTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void clearRecursive(Node* node) {
        if (node) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

    void printInorderRec(Node* node) {
        if (node) {
            printInorderRec(node->left);
            cout << node->data;
            printInorderRec(node->right);
        }
    }

public:
    BSTree() : root(nullptr) {}
    ~BSTree() {
        clear();
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void insert(int val) {
        Node** current = &root;
        while (*current) {
            if (val < (*current)->data) {
                current = &((*current)->left);
            }
            else {
                current = current = &((*current)->right);
            }
        }
        *current = new Node(val);
    }

    bool contains(int val) {
        Node* current = root;
        while (current) {
            if (val == current->data) {
                return true;
            }
            else if (val < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    void clear() {
        clearRecursive(root);
        root = nullptr;
    }

    void printInOrder() {
        printInorderRec(root);
    }
};

//Zadanie 13
class Sorting {
public:
    static double measurement(vector<int>& arr, void (*sortFunction)(vector<int>&)) {
        clock_t start = clock();
        sortFunction(arr);
        clock_t end = clock();
        return double(end - start) / CLOCKS_PER_SEC;
    }

    static void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void heapSort(vector<int>& arr) {
        make_heap(arr.begin(), arr.end());
        sort_heap(arr.begin(), arr.end());
    }

    static void quickSort(vector<int>& arr) {
        sort(arr.begin(), arr.end());
    }
};

void func1(){
    cout << "Podaj nazwe obiektu: " << endl;
    string name;
    cin >> name;
    VerboseObject obj1(name);
    obj1.show();

    unique_ptr<VerboseObject> obj2(new VerboseObject(name));
    obj2->show();

    VerboseObject* obj3 = new VerboseObject(name);
    obj3->show();
    delete obj3;
}

void func2(){
    BinomialSolver b1(1.0, -5.0, 4.0);
    cout << "Roots of the equation x*x - 5x + 4 = 0 are: " << endl;
    cout << "x1 = " << b1.returnX1() << ", x2 = " << b1.returnX2() << endl;
    cout << "The value of the polynomial x*x - 5x + 4 at x = 1 is: ";
    cout << b1.calculate(1.0) << endl;
    cout << "The value of the polynomial x*x - 5x + 4 at x = 3 is: ";
    cout << b1.calculate(3.0) << endl;
    BinomialSolver b2(1.0, 2.0, 1.0);
    cout << "Roots of the equation x*x + 2x + 1 = 0 are: " << endl;
    cout << "x1 = " << b2.returnX1() << ", x2 = " << b2.returnX2() << endl;
    cout << "The value of the polynomial x*x + 2x + 1 at x = 1 is: ";
    cout << b2.calculate(1.0) << endl;
    cout << "The value of the polynomial x*x + 2x + 1 at x = -1 is: ";
    cout << b2.calculate(-1.0) << endl;
}

void func3(){
    vector<Complex> numbers;
    double real, imag;
    ifstream inputFile("File name");

    if (!inputFile.is_open()) {
        cout << "Nie można otworzyć pliku." << endl;
    }

    while (inputFile >> real >> imag) {
        numbers.emplace_back(real, imag);
    }

    inputFile.close();
    if (numbers.empty()) {
        cout << "Brak danych." << endl;
    }

    Complex sum(0, 0), product(1, 1);
    double maxModulus = 0;
    Complex maxModulusNumber(0, 0);

    for (auto& num : numbers) {
        sum = sum + num;
        product = product * num;
        double modulus = num.modulus();
        if (modulus > maxModulus) {
            maxModulus = modulus;
            maxModulusNumber = num;
        }
    }

    cout << "Suma: " << sum.getRe() << (sum.getIm() >= 0 ? "+" : "") << sum.getIm() << "i" << endl;
    cout << "Iloczyn: " << product.getRe() << (product.getIm() >= 0 ? "+" : "") << product.getIm() << "i" << endl;
    cout << "Liczba z największym modułem: " << maxModulusNumber.getRe() << (maxModulusNumber.getIm() >= 0 ? "+" : "") << maxModulusNumber.getIm() << "i" << endl;

}

void func4(){
    double A, B, C, eps;
    int precision;

    cin >> A >> B >> C >> eps;

    precision = abs(static_cast<int>(log10(eps)));

    BinomialSolver binomial(A,B,C);
    binomial.solveEquation();

    if(!isnan(binomial.returnX1())){
        if(binomial.returnX1() > binomial.returnX2()){
            cout << fixed << setprecision(precision) << binomial.returnX1() << endl;
        }else{
            cout << fixed << setprecision(precision) << binomial.returnX2() << endl;
        }
    }
}

void func8(){
    BSTree bst;
    std::cout << (bst.isEmpty() ? "Tree is empty" : "Tree is not empty") << std::endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);
    std::cout << (bst.isEmpty() ? "Tree is empty" : "Tree is not empty") << std::endl;
    std::cout << "Tree contains element with the value of 3 : " << bst.contains(3) << std::endl;
    std::cout << "Tree contains element with the value of 9 : " << bst.contains(9) << std::endl;
    bst.printInOrder();
    std::cout << std::endl;
    bst.clear();
    std::cout << (bst.isEmpty() ? "Tree is empty" : "Tree is not empty") << std::endl;

}

void func13(){
    const int numArrays = 1000;
    const int arraySize = 300;
    const int range = 1000;

    double avgTimeBubble = 0.0;
    double avgTimeHeap = 0.0;
    double avgTimeQuick = 0.0;

    for (int i = 0; i < numArrays; ++i) {
        vector<int> arr(arraySize);
        for (int j = 0; j < arraySize; ++j) {
            arr[j] = rand() % range;
        }

        avgTimeBubble += Sorting::measurement(arr, Sorting::bubbleSort);
        avgTimeHeap += Sorting::measurement(arr, Sorting::heapSort);
        avgTimeQuick += Sorting::measurement(arr, Sorting::quickSort);
    }

    avgTimeBubble /= numArrays;
    avgTimeHeap /= numArrays;
    avgTimeQuick /= numArrays;

    cout << "BS: " << avgTimeBubble << "\n";
    cout << fixed << "HS: " << avgTimeHeap << "\n";
    cout << fixed << "QS: " << avgTimeQuick << "\n";
};

int main() {
    int exNumber;

    do {
        cout << "Podaj numer zadania: " << endl;
        cin >> exNumber;

        switch (exNumber) {
            case 1: {
                func1();
                break;
            }
            case 2: {
                func2();
                break;
            }
            case 3: {
                func3();
                break;
            }
            case 4: {
                func4();
                break;
            }
            case 8: {
                func8();
                break;
            }
            case 13: {
                func13();
                break;
            }
        }
    } while (true);
}