#include "function.h"
void sort()
{
    if (n <= 1) {
        std::cout << "Недостаточно данных для сортировки.\n";
        return; 
    }
    for (int i = 1; i < n; ++i) {
        ProductList key = p[i];
        int j = i - 1;

        double key_price = key.is_double_price ? key.price.price_d : static_cast<double>(key.price.price_f);

        while (j >= 0) {
            double current_price = p[j].is_double_price ? p[j].price.price_d : static_cast<double>(p[j].price.price_f);
            if (current_price < key_price) {
                p[j + 1] = p[j];
                --j;
            }
            else {
                break;
            }
        }
        p[j + 1] = key;
    }

    std::cout << "Массив отсортирован по цене (по убыванию).\n";
    for(int i = 0; i < n; i++)
    {
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