// Jack Cwynar
// jec0089
// 03/04/2021
// File name: project3_Cwynar_jec0089.cpp
// My Compiler Version: Apple clang version 12.0.0 (clang-1200.0.32.28)
// To compile, use default g++ compiler on server.
// Used lectures, notes, and Dr. Li's template provided on Canvas to finish Project 3.
// Used cplusplus.com to better undertand file I/O and vectors.
// Used sorting notes, https://www.softwaretestinghelp.com/sorting-techniques-in-cpp/
// and https://programmercave0.github.io/blog/2017/08/20/C++-Insertion-Sort-using-STL-(Sorting)
// to get help with merging vectors and applying known ways of sorting to vectors.

#include <iostream>
#include <fstream>
#include <vector>
//#include <cassert>
//#include <cstdlib> // for exit() function
//#include <string>
using namespace std;

// Defining functions
// Method to check whether file exists
bool checkFile(string);

// Method to read in file using vectors
vector<int> readFile(string);

// Method to write data to a new output file
void writeFile(string, vector<int>);

// Method to merge and sort lists of data
vector<int> merge(vector<int>, vector<int>);

// Basic toString method to display the values of a given vector
void toString(string, vector<int>);

//====================================
// Implementation of functions
bool checkFile(string file) {
    ifstream instream;
    
    instream.open(file.c_str());
    if (instream.fail())  {
        cout << "File opening failed! Please try again." << endl;
        return false;
    }
    instream.close();
    return true;
}

vector<int> readFile(string file)   {
    ifstream instream;
    vector<int> v;
    int i = 0;
    
    instream.open(file.c_str());
    while (instream.good()) {
        instream >> i;
        v.push_back(i);
    }
    v.pop_back();
    instream.close();
    
    return v;
}

void writeFile(string file, vector<int> v)  {
    ofstream outstream;
    
    // Vector iterator number to iterate through vector
    unsigned short i;
    
    outstream.open(file.c_str());
    for (i = 0; i < v.size(); i++)  {
        outstream << v.at(i) << "\n";
    }
    outstream << v.at(v.size() - 1);
    outstream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    v3.reserve(v1.size() + v2.size());
    v3.insert(v3.end(), v1.begin(), v1.end());
    v3.insert(v3.end(), v2.begin(), v2.end());
    return v3;
}

void insertionSort(vector<int>& newV) {
    for (int j = 1; j < newV.size(); j++)   {
        int key = newV[j];
        int i = j - 1;
        
        while (i >= 0 && newV[i] > key)    {
            newV[i + 1] = newV[i];
                 i--;
        }
        newV[i + 1] = key;
    }
}

void toString(string file, vector<int> v)    {
    unsigned short i;
    
    cout << "The list of " << v.size() << " numbers is " << file << " is:\n";
    
    for (i = 0; i < v.size(); i++)  {
        cout << v.at(i) << "\n";
    }
    cout << "\n";
}

int main()  {
    string file1, file2, newFile;
    vector<int> numbers1, numbers2, newNumbers;
    
    cout << "*** Welcome to Jack's sorting program **\n";
    
    // Get name of first file
    do  {
        cout << "Enter the first input file name: ";
        cin >> file1;
    } while (cin.fail() || !checkFile(file1));
    
    numbers1 = readFile(file1);
    toString(file1, numbers1);
    
    // Get name of second file
    do  {
        cout << "Enter the second input file name: ";
        cin >> file2;
    } while (cin.fail() || !checkFile(file2));
    
    numbers2 = readFile(file2);
    toString(file2, numbers2);
    
    // Combine vectors, sort, then display values
    newNumbers = merge(numbers1, numbers2);
    insertionSort(newNumbers);
    cout << "The sorted list of " << newNumbers.size() << " numbers is: ";
    
    for (int i = 0; i < newNumbers.size(); i++) {
        cout << newNumbers.at(i) << " ";
    }
    
    // Get name of new output file from user
    do  {
        cout << "\nEnter the output file name: ";
        cin >> newFile;
    } while (cin.fail());
    
    writeFile(newFile, newNumbers);
    cout << "*** Please check the new file - " << newFile << " ***\n";
    cout << "*** Goodbye. ***\n";
    
    return 1;
}
