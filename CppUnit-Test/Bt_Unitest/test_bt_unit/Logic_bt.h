#ifndef LOGIC_BT_H
#define LOGIC_BT_H
//khai báo class Calculator
#include <stdexcept>

class Calculator {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
};

#endif // LOGIC_BT_H
