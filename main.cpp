#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

bool Acronym(const std::string& s, const std::vector<std::string>& words)
{
    std::string acronym; // Создаем новую строку для хранения аббревиатуры

    // Перебираем каждое слово в векторе words, чтобы создать аббревиатуру
    for (const std::string& word : words)


    {
        if (!word.empty()) // Проверяем, что слово не пустое
        {
            acronym += word[0]; // Добавляем первую букву слова к аббревиатуре
        }
    }

    // Проверяем исходную строку и аббревиатуру на равенство 
    return (s == acronym);
}

// Удаления пробелов из строки
std::string RemoveSpaces(std::string str) {
    std::string result = ""; // Создаем пустую строку для хранения результата без пробелов
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') { // Если текущий символ не является пробелом
            result += str[i]; // Добавляем символ в результирующую строку
        }
    }
    return result; // Возвращаем строку без пробелов
}
// Проверка палиндрома
bool Palindrom(std::string str) {
    int left = 0; // Указатель в начале строки
    int right = str.length() - 1; // Указатель в конце строки
    while (left < right) {
        if (str[left] != str[right]) { // Если символы на позициях left и right не совпадают
            return false; // Строка не является палиндромом
        }
        left++; // Смещаем левый указатель вправо
        right--; // Смещаем правый указатель влево
    }
    return true; // Если все проверки пройдены, строка является палиндромом
}

int Search(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int max_counter = 0;

    for (const std::string& word : words)
    {
        std::vector<char> temp_letters = letters; // Создаем копию исходного вектора letters
        int counter = 0;

        for (char symbol : word)
        {
            auto it = std::find(temp_letters.begin(), temp_letters.end(), symbol); // Ищем символ во временном векторе
            if (it != temp_letters.end())
            {
                int letter_index = std::distance(temp_letters.begin(), it); // Получаем индекс символа
                counter += score[alphabet.find(temp_letters[letter_index])]; // Увеличиваем счетчик на значение из вектора score
                temp_letters.erase(it); // Удаляем использованный символ из временного вектора
            }
        }
        max_counter = std::max(max_counter, counter); // Обновляем максимальное значение счетчика
    }
    return max_counter;
}

int main() { 
    //Task 1
    std::cout << "Task number 1: ";
    std::vector<std::string> words1 = { "томский", "политехнический", "университет" };
    std::string s = "тпу";
    std::cout << Acronym(s, words1) << std::endl;
    // Task 2
    std::string input;
    std::cout << "Enter string: ";
    getline(std::cin, input);
    input = RemoveSpaces(input); // Удаляем пробелы из строки
    for (char& c : input) {
        c = tolower(c); // Преобразуем все символы в нижний регистр
    }
    if (Palindrom(input)) {
        std::cout << "Yes,this polindrom" << std::endl;
    }
    else {
        std::cout << "No, this don't polindrom" << std::endl;
    }
    //Task 3
    std::vector<std::string> words = { "abc", "dog", "cat", "bat" };
    std::vector<char> letters = { 'a', 'b', 'c', 'd', 'o', 'g', 't' };
    std::vector<int> score = { 1, 3, 2, 4, 1, 5, 3, 2, 1, 2, 2, 4, 3, 1, 2, 4, 4, 2, 1, 2, 1, 3, 3, 2, 4, 3 };

    int max_counter = Search(words, letters, score);
    std::cout <<"Max_score: "<< max_counter << std::endl;

    return 0;
}
