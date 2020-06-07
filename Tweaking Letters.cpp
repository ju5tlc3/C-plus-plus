//Perform a letter shift according to given shift number


#include<iostream>
#include<string>
#include<vector>


std::string tweakLetters(std::string word, std::vector<int> arr)
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	size_t alphabet_size = alphabet.size();
	for (size_t i = 0; i < word.size(); i++)
	{
		size_t pos;
		for (size_t j = 0; j < alphabet.size(); j++)
		{
			if (alphabet[j] == word[i])
			{
				pos = j;
				break;
			}
		}
		word[i] = alphabet[(pos + arr[i] + alphabet_size) % alphabet_size];
	}
	return word;
}


int main()
{
	std::cout << tweakLetters("xyz", { 1, 1, 1 }) << std::endl;
	std::cout << tweakLetters("abc", { -1, -1, -1 }) << std::endl;
	std::cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << std::endl;
	system("pause");
	return 0;
}