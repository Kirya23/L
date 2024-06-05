#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <unordered_map>
#include <openssl/engine.h>
#include <opencv2/opencv.hpp>
#include <openssl/sha.h>
#include <openssl/evp.h>

// Хэш-функция, возвращающая уникальное значение для строк
size_t hash_func(const std::string& surname);
// Функция, которая читает список фамилий из текстового файла и возвращает список уникальных фамилий
void enrolled(const std::string& filename, std::unordered_map<size_t, std::string>& voters);
// Функция, которая проверяет, проголосовал ли студент, и возвращает количество дубликатов
void unenrolled(const std::string& surname, std::unordered_map<size_t, std::string>& voters, int& duplicates);
// Класс хэш-таблицы
class HashTable {
private:
    // Хеш-функция для вычисления индекса ячейки для данного ключа
    int hash_f(const std::string& item);
    // Таблица для хранения пар ключ-значение
    std::vector<std::vector<std::pair<std::string, int>>> table;

public:
    // Конструктор по умолчанию создает пустую таблицу на 10 позиций
    HashTable();
    // Добавление элемента в таблицу
    void add(const std::string& item, int price);
    // Удаление элемента из таблицы
    void remove(const std::string& item);
    // Поиск цены товара
    int get(const std::string& item);
    // Проверка на пустую таблицу
    bool empty();
    // Получение размера таблицы
    int size();
};
void calculateSHA256(const cv::Mat& img,  unsigned char* md_buf);

#endif
