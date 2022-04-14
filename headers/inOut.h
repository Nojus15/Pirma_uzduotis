#pragma once

#include "data.h"
#include "generate.h"
#include "validation.h"

void ivestis(data &temp);
void enterMarkManually(data &temp);

void bufer_read(vector<data> &studentai, bool gen, string genFile_name, double &fopenTime);
void bufer_write(std::string write_vardas, vector<data> &studentai, bool manual, bool rez);

void bufer_read(list<data> &studentai, bool gen, string genFile_name, double &fopenTime);
void bufer_write(std::string write_vardas, list<data> &studentai, bool manual, bool rez);

void bufer_read(deque<data> &studentai, bool gen, string genFile_name, double &fopenTime);
void bufer_write(std::string write_vardas, deque<data> &studentai, bool manual, bool rez);

void genFile(int size, string file_name, int ndCount);
void containerToFile(string file_name, vector<data> &data);
void containerToFile(string file_name, list<data> &data);
void containerToFile(string file_name, deque<data> &data);
void openFile(std::ifstream &open_f);

void printToFile(string text);
