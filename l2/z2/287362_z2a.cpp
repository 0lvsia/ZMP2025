#include <iostream>

//poszukiwana liczba calkowita x - szukana
// dlugosc ciagu n - ileliczb

using namespace std;

int main()
{
    int ileliczb, szukana, indeks=0;
    bool czy=false;
    cout << "podaj szukana" << endl;
    cin >> szukana;
    cout << "podaj ile liczb" << endl;
    cin >> ileliczb;
    int t[ileliczb];

    for(int i=0; i<ileliczb; i++)
    {
        cout << "podaj " << i+1 << " liczbe ";
        cin >> t[i];
    }

    //jak nic nie wiemy o porzadku liczb no to porownuje szukana z kazda liczba z tabeli
    for(int i=0; i<ileliczb; i++)
    {
        if(t[i]==szukana)
        {
            czy=true;
            indeks=i;
            break;
        }else czy=false;
    }
    if(czy) cout << "tak " << indeks; else cout << "nie";




    return 0;
}
