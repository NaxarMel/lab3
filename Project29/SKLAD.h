#ifndef SKLAD_H
#define SKLAD_H

#include "TOVAR.h"

class SKLAD {
private:
    TOVAR* products;
    int size;

public:
    SKLAD(int s);
    ~SKLAD();
    TOVAR& operator[](int index);
    int getSize() const;
    int fpbn(std::string name) const;
    int fpbq(int quantity) const;
    int fpbp(double price) const;
};

#endif // SKLAD_H
