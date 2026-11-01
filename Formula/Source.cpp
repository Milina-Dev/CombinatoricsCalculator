#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    int k;
    int choice;
    long long P = 1;

    while (true)
    {
        cout << "КАЛЬКУЛЯТОР КОМБИНАТОРИКИ" << endl;
        cout << "1. Перестановки" << endl;
        cout << "2. Размещения" << endl;
        cout << "3. Сочетания" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите формулу: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка: введите число\n" << endl;
            continue;
        }

        if (choice < 1 || choice > 4)
        {
            cout << "Такой формулы в списке нет\n" << endl;
            continue;
        }

        if (choice == 4)
        {
            cout << "Вы вышли" << endl;
            break;
        }

        cout << "Введите n: ";
        cin >> n;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка: введите число\n" << endl;
            continue;
        }

        if (n < 0 || n > 20)
        {
            cout << "Ошибка: n должно быть от 0 до 20\n" << endl;
            continue;
        }

        if (choice != 1)
        {
            cout << "Введите k: ";
            cin >> k;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Ошибка: введите число\n" << endl;
                continue;
            }

            if (k < 0 || k > n)
            {
                cout << "Ошибка: неверное значение k\n" << endl;
                continue;
            }
        }
        else
        {
            k = 0;
        }

        P = 1;

        if (choice == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                P *= i;
            }

            cout << "Результат: P(" << n << ") = " << P << "\n" << endl;
        }

        else if (choice == 2)
        {
            for (int i = 1; i <= n; i++)
            {
                P *= i;
            }

            long long factNK = 1;

            for (int i = 1; i <= n - k; i++)
            {
                factNK *= i;
            }

            P /= factNK;

            cout << "Результат: A(" << n << ", " << k << ") = " << P << "\n" << endl;
        }

        else if (choice == 3)
        {
            long long numerator = 1;
            long long denominator = 1;

            for (int i = 1; i <= n; i++)
            {
                numerator *= i;
            }

            for (int i = 1; i <= k; i++)
            {
                denominator *= i;
            }

            for (int i = 1; i <= n - k; i++)
            {
                denominator *= i;
            }

            P = numerator / denominator;

            cout << "Результат: C(" << n << ", " << k << ") = " << P << "\n" << endl;
        }
    }

    return 0;
}