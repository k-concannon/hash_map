//
// Created by keegs on 6/23/24.
//

#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <string>
#include <cstdlib>
#include "HM_item.hpp"
using namespace std;

template <typename t> class hash_map{
    friend class HM_item<t>;
private:
    HM_item<t> **table;
    int size;
	int item_count;

    unsigned long hash_algo(string name){
        unsigned long k = 0;
        for(int i = 0; i < name.size(); i++){
            k += name[i];
        }
        k %= size;
        return k;
    }

public:

    hash_map(int size){
        this->size = size;
        table = (HM_item<t>**)malloc(sizeof(HM_item<t>)*size);
    }

    void place(t data, string name){
        unsigned long key = hash_algo(name);
        if(*(table+key) == NULL){
        HM_item<t> *current = new HM_item<t>(key, name, data);
        *(table+key) = current;
        }
        else{
            HM_item<t> *next = new HM_item<t>(key, name, data);
            HM_item<t> *last = *(table+key);
            last->set_next(*next);
        }
		item_count++;
		if(item_count == size*.75){this->resize();}
    }

    t find(string name){
        unsigned long key = hash_algo(name);
        HM_item<t> *current = *(table+key);
        if(current->get_next() == NULL){
            HM_item<t> *temp_item = *(table+key);
            return temp_item->get_data();
        }
        else{
            while(current->get_next()!=NULL){
                if(current->get_name() == name){return current->get_data();}
                current = current->get_next();
            }
        }
        return current->get_data();
    }

	void resize(){
		int new_size = size * 2;
		HM_item<t> **new_table = (HM_item<t>**)malloc(sizeof(HM_item<t>)*new_size);
		for(int i = 0; i < size; i++){
			if(*(table+i) == NULL){continue;}
			HM_item<t> *temp = *(table+i);
			unsigned long key = hash_algo(temp->get_name());
			*(new_table+key) = *(table+i);
		}
		free(table);
		table = new_table;

	}


};

#endif