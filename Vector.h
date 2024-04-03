#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector{
private:
    size_t dimensions;
    T* data;
public:
    //Konstruktor
    Vector<T>(size_t dimensions) : dimensions(dimensions), data(new T[dimensions]())
    {}
//Kopiujacy
//    Vector<T>(const Vector<T>& other) : dimensions(other.dimensions), data(new T[other.dimensions]) {
//        copy(other.data, other.data + other.dimensions, data);
//    }
////Przenoszacy
//    Vector<T>(Vector<T>&& other) noexcept : dimensions(other.dimensions), data(other.data) {
//        other.dimensions = 0;
//        other.data = nullptr;
//    }
//Destruktor
    virtual ~Vector<T>() {
        delete[] data;
    }
    size_t size() const {
        return dimensions;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    Vector<T> operator-(const Vector<T>& a){
        Vector<T> c(a.size());
        for (size_t i = 0; i < a.size(); i++) {
            c[i] = data[i] - a[i];
        }
        return c;
    }


    Vector<T> operator+(const Vector<T>& a){
        Vector<T> c(a.size());
        for (size_t i = 0; i < a.size(); i++) {
            c[i] = data[i] + a[i];
        }
        return c;
    }

    friend bool operator==(const Vector<T>& a, const Vector<T>& b){
        if (&a == &b) return true;
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const Vector<T>& a, const Vector<T>& b){
        if (&a == &b) return false;
        if (a.size() != b.size()) return true;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, Vector<T>& vec){
        os << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            os << vec[i];
            if (i != vec.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] data;
            dimensions = other.dimensions;
            data = new T[other.dimensions];
            copy(other.data, other.data + other.dimensions, data);
        }
        return *this;
    }


};