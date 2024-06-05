#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <openssl/engine.h>
#include <opencv2/opencv.hpp>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "functions.h"

/// @brief хэширует фамилию
/// @param surname 
/// @return хэш фамилии
size_t hash_func(const std::string& surname) {
    size_t hash = 5381;
    for (char c : surname) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

/// @brief добавление в список голосующих
/// @param filename путь до файла с фамилиями
/// @param voters список голосующих
void enrolled(const std::string& filename, std::unordered_map<size_t, std::string>& voters) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        size_t hash_value = hash_func(line);
        if (voters.find(hash_value) == voters.end()) { 
            // Если нет, то добавляем фамилию в список 
            voters.insert({hash_value, line});
        }
        //voters.insert({hash_value, line});  // Добавление пары (хэш, фамилия)
    }
}

/// @brief проверка на повторное голосование
/// @param surname фамилия
/// @param voters список голосующих
/// @param duplicates счетчик дубликатов
void unenrolled(const std::string& surname, std::unordered_map<size_t, std::string>& voters, int& duplicates) {
    size_t hash_value = hash_func(surname);
    if (voters.find(hash_value) == voters.end()) {
        voters.insert({hash_value, surname});  // Добавление пары (хэш, фамилия)
    }
    else {
        duplicates++;
    }
}



// Таблица для хранения пар ключ-значение
std::vector<std::unordered_map<std::string, int>> table;
// Хеш-функция для вычисления индекса ячейки для данного ключа
int HashTable::hash_f(const std::string& item) {
    int hash = 0;
    for (char c : item) {
        hash += c;
    }
    return hash % table.size();
};


// Конструктор по умолчанию создает пустую таблицу на 10 позиций
HashTable::HashTable() : table(10, std::unordered_map<std::string, int>()) {}
// Добавление элемента в таблицу
void HashTable::add(const std::string& item, int price) {
    // Вычисляем индекс ячейки для данного ключа
    int index = hash_f(item);
    // Добавляем пару ключ-значение в ячейку
    table[index][item] = price;
};

// Удаление элемента из таблицы
void HashTable:: remove(const std::string& item) {
    int index = hash_f(item);
    table[index].erase(item);
};

// Поиск цены товара
int HashTable:: get(const std::string& item) {
    int index = hash_f(item);
    if (table[index].find(item) != table[index].end()) {
        return table[index][item];
    } 
    else {
        return -1;
    }
};

// Проверка на пустую таблицу
bool HashTable::empty() {
    for (const auto& cell : table) {
        if (!cell.empty()) {
            return false;
        }
    }
    return true;
};

// Получение размера таблицы
int HashTable::size() {
    // Возвращаем количество ячеек в таблице
    return table.size();
};

/// @brief вычисляет хэш-сумму методом SHA256
/// @param img изображение
/// @param md_buf 
void calculateSHA256(const cv::Mat& img, unsigned char* md_buf)
{
    // Вычисляем хэш-сумму по алгоритму SHA256 для исходного изображения
    EVP_MD_CTX* ctx1 = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx1, EVP_sha256(), nullptr);
    size_t len = img.total() * img.elemSize();
    EVP_DigestUpdate(ctx1, img.data, len);
    EVP_DigestFinal_ex(ctx1, md_buf, nullptr);
    // Очищаем память
    EVP_MD_CTX_free(ctx1);
};
