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
                cout << "Студент с хорошими оценками  " << mass[i].name << "\tГруппа : "<< mass[i].group << endl;
                found = true;
                break;
            }
        }
    if (!found)
    {
        cout << "Студентов с хорошими оценками не найдено " << endl;
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
        {"Иванов Иван Иванович", {'И', 'И', 'И'}, "1", {5, 4, 3, 5, 4}},
        {"Петров Петр Петрович", {'П', 'П', 'П'}, "2", {4, 3, 4, 5, 5}},
        {"Сидоров Сидор Сидорович", {'С', 'С', 'С'}, "1", {3, 5, 4, 4, 4}},
        {"Кузнецов Николай Николаевич", {'К', 'Н', 'Н'}, "3", {4, 4, 5, 3, 4}},
        {"Смирнова Анна Павловна", {'С', 'А', 'П'}, "2", {5, 5, 5, 5, 5}},
        {"Морозов Дмитрий Алексеевич", {'М', 'Д', 'А'}, "1", {3, 4, 4, 5, 4}},
        {"Васильева Ольга Ивановна", {'В', 'О', 'И'}, "3", {4, 5, 3, 4, 4}},
        {"Коваленко Артем Сергеевич", {'К', 'А', 'С'}, "2", {5, 5, 5, 4, 5}},
        {"Романова Наталья Игоревна", {'Р', 'Н', 'И'}, "1", {3, 3, 4, 4, 5}},
        {"Титов Алексей Викторович", {'Т', 'А', 'В'}, "3", {4, 3, 3, 5, 4}}
    };
    for (int i = 0; i < size; i++)
    {
        average(mass[i]);
    }
    goodst(mass, size);
    cout << "Студенты отсортированные :" << endl;
    {
        for (const auto& student : mass)
            cout << "Студент " << student.name << "Средний балл" << student.srball<<endl;
    }
    

    return 0;
}
