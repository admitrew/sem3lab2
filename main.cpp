#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include "func.h"

int main(){
    std::vector<std::vector<int>> ip_address; // вектор векторов - 
    std::string s;
    std::ifstream file("ip_filter.tsv");
    while(std::getline(file, s)){
        auto splited = split(s.substr(0, s.find('\t'))); // разделяет ip-адрес на массив из 4 октетов
        std::vector<int> octets = {stoi(splited[0]), stoi(splited[1]), stoi(splited[2]), stoi(splited[3])}; // перевод октетов из строкового типа данных в целочисленный
        ip_address.push_back(octets); // заполнение массива ip-адресов ip-адресами
    } sort(ip_address.begin(), ip_address.end(), ip_sort); // сортировка по лямбда-функции ip_sort
    std::cout << "Отсортированный вывод всех IP-адресов: \n"; 
    print(ip_address);
    std::cout << "Отсортированный вывод всех IP-адресов, первый байт которых равен 1: \n"; 
    print1(ip_address);
    std::cout << "Отсортированный вывод всех IP-адресов, начинающиеся с \"46.70.\": \n"; 
    print46_70_(ip_address);
    std::cout << "Отсортированный вывод всех IP-адресов, любой байт которых равен 46: \n"; 
    print_46_(ip_address);
}