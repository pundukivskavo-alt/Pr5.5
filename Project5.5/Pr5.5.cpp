// Лабораторна робота № 5.5
// Варіант 20: a1 = 1, a(n) = (2*a(n-1) + 8 / a(n-1)^2) / 3, n > 1
// Знайти межу послідовності при n -> нескінченність та глибину рекурсії

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// a     – поточний член послідовності a(level)
// level – рівень рекурсії (параметр-значення), збігається з номером члена
// depth – глибина рекурсії (параметр-посилання)
// eps   – точність: зупиняємось, коли |a(n+1) - a(n)| < eps
double Lim(const double a, const int level, int& depth, const double eps)
{
    if (level > depth)
        depth = level;

    // вивід поточного рівня та члена послідовності (дія на спуску)
    cout << "level = " << setw(2) << level << "   a = " << a << endl;

    double next = (2 * a + 8 / (a * a)) / 3;    // наступний член послідовності

    if (fabs(next - a) < eps)
        return next;                            // умова закінчення рекурсії
    else
        return Lim(next, level + 1, depth, eps);
}

int main()
{
    double eps;
    cout << "eps = "; cin >> eps;

    cout << fixed << setprecision(10);

    int depth = 0;                              // початкове значення глибини
    double L = Lim(1.0, 1, depth, eps);         // a1 = 1, початковий рівень 1

    cout << "limit = " << L << endl;
    cout << "depth = " << depth << endl;

    return 0;
}