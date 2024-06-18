#include "list.h"


int main() {
    to_do_list *todo=new do_list;
    to_do_list *to_do= new to_do_list;
    to_do_list *to = todo->file(fs::path());
    to_do->print();
}