#include "function.h"
void dobavlenie()
{
    int meow;
    std::cout << "Введите количество товаров, которое вы хотите добавить: ";
    std::cin >> meow;
    if(meow <= 0){
        std::cout << "Количество товаров должно быть положительным.\n";
        return;
    }

    ProductList* temp = (ProductList*)realloc(p, (n + meow) * sizeof(ProductList));
    if (temp == nullptr && meow > 0) 
    {
        std::cerr << "Ошибка выделения памяти!\n";
        exit(1);
    }
    p = temp;

    for(int i = n; i < n + meow; i++)
    {
        std::cout << "Введите название товара: ";
        std::cin >> p[i].name;
        std::cout << "Введите количество товаров: ";
        std::cin >> p[i].quantity;
        std::cout << "Введите цену товара (f для float, d для double): ";
        char price_type;
        std::cin >> price_type;
        if(price_type == 'f' || price_type == 'F') {
            std::cin >> p[i].price.price_f;
            p[i].is_double_price = false;
        }
        else if(price_type == 'd' || price_type == 'D') {
            std::cin >> p[i].price.price_d;
            p[i].is_double_price = true;
        }
        else {
            std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
            p[i].price.price_d = 0.0;
            p[i].is_double_price = true;
        }

        std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
        std::cin >> p[i].date;

        double current_price = p[i].is_double_price ? p[i].price.price_d : static_cast<double>(p[i].price.price_f);
        if(current_price > 500)
        {
            strcpy(p[i].expensive, "Дорогостоящий");
        }
        else
        {
            strcpy(p[i].expensive, "Не дорогостоящий");
        }
    }
    n += meow;
    save_to_file(FILENAME);
}