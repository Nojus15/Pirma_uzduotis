#pragma once

#include "data.h"
#include "generate.h"
#include "validation.h"

void ivestis(data &temp);
void enterMarkManually(data &temp);

void bufer_read(vector<data> &studentai, bool gen, string genFile_name);
void bufer_write(std::string write_vardas, vector<data> &studentai, bool manual, bool rez);

void bufer_read(list<data> &studentai, bool gen, string genFile_name);
void bufer_write(std::string write_vardas, list<data> &studentai, bool manual, bool rez);

void bufer_read(deque<data> &studentai, bool gen, string genFile_name);
void bufer_write(std::string write_vardas, deque<data> &studentai, bool manual, bool rez);

void genFile(int size, string file_name, int ndCount);
void ssToFile(string file_name, std::stringstream &data);
