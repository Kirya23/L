#include <iostream>  
#include <string>  
#include <algorithm>  
#include <vector>
//факториал
int Factorial(int &input_1 ){
	int carry=0;
	std::vector<int> factorial = { 1 }; // Создаем вектор, начиная с единицы, для хранения цифр факториала

        for (int i = 2; i <=  input_1; i++) { // Начиная с 2, умножаем все цифры факториала на i

            for (int& digit : factorial) {
                int product = digit * i + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                factorial.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }

        std::cout<<"FECTORIAL ";
        for (auto it = factorial.rbegin(); it != factorial.rend(); it++) {
            std::cout << *it; // Выводим цифры факториала в обратном порядке
        }
		std::cout<<"\n";
		return 0;
}
// Возведение в степень
int Pow(int &input_1){
		int carry=0;
        std::vector<int> factorial = { 1 }; 

        for (int i = 0; i < input_1; ++i) { 

            for (int& digit : factorial) {
                int product = digit * 2 + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                factorial.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }

        std::cout<<"POW ";
        for (auto it = factorial.rbegin(); it != factorial.rend(); it++) {
            std::cout << *it; // Выводим цифры факториала в обратном порядке
        }
		std::cout<<"\n";
		return 0;
    }
///сумма 
std::vector<int> SUM(std::vector<int>vec1, std::vector<int>vec2)
{
    int dlina1=vec1.size(), dlina2 =vec2.size() ;

        int carry = 0;  // Переменная для хранения переноса
        int max_length = std::max(dlina1, dlina2); // Находим длину самого длинного вектора

        std::vector<int> result(max_length, 0); // Создаем вектор-результат длиной max_length, заполненный нулями

        for (int i = 0; i < max_length; ++i) {
            int sum = carry;  // Инициализируем сумму значением переноса
            if (i < dlina1) {
                sum += vec1[i];  // Добавляем значение из первого вектора, если есть
            }
            if (i < dlina2) {
                sum += vec2[i];  // Добавляем значение из второго вектора, если есть
            }
            result[i] = sum % 10;  // Записываем остаток от деления суммы на 10
            carry = sum / 10;  // Вычисляем новое значение для переноса
        }

        if (carry > 0) {
            result.push_back(carry);  // Если есть оставшийся перенос после сложения, добавляем его в конец результата
        }
        std::cout << "Sum result: ";
        for (int num : result) {
        std::cout << num;
        }
        return result;
    }

int Sumpow(int &input_1, int &input_2)
{		int carry=0;
        std::vector<int> power = { 1 };
        std::vector<int> power2 = { 1 };

        std::vector<int> power_copy;
        std::vector<int> power2_copy;

        //для первого инпута
        for (int i = 0; i < input_1; ++i) {

            for (int& digit : power) {
                int product = digit * 2 + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                power.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }
        std::cout << "Your 2^input_1 for sum = ";
        for (auto it = power.rbegin(); it != power.rend(); it++) {
            std::cout << *it;// Выводим цифры факториала в обратном порядке
            power_copy.insert(power_copy.end(), *it);//переписываем вектор в нужном порядке
        }

        std::cout << std::endl;

        //для второго импута
        for (int i = 0; i < input_2; ++i) {

            for (int& digit : power2) {
                int product = digit * 2 + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                power2.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }
        std::cout << "Your 2^input_2 for sum = ";
        for (auto it2 = power2.rbegin(); it2 != power2.rend(); it2++) {
            std::cout << *it2; // Выводим цифры факториала в обратном порядке
            power2_copy.insert(power2_copy.end(), *it2);//переписываем в вектор в нужном порядке
        }
        std::cout << std::endl;


        //Вывод победителя
        std::cout<<"SUM ";
        std::vector < int >result = SUM(power_copy, power2_copy);
		std::cout<<"\n";
        return 0;

}
//разность
std::vector<int> DIFF(std::vector<int>vec1, std::vector<int>vec2)
{
    int dlina1 = vec1.size(), dlina2 = vec2.size();

    int carry = 0;  // Переменная для хранения переноса
    int max_length = std::max(dlina1, dlina2); // Находим длину самого длинного вектора

    std::vector<int> result(max_length, 0); // Создаем вектор-результат длиной max_length, заполненный нулями


    for (int i = 0; i < max_length; ++i) {
        int diff = carry;  // Инициализируем разность значением переноса
        if (i < dlina1) {
            diff += vec1[i];  // Вычитаем значение из первого вектора, если есть
        }
        if (i < dlina2) {
            diff -= vec2[i];  // Вычитаем значение из второго вектора, если есть
        }
        if (diff < 0) {
            diff += 10;  // Если результат отрицательный, добавляем 10 для заёма десятка
            carry = -1; // Устанавливаем значение переноса равным -1
        }
        else {
            carry = 0;  // Если результат положительный, значение переноса равно 0
        }
        result[i] = diff;  // Записываем разность в результат
    }
    std::cout << "Sum difference: ";
    for (int num : result) {
        std::cout << num;
    }

    return result;
}
int Diff(int &input_1,int &input_2){
		int carry=0;
        std::vector<int> power = { 1 };
        std::vector<int> power2 = { 1 };

        std::vector<int> power_copy;
        std::vector<int> power2_copy;

        //для первого инпута
        for (int i = 0; i < input_1; ++i) {

            for (int& digit : power) {
                int product = digit * 2 + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                power.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }
        std::cout << "Your 2^input_1 difference = ";
        for (auto it = power.rbegin(); it != power.rend(); it++) {
            std::cout << *it;// Выводим цифры факториала в обратном порядке
            power_copy.insert(power_copy.end(), *it);//переписываем вектор в нужном порядке
        }

        std::cout << std::endl;

        //для второго импута
        for (int i = 0; i < input_2; ++i) {

            for (int& digit : power2) {
                int product = digit * 2 + carry;
                digit = product % 10; // Сохраняем только младший разряд умножения
                carry = product / 10; // Оставшуюся часть запоминаем для следующей цифры
            }
            while (carry) { // Если осталась цифра в умножении
                power2.push_back(carry % 10); // Добавляем ее в вектор
                carry /= 10; // Убираем добавленную цифру из carry
            }
        }
        std::cout << "Your 2^input_2 for differnce= ";
        for (auto it2 = power2.rbegin(); it2 != power2.rend(); it2++) {
            std::cout << *it2; // Выводим цифры факториала в обратном порядке
            power2_copy.insert(power2_copy.end(), *it2);//переписываем в вектор в нужном порядке
        }
        std::cout << std::endl;


        //Вывод победителя
        std::cout<<"SUMDIFF ";
        std::vector < int >result = DIFF(power_copy, power2_copy);
		std::cout<<"\n";
        return 0;
    }

std::vector<int> Fibonachi(int input_1)
{
	std::vector<int> result;
	std::vector<int> vec1;
	std::vector<int> vec2;
	vec2.push_back(0);
	vec1.push_back(1);
	int carry = 0;
	for (int i = 3; i <= input_1; i++)
	{
		result.clear();
		carry = 0;
		for (int j = 0; j < vec1.size(); j++)
		{
			int sum = 0;
			if (j >= vec2.size())
				sum += vec1[j] + carry;
			else
				sum = vec2[j] + vec1[j] + carry;

			result.push_back(sum % 10);
			carry = sum / 10;
		}
		while (carry != 0)
		{
			result.push_back(carry % 10);
			carry /= 10;
		}
		vec2 = vec1;
		vec1 = result;

	}
    std::cout<<"FIBONACHI ";
    for (int i = 0; i <= result.size() - 1; i++)
	{
		std::cout << result[i];
	}
	return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    int  input_1,input_2;
    std::cout << "Enter number: ";
    std::cin >>  input_1;
	std::cout << "Enter number2: ";
    std::cin >>  input_2;
    
	Factorial(input_1);
	Pow(input_1);
	Sumpow(input_1,input_2);
	Diff(input_1,input_2);
    std::vector<int> result = Fibonachi(input_1);
    
}