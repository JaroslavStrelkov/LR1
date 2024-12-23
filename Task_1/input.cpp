#include "function.h"
void meny() {
    std::cout << "+----------------------------------+" << '\n';
    std::cout << "| Выберите операцию над структурой |" << '\n';
    std::cout << "+----------------------------------+" << '\n';
    std::cout << "| 1. Ввод данных                   |" << '\n';
    std::cout << "| 2. Просмотр содержимого          |" << '\n';
    std::cout << "|    массива структур              |" << '\n';
    std::cout << "| 3. Добавление в массив           |" << '\n';
    std::cout << "|    структур                      |" << '\n';
    std::cout << "| 4. Поиск и вывод                 |" << '\n';
    std::cout << "|    структур                      |" << '\n';
    std::cout << "| 5. Удаление и изменение          |" << '\n';
    std::cout << "|    структур                      |" << '\n';
    std::cout << "| 6. Сортировка массива            |" << '\n';
    std::cout << "|    структур                      |" << '\n';
    std::cout << "| 7. Просмотр меню                 |" << '\n';
    std::cout << "| 8. Вывод цена > 100.341 рублей   |" << '\n';
    std::cout << "| 0. Выход                         |" << '\n';
    std::cout << "+----------------------------------+" << '\n';
}
void first_input()
{
    std::cout << "Введите количество структур: ";
    std::cin >> n;
    p = (ProductList*)malloc(sizeof(ProductList) * n);
    if (p == nullptr && n > 0) {
        std::cerr << "Ошибка выделения памяти!\n";
        exit(1);
    }
    for(int i = 0; i < n; i++)
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
}

void two_input()
{
    int k;
    std::cout << "Выберите категорию:\n1. Название (name)\n2. Количество (quantity)\n3. Цена (price)\n4. Дата (date)\n";
    std::cin >> k;

    switch(k)
    {
        case 1:
        {
            std::string s1;
            std::cout << "Введите признак для названия: ";
            std::cin >> s1;
            std::cin.ignore();

            while(true)
            {
                if (n == 0) {
                    p = (ProductList*)malloc(sizeof(ProductList));
                    if (p == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        exit(1);
                    }
                } else {
                    ProductList* temp = (ProductList*)realloc(p, (n + 1) * sizeof(ProductList));
                    if (temp == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        free(p);
                        exit(1);
                    }
                    p = temp;
                }

                std::cout << "Введите название товара: ";
                std::cin >> p[n].name;
                std::cout << "Введите количество товаров: ";
                std::cin >> p[n].quantity;
                std::cout << "Введите цену товара (f для float, d для double): ";
                char price_type;
                std::cin >> price_type;
                if(price_type == 'f' || price_type == 'F') {
                    std::cin >> p[n].price.price_f;
                    p[n].is_double_price = false;
                }
                else if(price_type == 'd' || price_type == 'D') {
                    std::cin >> p[n].price.price_d;
                    p[n].is_double_price = true;
                }
                else {
                    std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
                    p[n].price.price_d = 0.0;
                    p[n].is_double_price = true;
                }

                std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
                std::cin >> p[n].date;

                double current_price = p[n].is_double_price ? p[n].price.price_d : static_cast<double>(p[n].price.price_f);
                if(current_price > 500)
                {
                    strcpy(p[n].expensive, "Дорогостоящий");
                }
                else
                {
                    strcpy(p[n].expensive, "Не дорогостоящий");
                }

                if(p[n].name == s1){
                    n++;
                    break;
                }

                n++;
            }
            break;
        }

        case 2:
        {
            int q;
            std::cout << "Введите признак для количества: ";
            std::cin >> q;

            while(true)
            {
                if (n == 0) {
                    p = (ProductList*)malloc(sizeof(ProductList));
                    if (p == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        exit(1);
                    }
                } else {
                    ProductList* temp = (ProductList*)realloc(p, (n + 1) * sizeof(ProductList));
                    if (temp == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        free(p);
                        exit(1);
                    }
                    p = temp;
                }

                std::cout << "Введите название товара: ";
                std::cin >> p[n].name;
                std::cout << "Введите количество товаров: ";
                std::cin >> p[n].quantity;
                std::cout << "Введите цену товара (f для float, d для double): ";
                char price_type;
                std::cin >> price_type;
                if(price_type == 'f' || price_type == 'F') {
                    std::cin >> p[n].price.price_f;
                    p[n].is_double_price = false;
                }
                else if(price_type == 'd' || price_type == 'D') {
                    std::cin >> p[n].price.price_d;
                    p[n].is_double_price = true;
                }
                else {
                    std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
                    p[n].price.price_d = 0.0;
                    p[n].is_double_price = true;
                }

                std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
                std::cin >> p[n].date;

                double current_price = p[n].is_double_price ? p[n].price.price_d : static_cast<double>(p[n].price.price_f);
                if(current_price > 500)
                {
                    strcpy(p[n].expensive, "Дорогостоящий");
                }
                else
                {
                    strcpy(p[n].expensive, "Не дорогостоящий");
                }

                if(p[n].quantity == q){
                    n++;
                    break;
                }

                n++;
            }
            break;
        }

        case 3:
        {
            double x;
            std::cout << "Введите признак для цены: ";
            std::cin >> x;

            while(true)
            {
                if (n == 0) {
                    p = (ProductList*)malloc(sizeof(ProductList));
                    if (p == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        exit(1);
                    }
                } else {
                    ProductList* temp = (ProductList*)realloc(p, (n + 1) * sizeof(ProductList));
                    if (temp == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        free(p);
                        exit(1);
                    }
                    p = temp;
                }

                std::cout << "Введите название товара: ";
                std::cin >> p[n].name;
                std::cout << "Введите количество товаров: ";
                std::cin >> p[n].quantity;
                std::cout << "Введите цену товара (f для float, d для double): ";
                char price_type;
                std::cin >> price_type;
                if(price_type == 'f' || price_type == 'F') {
                    std::cin >> p[n].price.price_f;
                    p[n].is_double_price = false;
                }
                else if(price_type == 'd' || price_type == 'D') {
                    std::cin >> p[n].price.price_d;
                    p[n].is_double_price = true;
                }
                else {
                    std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
                    p[n].price.price_d = 0.0;
                    p[n].is_double_price = true;
                }

                std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
                std::cin >> p[n].date;

                double current_price = p[n].is_double_price ? p[n].price.price_d : static_cast<double>(p[n].price.price_f);
                if(current_price > 500)
                {
                    strcpy(p[n].expensive, "Дорогостоящий");
                }
                else
                {
                    strcpy(p[n].expensive, "Не дорогостоящий");
                }

                if((p[n].is_double_price && p[n].price.price_d == x) ||
                   (!p[n].is_double_price && static_cast<float>(p[n].price.price_f) == static_cast<float>(x))){
                    n++;
                    break;
                }

                n++;
            }
            break;
        }

        case 4:
        {
            std::string s1;
            std::cout << "Введите признак для даты: ";
            std::cin >> s1;

            while(true)
            {
                if (n == 0) {
                    p = (ProductList*)malloc(sizeof(ProductList));
                    if (p == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        exit(1);
                    }
                } else {
                    ProductList* temp = (ProductList*)realloc(p, (n + 1) * sizeof(ProductList));
                    if (temp == nullptr) {
                        std::cerr << "Ошибка выделения памяти!\n";
                        free(p);
                        exit(1);
                    }
                    p = temp;
                }

                std::cout << "Введите название товара: ";
                std::cin >> p[n].name;
                std::cout << "Введите количество товаров: ";
                std::cin >> p[n].quantity;
                std::cout << "Введите цену товара (f для float, d для double): ";
                char price_type;
                std::cin >> price_type;
                if(price_type == 'f' || price_type == 'F') {
                    std::cin >> p[n].price.price_f;
                    p[n].is_double_price = false;
                }
                else if(price_type == 'd' || price_type == 'D') {
                    std::cin >> p[n].price.price_d;
                    p[n].is_double_price = true;
                }
                else {
                    std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
                    p[n].price.price_d = 0.0;
                    p[n].is_double_price = true;
                }

                std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
                std::cin >> p[n].date;

                double current_price = p[n].is_double_price ? p[n].price.price_d : static_cast<double>(p[n].price.price_f);
                if(current_price > 500)
                {
                    strcpy(p[n].expensive, "Дорогостоящий");
                }
                else
                {
                    strcpy(p[n].expensive, "Не дорогостоящий");
                }

                if(strcmp(p[n].date, s1.c_str()) == 0)
                {
                    n++;
                    break;
                }

                n++;
            }
            break;
        }

        default:
            std::cout << "Вы ввели неверный выбор!\n";
    }
}

void three_input()
{
    while(true)
    {
        std::string s1;
        std::cout << "Хотите продолжить ввод? (y/n): ";
        std::cin >> s1;
        if(s1 == "n" || s1 == "N")
        {
            break;
        }
        else if(s1 == "y" || s1 == "Y")
        {    
            if (n == 0) {
                p = (ProductList*)malloc(sizeof(ProductList));
                if (p == nullptr) {
                    std::cerr << "Ошибка выделения памяти!\n";
                    exit(1);
                }
            } else {
                ProductList* temp = (ProductList*)realloc(p, (n + 1) * sizeof(ProductList));
                if (temp == nullptr) {
                    std::cerr << "Ошибка выделения памяти!\n";
                    free(p);
                    exit(1);
                }
                p = temp;
            }

            std::cout << "Введите название товара: ";
            std::cin >> p[n].name;
            std::cout << "Введите количество товаров: ";
            std::cin >> p[n].quantity;
            std::cout << "Введите цену товара (f для float, d для double): ";
            char price_type;
            std::cin >> price_type;
            if(price_type == 'f' || price_type == 'F') {
                std::cin >> p[n].price.price_f;
                p[n].is_double_price = false;
            }
            else if(price_type == 'd' || price_type == 'D') {
                std::cin >> p[n].price.price_d;
                p[n].is_double_price = true;
            }
            else {
                std::cout << "Неверный тип цены. Установлено значение по умолчанию (double = 0.0).\n";
                p[n].price.price_d = 0.0;
                p[n].is_double_price = true;
            }

            std::cout << "Введите дату поступления товара на склад (ДД.ММ.ГГГГ): ";
            std::cin >> p[n].date;
        
            double current_price = p[n].is_double_price ? p[n].price.price_d : static_cast<double>(p[n].price.price_f);
            if(current_price > 500)
            {
                strcpy(p[n].expensive, "Дорогостоящий");
            }
            else
            {
                strcpy(p[n].expensive, "Не дорогостоящий");
            }

            n++;
        }
        else
        {
            std::cout << "Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}
void load_from_file(const char* filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (!file) {
        std::cout << "Файл " << filename << " не найден. Начинается новый ввод данных.\n";
        return;
    }
    file.read(reinterpret_cast<char*>(&n), sizeof(n));
    if(file.eof()) {
        std::cout << "Файл " << filename << " пуст.\n";
        n = 0;
        p = nullptr;
        file.close();
        return;
    }
    p = (ProductList*)realloc(p, sizeof(ProductList) * n);
    if (p == nullptr && n > 0) {
        std::cerr << "Ошибка выделения памяти при загрузке данных.\n";
        file.close();
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        file.read(reinterpret_cast<char*>(&p[i].is_double_price), sizeof(p[i].is_double_price));
        if(p[i].is_double_price) {
            file.read(reinterpret_cast<char*>(&p[i].price.price_d), sizeof(p[i].price.price_d));
        }
        else {
            file.read(reinterpret_cast<char*>(&p[i].price.price_f), sizeof(p[i].price.price_f));
        }
        file.read(reinterpret_cast<char*>(&p[i].quantity), sizeof(p[i].quantity));
        file.read(reinterpret_cast<char*>(p[i].date), sizeof(p[i].date));
        file.read(reinterpret_cast<char*>(p[i].name), sizeof(p[i].name));
        file.read(reinterpret_cast<char*>(p[i].expensive), sizeof(p[i].expensive));
    }

    file.close();
    std::cout << "Данные успешно загружены из файла " << filename << ".\n";
}
void main_input()
{
    int a;
    std::cout << "Выберите вид ввода:\n"
              << "1. Ввод заранее заданного количества структур\n"
              << "2. Ввод до появления структуры с заданным признаком\n"
              << "3. Диалог с пользователем о необходимости продолжать ввод\n"
              << "4. Чтение из бинарного файла\n"
              << "Ваш выбор: ";
    std::cin >> a;
    switch(a)
    {
        case 1:
        {
            first_input();
            break;
        }
        case 2:
        {
            two_input();
            break;
        }
        case 3:
        {
            three_input();
            break;
        }
        case 4: 
        {
            std::string filename;
            std::cout << "Введите название бинарного файла" << '\n';
            std::cin >> filename;
            load_from_file(filename.c_str());
            break;
        }
        default:
        {
            std::cout << "Неверный выбор. Возврат в главное меню.\n";
            break;
        }
    }
}