//Aleksandra Cichecka

#include <iostream>

using namespace std;

int main()
{
    int n=0, ile=1;
    cout << "zadanie 1" << endl;
    cout << "podaj n" << endl;
    cin >> n;

    while(n!=1)
    {
        cout << " ";
        if(n%2==0)
        {
            n=n/2;
            cout << n;
        } else
            {
            n=3*n+1;
            cout << n;
            }
        ile++;
    }
    cout << ", " << ile;

    //tak kazda w koncu uderza w 1 :)

    return 0;
}
