#include <iostream>
#include <string>

using namespace std;

/*
В строке текста записаны слова, разделенные пробелами в произвольном количестве. Сжатие текста состоит
в том, что между словами оставляется по одному пробелу, а после последнего слова пробелы удаляются (пробелы
перед первым словом сохраняются). Если строка содержит только пробелы, то все они сохраняются.
Написать функцию, сжимающую описанным образом текст.
*/

void Str_compressing(string str)
{
    cout << "length = " << str.length() << endl;
    cout << "Text = " << str << endl;
    cout << "Spaces = " << std::count(str.begin(), str.end(), ' ') << '\n';

	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))									
		{
			for (int j = 0; j < str.length(); j++)
			{
				if (isspace(str[j]) && isspace(str[j + 1]))	
				{
					str.erase(j + 1, 1);						
					j--;
				}
			}											    
		}
	}
	cout << str;
}

int main()
{
    string str = "Text      test for   the    sake       of tests     test ";
    Str_compressing(str);
    return 0;
}
