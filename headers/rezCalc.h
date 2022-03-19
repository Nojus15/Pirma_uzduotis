#pragma once

#include "data.h"
#include <sstream>
#include <iomanip>

using std::left;
using std::setw;

double galutinisVid(vector<int> paz, int egz);
double galutinisMed(vector<int> paz, int egz);
void calcRez(vector<data> &studentai, bool rez, bool manual);

void sortStudents(std::stringstream &kietiakai, std::stringstream &vargsai, vector<data> &students);