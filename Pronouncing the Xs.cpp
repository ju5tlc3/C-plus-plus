/*
Replace all x's with "cks" UNLESS:

The word begins with "x", therefore replace it with "z".
The word is just the letter "x", therefore replace it with "ecks".
*/
#include<iostream>
#include<string>
#include<vector>
#include <regex>

void xPronounce(std::string);

void xPronounce(std::string sentence)
{
	std::string temp;
	std::vector<std::string> words;
	for (size_t i= 0; i < sentence.size(); i++)
	{
		if (sentence[i] == ' ' || i == sentence.size() - 1)
		{
			if (i == sentence.size() - 1)
			{
				temp += sentence[i];
			}
			words.push_back(temp);
			temp.clear();
		}
		else
		{
			temp += sentence[i];
		}
	}
	for (auto& word : words)
	{
		if (count(word.begin(), word.end(), 'x') > 0)
		{
			if (word == "x")
			{
				word = "ecks";
				continue;
			}
			if (word[0] == 'x')
			{
				word[0] = 'z';
			}
			auto it = find(word.begin() + 1, word.end(), 'x');
			while (it != word.end())
			{
				*it = 'c';
				word.insert(++it, 'k');
				word.insert(++it, 's');
				it = find(++it, word.end(), 'x');
			}
		}
	}
	for (const auto& word : words)
	{
		std::cout << word << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int choice;
	std::cout << "If you want to test examples, enter 0, otherwise enter 1: ";
	std::cin >> choice;
	if (choice == 0)
	{
		std::string str = "Inside the box was a xylophone";
		std::string str2 = "The x ray is excellent";
		std::string str3 = "OMG x box unboxing video x D";
		std::cout << str << " -> ";
		xPronounce(str);
		std::cout << str2 << " -> ";
		xPronounce(str2);
		std::cout << str3 << " -> ";
		xPronounce(str3);
	}	
	else
	{
		std::string sentence;
		std::cout << "Please enter a sentence: ";
		getline(std::cin, sentence);
		xPronounce(sentence);
	}
	system("pause");
	return 0;
}