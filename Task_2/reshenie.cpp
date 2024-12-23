#include "function.h"



void processOrders() {
    
    std::map<std::string, std::pair<int, int>> groupStats; 

    for (int i = 0; i < n; i++) {
        if (std::strlen(p[i].name) == 0) {
            break; 
        }

        
        std::string groupName(p[i].name);
        std::string orderCondition(p[i].condition);


        if (orderCondition == " completed") {
            groupStats[groupName].first++; 
        } else if (orderCondition == " no completed") {
            groupStats[groupName].second++; 
        }
    }


    if (!groupStats.empty()) {
        std::cout << "Состояние заказов на текущие сутки по группам:\n";
        for (const auto& entry : groupStats) {
            std::cout << "Группа: " << entry.first
                      << " | Выполнено: " << entry.second.first
                      << " | Не выполнено: " << entry.second.second << '\n';
        }
    } else {
        std::cout << "Нет данных для обработки.\n";
    }
}
