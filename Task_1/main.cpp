#include "function.h"
ProductList* p = nullptr;
int n = 0;
const char* FILENAME = "products.bin";

int main()
{
    load_from_file(FILENAME);

    int a;
    while(true)
    {
        meny();
        std::cin >> a;
        switch(a)
        {
            case 1:
            {
                main_input();
                save_to_file(FILENAME);
                break;
            }
            case 2:
            {
                output();
                break;
            }
            case 3:
            {
                dobavlenie();
                break;
            }
            case 4:
            {
                find_structure();
                break;
            }
            case 5:
            {
                delete_change();
                break;
            }
            case 6: 
            {
                sort();
                save_to_file(FILENAME);
                break;
            }
            case 7:
            {
                meny();
                break;
            }
            case 8:
            {
                output_new();
                break;
            }
            case 0:
            {
                std::cout << "Выход из программы.\n";
                free(p);
                return 0;
            }
            default:
            {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    }
}