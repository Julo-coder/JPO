#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>

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

    void solveEquation() {
        double delta = factB * factB - 4 * factA * factC;
        if (delta > 0) {
            x1 = (-factB + sqrt(delta) / (2 * factA));
            x2 = (-factB - sqrt(delta) / (2 * factA));
        }
        else if (delta == 0) {
            x0 = -factB / 2 * factA;
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

//Zadanie 8

//Zadanie 13
class Sorting {
public:
    static double measurement(std::vector<int>& arr, void (*sortFunction)(std::vector<int>&)) {
        std::clock_t start = std::clock();
        sortFunction(arr);
        std::clock_t end = std::clock();
        return double(end - start) / CLOCKS_PER_SEC;
    }

    static void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void heapSort(std::vector<int>& arr) {
        std::make_heap(arr.begin(), arr.end());
        std::sort_heap(arr.begin(), arr.end());
    }

    static void quickSort(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
    }
};

int main() {
    int exNumber;

    do {
        cout << "Podaj numer zadania: " << endl;
        cin >> exNumber;

        switch (exNumber) {
            case 1: {
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

                break;
            }
            case 2: {
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
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 8: {
                break;
            }

            case 13: {
                const int numArrays = 1000;
                const int arraySize = 300;
                const int range = 1000;

                double avgTimeBubble = 0.0;
                double avgTimeHeap = 0.0;
                double avgTimeQuick = 0.0;

                for (int i = 0; i < numArrays; ++i) {
                    std::vector<int> arr(arraySize);
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

                cout << "Average time taken for Bubble Sort: " << avgTimeBubble << " seconds\n";
                cout << fixed << "Average time taken for Heap Sort: " << avgTimeHeap << " seconds\n";
                cout << fixed << "Average time taken for Quick Sort: " << avgTimeQuick << " seconds\n";
                break;
            }
        }
    } while (true);

}