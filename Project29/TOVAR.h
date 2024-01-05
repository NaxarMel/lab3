#ifndef TOVAR_H
#define TOVAR_H

#include <iostream>
#include <string>

class TOVAR {
private:
    std::string name;
    int quantity;
    double price;

public:
    TOVAR();
    TOVAR(std::string n, int q, double p);
    void setName(std::string n);
    void setQuantity(int q);
    void setPrice(double p);
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    void increase_Quantity(int q);
    void decrease_Quantity(int q);
    void operator++();
    void operator--();
    TOVAR& operator=(const TOVAR& other);
    bool operator==(const TOVAR& other) const;
    friend std::ostream& operator<<(std::ostream& os, const TOVAR& t);
};

#endif // TOVAR_H
