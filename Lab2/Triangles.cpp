#include "Triangles.h"

void Triangles::Init(double a, double b, double c)
{
    sideA = a;
    sideB = b;
    sideC = c;
    // Розрахунок кутів за законом синусів
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2.0 * sideB * sideC));
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2.0 * sideA * sideC));
    angleC = acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2.0 * sideA * sideB));
}

void Triangles::Read()
{
    cout << "Введіть довжину сторони A: ";
    cin >> sideA;
    cout << "Введіть довжину сторони B: ";
    cin >> sideB;
    cout << "Введіть довжину сторони C: ";
    cin >> sideC;
    // Розрахунок кутів за законом синусів
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2.0 * sideB * sideC));
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2.0 * sideA * sideC));
    angleC = acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2.0 * sideA * sideB));
}

void Triangles::Display()
{
    cout << "Сторона A: " << sideA << endl;
    cout << "Сторона B: " << sideB << endl;
    cout << "Сторона C: " << sideC << endl;
    cout << "Кут A: " << angleA << " радіан" << endl;
    cout << "Кут B: " << angleB << " радіан" << endl;
    cout << "Кут C: " << angleC << " радіан" << endl;
}

string Triangles::toString()
{
    string triangleInfo = "Трикутник зі сторонами A = " + to_string(sideA) + ", B = " + to_string(sideB) +
        ", C = " + to_string(sideC);
    return triangleInfo;
}

double Triangles::CalculateArea()
{
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangles::CalculatePerimeter()
{
    return sideA + sideB + sideC;
}

string Triangles::DetermineType()
{
    if (fabs(angleA - M_PI / 2.0) < 1e-6 || fabs(angleB - M_PI / 2.0) < 1e-6 || fabs(angleC - M_PI / 2.0) < 1e-6) {
        return "Прямокутний трикутник";
    }
    else if (fabs(sideA - sideB) < 1e-6 && fabs(sideB - sideC) < 1e-6) {
        return "Рівносторонній трикутник";
    }
    else if (fabs(sideA - sideB) < 1e-6 || fabs(sideA - sideC) < 1e-6 || fabs(sideB - sideC) < 1e-6) {
        return "Рівнобедрений трикутник";
    }
    else {
        return "Звичайний трикутник";
    }
}
