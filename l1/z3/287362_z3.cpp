#include <iostream>

using namespace std;

int main()
{
    //oblicza liczby zero przez n/5^k gdzie k=(1,2,3,4, ...)

    int n, ile=0;
    cout << "zadanie 3" << endl;
    cout << "podaj n" << endl;
    cin >> n;

    for(int i=5; n>=i; i=i*5)
    {
        ile=ile+n/i;
    }
    cout << ile;

    return 0;
}
