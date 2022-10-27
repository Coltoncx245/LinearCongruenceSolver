#include <iostream>
#include <string>

// Function using Euclid's algorithm for finding GCD of two integer params
// If returns 1, params are relatively prime
int GCD(int a, int b)
{
	int r, larger, smaller;

	for (;;)
	{
		if (a >= b) { larger = a; smaller = b; }
		else { larger = b; smaller = a; }
		r = larger % smaller;
		if (r == 0) { return smaller; }
		else { a = smaller; b = r; }
	}
}

std::string LinearCombination(int r, int divid, int divis, int q)
{
	std::string remainder = std::to_string(r);
	std::string dividend = std::to_string(divid);
	std::string divisor = std::to_string(divis);
	std::string quotient = std::to_string(q);

	return remainder + " = " + "1(" + dividend + ")-" + quotient + "(" + divisor + ")\n";
}

int ModInverse(int a, int m)
{
	int dividend, divisor, q, r;

	if (a >= m) { dividend = a; divisor = m; }
	else { divisor = a; dividend = m; }
	q = dividend / divisor;
	r = dividend % divisor;
	std::cout << "A\tB\tQ\tR\tLinear Combination" << std::endl;

	while (r != 0) {
		printf("%i\t%i\t%i\t%i\t", dividend, divisor, q, r); std::cout << LinearCombination(r, dividend, divisor, q);
		dividend = divisor;
		divisor = r;
		q = dividend / divisor;
		r = dividend % divisor;

	}
	return r;
}




// Brute force algorithm (works?)
/*
int ModInverse(int a, int m)
{
	for (int i = 1; i < m; i++)
	{
		if ((i * a - 1) % m == 0)
		{
			return i;
		}
	}
}
*/

int main()
{
	ModInverse(34, 89);

	return 0;
}