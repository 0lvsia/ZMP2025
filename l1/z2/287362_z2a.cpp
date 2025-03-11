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

int main()
{

    int n, ile=0;
    cout << "zadanie 2a; funkcja eulera" << endl;
    cout << "podaj n" << endl;
    cin >> n;

    for(int i=1; i<=n; i++)
   {
        if (nwd(n,i)==1)
        {
            ile++;
        }
   }
    cout << ile;


    return 0;
}
