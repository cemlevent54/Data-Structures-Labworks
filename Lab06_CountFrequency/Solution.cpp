#include "WordFreq.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
#include "AVLTree.h"
#include "AVLNode.h"
using namespace std;


/// Clean word: remove non-alphabetic characters and convert to lowercase
string CleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c)) cleaned += tolower(c);
    }
    return cleaned;
}


///-----------------------------------------------------------------
/// Process the given text file and return the most frequent "k" words
///
vector<WordFreq> GetMostFrequentKWords(string filename, int k) {
    AVLTree wordFrequencyTree; // AVL a�ac�
    ifstream file(filename);
    string line, word;

    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return {};
    }

    // 1. Dosyay� oku ve kelimeleri AVL A�ac�na ekle
    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word) {
            word = CleanWord(word);
            if (word.length() >= 3) {
                wordFrequencyTree.insert(word);
            }
        }
    }

    file.close();

    // 2. T�m kelime ve frekanslar�n� al
    vector<pair<string, int>> words = wordFrequencyTree.getAllWords();

    // 3. Frekansa g�re s�ralama
    sort(words.begin(), words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second; // Frekans s�ralamas�
        return a.first < b.first; // Alfabetik s�ralama
        });

    // 4. �lk K kelimeyi se� ve d�nd�r
    vector<WordFreq> result;
    for (int i = 0; i < k && i < words.size(); i++) {
        WordFreq wordFreq(words[i].first);
        wordFreq.freq = words[i].second;

        result.push_back(wordFreq);
    }

    return result;

} //end-GetMostFrequentKWords

