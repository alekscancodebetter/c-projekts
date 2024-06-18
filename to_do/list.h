#include <iostream>
#include <string.h>
#include <vector>
#include <filesystem>
namespace fs=std::filesystem;


class list {    
public:
    list() {};
protected:
    int len;
    std::vector<std::string> tasks;
    virtual list* file(fs::path(file)) = 0;
    virtual void  print() = 0;
};

class to_do_list : public list{
public:
    to_do_list() {};
    to_do_list* file(fs::path(file)) override;
    void print() override {
        std::cout<<"from to_do_list";
    }
};

class do_list: public to_do_list {
public:
    do_list() {}
    to_do_list *file(fs::path(file));
    // mal rausnehmen
    void print() override {
        std::cout<<"from do_list";
    }
};