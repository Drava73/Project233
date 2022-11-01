#include "pch.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

class Exception  
{
public:
    string E_error;  
    Exception() : E_error("\n Обнаружена ошибка: ") {};
    virtual const string GetError() = 0;
};


class DevZero : public Exception  
{
public:
    string Z_error;  
    DevZero() : Z_error("Деление на ноль !!!") { }
    virtual const string GetError() override
    {
        return E_error + Z_error;
    }
};

class MemErr : public Exception 
{
public: 
    MemErr() : M_error("Переполнение масива !!!") { }
    virtual const string GetError() override
    {
        return E_error + M_error;
    }
};

class FileOpErr : public Exception  
{
public:
    string F_error;  
    FileOpErr() : F_error("Не удалось открыть файл !!!") { }
    virtual const string GetError() override
    {
        return E_error + F_error;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    char ch = '4';



    while (ch != '0')
    {
        cout << "\n 0 - Выход";
        cout << "\n 1 - Проверка попытки деления a на b (5 на 0)";
        cout << "\n 2 - Проверка открытия файла (по заданному пути) ";
        cout << "\n 3 - Проверка открытия файла (по заданному пути) ";
        cout << "\n     Выберите проверку исключения для возможных ошибок: ";
        cin >> ch;
        cout << endl << endl;

        try
        {
            if (ch == '1')
            {
                a = 5;  
                b = 0;

                if (b == 0) throw DevZero();
                int c = a / b;
            }

            else if (ch == '2')
            {
                cout << "\n Проверка недостатка памяти (7 элемент не входит в массив из 6 элементов) ";
                const int size = 6;
                int ms[size];
                for (int i = 0; i < 7; i++)  
                {
                    if (i > 5) throw MemErr();
                    ms[i] = i;
                    cout << ms[i] << " ";
                }
            }

            else if (ch == '3')
            {
                cout << "\n Проверка открытия файла (по заданному пути) ";
                char path[128]{ "C:\\print.txt" };  
                cout << path;
                fstream fout(path, ios::in | ios::binary | ios::app);
                if (!fout) throw FileOpErr();
            }

        }
        catch (Exception& exception)
        {
            cout << exception.GetError();
        }
        system("pause");
        system("cls");
    }
}