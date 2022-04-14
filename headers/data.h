#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::left;
using std::list;
using std::mt19937;
using std::right;
using std::setw;
using std::string;
using std::to_string;
using std::vector;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
struct data
{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double vid = 0;
    double med = 0;
};

extern bool egz;
extern bool paz;
extern bool rez;
extern bool manual;