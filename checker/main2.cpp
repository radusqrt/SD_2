#include "backend.h"

int main()
{
	Backend b;
	b.Copy(5, 5);
	cout << b.GetText() << "\n";
	b.Paste(0);	cout << b.GetText() << "\n";
	b.Add(0, "mamaliga");	cout << b.GetText() << "\n";
	b.Copy(0, 9);	cout << b.GetText() << "\n";
	b.Paste(9);	cout << b.GetText() << "\n";
	return 0;
}
