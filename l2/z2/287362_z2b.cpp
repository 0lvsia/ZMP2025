#include <iostream>
using namespace std;


int main()
{
    int ileliczb, szukana, indeks=0;

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

    //i tutaj uzywam wyszukiwania binarnego wedlug podpowiedzi patrzac na cwiczenie 6 :D

    bool czy=false;
    int poczatek=0, koniec=ileliczb-1, srodek;

    while (poczatek <= koniec)
    {
        srodek = (poczatek + koniec) / 2;
        if(t[srodek] == szukana)
        {
            czy=true;
            indeks=srodek;
        }
        if(t[srodek] > szukana) koniec = srodek - 1;
        	else poczatek = srodek + 1;
    }
    if (czy) cout << "tak " << indeks; else cout <<"nie" << endl;



    return 0;
}
