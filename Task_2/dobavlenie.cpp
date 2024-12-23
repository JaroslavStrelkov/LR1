#include "function.h"

void dobavlenie()
{
    char bla[] = " completed";
    char nebla[] = " no completed";
    int mur;
    char ü;
    int meow;
    std::cout << "Введите количество товаров которое вы хотите добавить!" << '\n';
    std::cin >> meow;
    p = (Radio_otel*)realloc(p, (n + meow) * sizeof(Radio_otel));
     if (p == nullptr) 
     {
        std::cerr << "Ошибка выделения памяти!" << '\n';
        exit(1);
    }
    for(int i = n; i < n + meow; i++)
    {
        std::cout << "Введите наименование группы изделий: ";
        std::cin >> p[i].name;
        std::cout << "Для ввода короткого названия нажмите 1. Для ввода длинного названия введите 2" << '\n';
        std::cin >> p[1].brand_type;
        if ( p[1].brand_type == '1')
        {
            std::cin.ignore();
            std::cin.getline(p[i].brand.brand_notlong, 10);
        }
        else if (p[1].brand_type == '2')
        {
            std::cin.ignore();
            std::cin.getline(p[i].brand.brand_long, 30);
        }
        std::cout << "Введите дату приемки в ремонт" << '\n';
        std::cin >> p[i].date;
        std::cout << "Введите состояние готовности заказа(y/n)" << '\n';
        std::cin >> ü;
        if (ü == 'y')
        {
            strcpy(p[i].condition, bla);
        }
        else if (ü == 'n')
        {
            strcpy(p[i].condition, nebla);
        }
    }  
    n += meow;
}