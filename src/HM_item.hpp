//
// Created by keegs on 6/25/24.
//
#include <string>
#include <cstdlib>
#ifndef HM_ITEM_HPP
#define HM_ITEM_HPP
using namespace std;

template <typename t> class HM_item{

private:
    t data;
    string name;
    unsigned long key;
    HM_item *next = NULL;
public:

    t get_data(){
        t tempdata = this->data;
        return tempdata;
    }

    HM_item* get_next(){
        HM_item* temp_next = next;
        return temp_next;
    }

    string get_name(){
        string tempname = name;
        return tempname;
    }

    void set_data(t tempdata){
        this->data = tempdata;
    }

    void set_next(HM_item &new_next){
        this->next = &new_next;
    }

    HM_item(unsigned long key, string name, t data){
        this->key = key;
        this-> name = name;
        this-> data = data;
    }















};

#endif //HM_ITEM_HPP
