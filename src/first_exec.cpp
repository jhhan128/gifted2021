/*
 * src/first_exec.cpp
 * Created by jhhan128.
 *
 *
 * Setup program for first execution.
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "../lib/function"


extern std::vector<int> today;

// Put whole file to stdout.
void outputAll(const std::string &fileName) {
    std::ifstream fin(fileName);
    std::string s;

    while (std::getline(fin, s)) {
        std::cout << s << std::endl;
    }

    std::cout << std::endl;
}


// For first execution, run this function to set up.
void firstExec(void) {
    std::ofstream config("config.txt");
    std::string str;
    int counter = 1;
    std::ifstream fin;
    std::string s;

    // output firstexec_1 and get input; jobs
    outputAll("lib/output/firstexec_1.txt");

    while (true) {
        printf("%d. ", counter++);
        std::getline(std::cin, str);

        if (str == "END") break;
        config << str << '\n';
    }

    counter -= 2;
    config << '\n';


    // output firstexec_2 and get input; relationship
    outputAll("lib/output/firstexec_2.txt");

    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, str);
        if (str == "END") break;

        // parse integer from string
        char *end;
        int a = (int)strtol(str.c_str(), &end, 10);
        int b = (int)strtol(end, &end, 10);

        // if a and b is bigger than counter(= not in normal range)
        if (a > counter || b > counter) {
            fin.open("lib/output/firstexec_3.txt");
    
            while (std::getline(fin, s)) {
                std::cout << s << std::endl;
            }

            continue;
        }

        config << a << ' ' << b << '\n';
    }

    outputAll("lib/output/firstexec_4.txt");
}
