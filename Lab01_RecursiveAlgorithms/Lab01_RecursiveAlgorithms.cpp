#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define MAX_BLOB_NUMBER 100

using namespace std;

struct Blob {
    int no;
    int numberOfBlobPixels;
    float x;
    float y;
};

// Metin dosyasından satır sayısını okur
int getNumberOfRows(string fileName);
// Metin dosyasından sütun sayısını okur
int getNumberOfColumns(string fileName);

// Satır ve sütuna göre dinamik olarak 2D dizi oluşturur ve geri döner
char** allocateMatrix(int rows, int cols);

// Gereksiz RAM erişimini önlemek için matrisi varsayılan karakter (-) ile başlatır
char** initializeMatrix(char** arr, int rows, int cols);

// Satır ve sütun bilgilerini kullanarak metin dosyasından matrisi okur ve nihai matrisi döndürür
char** loadMatrixFromFile(char** arr, string fileName, int rows, int cols);

// Matrisi tablo şeklinde satır ve sütunlara göre yazdırır
void displayMatrix(char** arr, int rows, int cols);
void displayHeader(int cols);
void displayFooter(int cols);

// Her bir Blob'un bilgilerini hesaplar
void processBlob(int row, int col, int& blobSize, float& centerX, float& centerY, char** grid, int rows, int cols);

// Her bir Blob'un bilgilerini yazdırır
void displayBlobDetails(Blob BlobArray[], int blobNumber);

int main()
{
    string fileName = "blobs1.txt";

    // Dosya bulunamazsa hata verir
    if (getNumberOfRows(fileName) == -1) {
        cout << "Dosya bulunamadı." << endl;
        return 1;
    }

    // Satır ve sütun sayılarını alır
    int rows = getNumberOfRows(fileName);
    int cols = getNumberOfColumns(fileName);

    // Matrisi dinamik olarak oluşturur
    char** matrix = allocateMatrix(rows, cols);

    // Matrisi dosyadan okur
    matrix = loadMatrixFromFile(matrix, fileName, rows, cols);

    // Matrisi ekrana yazdırır
    displayMatrix(matrix, rows, cols);
    cout << endl << endl << endl;

    Blob BlobArray[MAX_BLOB_NUMBER];

    int blobNumber = 0;
    int k = 0;
    // Tüm matrisi tarar ve blob'ları bulur
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Blob başlangıcını bulur
            if (matrix[i][j] == 'x') {
                int blobSize = 0;
                float centerX = 0;
                float centerY = 0;
                // Blob'u işler ve boyutunu, merkezi hesaplar
                processBlob(i, j, blobSize, centerX, centerY, matrix, rows, cols);

                if (blobSize > 0) {
                    blobNumber++;
                    centerX /= blobSize;
                    centerY /= blobSize;

                    BlobArray[k].no = blobNumber;
                    BlobArray[k].numberOfBlobPixels = blobSize;
                    BlobArray[k].x = centerX;
                    BlobArray[k].y = centerY;

                    k++;
                }
            }
        }
    }

    // Blob bilgilerini ekrana yazdırır
    displayBlobDetails(BlobArray, blobNumber);

    return 0;
}

// Dosyadan satır sayısını okur
int getNumberOfRows(string fileName) {

    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return -1;
    }

    int row;
    file >> row;

    file.close();

    return row;
}

// Dosyadan sütun sayısını okur
int getNumberOfColumns(string fileName) {

    ifstream file;
    file.open(fileName);

    int column;
    file >> column;
    file >> column;

    file.close();

    return column;
}

// Dinamik olarak bellek tahsis eder ve matrisi oluşturur
char** allocateMatrix(int rows, int cols) {

    char** matrix = new char* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
    }

    // Matrisi varsayılan karakterle (-) başlatır
    matrix = initializeMatrix(matrix, rows, cols);

    return matrix;
}

// Matrisi varsayılan karakter (-) ile doldurur
char** initializeMatrix(char** arr, int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = '-';
        }
    }

    return arr;
}

// Dosyadan matrisi okur ve diziyi doldurur
char** loadMatrixFromFile(char** arr, string fileName, int totalRows, int totalCols) {

    char character;

    ifstream file(fileName);
    int trash;
    file >> trash;
    file >> trash;
    file.get(character);

    int row = 0, column = 0;
    while (file.get(character)) {

        if (character == '\n') {
            continue; // Satır sonu karakterlerini atlar
        }

        if (row < totalRows && column < totalCols) {
            arr[row][column] = character;
            column++;
        }

        if (column == totalCols) {
            column = 0;
            row++;
        }

    }

    file.close();

    return arr;
}

// Matrisi tablo halinde yazdırır
void displayMatrix(char** arr, int rows, int cols) {

    displayHeader(cols);

    for (int i = 0; i < rows; i++) {
        if (i < 10)
            cout << " ";

        cout << i << "|";
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j];
        }
        cout << "|" << i << endl;
    }

    displayFooter(cols);
}

// Tablonun üst kısmını yazdırır
void displayHeader(int cols) {

    cout << "   ";
    for (int i = 0; i < cols; i++) {
        cout << i % 10;
    }
    cout << endl;

    cout << "  +";
    for (int i = 1; i <= cols; i++)
        cout << "-";
    cout << "+" << endl;
}

// Tablonun alt kısmını yazdırır
void displayFooter(int cols) {

    cout << "  +";
    for (int i = 1; i <= cols; i++)
        cout << "-";
    cout << "+" << endl;

    cout << "   ";
    for (int i = 0; i < cols; i++) {
        cout << i % 10;
    }
}

// Her bir blob'u işler ve boyutunu, merkezi hesaplar
void processBlob(int row, int col, int& blobSize, float& centerX, float& centerY, char** arr, int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || arr[row][col] != 'x') {
        return;
    }

    blobSize++;
    centerX += col;
    centerY += row;
    arr[row][col] = ' ';

    processBlob(row - 1, col, blobSize, centerX, centerY, arr, rows, cols);
    processBlob(row + 1, col, blobSize, centerX, centerY, arr, rows, cols);
    processBlob(row, col - 1, blobSize, centerX, centerY, arr, rows, cols);
    processBlob(row, col + 1, blobSize, centerX, centerY, arr, rows, cols);
}

// Blob bilgilerini tablo şeklinde yazdırır
void displayBlobDetails(Blob BlobArray[], int blobNumber) {
    cout << "+----------------------------------------------+" << endl;
    cout << "| Blob   | NoOfPixels   | CoM Row | CoM Column |" << endl;
    cout << "+----------------------------------------------+" << endl;

    for (int i = 0; i < blobNumber; i++) {
        printf("| %-6d | %-12d | %-7.2f | %-10.2f |\n", BlobArray[i].no, BlobArray[i].numberOfBlobPixels, BlobArray[i].y, BlobArray[i].x);
    }

    cout << "+----------------------------------------------+" << endl;
}