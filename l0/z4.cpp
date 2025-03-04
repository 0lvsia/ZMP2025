//aleksandra cichecka

#include <iostream>

using namespace std;

int main()
{
	int intowa=100;
	short int shortowa;
	char charowa;
	unsigned int unsignedowaint;

	shortowa = intowa;
	charowa = intowa;

    cout << "wieksze na mniejsze" << endl;
	cout << intowa << endl;
	cout << shortowa << endl;
	cout << charowa << endl; //daje w ascii 100 to d wiec d

	cout << "mniejsze na wieksze" << endl;
	unsignedowaint = intowa;
	cout << intowa << endl;


	return 0;
}
