#include <iostream>

using namespace std;

int main()
{
    int dlugosc=8;
    int sekret, wiadomosc;
    int s[dlugosc], w[dlugosc], sw[dlugosc];

    // podawanie sekretu
    cout << "podaj 8 cyfr do sekretu " << endl;
    for(int i=0; i<dlugosc; i++)
    {
        cin >> s[i];
    }
    //podawanie wiadomosci
    cout << "podaj 8 cyfr do wiadomosci" << endl;
    for(int i=0; i<dlugosc; i++)
    {
        cin >> w[i];
    }

    //szyfrowanie
    for(int i=0; i<dlugosc; i++)
    {
        sw[i]=s[i]^w[i];
    }

    //wypisywanie szyfrowania
    for(int i=0; i<dlugosc; i++)
    {
        cout << sw[i] << " ";
    }

    return 0;
}
