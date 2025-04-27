#include <iostream>

using namespace std;

int maks(int t[], int lewa, int prawa)
{
    if(lewa>=prawa) return 0;
    int srodek=(lewa+prawa)/2;

    //roznica w lewej i prawej polowie
    int lewaroznica=maks(t, lewa, srodek);
    int prawaroznica=maks(t, srodek+1, prawa);

    //minimum w lewej
    int minlewa=t[lewa];
    for(int i=lewa+1; i<=srodek; i++)
        if (t[i]<minlewa) minlewa=t[i];

    //maksimum w prawej
    int maxprawa=t[srodek+1];
    for(int i=srodek+2; i<=prawa; i++)
        if(t[i]>maxprawa) maxprawa=t[i];

    //roznica miedzy polowami
    int roznica=maxprawa-minlewa;

    //zwracanie maksa
    int maksymalna=lewaroznica;
    if(prawaroznica>maksymalna)
    {
        maksymalna=prawaroznica;
    }
    if(roznica>maksymalna)
    {
        maksymalna=roznica;
    }
    return maksymalna;
}

int main()
{
    int n;
    cout << "podaj rozmiar tablicy ";
    cin >> n;
    int t[n];

    for(int i=0; i<n; i++)
    {
        cout << "podaj " << i+1 << " element tablicy ";
        cin >> t[i];
    }

    int wynik=maks(t, 0, n-1);
    cout << "maksymalna roznica " << wynik;


    return 0;
}
