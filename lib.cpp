//
// Created by BedTed on 1/16/2021.
//
#include "lib.h"
#include <iostream>
#include <fstream>
#include "pthread.h"
string fileNameStr = "C:\\Users\\BedTed\\CLionProjects\\pthread\\TXTfiels\\ .txt"; // !!! указать свой путь до файла !!!

using namespace std;
int buff;
int sumMultiThreading[10] {};
//int fileNumber = 0;

int singleThreading () {
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        fileNameStr[fileNameStr.length() - 5] = to_string(i)[0];
        ifstream inFile(fileNameStr);

        while (!inFile.eof()) {
            if (inFile.is_open()) {
                inFile >> buff;
                sum += buff;
            }
        }
        inFile.close();
    }
    return sum;
}

void *sumInFile (void *arg) {

    int* fileNumber = (int*) arg;

        fileNameStr[fileNameStr.length() - 5] = to_string(*fileNumber)[0];
        ifstream inFile(fileNameStr);

        //sumMultiThreading[*fileNumber] = 0;

        while (!inFile.eof()) {
            if (inFile.is_open()) {
                inFile >> buff;
                sumMultiThreading[*fileNumber] += buff;
            }
        }
        inFile.close();
}

int multiThreading () {
    int sumMulti = 0;
    pthread_t threads[10];
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        pthread_create(&(threads[i]), nullptr, sumInFile, &arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join (threads[i], nullptr);
        sumMulti += sumMultiThreading[i];
    }


    return sumMulti;
}
