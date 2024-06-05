#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "functions.h"

int main() {
    setlocale(LC_ALL,"Russian");
    
    std::cout<<"1 ЗАДАНИЕ"<<std::endl;
    std::string filename = "C:/Users/PiroZHoCheck_2.0/Desktop/LB_8/group.txt";
    int duplicates = 0;
    std::unordered_map<size_t, std::string> voters;
    enrolled(filename, voters);
    std::string surname;
    while (true) {
        std::cout << "Введите фамилию или \"end\" для завершения: ";
        std::getline(std::cin, surname);
        if (surname == "end") {
            break;
        } 
        else {
            unenrolled(surname, voters, duplicates);
        }
    }
    std::cout << "\nКоличество голосующих: " << voters.size() << std::endl;
    std::cout<<"Количество дубликатов: " << duplicates << std::endl;
    std::cout << "Фамилии голосующих:" << std::endl;
    for (const auto& voter : voters) {
        std::cout << voter.second << std::endl;  // Вывод фамилии (второго элемента пары)
    }

    std::cout<<"2 ЗАДАНИЕ"<<std::endl;
    // Создаем хэш-таблицу
    HashTable data;
    int count, price;
    std::string item;
    // Добавляем элементы в таблицу
    std::cout<<"Введите количество товаров: ";
    std::cin>>count;
    while (count!=0) {
        std::cout<<"Введите товар и его цену: ";
        std::cin>>item>>price;
        data.add(item,price);
        count--;
    }
    // Получаем цену товара
    std::cout<<"Введите товар, цену которого хотите узнать: ";
    std::cin>>item;
    // int item_price = data.get(item);
    std::cout<<"Цена "<<item<<": "<<data.get(item)<<std::endl;
    // Удаляем товар из таблицы
    std::cout<<"Введите товар, который хотите удалить из таблицы: ";
    std::cin>>item;
    data.remove(item);
    // Проверяем, есть ли в таблице товар
    std::cout<<"Введите товар, наличие которого хотите проверить: ";
    std::cin>>item;
    // bool has_item = data.get(item);
    std::cout << "В таблице есть элемент "<<item<<": " << (data.get(item)==-1 ? "нет" : "да") << std::endl;
    // Проверяем, пуста ли таблица
    // bool data_is_empty = data.empty();
    std::cout << "Таблица пуста: " << (data.empty() ? "да" : "нет") << std::endl;
    // Получаем размер таблицы
    // int size = data.size();
    std::cout << "Размер таблицы: " << data.size() << std::endl;
    
    std::cout<<"3 ЗАДАНИЕ"<<std::endl;
    
    // Загружаем пользовательское изображение
    std::string file_name = "C:/Users/PiroZHoCheck_2.0/Desktop/LB_8/Lukoshko.jpg";
    cv::Mat img = cv::imread(file_name);

    // Выделяем память для буфера хэша
    unsigned char* md_buf1 = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    unsigned char* md_buf2 = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    calculateSHA256(img,md_buf1);

    // Изменяем значение одного канала одного пикселя изображения
    int x, y, channel;
    std::cout << "Введите координаты пикселя (x, y): ";
    std::cin >> x >> y;
    std::cout << "Введите номер канала (0 - синий, 1 - зеленый, 2 - красный): ";
    std::cin >> channel;
    img.at<cv::Vec3b>(y, x)[channel] = 255;
    calculateSHA256(img, md_buf2);

    // Сравниваем две хэш-суммы
    bool equal = memcmp(md_buf1, md_buf2, SHA256_DIGEST_LENGTH) == 0;
    // Сохраняем хэш-суммы и результат сравнения в txt-файл

    std::ofstream file("hash.txt");
    file << "Хэш-сумма исходного изображения: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        file << std::hex << int(md_buf1[i]);
    }
    file << std::endl;
    file << "Хэш-сумма измененного изображения: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        file << std::hex << int(md_buf2[i]);
    }
    file << std::endl;
    file << "Хэш-суммы равны: " << (equal ? "да" : "нет") << std::endl;
    file.close();
    // Очищаем память
    free(md_buf1);
    free(md_buf2);
    return 0;
}