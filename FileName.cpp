#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

struct STUDENT {
    string name;          
    char initials[3];     
    string group;        
    float grades[5];
    double srball;
};

void average(STUDENT& student) {
    double sum = 0;
    for (float grade : student.grades) {
        sum += grade;
    }
    student.srball = sum / 5;
}
void goodst(const STUDENT mass[], int size)
{
    bool found = false;
    for(int i = 0; i<size ; i++)
        for (float grades : mass[i].grades)
        {
            if (grades == 4 || grades == 5)
            {
                cout << "������� � �������� ��������  " << mass[i].name << "\t������ : "<< mass[i].group << endl;
                found = true;
                break;
            }
        }
    if (!found)
    {
        cout << "��������� � �������� �������� �� ������� " << endl;
    }
}
void sortStudentsByAverage(STUDENT mass[], int size) {
    sort(mass, mass + size, [](const STUDENT& a, const STUDENT& b) {
        return a.srball < b.srball;
        });
}


int main() {
    setlocale(LC_ALL, "ru");
    int const size = 10;
    STUDENT mass[size] = {
        {"������ ���� ��������", {'�', '�', '�'}, "1", {5, 4, 3, 5, 4}},
        {"������ ���� ��������", {'�', '�', '�'}, "2", {4, 3, 4, 5, 5}},
        {"������� ����� ���������", {'�', '�', '�'}, "1", {3, 5, 4, 4, 4}},
        {"�������� ������� ����������", {'�', '�', '�'}, "3", {4, 4, 5, 3, 4}},
        {"�������� ���� ��������", {'�', '�', '�'}, "2", {5, 5, 5, 5, 5}},
        {"������� ������� ����������", {'�', '�', '�'}, "1", {3, 4, 4, 5, 4}},
        {"��������� ����� ��������", {'�', '�', '�'}, "3", {4, 5, 3, 4, 4}},
        {"��������� ����� ���������", {'�', '�', '�'}, "2", {5, 5, 5, 4, 5}},
        {"�������� ������� ��������", {'�', '�', '�'}, "1", {3, 3, 4, 4, 5}},
        {"����� ������� ����������", {'�', '�', '�'}, "3", {4, 3, 3, 5, 4}}
    };
    for (int i = 0; i < size; i++)
    {
        average(mass[i]);
    }
    goodst(mass, size);
    cout << "�������� ��������������� :" << endl;
    {
        for (const auto& student : mass)
            cout << "������� " << student.name << "������� ����" << student.srball<<endl;
    }
    

    return 0;
}
