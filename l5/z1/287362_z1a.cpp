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

    int ile=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(i==j) continue;

            if (t[i]>t[j])
            {

                ile++;
            }
        }
    }

    cout << ile;

    return 0;
}
