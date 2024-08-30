#include <iostream>
#include "List.h"

int main() {
    List<int> list;
    size_t NumbersCount = 5;
    for (size_t i = 0; i < NumbersCount; i++) {
        list.push_back(rand()%100);
    }
    list.pop_back();
    list.print_list();

}