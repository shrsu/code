#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string inputString ="10 5 2 * +";
    vector<string> words;
    string word;

    // Using std::stringstream to split the string
    stringstream ss(inputString);

    // Read each word separated by space
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Print the array of words
    for (const auto &w : words)
    {
        cout << w << endl;
    }

    return 0;
}
