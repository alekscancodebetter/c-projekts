#include "dynamic_array.cpp"
#include <iostream>

template<typename T,template<typename> class C> const T min(const C<T>& cont) {
    T min=cont[0];
    for (int i=1;i<cont.lenght();i++) {
        if (cont[i] < min) {
            min = cont[i];
        }
    }
    return min;
}