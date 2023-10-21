#include <iostream>
#include <string>
#include <windows.h>

struct Address {
    std::string city;
    std::string street;
    int number_home;
    int number_apart;
    int index;
};

Address* AddStruct(Address* object, const int amount) {
    if (amount == 0) {
        object = new Address[amount + 1];
    }
    else {
        Address* temp_obj = new Address[amount + 1];
        for (int i = 0; i < amount; i++) {
            temp_obj[i] = object[i];
        }
        delete[] object;
        object = temp_obj;
    }
    return object;
}

void cinaddress(Address* obj, const int amount) {
    std::cout << "Город: ";
    std::cin >> obj[amount].city;
    std::cout << "Улица: ";
    std::cin >> obj[amount].city;
    std::cout << "Номер дома: ";
    std::cin >> obj[amount].city;
    std::cout << "Номер квартиры: ";
    std::cin >> obj[amount].city;
    std::cout << "Индекс: ";
    std::cin >> obj[amount].city;
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 0;
    Address* address = 0;
    int addressamount = 0;

    do {
        address = AddStruct(address, addressamount);
        cinaddress(address, addressamount);

        std::cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        std::cin >> count;
        std::cin.get();

    } while (count != 0);
 
    delete[] address;

}
