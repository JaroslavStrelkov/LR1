#include "function.h"
void change(int q)
{
    int criteria;
    std::cout << "Укажите номер критерия, который хотите изменить у товара " << q + 1 << ":\n"
              << "1. Название товара\n"
              << "2. Количество товара\n"
              << "3. Цена товара\n"
              << "4. Дата поступления товара\n"
              << "Ваш выбор: ";
    std::cin >> criteria;

    switch (criteria) 
    {
        case 1:
        {
            std::cout << "Введите новое название товара: ";
            std::cin >> p[q].name;
            break;
        }
        case 2:
        {
            std::cout << "Введите новое количество товара: ";
            std::cin >> p[q].quantity;
            break;
        }
        case 3:
        {
            std::cout << "Введите новый тип цены (f для float, d для double): ";
            char price_type;
            std::cin >> price_type;
            if(price_type == 'f' || price_type == 'F') {
                std::cin >> p[q].price.price_f;
                p[q].is_double_price = false;
            }
            else if(price_type == 'd' || price_type == 'D') {
                std::cin >> p[q].price.price_d;
                p[q].is_double_price = true;
            }
            else {
                std::cout << "Неверный тип цены. Цена не изменена.\n";
                break;
            }

            double current_price = p[q].is_double_price ? p[q].price.price_d : static_cast<double>(p[q].price.price_f);
            if(current_price > 500)
            {
                strcpy(p[q].expensive, "Дорогостоящий");
            }
            else
            {
                strcpy(p[q].expensive, "Не дорогостоящий");
            }
            break;
        }
        case 4:
        {
            std::cout << "Введите новую дату поступления товара на склад (ДД.ММ.ГГГГ): ";
            std::cin >> p[q].date;
            break;
        }
        default:
        {
            std::cout << "Введён неверный критерий.\n";
            break;
        }
    }

    update_record_in_file(FILENAME, q);
}
void all_change() 
{
    std::cout << "Введите критерий для изменения товаров:\n"
              << "1. Название\n"
              << "2. Количество\n"
              << "3. Цена\n"
              << "4. Дата поступления\n"
              << "Ваш выбор: ";
    int criteria;
    std::cin >> criteria;

    switch (criteria) 
    {
        case 1:
        {
            char current_name[100], new_name[100];
            std::cout << "Введите текущее название товара: ";
            std::cin >> current_name;
            std::cout << "Введите новое название: ";
            std::cin >> new_name;

            for (int i = 0; i < n; i++) 
            {
                if (strcmp(p[i].name, current_name) == 0) 
                {
                    strcpy(p[i].name, new_name);
                    update_record_in_file(FILENAME, i);
                }
            }
            break;
        }
        case 2:
        {
            int current_quantity, new_quantity;
            std::cout << "Введите текущее количество товара: ";
            std::cin >> current_quantity;
            std::cout << "Введите новое количество: ";
            std::cin >> new_quantity;

            for (int i = 0; i < n; i++) 
            {
                if (p[i].quantity == current_quantity) 
                {
                    p[i].quantity = new_quantity;
                    update_record_in_file(FILENAME, i);
                }
            }
            break;
        }
        case 3:
        {
            double current_price, new_price;
            char current_price_type, new_price_type;

            std::cout << "Введите текущую цену товара (f для float, d для double): ";
            std::cin >> current_price_type;
            if(current_price_type == 'f' || current_price_type == 'F') {
                std::cin >> current_price;
            }
            else if(current_price_type == 'd' || current_price_type == 'D') {
                std::cin >> current_price;
            }
            else {
                std::cout << "Неверный тип цены. Возврат.\n";
                break;
            }

            std::cout << "Введите новую цену товара (f для float, d для double): ";
            std::cin >> new_price_type;
            if(new_price_type == 'f' || new_price_type == 'F') {
                std::cin >> new_price;
            }
            else if(new_price_type == 'd' || new_price_type == 'D') {
                std::cin >> new_price;
            }
            else {
                std::cout << "Неверный тип цены. Возврат.\n";
                break;
            }

            for (int i = 0; i < n; i++) 
            {
                double current_p = p[i].is_double_price ? p[i].price.price_d : static_cast<double>(p[i].price.price_f);
                if (current_p == current_price) 
                {
                    if(new_price_type == 'f' || new_price_type == 'F') {
                        p[i].price.price_f = static_cast<float>(new_price);
                        p[i].is_double_price = false;
                    }
                    else if(new_price_type == 'd' || new_price_type == 'D') {
                        p[i].price.price_d = new_price;
                        p[i].is_double_price = true;
                    }
                    else {
                        std::cout << "Неверный тип цены. Пропуск.\n";
                        continue;
                    }

                    double updated_price = p[i].is_double_price ? p[i].price.price_d : static_cast<double>(p[i].price.price_f);
                    if(updated_price > 500)
                    {
                        strcpy(p[i].expensive, "Дорогостоящий");
                    }
                    else
                    {
                        strcpy(p[i].expensive, "Не дорогостоящий");
                    }
                    update_record_in_file(FILENAME, i);
                }
            }
            break;
        }
        case 4:
        {
            char current_date[11], new_date[11];
            std::cout << "Введите текущую дату поступления товара на склад (ДД.ММ.ГГГГ): ";
            std::cin >> current_date;
            std::cout << "Введите новую дату: ";
            std::cin >> new_date;
            for (int i = 0; i < n; i++) 
            {
                if (strcmp(p[i].date, current_date) == 0) 
                {
                    strcpy(p[i].date, new_date);
                    update_record_in_file(FILENAME, i);
                }
            }
            break;
        }
        default:
        {
            std::cout << "Введён неверный критерий.\n";
            break;
        }
    }
}

void all_delete() 
{
    std::cout << "Введите критерий для удаления товаров:\n"
              << "1. Название\n"
              << "2. Количество\n"
              << "3. Цена\n"
              << "4. Дата поступления\n"
              << "Ваш выбор: ";
    int criteria;
    std::cin >> criteria;

    std::map<int, bool> to_delete;

    switch (criteria) {
        case 1:
        {
            char current_name[100];
            std::cout << "Введите название товаров для удаления: ";
            std::cin >> current_name;
            for (int i = 0; i < n; i++) 
            {
                if (strcmp(p[i].name, current_name) == 0) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        }
        case 2:
        {
            int current_quantity;
            std::cout << "Введите количество товаров для удаления: ";
            std::cin >> current_quantity;
            for (int i = 0; i < n; i++) 
            {
                if (p[i].quantity == current_quantity) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        }
        case 3:
        {
            double current_price;
            char current_price_type;
            std::cout << "Введите цену товаров для удаления (f для float, d для double): ";
            std::cin >> current_price_type;
            if(current_price_type == 'f' || current_price_type == 'F') {
                std::cin >> current_price;
            }
            else if(current_price_type == 'd' || current_price_type == 'D') {
                std::cin >> current_price;
            }
            else {
                std::cout << "Неверный тип цены. Возврат.\n";
                return;
            }
            for (int i = 0; i < n; i++) 
            {
                double current_p = p[i].is_double_price ? p[i].price.price_d : static_cast<double>(p[i].price.price_f);
                if (current_p == current_price) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        }
        case 4:
        {
            char current_date[11];
            std::cout << "Введите дату поступления товаров для удаления (ДД.ММ.ГГГГ): ";
            std::cin >> current_date;
            for (int i = 0; i < n; i++) 
            {
                if (strcmp(p[i].date, current_date) == 0) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        }
        default:
        {
            std::cout << "Неверный выбор!\n";
            return;
        }
    }

    if(to_delete.empty()) {
        std::cout << "Нет товаров, соответствующих заданному критерию.\n";
        return;
    }

    int new_n = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!to_delete[i]) 
        {
            p[new_n++] = p[i];
        }
    }
    ProductList* new_p = (ProductList*)realloc(p, new_n * sizeof(ProductList));
    if (new_p == nullptr && new_n > 0) {
        std::cerr << "Ошибка перераспределения памяти!\n";
        free(p);
        exit(1);
    }
    p = new_p;
    n = new_n;

    std::cout << "Удаление выполнено.\n";

    save_to_file(FILENAME);
}

void delete_change() 
{
    int choice;
    
    std::cout << "+-----+-------------------------------------------+\n";
    std::cout << "| №   | Операция                                  |\n";
    std::cout << "+-----+-------------------------------------------+\n";
    std::cout << "| 1   | Изменить товар по индексу                 |\n";
    std::cout << "| 2   | Изменить данные всех товаров по критерию  |\n";
    std::cout << "| 3   | Удалить товар(ы)                          |\n";
    std::cout << "| 0   | Вернуться в главное меню                  |\n";
    std::cout << "+-----+-------------------------------------------+\n";
    std::cout << "Выберите действие: ";
    std::cin >> choice;

    switch (choice) 
    {
        case 1:
        {
            if(n == 0){
                std::cout << "Нет товаров для изменения.\n";
                break;
            }
            int idx;
            std::cout << "Введите номер товара для изменения (1 - " << n << "): ";
            std::cin >> idx;
            idx--; 
            if (idx >= 0 && idx < n) {
                change(idx); 
            } else {
                std::cout << "Неверный индекс товара!\n";
            }
            break;
        }
        case 2:
        {
            all_change(); 
            break;
        }
        case 3:
        {
            all_delete(); 
            break;
        }
        case 0:
        {
            std::cout << "Возврат в главное меню.\n";
            break;
        }
        default:
        {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}