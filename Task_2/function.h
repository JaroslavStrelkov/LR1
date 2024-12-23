#ifndef FUNCTION_H
#define FUNCTION_H
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <limits>
typedef struct
{
    
    char date[100];
    char state[100];
    char name[100];
    char brand_type;
    char condition[50];
    union
    {
        char brand_notlong[10];
        char brand_long[100];
    } brand; 
} Radio_otel;

extern Radio_otel* p;
extern int n;

void change(int q);
void all_change();
void all_delete();
void delete_change();
void dobavlenie();
void first_input();
void meny();
void output();
void processOrders();
void output();



#endif 