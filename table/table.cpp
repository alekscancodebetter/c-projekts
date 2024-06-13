#include  "table.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

stringstream open_read_file(fs::path filename) {
    ifstream file{filename};
    if (file) {
        string line;
        stringstream cont;
        while(getline(file,line)) {
            cont<<line<<endl;
        }
        return cont;
    }
    cerr<<"cant open";
    exit(1);
}

table::table(): rows(0),cols(0),data(nullptr) {}

table::table(int rows,int cols,int *data_): rows(rows),cols(cols),data(new int[rows]) {
    for (int r=0;r<rows;r++) {
        for (int c=0;c<cols;c++) {
            data[r * cols + c]= data_[r * cols +c];
        }
    }
}

    

tuple<int,int,vector<int>> get_r_c_data(const stringstream& cont) {
    string line;
    stringstream temp(cont.str());
    int r,c;
    vector<int> ints;
    while (getline(temp,line)) {
        r++;
        stringstream line_(line);
        int temp;
        while(line_>>temp) {
            ints.push_back(temp);
        }
    }
    c=ints.size()/r;
    for (int i=0;i<ints.size();i++) {
    }
    return make_tuple(r,c,ints);
}

tuple<int,int,vector<int>> init_from_file(fs::path file) {
    const stringstream cont=open_read_file(file);
    auto [rows,cols,list] = get_r_c_data(cont);
    return {rows,cols,list};
}

table::table(const fs::path &file) : table::table() {
    auto [rows,cols,data_]= init_from_file(file);
    this->rows=rows;
    this->cols=cols;
    this->data=new int[rows*cols];
    for (int r=0;r<rows;r++) {
        for (int c=0;c<cols;c++) {
            this->data[r * cols + c]=data_[r * cols + c];
        }
    }
}

ostream& operator<<(ostream& out,const table& tab) {
    for (int r=0;r<tab.rows;r++) {
        for (int c=0;c<tab.cols;c++) {
            out<<tab.data[r * tab.cols + c]<<" ";
        }
        out<<std::endl;
    }
    return out;
}