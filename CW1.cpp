#include <iostream>
#include <memory>
#include <cmath>

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
    BinomialSolver(int a, int b, int c) : factA(a), factB(b), factC(c) {};


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
//void bubbleSort(float arr[], int n);
//void heapSort(float arr[], int n);
//void quickSort(float arr[], int low, int high);
//
//class Sorting {
//public:
//    int measurement(float* Data, int Size, void (*sort)(float[], int)) {
//        long start = getTime();
//        (*sort)(Data, Size);
//        long end = getTime();
//        return end - start;
//    }
//
//private:
//    long getTime() {
//        return static_cast<long>(time(NULL)) * 1000;
//    }
//};
//
//void bubbleSort(float arr[], int n) {
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//
//void heapify(float arr[], int n, int i) {
//    int largest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    if (left < n && arr[left] > arr[largest]) {
//        largest = left;
//    }
//
//    if (right < n && arr[right] > arr[largest]) {
//        largest = right;
//    }
//
//    if (largest != i) {
//        swap(arr[i], arr[largest]);
//        heapify(arr, n, largest);
//    }
//}
//
//void heapSort(float arr[], int n) {
//    for (int i = n / 2 - 1; i >= 0; --i) {
//        heapify(arr, n, i);
//    }
//
//    for (int i = n - 1; i > 0; --i) {
//        swap(arr[0], arr[i]);
//        heapify(arr, i, 0);
//    }
//}
//
//int partition(float arr[], int low, int high) {
//    float pivot = arr[high];
//    int i = low - 1;
//
//    for (int j = low; j < high; ++j) {
//        if (arr[j] < pivot) {
//            ++i;
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return i + 1;
//}
//
//void quickSort(float arr[], int low, int high) {
//    if (low < high) {
//        int pi = partition(arr, low, high);
//
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}

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

                /*case 13: {
                        const int numArrays = 1000;
                        const int arraySize = 300;
                        const int range = 1000;

                        Sorting sorter;

                        double avgTimeBubble = 0.0;
                        double avgTimeHeap = 0.0;
                        double avgTimeQuick = 0.0;

                        for (int i = 0; i < numArrays; ++i) {
                            float* arr = new float[arraySize];
                            for (int j = 0; j < arraySize; ++j) {
                                arr[j] = static_cast<float>(rand() % range);
                            }

                            avgTimeBubble += sorter.measurement(arr, arraySize, bubbleSort);
                            avgTimeHeap += sorter.measurement(arr, arraySize, heapSort);
                            avgTimeQuick += sorter.measurement(arr, arraySize, quickSort);

                            delete[] arr;
                        }

                        avgTimeBubble /= numArrays;
                        avgTimeHeap /= numArrays;
                        avgTimeQuick /= numArrays;

                        cout << "Average time taken for Bubble Sort: " << avgTimeBubble << " milliseconds\n";
                        cout << "Average time taken for Heap Sort: " << avgTimeHeap << " milliseconds\n";
                        cout << "Average time taken for Quick Sort: " << avgTimeQuick << " milliseconds\n";
                        break;
                    }*/
        }
    } while (true);

}