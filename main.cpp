// Author: Nathan Maynard
// Course: CSC 112 Section B (Fall 2019)
// Project: Project 8
// Due Date: 3:30pm, Nov 21, 2019

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include "Data.h"
using namespace std;

int main() {
    ifstream inFile; //Input
    ofstream staFile, qFile, sorFile; //Outputs
    stack<Data> dataStack;
    queue<Data> dataQueue;
    priority_queue<Data> dataPriQueue;

    //Open files
    cout << "Opening Files..." << endl;
    inFile.open("../top2018.csv");
    staFile.open("../stacked.txt");
    qFile.open("../queued.txt");
    sorFile.open("../sorted.txt");

    if (!inFile.is_open()) {
        cout << "Error opening input file" << endl;
        return 1;
    }
    if (!staFile.is_open()) {
        cout << "Error opening stacked.txt" << endl;
        return 1;
    }
    if (!qFile.is_open()) {
        cout << "Error opening queued.txt" << endl;
        return 1;
    }
    if (!sorFile.is_open()) {
        cout << "Error opening sorted.txt" << endl;
        return 1;
    }

    //Fill Stack, Queue, and Priority Queue
    for (int i = 0; i < 100; i++) {
        Data songData(inFile);
        dataStack.push(songData);
        dataQueue.push(songData);
        dataPriQueue.push(songData);
    }

    //Print Stack to Output File
    while(!dataStack.empty()) {
        staFile << dataStack.top();
        dataStack.pop();
    }

    //Print Queue to Output File
    while(!dataQueue.empty()) {
        qFile << dataQueue.front();
        dataQueue.pop();
    }

    //Print Priority Queue to Output File
    while(!dataPriQueue.empty()) {
        sorFile << dataPriQueue.top();
        dataPriQueue.pop();
    }

    //Close files
    cout << "Closing Files.." << endl;
    inFile.close();
    staFile.close();
    qFile.close();
    sorFile.close();

    return 0;
}