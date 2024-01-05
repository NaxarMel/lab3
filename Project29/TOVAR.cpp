#include "TOVAR.h"
#include <stdexcept>

TOVAR::TOVAR() : name(""), quantity(0), price(0.0) {}

TOVAR::TOVAR(std::string n, int q, double p) : name(n), quantity(q), price(p) {}

void TOVAR::setName(std::string n) {
    name = n;
}

void TOVAR::setQuantity(int q) {
    if (q < 0) {
        throw std::invalid_argument("Кількість не може бути від'ємною.");
    }
    quantity = q;
}

void TOVAR::setPrice(double p) {
    if (p < 0) {
        throw std::invalid_argument("Ціна не може бути від'ємною.");
    }
    price = p;
}

std::string TOVAR::getName() const {
    return name;
}

int TOVAR::getQuantity() const {
    return quantity;
}

double TOVAR::getPrice() const {
    return price;
}

void TOVAR::increase_Quantity(int q) {
    if (q < 0) {
        throw std::invalid_argument("Кількість для збільшення не може бути від'ємною.");
    }
    quantity += q;
}

void TOVAR::decrease_Quantity(int q) {
    if (q < 0) {
        throw std::invalid_argument("Кількість для зменшення не може бути від'ємною.");
    }
    if (q > quantity) {
        throw std::invalid_argument("Недостатньо товару для зменшення.");
    }
    quantity -= q;
}

void TOVAR::operator++() {
    increase_Quantity(1);
}

void TOVAR::operator--() {
    decrease_Quantity(1);
}

TOVAR& TOVAR::operator=(const TOVAR& other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    quantity = other.quantity;
    price = other.price;
    return *this;
}

bool TOVAR::operator==(const TOVAR& other) const {
    return (name == other.name) && (quantity == other.quantity) && (price == other.price);
}

std::ostream& operator<<(std::ostream& os, const TOVAR& t) {
    os << "Назва: " << t.getName() << ", Кількість: " << t.getQuantity() << ", Ціна: "
        << t.getPrice() << std::endl;
    return os;
}
