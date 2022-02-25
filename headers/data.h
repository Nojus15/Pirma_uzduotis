#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct data
{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double vid;
    double med;
};

extern bool egz;
extern bool paz;
extern bool rez;
extern bool manual;