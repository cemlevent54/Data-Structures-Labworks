#include <iostream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#include <string>


void Q1() {
    string str;
    cout << "Metin giriniz: ";
    getline(cin, str);

    unordered_set<char> uniqueChars;

    for (char c : str) {
        if (c != ' ') {
            uniqueChars.insert(c);
        }
    }

    cout << "Metindeki benzersiz karakterler: ";
    for (char c : uniqueChars) {
        cout << c << " ";
    }
    cout << endl;




}

void Q2() {
    unordered_multiset<int> borrowedBooks;
    string bookName;
    int barcode;

    while (true) {
        cout << "Kitap adi giriniz (Cikmak icin 'q' giriniz): ";
        getline(cin, bookName);
        if (bookName == "q") {
            break;
        }

        cout << "Barkod numarasi giriniz: ";
        cin >> barcode;
        cin.ignore();
        borrowedBooks.insert(barcode);
    }

    cout << "Bir kitabin barkod numarasini giriniz: ";
    cin >> barcode;
    int borrowCount = borrowedBooks.count(barcode);

    cout << barcode << " barkod numarali kitap " << borrowCount << " kez odunc alınmıstır." << endl;
}

void Q3() {
    multimap<string, int> studentScores;
    string studentName;

    while (true) {
        cout << "Ogrenci adi giriniz (Cikmak icin 'q' giriniz): ";
        cin >> studentName;
        if (studentName == "q") {
            break;
        }

        cout << "Notu giriniz: ";
        int score;
        cin >> score;

        studentScores.insert({ studentName, score });
    }

    cout << "Not araligi giriniz: ";
    int minScore, maxScore;
    cin >> minScore >> maxScore;

    cout << "Belirtilen araliktaki ogrenciler:\n";
    for (auto& entry : studentScores) {
        if (entry.second >= minScore && entry.second <= maxScore) {
            cout << entry.first << " " << entry.second << endl;
        }
    }
}


int main()
{
#if 1
    Q1();
#elif 0
    Q2();
#elif 0
    Q3();
#endif
}



