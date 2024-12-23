#include "function.h"
void find_structure()
{
    if (n == 0) {
        std::cout << "\nТоваров нет для поиска.\n\n";
        return;
    }

    std::string search_name;
    std::cout << "Введите название товара для поиска: ";
    std::cin >> search_name;

    bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(strcmp(p[i].name, search_name.c_str()) == 0)
        {
            found = true;
            std::cout << "Товар найден:\n";
            std::cout << "Товар номер " << i + 1 << ":\n";
            std::cout << "Название товара: " << p[i].name << '\n';
            std::cout << "Количество товара: " << p[i].quantity << '\n';
            std::cout << "Цена товара: ";
            if(p[i].is_double_price)
                std::cout << p[i].price.price_d << '\n';
            else
                std::cout << p[i].price.price_f << '\n';
            std::cout << "Дата поступления товара на склад: " << p[i].date << '\n';
            std::cout << "Категория цены: " << p[i].expensive << '\n';  
    
            std::cout << "--------------------------\n";
        }
    }

    if(!found){
        std::cout << "Товар с названием \"" << search_name << "\" не найден.\n";
    }
}