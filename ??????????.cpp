#ifndef STRING_H 
#define STRING_H 

#include <malloc>
#include <clocale>
#include <cstddef> 
#include <iostream> 
#include <string> 



using namespace std;

class String
{
	
public:
	String(const char* = "");//конст преобразования(по умолчанию) 
	String(const String&);//конструктор копирования 
	~String();//деструктор 

	char *fname, *lname; /* тут дальше указатели на куски, которые тебе нужны */
	int lenght()const;
	int index()const;
	char OldWord()const;
	char NewWord()const;
	char delim()const;
	void append(const String &v);
	void substring(char str, int, int);
private:
	int length;
	size_t size;
	char *str;
};

void String::append(const String & v) {
	char * temp = new char[size + v.size + 1];
	for (int i = 0; i < size; ++i)
		temp[i] = str[i];
	for (int  j = 0; j < v.size; ++j)
		temp[size + j] = v.str[j];
	temp[size + v.size] = 0;

	delete[] str;
	str = temp;
	size += v.size;
}
void String::substring(char str, int index, int length)
{
	char resChar[255] = "";
	for (int i = index; i < (index + length); i++)
	{
		char c[2];
		sprintf_s(c, "%c", str[i]);
		strcat(resChar, c);
	}
	return resChar;
}

string string::split(char *delim, int lengt, char *str) {
	char *oldstr = (char*)malloc(lengt);
	strcpy(oldstr, str);
	char fname = strtok(str, "|); .азделитель "|" */
	printf("Firstname: %s\n", delim);
	free(oldstr);
	return 0;
}

void string::format(char* str, char OldWord, char NewWord) {
	
	char* str_2 = new char[100];

	cout << "Введите строку: ";// 
	cin.getline(str, 100);

	cout << "\n Ваша строка: ";
	for (int i = 0; i<strlen(str); i++)
	{
		cout << *(str + i);
	}
	cout << "\n\n Введите слово, которое хотите заменить: ";
	cin >> OldWord;
	cin.ignore();

	cout << "\n Введите слово, которым хотите заменить: ";
	cin >> NewWord;
	for (char* p = strtok(str, " ")){
		if (str[*p] == OldWord)
		{
			str_2[*p] = NewWord;
		}
		else
		{
			str_2[*p] = str[*p];
		}
	}
}
#endif
