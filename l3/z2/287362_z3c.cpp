// podzbiory dokladnie k

#include <iostream>

using namespace std;

// pz tablica do podzbiorow
// npz wielkosc tablicy do podzbiorow

void podzbior(int t[], int n, int i, int pz[], int npz, int k )
{

    if(i==n)
    {
        if(npz==k)
        {
            for(int i=0; i<npz; i++)
            {
                if(i>0) cout << " "; cout << pz[i];
            }
        }
        cout << endl;
        return;
    }

    podzbior(t, n, i+1, pz, npz, k);
    pz[npz]=t[i];
    podzbior(t, n, i+1, pz, npz+1, k);

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

   int k;
   cout << "podaj k " << endl;
   cin >> k;

    podzbior(t, n, 0, pz, 0, k);

    return 0;
}
