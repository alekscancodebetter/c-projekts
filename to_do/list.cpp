#include "list.h"
#include <fstream>
#include <sstream>

to_do_list* to_do_list::file(fs::path(file)) {
    std::cout<<"lese von to_do_list";
}

to_do_list* do_list::file(fs::path(file)) {
    std::ifstream file_{file};
    std::stringstream cont;
    std::string line;
    while (getline(file_,line)) {
        this->tasks.push_back(line);
    }
}