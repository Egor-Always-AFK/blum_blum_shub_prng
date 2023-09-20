#include<iostream>
#include <fstream>
#include "bbs.h"

using namespace std;

void generation(int amountOfGeneration, int p, int q, int seed) {
    BBS numberGen(p, q, seed);

    ofstream outputStreamForTxt;
    outputStreamForTxt.open("RandomNumbers.txt");
    ofstream outputStreamForXls;
    outputStreamForXls.open("RandomNumbers.xls");
    for (int i = 0; i < amountOfGeneration; i++) {
        long tmp = numberGen.getRandNum();

        outputStreamForTxt << tmp << " ";
        outputStreamForXls << tmp << endl;
        cout << tmp << " ";
    }
    outputStreamForXls.close();
    outputStreamForTxt.close();
    cout << "\n";
}

int castCharPointIntoInteger(char *argv) {
    int ret = 0;
    for (int i = 0; argv[i] != '\0'; i++) {
        ret = ret * 10 + (argv[i] - '0');
    }
    return ret;
}

int main(int argc, char *argv[]) {
    const int P = 1993;
    const int Q = 1000-7;
    const int seed = 29;

    if (argc == 1) {
        generation(10, P, Q, seed);
    } else if (argc == 2) {
        generation(castCharPointIntoInteger(argv[1]), P, Q, seed);
    } else if (argc == 5) {
        generation (castCharPointIntoInteger(argv[1]),
                    castCharPointIntoInteger(argv[2]),
                    castCharPointIntoInteger(argv[3]),
                    castCharPointIntoInteger(argv[4]));
    } else {
        cout << "Please use:\n"
                "0 params (default: p = 99; q == 127; x0 = 10; amountOfGen = 10)\n"
                "1 param (default: p = 99; q == 127; x0 = 10; amountOfGen = your param\n"
                "5 params (default: p, q, x0, amountOfGen = your params)\n";
    }
}
