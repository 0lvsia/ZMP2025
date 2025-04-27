#include <iostream>

using namespace std;

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
    int temp[n], krok = 1;

    while(krok<n)
    {
        for(int poczatek=0; poczatek<n; poczatek=poczatek+2*krok)
        {
            int srodek=min(poczatek+krok, n);
            int koniec=min(poczatek+2*krok, n);

            int i=poczatek, j=srodek, k=poczatek;


            while(i<srodek && j<koniec)
            {
                if(t[i]<=t[j])
                {
                    temp[k++]=t[i++];
                }
                else
                {
                        temp[k++]=t[j++];
                }

            }

            while(i<srodek) temp[k++]=t[i++];
            while(j<koniec) temp[k++]=t[j++];
        }

        for(int i=0; i<n; i++) t[i]=temp[i];

        krok=krok*2;

    }


    cout << "posortowana tablica ";
    for(int i=0; i<n; i++)
    {
        cout << t[i] << " ";
    }


    return 0;
}
