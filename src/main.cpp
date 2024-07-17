//
// Created by keegs on 6/23/24.
//
#include "hash_map.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    hash_map<int> a(50);
    a.place(6, "six");
    a.place(7, "seven");
    int b = a.find("six");
    int d = a.find("seven");
    cout<<b<<" "<<d;






return 0;

}