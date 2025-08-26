#include "tinh.h"

double Tong(double a, double b) {
    return a + b;
}

double Hieu(double a, double b) {
    return a - b;
}

double Tich(double a, double b) {
    return a * b;
}

bool Thuong(double a, double b, double& ketQua) {
    if (b == 0) {
        return false;
    }
    ketQua = a / b;
    return true;
}