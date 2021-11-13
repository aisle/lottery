#include <cstring>
#include <iostream>
#include <vector>

#include "lottery.h"

using namespace std;

static void PrintUsage() {
    std::cout << "Input like this:" << std::endl
              << "\t./lottery r1 r2 r3 r4 r5 r6 b1" << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 8) {
        PrintUsage();
        return -1;
    }

    std::vector<int> target;
    for (int i = 1; i <= 7; i++) {
        target.push_back(atoi(argv[i]));
    }

    VerifyTickets(target);

    return 0;
}
