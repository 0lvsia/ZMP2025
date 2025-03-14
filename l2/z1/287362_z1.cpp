#include <iostream>

using namespace std;

int nwd(int a, int b)
{
     while(a != b)
    {
        if (a>b) a=a-b;
            else b=b-a;
    }
    return a;
}

int main()
{
    int ileliczb, d;
    cout << "podaj ile liczb" << endl;
    cin >> ileliczb;
    int t[ileliczb];

    for(int i=0; i<ileliczb; i++)
    {
        cout << "podaj " << i+1 << " liczbe ";
        cin >> t[i];
    }
    d=t[0];

    for(int i=1; i<ileliczb; i++)
    {
        d=nwd(t[i], d);
    }
    cout << d << endl;


    return 0;
}
