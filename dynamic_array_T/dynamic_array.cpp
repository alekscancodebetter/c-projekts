#include <iostream>
#pragma once
template<typename T>
class dynamic_array {
    int len;
    T *elements;
public:
    dynamic_array();

    const T& operator[](int pos) const;
    dynamic_array<T>& push_back(const T& other);
    template<typename U> friend std::ostream& operator<<(std::ostream& out, const dynamic_array<U>& arr);
    const T sum() const;
    const int lenght() const;
};

template<typename T> const T& dynamic_array<T>::operator[](int pos) const {
    return this->elements[pos];
}

template<typename T> const int dynamic_array<T>::lenght() const {
    return this->len;
}

template<typename T> const T dynamic_array<T>::sum() const {
    T summ=0;
    for (int i=0;i<this->len;i++) {
        summ+=this->elements[i];
    }
    return summ;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const dynamic_array<T>& arr) {
    for (int i = 0; i < arr.len; ++i) {
        out << arr.elements[i] << " ";
    }
    return out;
}

template<typename T>
dynamic_array<T>::dynamic_array() : len(0), elements(nullptr) {}

template<typename T>
dynamic_array<T>& dynamic_array<T>::push_back(const T& other) {
    ++len;
    T *new_el = new T[len];
    for (int i = 0; i < len - 1; i++) {
        new_el[i] = this->elements[i];
    }
    new_el[len - 1] = other;
    delete[] elements;
    elements = new_el;
    return *this;
}