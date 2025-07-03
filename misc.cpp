#include <iostream>
#include <string>
using namespace std;
string removeVowels(const string& input)
{
    string result;
    const string vowels = "aeiouAEIOU";
    for (const char c : input)
    {
        if (vowels.find(c) == string::npos)
        {
            result.push_back(c);
        }
    }
    return result;
}

int main()
{
    string text = "Hello, World!";
    cout << "Text without vowels: " << removeVowels(text) << endl;


    const bool x = true;
    int y = x; // Narrowing conversion: bool to int
    cout << "y: " << y << endl;

    return 0;
}