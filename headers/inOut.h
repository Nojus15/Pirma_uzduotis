#pragma once

#include "data.h"
#include "generate.h"
#include "validation.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
// #include <string>
// #include <boost/algorithm/string.hpp>

using hrClock = std::chrono::high_resolution_clock;

void ivestis(data &temp);
void isvedimas(data &temp, std::ofstream &fout);
void read(std::ifstream &fin, std::vector<string> &length, std::vector<data> &studentai);
void enterMarkManually(data &temp);

void bufer_read(vector<data> &studentai);
void bufer_write(std::string write_vardas, vector<data> &studentai);
void genFile(int size, string file_name, int ndCount);