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
        cout << "������ ������� ������: ";
        cin >> numProducts;
        SKLAD sklad(numProducts);

        for (int i = 0; i < numProducts; i++) {
            string name;
            int quantity;
            double price;

            cout << "������ ����� ������: ";
            cin.ignore();
            getline(cin, name);

            cout << "������ �������: ";
            cin >> quantity;

            if (quantity < 0) {
                throw invalid_argument("ʳ������ �� ���� ���� ��'�����.");
            }

            cout << "������ ����: ";
            cin >> price;

            if (price < 0) {
                throw invalid_argument("ֳ�� �� ���� ���� ��'�����.");
            }

            sklad[i] = TOVAR(name, quantity, price);
        }

        for (int i = 0; i < numProducts; i++) {
            cout << sklad[i];
        }

        string searchName;
        cout << "������ ����� ������ ��� ������: ";
        cin.ignore();
        getline(cin, searchName);

        int productIndex = sklad.fpbn(searchName);

        if (productIndex != -1) {
            cout << "�������� �� ������: " << sklad[productIndex].getName() << endl;
        }
        else {
            cout << "�� �������� �� ������." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "�������: " << e.what() << endl;
    }
    return 0;
}
