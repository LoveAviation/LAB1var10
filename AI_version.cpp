#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция для операции MOD2 (XOR)
int mod2(int x, int y) {
    return x ^ y;
}

// Функция вычисления F(x) по кусочной формуле
double computeF(double x, double a, double b, double c) {
    if (x < 3 && b != 0) {
        return a * x * x - b * x + c;
    }
    else if (x > 3 && b == 0) {
        if (fabs(x - c) < 1e-9) return NAN; // защита от деления на 0
        return (x - a) / (x - c);
    }
    else {
        if (fabs(c) < 1e-9) return NAN; // защита от деления на 0
        return x / c;
    }
}

// Функция для безопасного ввода числа
bool safeInput(double &var) {
    cin >> var;
    if (cin.fail()) {
        return false; // введено не число
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    double Xnach, Xkon, dX;

    cout << "Введите a, b, c: ";
    if (!safeInput(a) || !safeInput(b) || !safeInput(c)) {
        cout << "Ошибка ввода! Введено не число." << endl;
        return 1;
    }

    cout << "Введите Xнач, Xкон, dX: ";
    if (!safeInput(Xnach) || !safeInput(Xkon) || !safeInput(dX)) {
        cout << "Ошибка ввода! Введено не число." << endl;
        return 1;
    }

    // Целые части
    int Ac = static_cast<int>(floor(a));
    int Bc = static_cast<int>(floor(b));
    int Cc = static_cast<int>(floor(c));

    cout << "    X\tF(X)" << endl;

    for (double x = Xnach; x <= Xkon; x += dX) {
        double F = computeF(x, a, b, c);

        if (isnan(F)) {
            cout << setw(6) << x << "\tделение на 0!" << endl;
            continue;
        }

        // Условие: НЕ(Ац ИЛИ Вц) И (Ац МОД2 Сц) != 0
        // Условие: все операции поразрядные
        bool condition = ((~(Ac | Bc)) & (Ac ^ Cc)) != 0;
        
        cout << setprecision(3) << setw(6) << x << "\t";
        if (condition) {
            cout << fixed << setprecision(3) << F;   // действительное
        } else {
            cout << static_cast<int>(F);             // целое
        }
        cout << endl;
    }

    return 0;
}