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

    int ile=0, temp[n], krok=1;
    //krok to rozmiar akutalnie sortowanych podtablic

     while(krok<n)
    {
        //przechodzi przez tablice o 2*krok
        for(int poczatek=0; poczatek<n; poczatek=poczatek+2*krok)
        {
            //granice podtablic
            int srodek = min(poczatek+krok-1, n-1); // lewa podtablica
            int koniec = min(poczatek+2*krok-1, n-1); // prawa podtablica

            int i=poczatek, j=srodek+1, k=poczatek;

            //scalanie dwoch podtablic
            while(i<=srodek && j<=koniec)
            {
                if(t[i]<=t[j])
                {
                    temp[k++]=t[i++];
                }
                else
                {
                        ile+=srodek-i+1;
                        temp[k++]=t[j++];
                }

            }

            while(i<=srodek) temp[k++]=t[i++]; //kopiowanie pozostalych do lewej podtablicy
            while(j<=koniec) temp[k++]=t[j++]; // -||- do prawej podtablicy
        }

        for(int i=0; i<n; i++) t[i]=temp[i]; //kopiowanie posortowanej tablicy pomocniczej z powrotem do glownej

        krok=krok*2; //podwaja rozmiar sortowanych podtablic
    }

    cout << ile;

    return 0;
}
