// ЛР 6.4 рек

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void Create(double* x, const int size, const double Low, const double High, int i);
void Print(double* x, const int size, int i);
int MinAbsIndex(double* x, const int size, int i, int minIndex);
int FirstNegativeIndex(double* x, const int size, int i);
double SumAbs(double* x, const int size, int i);
double SumAbsAfterFirstNegative(double* x, const int size);
int Compress(double* x, const int size, const double a, const double b, int i, int k);
void FillZeros(double* x, const int size, int i);

int main()
{
    srand((unsigned)time(NULL)); //щоб при кожному запуску числа були різні
    cout << fixed << setprecision(2); //fixed виводить числа з крапкою, setprecision(2) залишає 2 цифри після крапки

    int n;
    cout << "n = ";
    cin >> n;
    double a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    if (n <= 0)
    {
        cout << "n must be positive." << endl;
        return 1;
    }

    double* x = new double[n]; //динамічний масив (розмір вводиться під час виконання програми)
    double Low = -10;
    double High = 10;

    Create(x, n, Low, High, 0); // заповнення випадковими числами
    cout << "Array:" << endl;
    Print(x, n, 0);

    cout << "Index of the minimum by modulus = " << MinAbsIndex(x, n, 1, 0) << endl;
    cout << "Sum of moduli after the first negative = " << SumAbsAfterFirstNegative(x, n) << endl;

    int k = Compress(x, n, a, b, 0, 0); // k - скільки елементів залишилось
    FillZeros(x, n, k); //решту заповнити нулями
    cout << "Array after compressing:" << endl;
    Print(x, n, 0);

    delete[] x; // видалити масив для звільення пам'яті

    return 0;
}

void Create(double* x, const int size, const double Low, const double High, int i)
{
    x[i] = Low + (High - Low) * rand() / RAND_MAX; // випадкове число від -10 до 10
    if (i < size - 1)
        Create(x, size, Low, High, i + 1);
}

void Print(double* x, const int size, int i)
{
    cout << setw(8) << x[i];
    if (i < size - 1)
        Print(x, size, i + 1);
    else
        cout << endl;
}

int MinAbsIndex(double* x, const int size, int i, int minIndex)
{
    if (i < size)
    {
        if (fabs(x[i]) < fabs(x[minIndex])) //порівнює модулі двох елементів (fabs - модуль)
            minIndex = i;
        return MinAbsIndex(x, size, i + 1, minIndex);
    }
    else
        return minIndex;
}

int FirstNegativeIndex(double* x, const int size, int i)
{
    if (i < size)
    {
        if (x[i] < 0) // пошук від'ємного
            return i; // повернення його номеру і вихід з функції
        else
            return FirstNegativeIndex(x, size, i + 1);
    }
    else
        return -1; // -1 бо такого номера не існує
}

double SumAbs(double* x, const int size, int i)
{
    if (i < size)
        return fabs(x[i]) + SumAbs(x, size, i + 1);
    else
        return 0;
}

double SumAbsAfterFirstNegative(double* x, const int size)
{
    int k = FirstNegativeIndex(x, size, 0);
    if (k == -1) // перевірка чи від'ємний існує
        return 0;
    else
        return SumAbs(x, size, k + 1);
}

int Compress(double* x, const int size, const double a, const double b, int i, int k)
{
    if (i < size)
    {
        if (x[i] < a || x[i] > b) //перевірка чи знаходиться елемент поза інтервалом [a, b]
        {
            x[k] = x[i];
            return Compress(x, size, a, b, i + 1, k + 1);
        }
        else
            return Compress(x, size, a, b, i + 1, k);
    }
    else
        return k; //повертає нову кількість елементів у масиві після стиснення
}

void FillZeros(double* x, const int size, int i)
{
    if (i < size)
    {
        x[i] = 0;
        FillZeros(x, size, i + 1); // від позиції from (k) до кінця масиву
    }
}
