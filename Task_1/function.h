#ifndef FUNCTION_H
#define FUNCTION_H
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
typedef struct
{
    union
    {
        float price_f;
        double price_d;
    } price; 

    bool is_double_price; 

    int quantity;
    char date[11];
    char name[100];
    char expensive[100];
} ProductList;

extern ProductList* p;
extern int n;
extern const char* FILENAME; 

void main_input();
void first_input();
void two_input();
void three_input();
void dobavlenie();
void output();
void output_new();
void find_structure();
void delete_change();
void change(int q);
void all_change();
void all_delete();
void sort();
void meny();
void save_to_file(const char* filename);
void load_from_file(const char* filename);
void update_record_in_file(const char* filename, int index);

#endif 