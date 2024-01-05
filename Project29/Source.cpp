#include <iostream>
#include <string>
#include <windows.h>
#include "SKLAD.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try {
        int numProducts;
        cout << "Введіть кількість товарів: ";
        cin >> numProducts;
        SKLAD sklad(numProducts);

        for (int i = 0; i < numProducts; i++) {
            string name;
            int quantity;
            double price;

            cout << "Введіть назву товару: ";
            cin.ignore();
            getline(cin, name);

            cout << "Введіть кількість: ";
            cin >> quantity;

            if (quantity < 0) {
                throw invalid_argument("Кількість не може бути від'ємною.");
            }

            cout << "Введіть ціну: ";
            cin >> price;

            if (price < 0) {
                throw invalid_argument("Ціна не може бути від'ємною.");
            }

            sklad[i] = TOVAR(name, quantity, price);
        }

        for (int i = 0; i < numProducts; i++) {
            cout << sklad[i];
        }

        string searchName;
        cout << "Введіть назву товару для пошуку: ";
        cin.ignore();
        getline(cin, searchName);

        int productIndex = sklad.fpbn(searchName);

        if (productIndex != -1) {
            cout << "Знайдено за назвою: " << sklad[productIndex].getName() << endl;
        }
        else {
            cout << "Не знайдено за назвою." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
    return 0;
}
