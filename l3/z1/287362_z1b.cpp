//fibonaci rekurencja

/*
szybkie potegowanie fibonacciego
F(2k) = F(k) * (2F(k+1) - F(k))
F(2k+1) = F(k+1)^2 + F(k)^2

jesli znamy F(k) i F(k+1) to w jednym kroku mozna liczyc F(2k) i F(2k+1)


niby dziala dla n=10^8 ale chyba nie powinny wychodzic minusowe wartosci...
*/

#include <iostream>
#include <vector>

using namespace std;


long long fibonacci(long long n, long long &b)
{
     if (n == 0)
    {
        b = 1;
        return 0;
    }

    long long a = fibonacci(n / 2, b);
    long long c = a * (2 * b - a);  // F(2k) = F(k) * (2F(k+1) - F(k))8
    long long d = b * b + a * a;    // F(2k+1) = F(k+1)^2 + F(k)^2

    if (n % 2 == 0) {
        b = d;
        return c;
    } else {
        b = c + d;
        return d;
    }
}
int main()
{
    long long n, b;
    cout << "podaj n ";
    cin >> n;

    cout << fibonacci(n, b) << endl;

    return 0;
}
