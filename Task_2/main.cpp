#include "function.h"
int n = 0;
Radio_otel* p = nullptr;
bool task_end = 0;

int main()
{

    int a;
    while(true)
    {
        meny();
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
                delete_change();
                break;
            }
            case 5:
            {
                meny();
                break;
            }
            case 6:
            {
                processOrders();
                break;
            }
            default :
            {
                task_end = 1;
                break;
            }
        }

        
        if (task_end) break;

        std::ofstream file("resultat.txt");
        for (int i = 0; i < n; i++) {
            file << "Данные " << i + 1 << "-ой квитанции\n";
            file << "Название: ";
            file << p[i].name << '\n';
            file << "Марка: ";

            file << ((p[i].brand_type == '1') ? p[i].brand.brand_notlong : p[i].brand.brand_long) << '\n';

            file << "Дата поступления: ";
            file << p[i].date << '\n';

            file << "Состояние готовности: ";
            file << p[i].condition << '\n';
        }
        file.close();
    }

    free(p);
    return 0;
        
    
}