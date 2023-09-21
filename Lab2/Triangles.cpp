#include "Triangles.h"

void Triangles::Init(double a, double b, double c)
{
    sideA = a;
    sideB = b;
    sideC = c;
    // ���������� ���� �� ������� ������
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2.0 * sideB * sideC));
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2.0 * sideA * sideC));
    angleC = acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2.0 * sideA * sideB));
}

void Triangles::Read()
{
    cout << "������ ������� ������� A: ";
    cin >> sideA;
    cout << "������ ������� ������� B: ";
    cin >> sideB;
    cout << "������ ������� ������� C: ";
    cin >> sideC;
    // ���������� ���� �� ������� ������
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2.0 * sideB * sideC));
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2.0 * sideA * sideC));
    angleC = acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2.0 * sideA * sideB));
}

void Triangles::Display()
{
    cout << "������� A: " << sideA << endl;
    cout << "������� B: " << sideB << endl;
    cout << "������� C: " << sideC << endl;
    cout << "��� A: " << angleA << " �����" << endl;
    cout << "��� B: " << angleB << " �����" << endl;
    cout << "��� C: " << angleC << " �����" << endl;
}

string Triangles::toString()
{
    string triangleInfo = "��������� � ��������� A = " + to_string(sideA) + ", B = " + to_string(sideB) +
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
        return "����������� ���������";
    }
    else if (fabs(sideA - sideB) < 1e-6 && fabs(sideB - sideC) < 1e-6) {
        return "г����������� ���������";
    }
    else if (fabs(sideA - sideB) < 1e-6 || fabs(sideA - sideC) < 1e-6 || fabs(sideB - sideC) < 1e-6) {
        return "г����������� ���������";
    }
    else {
        return "��������� ���������";
    }
}
