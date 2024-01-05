#include "SKLAD.h"
#include <stdexcept>

SKLAD::SKLAD(int s) : size(s) {
    products = new TOVAR[size];
}

SKLAD::~SKLAD() {
    delete[] products;
}

TOVAR& SKLAD::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Неправильний індекс.");
    }
    return products[index];
}

int SKLAD::getSize() const {
    return size;
}

int SKLAD::fpbn(std::string name) const {
    for (int i = 0; i < size; i++) {
        if (products[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

int SKLAD::fpbq(int quantity) const {
    for (int i = 0; i < size; i++) {
        if (products[i].getQuantity() == quantity) {
            return i;
        }
    }
    return -1;
}

int SKLAD::fpbp(double price) const {
    for (int i = 0; i < size; i++) {
        if (products[i].getPrice() == price) {
            return i;
        }
    }
    return -1;
}
