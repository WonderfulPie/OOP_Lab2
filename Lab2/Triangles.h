#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Triangles
{
private:
    double sideA, sideB, sideC;
    double angleA, angleB, angleC;
    const double M_PI = 3.14159265359;

public:
    // Конструктор класу
    Triangles() : sideA(0.0), sideB(0.0), sideC(0.0), angleA(0.0), angleB(0.0), angleC(0.0)
    {
    }
    void Init(double a, double b, double c); // Метод ініціалізації
    void Read(); // Метод введення із клавіатури
    void Display(); // Метод виведення на екран
    string toString(); // Перетворення в рядок
    double CalculateArea(); // Обчислення площі трикутника за формулою Герона
    double CalculatePerimeter(); // Обчислення периметра трикутника
    string DetermineType(); // Визначення виду трикутника
};

