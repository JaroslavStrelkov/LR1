#include "function.h"
void save_to_file(const char* filename)
{
    std::ofstream file(filename, std::ios::binary | std::ios::out);
    if (!file) {
        std::cerr << "Ошибка открытия файла для записи.\n";
        return;
    }
    file.write(reinterpret_cast<char*>(&n), sizeof(n));
    for(int i = 0; i < n; i++) {
        file.write(reinterpret_cast<char*>(&p[i].is_double_price), sizeof(p[i].is_double_price));
        if(p[i].is_double_price) {
            file.write(reinterpret_cast<char*>(&p[i].price.price_d), sizeof(p[i].price.price_d));
        }
        else {
            file.write(reinterpret_cast<char*>(&p[i].price.price_f), sizeof(p[i].price.price_f));
        }
        file.write(reinterpret_cast<char*>(&p[i].quantity), sizeof(p[i].quantity));
        file.write(reinterpret_cast<char*>(p[i].date), sizeof(p[i].date));
        file.write(reinterpret_cast<char*>(p[i].name), sizeof(p[i].name));
        file.write(reinterpret_cast<char*>(p[i].expensive), sizeof(p[i].expensive));
    }

    file.close();
    std::cout << "Данные успешно сохранены в файл " << filename << ".\n";
}
// void load_from_file(const char* filename)
// {
//     std::ifstream file(filename, std::ios::binary | std::ios::in);
//     if (!file) {
//         std::cout << "Файл " << filename << " не найден. Начинается новый ввод данных.\n";
//         return;
//     }
//     file.read(reinterpret_cast<char*>(&n), sizeof(n));
//     if(file.eof()) {
//         std::cout << "Файл " << filename << " пуст.\n";
//         n = 0;
//         p = nullptr;
//         file.close();
//         return;
//     }
//     p = (ProductList*)realloc(p, sizeof(ProductList) * n);
//     if (p == nullptr && n > 0) {
//         std::cerr << "Ошибка выделения памяти при загрузке данных.\n";
//         file.close();
//         exit(1);
//     }
//     for(int i = 0; i < n; i++) {
//         file.read(reinterpret_cast<char*>(&p[i].is_double_price), sizeof(p[i].is_double_price));
//         if(p[i].is_double_price) {
//             file.read(reinterpret_cast<char*>(&p[i].price.price_d), sizeof(p[i].price.price_d));
//         }
//         else {
//             file.read(reinterpret_cast<char*>(&p[i].price.price_f), sizeof(p[i].price.price_f));
//         }
//         file.read(reinterpret_cast<char*>(&p[i].quantity), sizeof(p[i].quantity));
//         file.read(reinterpret_cast<char*>(p[i].date), sizeof(p[i].date));
//         file.read(reinterpret_cast<char*>(p[i].name), sizeof(p[i].name));
//         file.read(reinterpret_cast<char*>(p[i].expensive), sizeof(p[i].expensive));
//     }

//     file.close();
//     std::cout << "Данные успешно загружены из файла " << filename << ".\n";
// }
void update_record_in_file(const char* filename, int index)
{
    if (index < 0 || index >= n) {
        std::cerr << "Неверный индекс записи для обновления.\n";
        return;
    }

    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Ошибка открытия файла для обновления.\n";
        return;
    }
    std::streampos pos = sizeof(n);
    for(int i = 0; i < index; i++) {
        pos += sizeof(p[i].is_double_price);
        pos += p[i].is_double_price ? sizeof(p[i].price.price_d) : sizeof(p[i].price.price_f);
        pos += sizeof(p[i].quantity);
        pos += sizeof(p[i].date);
        pos += sizeof(p[i].name);
        pos += sizeof(p[i].expensive);
    }

    file.seekp(pos, std::ios::beg);
    if (!file) {
        std::cerr << "Ошибка перемещения указателя в файле.\n";
        file.close();
        return;
    }
    file.write(reinterpret_cast<char*>(&p[index].is_double_price), sizeof(p[index].is_double_price));
    if(p[index].is_double_price) {
        file.write(reinterpret_cast<char*>(&p[index].price.price_d), sizeof(p[index].price.price_d));
    }
    else {
        file.write(reinterpret_cast<char*>(&p[index].price.price_f), sizeof(p[index].price.price_f));
    }

    file.write(reinterpret_cast<char*>(&p[index].quantity), sizeof(p[index].quantity));
    file.write(reinterpret_cast<char*>(p[index].date), sizeof(p[index].date));
    file.write(reinterpret_cast<char*>(p[index].name), sizeof(p[index].name));
    file.write(reinterpret_cast<char*>(p[index].expensive), sizeof(p[index].expensive));
    std::cout << '\n';

    file.close();
    std::cout << "Запись номер " << index + 1 << " успешно обновлена в файле " << filename << ".\n";
}