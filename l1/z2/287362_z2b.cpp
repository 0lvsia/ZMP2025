#include <iostream>

using namespace std;

int nwd(int x, int y)
{
    while(x!=y)
		if(x>y)
			x=x-y;
		else
			y=y-x;

    return x;
}

int euler(int a)
{
    int ile=0;
    for(int i=1; i<=a; i++)
   {
        if (nwd(a,i)==1)
        {
            ile++;
        }
   }
   return ile;
}

int main()
{
    int n, d;
    cout << "zadanie 2b, dzielniki funkcji eulera; " << endl;
    cout << "podaj n" << endl;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        if(n%i==0 && i!=n/i)
        {
            d=d+euler(i);
        }
    }
    cout << d << endl;


    return 0;
}
