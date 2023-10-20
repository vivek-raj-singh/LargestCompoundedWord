#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

bool isCompoundWord(const string &word, const vector<string> &wordList)
{
    if (word.empty())
    {
        return false;
    }

    int wordLength = word.size();
    for (int i = 1; i < wordLength; ++i)
    {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);

        if (find(wordList.begin(), wordList.end(), prefix) != wordList.end() &&
            (find(wordList.begin(), wordList.end(), suffix) != wordList.end() || isCompoundWord(suffix, wordList)))
        {
            return true;
        }
    }

    return false;
}

string findLongestCompoundWord(vector<string> &wordList)
{
    sort(wordList.begin(), wordList.end(), [](const string &a, const string &b)
         { return a.size() > b.size(); });

    for (const string &word : wordList)
    {
        if (isCompoundWord(word, wordList))
        {
            return word;
        }
    }

    return "";
}

int main()
{
    vector<string> words;
    ifstream inputFile("Input_02.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    string currentWord;
    while (getline(inputFile, currentWord))
    {
        words.push_back(currentWord);
    }

    inputFile.close();

    auto startTime = chrono::high_resolution_clock::now();
    string longestWord = findLongestCompoundWord(words);
    auto endTime = chrono::high_resolution_clock::now();

    auto processingTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    cout << "Longest Compound Word: " << longestWord << endl;
    words.erase(remove(words.begin(), words.end(), longestWord), words.end());
    string secondLongestWord = findLongestCompoundWord(words);
    cout << "Second Longest Compound Word: " << secondLongestWord << endl;
    cout << "Processing Time for Input_02.txt: " << processingTime.count() << " milliseconds." << endl;

    return 0;
}
