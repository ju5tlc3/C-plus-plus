//Universal method for calculating square (x*x) for all possible types of data

#include<iostream>
#include<map>
#include<vector>
#include<exception>

using namespace std;

template<typename T> T Sqr(const T& x);
template<typename key, typename value> pair<key, value> Sqr(const pair<key, value>& x);
template<typename key, typename value> map<key, value> Sqr(const map<key, value>& x);
template<typename T> vector<T> Sqr(const vector<T>& x);



template<typename T> T Sqr(const T& x)
{
	return x * x;
}

template<typename key, typename value> pair<key, value> Sqr(const pair<key, value>& x)
{
	return make_pair(Sqr(x.first), Sqr(x.second));
}

template<typename key, typename value> map<key, value> Sqr(const map<key, value>& x)
{
	map<key, value> temp;
	for (auto& item : x)
	{
		temp[item.first] = Sqr(item.second);
	}
	return temp;
}


template<typename T> vector<T> Sqr(const vector<T>& x)
{
	vector<T> temp;
	for (auto& s : x)
	{
		temp.push_back(Sqr(s));
	}
	return temp;
}



int main()
{
	vector<int> v = {1,2,2,2};
	for(const auto& s : v)
	{
		cout << s << " ";
	}
	cout << endl;
	return 0;
}