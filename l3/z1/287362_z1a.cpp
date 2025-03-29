//fibonaci petla

#include <iostream>

using namespace std;

int main()
{
    int n, suma, a, b;
  	cout << "podaj n ";
  	cin >> n;

  	if (n<3) cout << 1 << endl;
  	else if (n==0) cout << 0 << endl;

  	else
  	{
    	a=1;
    	b=1;
    	for (int i=3; i<=n; i++)
    	{
    	     suma=a+b;
    	     b=a;
    	     a=suma;
    	}
    	cout << suma << endl;
    }

    return 0;
}
