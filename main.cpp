#include <iostream>
#include <string>
#include <math.h>

/*int smth_to_ten(std::string str, int system) {//Перевод из любой в десятичную систему счисления
	int number, result = 1;
	number = str.length();
	if (int(str[0]) > 9) {	//запоминание первого символа если это символ
		result = (int(toupper(str[0])) - int('x') + 10);
	}
	else {	//запоминание первого символа если это число
		result = (int(str[0]) - int('0'));
	}
	for (int i = 1; i < number; i++) {	//основной цикл перевода числа
		if (int(str[i]) > int('9')) {
			result = result * system + (int(toupper(str[i])) - int('my_number') + 10);
		}
		else {
			result = result * system + (int(str[i]) - int('0'));
		}
	}
	return result;
}*/

int smth_to_ten(std::string my_number, int number_system) {//Перевод из любой в десятичную систему счисления
	int result = 1;
	if (my_number[0] > '9') {	//запоминание первого символа если это символ
		result = (int(toupper(my_number[0])) - int('A') + 10);
	}
	else {	//запоминание первого символа если это число
		result = (int(my_number[0]) - int('0'));
	}
	for (int i = 1; i < my_number.length(); i++) {	//основной цикл перевода числа
		if (int(my_number[i]) > int('9')) {
			result = result * number_system + (int(toupper(my_number[i])) - int('A') + 10);
		}
		else {
			result = result * number_system + (int(my_number[i]) - int('0'));
		}
	}
	return result;
}

int smth_to_ten1(std::string &my_number, int &number_system) {//Перевод из любой в десятичную систему счисления
	int result = 1;
	if (int(my_number[0]) > int('9')) {	//запоминание первого символа если это символ
		result = (int(toupper(my_number[0])) - int('A') + 10);
	}
	else {	//запоминание первого символа если это число
		result = (int(my_number[0]) - int('0'));
	}
	for (int i = 1; i < my_number.length(); i++) {	//основной цикл перевода числа
		if (int(my_number[i]) > int('9')) {
			result = result * number_system + (int(toupper(my_number[i])) - int('A') + 10);
		}
		else {
			result = result * number_system + (int(my_number[i]) - int('0'));
		}
	}
	return result;
}

int smth_to_ten2(std::string *my_number, int *number_system) {//Перевод из любой в десятичную систему счисления
	int result = 1;
	if (int((*my_number)[0]) > int('9')) {	//запоминание первого символа если это символ
		result = (int(toupper((*my_number)[0])) - int('A') + 10);
	}
	else {	//запоминание первого символа если это число
		result = (int((*my_number)[0]) - int('0'));
	}
	for (int i = 1; i < (*my_number).length(); i++) {	//основной цикл перевода числа
		if (int((*my_number)[i]) > int('9')) {
			result = result * *number_system + (int(toupper((*my_number)[i])) - int('A') + 10);
		}
		else {
			result = result * *number_system + (int((*my_number)[i]) - int('0'));
		}
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "ru");
	std::string my_number;
	int number_system, result;
	std::cout << "Введите систему счисления: ";
	std::cin >> number_system;
	std::cout << "Введите число: ";
	std::cin >> my_number;
	int  *number_system1 = &number_system;
	std::string  *my_number1 = &my_number;
	std::cout << my_number << "(" << number_system << ") = ";
	result = smth_to_ten(my_number, number_system);//по значению
	std::cout << result <<"(10)"<< '\n';
	result= smth_to_ten1(my_number, number_system);//по ссылке
	std::cout << result << "(10)" << '\n';
	result = smth_to_ten2(my_number1, number_system1);//по указатнлю
	std::cout << result << "(10)" << '\n';
	return 0;
}

