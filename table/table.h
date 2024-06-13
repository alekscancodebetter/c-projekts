#pragma once
#include <iostream>
#include <filesystem>
namespace fs=std::filesystem;

class table{
    int rows,cols;
    int *data;
public: 
    table();
    table(int rows,int cols, int* data);

    table(const fs::path& file);

    friend std::ostream& operator<<(std::ostream& out,const table& tab);
};