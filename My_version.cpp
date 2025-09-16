#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double a, b, c, x0, x, dx;
double eps = 0.00001;

double F(double i){
    if(i < 3){
        return a*i*i - b*i + c;
    }else if (i > 3 && fabs(b) < eps){
        if(fabs(i - c) > eps){
            return (i-a)/(i-c);   
        }else{
            return NAN;
        }
    }else{
        if(fabs(c) > eps){
            return i/c;
        }else{
            return NAN;
        }
    }
}

bool gotFloat(double &var) {
    cin >> var;
    if (cin.fail()) {
        return false;
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "Введите числа a, b, c: ";
    if(!gotFloat(a) || !gotFloat(b) || !gotFloat(c)){
        cout << "Некорректный ввод!";
        return 0;
    }
    cout << "Введите числа Хнач, Хкон, dX: ";
    if(!gotFloat(x0) || !gotFloat(x) || !gotFloat(dx)){
        cout << "Некорректный ввод!";
        return 0;
    }
    if(fabs(dx) < eps){
        cout << "Слишком маленький шаг!";
        return 0;
    }
    if(x < x0 && dx == fabs(dx)){
        cout << "Начальный Х больше конечного, вычисления не могут быть проведены!";
        return 0;
    }
    cout << endl;

    int Ac = static_cast<int>(a);
    int Bc = static_cast<int>(b);
    int Cc = static_cast<int>(c);
    bool useInt = ((~(Ac | Bc)) & (Ac ^ Cc)) != 0;
    
    cout << setprecision(4) << "    X     |    F(X)" << endl;
    for(double i = x0; dx > 0 ? i <= x : i >= x; i = i + dx){    
        cout << setw(9) << fixed << i << " | ";
         if(isnan(F(i))){
            cout << setw(29) << "Деление на ноль!" << endl;
        }else if (useInt){
            cout << setw(9) << fixed << F(i) << endl;
        }else{
            cout << setw(5) << static_cast<int>(F(i)) << endl;
        }
    }
}