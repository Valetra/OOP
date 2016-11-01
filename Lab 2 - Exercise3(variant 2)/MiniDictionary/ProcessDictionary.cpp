#include "ProcessDictionary.h"
#include "ProcessErrors.h"

bool WriteFoundWordsOfTranslation(map<string, string> &dictionary, string &word)
{
	if (dictionary.find(word) != dictionary.end())
	{
		cout << word << " translation is " << dictionary.at(word) << '\n';
		return true;
	}
	else
	{
		bool found = false;
		for (auto wordInDictionary : dictionary)
		{
			if (word == wordInDictionary.second)
			{
				cout << wordInDictionary.second << " translation is " << wordInDictionary.first << '\n';
				found = true;
				return found;
			}
		}
		if (!found)
		{
			cout << word << " is not found\n";
			return found;
		}
	}
	return false;
}

void ReadDictionaryFromFile(fstream &dictionaryFile, map<string, string> &dictionary)
{
	string line;
	while (getline(dictionaryFile, line))
	{
		size_t i = 0;

		string firstWord;
		for (i; i < line.length() && line[i] != ':'; ++i)
		{
			firstWord += line[i];
		}

		string secondWord;
		for (++i; i < line.length(); ++i)
		{
			secondWord += line[i];
		}
		ToLowerCase(firstWord);
		ToLowerCase(secondWord);
		dictionary.insert(pair<string, string>(firstWord, secondWord));
	}
}

void ToLowerCaseRussianWord(string &word)
{
	for (size_t i = 0; i < word.length(); ++i)
	{
		switch (word[i])
		{
		case 'A':
			word[i] = 'a';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		case '�':
			word[i] = '�';
			break;
		}
	}
}

void ToLowerCase(string &word)
{
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	ToLowerCaseRussianWord(word);
}

void CreateNewWord(string &word, map<string, string> &dictionary, bool &wasChanges)
{
	string answer;
	cout << "����������� ����� �" << word << "�. ������� ������� ��� ������ ������ ��� ������.\n";
	getline(cin, answer);
	ToLowerCase(answer);
	if (!answer.empty())
	{
		dictionary.insert(pair<string, string>(word, answer));
		cout << "����� �" << word << "� ��������� � ������� ��� �" << answer << "�.\n";
		wasChanges = true;
	}
	else
	{
		cout << "����� �" << word << "� ���������������.\n";
	}
}

void WriteDictionaryToFile(map<string, string> &dictionary, bool &saveChanges, string dictionaryFileName)
{
	if (saveChanges)
	{
		fstream dictionaryFile(dictionaryFileName, ios::out);
		for (map<string, string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		{
			dictionaryFile << i->first << ":" << i->second << endl;
		}
		dictionaryFile.close();
	}
}

void ProcessWords(map<string, string> &dictionary, bool &saveChanges, fstream &dictionaryFile)
{
	ReadDictionaryFromFile(dictionaryFile, dictionary);

	string word;
	bool wasChanges = false;

	while (true)
	{
		getline(cin, word);
		if (word.empty())
		{
			cout << "���� ������� ������ ������\n";
		}
		else
		{
			ToLowerCase(word);
			if (word == "..." && wasChanges)
			{
				string answer;
				cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
				getline(cin, answer);
				ToLowerCase(answer);
				if (answer == "y")
				{
					saveChanges = true;
					cout << "��������� ���������. �� ��������.";
				}
				break;
			}
			else if (word == "..." && !wasChanges)
			{
				cout << "������� �� ��� �������. �� ��������.\n";
				break;
			}
			if (dictionary.find(word) != dictionary.end())
			{
				cout << dictionary.at(word) << '\n';
			}
			else
			{
				bool found = false;
				for (auto wordInDictionary : dictionary)
				{
					if (word == wordInDictionary.second)
					{
						cout << wordInDictionary.first << '\n';
						found = true;
					}
				}
				if (!found)
				{
					CreateNewWord(word, dictionary, wasChanges);
				}
			}
		}
	}
}