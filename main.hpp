#ifndef MAIN_HPP
#define MAIN_HPP

// Construct an array-of-records from a multi-column data file (babyname.txt)
// and search for matching names by state and starting character.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int N = 5000;

int makeNameRecord(string[], string[], int[], string[], int[]);
void printoutallrecords(int, string[], string[], int[], string[], int[]);
int findNames(int, string[], string[], int[], string[], int[], char, string);
void printoutcontents(string, string, int, string, int);

int makeNameRecord(string state[], string gender[], int year[], string name[], int count[])
{
    // TODO: open "babyname.txt", read each line into the parallel arrays,
    ifstream inputfile;
    inputfile.open("babyname.txt");
    if(!inputfile){
        cerr << "Unable to open file";
        exit(1); 
    }
    int coun = 0;
    while(inputfile >> state[coun] >> gender[coun] >> year[coun] >> name[coun] >> count[coun]){
        cout << state[coun] << " " << gender[coun] << " " << year[coun] << " " << name[coun] << " " << count[coun] << endl;
        coun++;
    }
    inputfile.close();
    return coun; 
}

int findNames(int cnt, string state[], string gender[], int year[], string name[], int count[], char starting, string stname)
{
    // TODO: print each record where the state matches `stname` and the name
    for(int i = 0; i < cnt; i++){
        name[i].rfind(starting, 0) == 0;
        if (state[i] == stname && name[i].rfind(starting, 0) == 0){
            printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
            cnt += 1; 
        }
    }
    return cnt;
}

void printoutallrecords(int cnt, string state[], string gender[], int year[], string name[], int count[])
{
    for (int i = 0; i < cnt; i++)
        printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
    cout << "total lines: " << cnt << endl;
}

void printoutcontents(string statename, string sex, int year, string name, int count)
{
    cout << setw(5) << statename << "\t";
    cout << setw(3) << sex << "\t";
    cout << setw(5) << year << "\t";
    cout << setw(10) << name << "\t\t";
    cout << setw(5) << count << endl;
}

#endif
