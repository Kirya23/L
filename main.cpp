#include <iostream>
#include "Papka1/Functions.h"

int main()
{
    std::cout << "Задание 1:";
    int input_1, input_2, devinded, devinder;
    std::cout << "Enter number: ";
    std::cin >> input_1;
    std::cout << "Enter number2: ";
    std::cin >> input_2;
    Factorial(input_1);
    Pow(input_1);
    Sumpow(input_1, input_2);
    Diff(input_1, input_2);
    Fibonachi(input_1);
    std::cout << "////////////" << "\n";
    std::cout << "Задание 2:" << "\n";
    signed int dividend, divisor;
    std::cout << "Введите делимое: ";
    std::cin >> dividend;
    std::cout << "Введите делитель: ";
    std::cin >> divisor;
    Func_for_division(dividend, divisor);
    std::cout << "////////////" << "\n";
    std::cout << "Задание 3:" << "\n";
    std::cout << "Начало функции main" << std::endl;
    try
    {
        level2();
    }
    catch (...)
    {
        std::cout << "Обработка неизвестного исключения в функции main" << std::endl;
    }
    std::cout << "Конец функции main" << std::endl;
}