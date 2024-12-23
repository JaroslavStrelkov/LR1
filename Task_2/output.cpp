#include "function.h"

void output()
{
    if (n == 0) {
        std::cout << "\nТоваров нет" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Товар номер " << i + 1 << '\n';
        std::cout << "Название товара: " << p[i].name << '\n';

        if (std::strlen(p[i].brand.brand_notlong) > 0) {
            std::cout << "Марка товара (короткое название): " << p[i].brand.brand_notlong << '\n';
        } else if (std::strlen(p[i].brand.brand_long) > 0) {
            std::cout << "Марка товара (длинное название): " << p[i].brand.brand_long << '\n';
        } else {
            std::cout << "Марка товара: не указана\n";
        }

        std::cout << "Дата поступления товара в ремонт: " << p[i].date << '\n';
        std::cout << "Состояние готовности: " << p[i].condition << '\n';
    }
}