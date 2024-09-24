#include <iostream>
#include <gtest/gtest.h>
#include <cmath>
double func(double start, double end, double step) {
double sum = 0;
// double touble, start, end, step;
// std::cout << "Введите начальное значение x: ";
// std::cin >> start; // Задаем исходное значение переменной
// std::cout << "Введите конечное значение x: ";
// std::cin >> end; // Задаем конечно значение переменной
// std::cout << "Введите шаг: ";
// std::cin >> step; // Задаем шаг, с которым с которым будет изменяться aргумент
for (double x = start; x <= end; x += step) {
double y = sin(x); // функция y = sin(x)
sum += y;

// std::cout << x << " | " << y << std::endl; // Выводим значения функции для каждого аргумента (x | y)
}
return sum;
}

TEST(func, first) {
ASSERT_EQ(0, func(0,0,1));
}
int main(int argc, char** argv) 
{

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}