
#include <iostream>
#include <string>

#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include <stdio.h>
#include <Windows.h>

using namespace std;

// Обьявление статического класса
static class Anagram
{
// Секция для функций внутреннего использования
private:
    static string ShuffleLetters(string temp); // Функция для перемешивания букв в вырезанном слове
    static int GenRandom(string temp);  // Функция генерирования случайного числа в диапазоне длинны слова
// Секция для внешнего вызова
public:
    static string GetAnnogram(string _word);    // Функция принимяющая входные данные и возвращающая аннограму 
};

/*Внешнее определение методов класса*/

string Anagram::ShuffleLetters(string temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        // Меняет местами буквы в слове
        swap(temp[i], temp[GenRandom(temp)]);
    }

    return temp;
}


int Anagram::GenRandom(string temp)
{
    srand((unsigned)time(0));

    // Сгенериоовать случайное число в диапазоне от начала слова и до его конца
    int randomNumber = (rand() % temp.size()) + 0;
    return randomNumber;
}


string Anagram::GetAnnogram(string _word)
{
    setlocale(LC_ALL, "Rus");

    // Добавление отступа в конце слова (фиксит баг с пропаданием последнего слова в строке)
    _word += ' ';

    // Переменные результата и промежуточных операций
    string result, temp = "";

    for (int i = 0; i <= _word.size(); i++)
    {
        // Обход знаков разделения и препинания
        if (_word[i] != ' ' && _word[i] != '.' && _word[i] != ',' && _word[i] != '!' && _word[i] != '?' && _word[i] != '/' && _word[i] != '{' && _word[i] != '}' && _word[i] != '(' && _word[i] != ')')
        {
            // Записать в промежуточную переменную слово
            temp += _word[i];
        }
        else
        {
            // Перемешать слово и добавить в результирующую переменную
            result = result + ShuffleLetters(temp) + _word[i];
            // Обнулить промежуточную переменную
            temp = "";
        }
    }

    // Вернуть результат
    return result;
}

// Остановка выполнения
void AbortOP(string command)
{
    if (command == "0")
        exit(0);
}

int main()
{   
    // Установки кодировки для потока ввода и вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Слово для ввода
    char input[2000] = "";

    cout << "Для завершение введите 0" << endl;

    while (input != "0      ")
    {
        cout << "Введите строку: ";
        // Сохранение ввода в переменную
        gets_s(input);

        // Завершаение программы пользователем
        AbortOP(input);

        // Вызов функции
        cout << Anagram::GetAnnogram(input)<<endl;
    }
    return 0;
}

