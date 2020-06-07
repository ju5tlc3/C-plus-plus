//Calculate the subtraction between a given number and the same number with sorted digits.

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>  

int func(int);

int func(int a)
{
	int res;
	std::vector<int> temp;
	for (int i = 0; ; i++)
	{
		res = a / pow(10, i);
		if (res == 0)
		{
			break;
		}
		res %= 10;
		temp.push_back(res);
	}
	sort(temp.begin(), temp.end(), std::greater<int>());
	int sorted = 0;
	for (size_t i = 0; i < temp.size(); i++)
	{
		sorted += temp[i] * pow(10, i);
	}
	return a - sorted;

}

int main()
{
	int a;
	std::cin >> a;
	std::cout << std::endl;
	std::cout << func(a);
	system("pause");
	return 0;
}