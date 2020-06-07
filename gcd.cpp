//GCD realization. No something additional needed

#include<iostream>

int gcd(int, int);

int gcd(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a + b;
}

int main()
{
	int a, b;
	std::cout << "Please enter two numbers: ";
	std::cin >> a >> b;
	std::cout << "Gcd is equal to " << gcd(a, b) << std::endl;
	system("pause");
	return 0;
}