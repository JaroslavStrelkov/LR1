#include "function.h"

void change(int q)
{
    char bla[] = " completed";
    char nebla[] = " no completed";
    int ä;
    std::cout << "Укажите номер критерия, который хотите изменить у товара" << q + 1 << ":" << '\n'
              << "1. Название товара" << '\n'
              << "2. Марку товара" << '\n'
              << "3. Дата поступления товара" << '\n'
              << "4. Состояние готовности" << '\n';
    std::cin >> ä;

    switch (ä) 
    {
        case 1:
            std::cout << "Введите новое название товара: ";
            std::cin >> p[q].name;
            break;
        case 2:
        int mur;
            std::cout << "Для ввода нового короткого названия марки введите 1. Для ввода нового длинного названия марки введите 2" << '\n';
            std::cin >> p[q].brand_type;
        
        if ( p[q].brand_type == '1')
        {
            std::cin.ignore();
            std::cin.getline(p[q].brand.brand_notlong, 10);
        }
        else if (p[q].brand_type == '2')
        {
            std::cin.ignore();
            std::cin.getline(p[q].brand.brand_long, 30);
        }
            break;
        case 3:
            std::cout << "Введите новую дату поступления товара: ";
            std::cin >> p[q].date;
            break;
        case 4:
        char ü;
        std::cout << "Введите состояние готовности заказа(y/n)" << '\n';
        std::cin >> ü;
        if (ü == 'y')
        {
            strcpy(p[q].condition, bla);
        }
        else if (ü == 'n')
        {
            strcpy(p[q].condition, nebla);
        }
     
            break;
        default:
            std::cout << "Введён неверный критерий" << '\n';
            break;
    }
}

void all_change() 
{
    std::cout << "Введите критерий для изменения товаров:"<< '\n'
              << "1. Название" << '\n'
              << "2. Марка" << '\n'
              << "3. Дата поступления" << '\n'
              << "4. Состояние готовности" << '\n';
    int ä;
    char ö, ü;
    std::cin >> ä;

    char jetzt_date[100];
    char new_date[100];
    char jetzt_condition[100];
    char new_condition[100];
    char jetzt_name[100];
    char new_name[100];
    char jetzt_brand[100];
    char new_brand[100];
    char bla[] = " completed";
    char nebla[] = " no completed";

    switch (ä) 
    {
        case 1:
            std::cout << "Введите текущее название товара: ";
            std::cin >> jetzt_name;
            std::cout << "Введите новое название: ";
            std::cin >> new_name;

            for (int i = 0; i < n; i++) 
            {

                if (p[i].name == jetzt_name) 
                {
                    strcpy(p[i].name, new_name);
                
                }
            }
            break;
        case 2:
        {
            std::cout << "Вы будете менять длинные названия марок?(y/n)" << '\n';
            std::cin >> ö;
            if( ö == 'y')
            {
                std::cout << "Введите текущее длинное название марки" << '\n';
                std::cin >> jetzt_brand;
                std::cout << "Введите новое длинное название марки" << '\n';
                std::cin >> new_brand;
                for (int i = 0; i < n; i++) 
                {
                    if (strcmp(p[i].brand.brand_long, jetzt_brand) == 0) 
                    {
                        strcpy(p[i].brand.brand_long, new_brand);
                    }
                }
            }
            else if (ö == 'n')
            {
                std::cout << "Введите текущее короткое название марки" << '\n';
                std::cin >> jetzt_brand;
                std::cout << "Введите новое короткое название марки" << '\n';
                std::cin >> new_brand;
                for (int i = 0; i < n; i++) 
                {
                    if (strcmp(p[i].brand.brand_notlong, jetzt_brand) == 0) 
                    {
                        strcpy(p[i].brand.brand_notlong, new_brand);
                    }
                }


            }
                
            break;
        }
        case 3:
        {
            std::cout << "Введите текущую дату поступления товара: ";
            std::cin >> jetzt_date;
            std::cout << "Введите новую дату: ";
            std::cin >> new_date;
            for (int i = 0; i < n; i++) {

                if (strcmp(p[i].date, jetzt_date) == 0) {
                        strcpy(p[i].date, new_date);
                }
                
            break;
            }
        case 4:
        {
            std::cout << "Введите текущее состояние готовности" << '\n';
            std::cin >> jetzt_condition;
            std::cout << "Введите состояние готовности заказа(y/n)" << '\n';
            std::cin >> ü;
            
                if (ü == 'y')
                {
                    strcpy(new_condition, bla);
                    
                }
                else if (ü == 'n')
                {
                    strcpy(new_condition, nebla);
                }
                for(int i = 0; i < n; i++)
                {
                    if (strcmp(p[i].condition, jetzt_condition) == 0) {
                        strcpy(p[i].condition, new_condition);
                    }
                }
                break;
        }
               
        default:
            std::cout << "Введён неверный критерий" << '\n';
            break;
    }
}
}

void all_delete() 
{
    std::cout << "Введите критерий для удаления товаров:" << '\n'
              << "1. Название" << '\n'
              << "2. Марка" << '\n'
              << "3. Дата поступления" << '\n'
              << "4. Количество" << '\n';
    int ä;
    int mur;
    std::cin >> ä;

    std::string jetzt_name, jetzt_date, jetzt_condition;
    char jetzt_brand[100];
    std::map<int, bool> to_delete;

    switch (ä) {
        case 1:
            std::cout << "Введите название товаров для удаления: ";
            std::cin >> jetzt_name;
            for (int i = 0; i < n; i++) 
            {
                if (p[i].name == jetzt_name) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        case 2:
            std::cout << "Для удаления короткого(их) названия(ий) марки(ок) введите 1. Для удаления длинного(ых) названия(ий) марки(ок) введите 2" << '\n';
            std::cin >> p[1].brand_type;
            if ( p[1].brand_type == '1')
            {
                std::cout << "Введите короткое название марки которую хотите удалить из структуры" << '\n';
                std::cin.ignore();
                std::cin.getline(jetzt_brand, 100);
                for (int i = 0; i < n; i++)
                {
                if (strcmp(p[i].brand.brand_notlong, jetzt_brand) == 0) 
                    {
                        to_delete[i] = true;
                    }
                }
                
            }
            else if (p[1].brand_type == '2')
            {
                std::cout << "Введите длинное название марки которую хотите удалить из структуры" << '\n';
                std::cin.ignore();
                std::cin.getline(jetzt_brand, 100);
                for (int i = 0; i < n; i++)
                {
                if (strcmp(p[i].brand.brand_long, jetzt_brand) == 0) 
                    {
                        to_delete[i] = true;
                    }
                }
                
            }
            break;
        
        case 3:
            std::cout << "Введите дату поступления товаров для удаления: ";
            std::cin >> jetzt_date;
            for (int i = 0; i < n; i++) 
            {
                if (p[i].date == jetzt_date) 
                {
                    to_delete[i] = true;
                }
            }
            break;
        case 4:
            std::cout << "Введите текущее состояние готовности для удаления" << '\n';
            std::cin >> jetzt_condition;
            for(int i = 0; i < n; i++)
                {
                    if (p[i].condition == jetzt_condition)
                    {
                        to_delete[i] = true;
                    }
                }


        default:
            std::cout << "Неверный выбор!\n";
            return;
    }

    int new_n = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!to_delete[i]) 
        {
            new_n++;
        }
    }

    Radio_otel* new_p = (Radio_otel*)malloc(new_n * sizeof(Radio_otel));
    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        if (!to_delete[i]) 
        {
            new_p[index++] = p[i];
        }
    }

    free(p);
    p = new_p;
    n = new_n;

    std::cout << "Удаление выполнено" << '\n';
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
    std::cout << "+-----+-------------------------------------------+\n";
    std::cout << "Выберите действие: " << '\n';
    std::cin >> choice;

    switch (choice) 
    {
        case 1:
            {
                int idx;
                std::cout << "Введите номер товара для изменения: " << '\n';
                std::cin >> idx;
                idx--; 
                if (idx >= 0 && idx < n) {
                    change(idx); 
                } else {
                    std::cout << "Неверный индекс товара!" << '\n';
                }
            }
            break;
        case 2:
            all_change(); 
            break;
        case 3:
            all_delete(); 
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
    }
    
}
