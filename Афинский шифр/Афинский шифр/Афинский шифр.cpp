// Афинский шифр
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Crypto
{
public:
	string enCode(string text)
	{
		string result;

		for (unsigned i = 0; i < text.length(); i++)
			for (unsigned j = 0; j < 26; j++)
				if (text[i] == sh[j])
				{
					index = (3 * k + 4) % 26; //a=3 b=4
					result += sh[index];
					k = 0;
					break;
				}
				else k++;
		return result;
	}
	string deCode(string text)
	{
		string result;

		for (unsigned i = 0; i < text.length(); i++)
			for (unsigned j = 0; j < 26; j++)
				if (text[i] == sh[j])
				{
					index = (9 * (k + 26 - 4)) % 26;  //a=3 b=4
					result += sh[index];
					k = 0;
					break;
				}
				else k++;
		return result;
	}
private:
	string sh = "abcdefghijklmnopqrstuvwxyz";
	int k = 0;
	int index = 0;
};

void inputConsole(string& inputStr)
{
	cout << "Введите текст> ";
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	getline(cin, inputStr, '\n');
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int input;
	string  res, inputStr, decryptRes;

	Crypto crypto;
	while (true)
	{
		cout << "(0)Выход\n";
		cout << "(1)Зашифровать\n";
		cout << "(2)Расшифровать\n";
		cout << "> ";
		cin >> input;
		switch (input)
		{
		case 1://Шифрование
			inputConsole(inputStr);
			res = crypto.enCode(inputStr);
			cout << "Зашифрованный текст: \"" << res << "\"" << endl;
			break;
		case 2://Дешифрование
			inputConsole(inputStr);

			decryptRes = crypto.deCode(inputStr);
			cout << "Дешифрованный текст: \"" << decryptRes << "\"" << endl;
			break;
		case 0: //Выход из программы
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}