#include "dynamic_array.cpp"
#include <iostream>
#include "temptemp.cpp"
using std::cout;

int main() {
    dynamic_array<int> a;
    a.push_back(12);
    a.push_back(21);
    cout<<a<<" sum: "<<a.sum()<<std::endl;
    dynamic_array<float> b;
    b.push_back(2.12);
    b.push_back(1.12);
    cout<<b<<" sum: "<<b.sum();
    cout<<std::endl<<min<float>(b);
    return 0;
}