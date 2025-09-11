#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double a, b, c, x0, x, dx;
float eps = 0.00001;

double F(double i){
    if( i < 3 && fabs(b) > eps){
        return a*i*i - b*i + c;
    }else if (i > 3 && fabs(b) < eps){
        if(fabs(i - c) > eps){
            return (i-a)/(i-c);   
        }else{
            return NAN;
        }
    }else{
        if(c > eps){
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
    cout << endl;

    bool useInt = ((~((int)a | (int)b)) & ((int)a ^ (int)c)) != 0;
    cout << setprecision(4) << "    X     |    F(X)" << endl;;
    for(double i = x0; i <= x; i = i + dx){    
        cout << setw(9) << fixed << i << " | ";
        if (useInt && !isnan(F(i))){
            cout << setw(9) << fixed << F(i) << endl;
        }else if(isnan(F(i))){
            cout << setw(29) << "Деление на ноль!" << endl;;
        }else{
            cout << setw(5) << (int)F(i) << endl;
        }
    }
}