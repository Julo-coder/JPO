#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector{
private:
    size_t dimensions;
    T* data;
public:
    Vector<T>(size_t dimensions) : dimensions(dimensions), data(new T[dimensions]())
    {}

    Vector<T>(const Vector<T>& other) : dimensions(other.dimensions), data(new T[other.dimensions]) {
        copy(other.data, other.data + other.dimensions, data);
    }

    Vector<T>(Vector<T>&& other) noexcept : dimensions(other.dimensions), data(other.data) {
        other.dimensions = 0;
        other.data = nullptr;
    }

    ~Vector<T>() {
        if (data) delete[] data;
    }
    size_t size() const {
        return dimensions;
    }
    T& at(size_t index) { // a
        return data[index];
    }
    const T& at(size_t index) const { // a
        return data[index];
    }

    T& operator[](size_t index) {
        return at(index);
    }

    const T& operator[](size_t index) const {
        return at(index);
    }

    friend Vector<T> operator-(const Vector<T>& a, const Vector<T>& b){
        Vector<T> c(a.size());
        for (size_t i = 0; i < a.size(); i++) {
            c[i] = a[i] - b[i];
        }
    }


    friend Vector<T> operator+(const Vector<T>& a, const Vector<T>& b){
        Vector<T> c(a.size());
        for (size_t i = 0; i < a.size(); i++) {
            c[i] = a[i] + b[i];
        }
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

    friend ostream& operator<<(ostream os, Vector<T>& vec){
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