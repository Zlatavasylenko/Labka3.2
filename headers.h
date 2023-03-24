#pragma once


const int N = 12;

bool inputUser(int (&a)[N], int &cnt);
void inputRandom(int (&a)[N], int &length);
void printArray(int *a, int length);
void processArray(int *cur, int *last, int *edge, int &length, int n);
int getOption();
void printHeader();
bool isSimple(int n);


