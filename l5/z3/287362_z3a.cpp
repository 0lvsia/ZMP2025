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

    int maks=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j=j+1)
        {
            if(i==j) continue;

            if(t[j]-t[i]>maks) maks=t[j]-t[i];
        }
    }

    cout << "maksymalna roznica " << maks;

    return 0;
}
