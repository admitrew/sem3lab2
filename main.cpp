#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>

std::vector<std::string> split(const std::string &str){
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of('.'); // точка будет являться разделителем
    while(stop != std::string::npos){
        r.push_back(str.substr(start, stop - start)); // кладём октет в массив
        start = stop + 1; // ставим новую стартовую точку 
        stop = str.find_first_of('.', start); // ставим новую конечную точку
    } r.push_back(str.substr(start)); // кладём последний октет
    return r;
}

auto ip_sort = [](auto a, auto b){
    if (a==b) return false;
    for (auto i=0; i<4; i++){
        if (a[i]>b[i]) return false;
        else if (a[i]<b[i]) return true;
    }
    return false;
};

auto print = [](std::vector<std::vector<int>> ip_address){
    for (size_t i=0; i<ip_address.size(); i++){
        for (auto j=0; j<3; j++){
            std::cout << ip_address[i][j] << ".";
        } std::cout << ip_address[i][3] << '\n';
    }
};

auto print1 = [](std::vector<std::vector<int>> ip_address){
    for (size_t i=0; i<ip_address.size(); i++){
        if (ip_address[i][0]==1){
            for (auto j=0; j<3; j++){
                std::cout << ip_address[i][j] << ".";
            } std::cout << ip_address[i][3] << '\n';
        }
    }
};

auto print46_70_ = [](std::vector<std::vector<int>> ip_address){
    for (size_t i=0; i<ip_address.size(); i++){
        if (ip_address[i][0]==46 && ip_address[i][1]==70){
            for (auto j=0; j<3; j++){
                std::cout << ip_address[i][j] << ".";
            } std::cout << ip_address[i][3] << '\n';
        }
    }
};

auto print_46_ = [](std::vector<std::vector<int>> ip_address){
        for (size_t i=0; i<ip_address.size(); i++){
            if (std::find(ip_address[i].begin(), ip_address[i].end(), 46) != ip_address[i].end()){
                for (auto j=0; j<3; j++){
                std::cout << ip_address[i][j] << ".";
            } std::cout << ip_address[i][3] << '\n';
        }
    }
};
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