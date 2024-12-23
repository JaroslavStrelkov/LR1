#include "function.h"

void input_file() {
    std::string s;
    input:
    std::cout << "Введите название файла с расширением\n";
    std::cin >> s;

    std::ifstream file(s);

    if (!file.is_open()) {
        std::cerr << "Ошибка: файл \"" << s << "\" не существует или не может быть открыт\n";
        goto input;
    }

    file >> n;
    p = (Radio_otel*)malloc(n * sizeof(Radio_otel));

    for (int i = 0; i < n; i++) {
        file >> p[i].name;
        file >> p[i].brand_type;
        if(p[i].brand_type == '1')
        {
           file >> p[i].brand.brand_notlong; 
        }
        else if (p[i].brand_type == '2')
        {
            file >> p[i].brand.brand_long;
        }
        file >> p[i].date;
         std::string temp_condition;
        std::getline(file, temp_condition);
        strncpy(p[i].condition, temp_condition.c_str(), sizeof(p[i].condition) - 1);
        p[i].condition[sizeof(p[i].condition) - 1] = '\0'; 
    }

    file.close();
}

void first_input()
{
    free(p);
    p = nullptr;
    n = 0;

    std::cout << "Если хотите считать данные из файла - введите 1 иначе любое значение" << '\n';
    std::string mumu;
    std::cin >> mumu;

    if (mumu == "1") {
        input_file();
        return;
    }


    char bla[] = " completed";
    char nebla[] = " no completed";
    int mur;
    char l;
    std::cout << "Введите количество квитанции о сданной в ремонт радиоаппаратуре которые вы хотите починить: ";
    std::cin >> n;
    p = (Radio_otel*)malloc(sizeof(Radio_otel) * n);
    if (p == nullptr && n > 0) {
        std::cerr << "Ошибка выделения памяти!\n";
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << "Введите наименование группы изделий: ";
        std::cin.ignore();
        std::cin.getline(p[i].name, 30);
        std::cout << "Для ввода короткого названия марки введите 1. Для ввода длинного названия марки введите 2" << '\n';
        std::cin >> p[i].brand_type;
        if ( p[i].brand_type == '1')
        {
            std::cin.ignore();
            std::cin.getline(p[i].brand.brand_notlong, 10);
        }
        else if (p[i].brand_type == '2')
        {
            std::cin.ignore();
            std::cin.getline(p[i].brand.brand_long, 100);
        }
        std::cout << "Введите дату приемки в ремонт" << '\n';
        std::cin.ignore();
        std::cin.getline(p[i].date, 100);
        std::cout << "Введите состояние готовности заказа(y/n)" << '\n';
        std::cin >> l;
        if (l == 'y')
        {
            strcpy(p[i].condition, bla);
            
        }
        else if (l == 'n')
        {
            strcpy(p[i].condition, nebla);
        }
    }   
}