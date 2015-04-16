#include "backend.h"

int main()
{
	Backend b;
	
	/*b.Add(0, "mamaliga");
	cout << b.GetText() << "\n";	
	b.Copy(3, 9);
	cout << b.GetText() << "\n";
	b.Copy(0, 3);
	cout << b.GetText() << "\n";
	b.Copy(2, 5);
	cout << b.GetText() << "\n";
	b.Copy(0, 9);
	cout << b.GetText() << "\n";
	b.Paste(9);
	cout << b.GetText() << "\n";
	b.Copy(3, 12);
	cout << b.GetText() << "\n";
	b.Paste(18);
	cout << b.GetText() << "\n";	
	b.Copy(-1, -3);
	cout << b.GetText() << "\n";
	b.Paste(9);
	cout << b.GetText() << "\n";
	b.Copy(4, 1);
	cout << b.GetText() << "\n";
	b.Paste(9);
	cout << b.GetText() << "\n";
	b.Copy(-1, 4000);
	cout << b.GetText() << "\n";
	b.Paste(9);
	cout << b.GetText() << "\n";*/

	b.Add(0, "mamaliga");
	cout << b.GetText() << "\n";
	b.Cut(0, 9);
	cout << b.GetText() << "\n";
	b.Add(0, "mamaliga");
	cout << b.GetText() << "\n";
	b.Add(9, "cu");
	cout << b.GetText() << "\n";
	b.Add(12, "smantana");
	cout << b.GetText() << "\n";
	b.Cut(9, 12);
	cout << b.GetText() << "\n";
	b.Cut(9, 18);
	cout << b.GetText() << "\n";
	b.Add(9, "cu");
	cout << b.GetText() << "\n";
	b.Add(12, "smantana");
	cout << b.GetText() << "\n";
	b.Cut(0, 12);
	cout << b.GetText() << "\n";
	b.Add(0, "mamaliga");
	cout << b.GetText() << "\n";
	b.Add(9, "cu");
	cout << b.GetText() << "\n";
	b.Cut(0, 22);
	cout << b.GetText() << "\n";
	return 0;
}
