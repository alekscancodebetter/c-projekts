#include <iostream>
#include "table.h"
#include <filesystem>
using std::cout;

int main() {
    int a[] ={1,2,3,4};
    table tab(2,2,a);
    table b(std::filesystem::path("table.txt"));
    cout<<b;
    return 0;
}