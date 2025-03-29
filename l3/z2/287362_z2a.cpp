// wszystkie podzbiory

#include <iostream>

using namespace std;

// pz tablica do podzbiorow
// npz wielkosc tablicy do podzbiorow

void podzbior(int t[], int n, int i, int pz[], int npz )
{
    if(i==n)
    {
        if(npz==0)
        {
            cout << "empty";
        } else
        {
            for(int i=0; i<npz; i++)
            {
                if(i>0) cout << " "; cout << pz[i];
            }
        }
        cout << endl;
        return;
    }

    podzbior(t, n, i+1, pz, npz);
    pz[npz]=t[i];
    podzbior(t, n, i+1, pz, npz+1);

}

int main()
{
   int n;
   cout << "podaj n " << endl;
   cin >> n;
   int t[n], pz[n];

   for(int i=0; i<n; i++)
   {
       cout << "podaj " << i+1 << " element tablicy ";
       cin >> t[i];
   }

    podzbior(t, n, 0, pz, 0);

    return 0;
}
