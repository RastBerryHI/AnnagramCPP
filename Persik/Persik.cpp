
#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

#include <stdio.h>
#include <Windows.h>

using namespace std;


class Anagram
{
private:
    string ShuffleLetters(string temp);
    int GenRandom(string temp);
public:
    Anagram() {};
    string GetAnnogram(string _word);
};

string Anagram::ShuffleLetters(string temp)
{
    setlocale(LC_ALL, "rus");

    for (int i = 0; i < temp.size(); i++)
    {
        swap(temp[i], temp[GenRandom(temp)]);
    }

    return temp;
}

int Anagram::GenRandom(string temp)
{
    srand((unsigned)time(0));

    int randomNumber = (rand() % temp.size()) + 0;
    return randomNumber;
}


string Anagram::GetAnnogram(string _word)
{
    setlocale(LC_ALL, "Rus");

    _word += ' ';

    string temp = "";
    string result;
    for (int i = 0; i <= _word.size(); i++)
    {
        if (_word[i] != ' ' && _word[i] != '.' && _word[i] != ',' && _word[i] != '!' && _word[i] != '?' && _word[i] != '/' && _word[i] != '{' && _word[i] != '}' && _word[i] != '(' && _word[i] != ')')
        {
            temp += _word[i];
        }
        else
        {
            result = result + ShuffleLetters(temp) + _word[i];
            temp = "";
        }
    }

    return result;
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Anagram* anagram = new Anagram();

    char input[2000] = "";
    gets_s(input);

    cout << anagram->GetAnnogram(input);

    return 0;
}

