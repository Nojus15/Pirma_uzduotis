#pragma once

#include "data.h"
#include "generate.h"
#include "validation.h"

void ivestis(data &temp);
void isvedimas(data &temp, std::ofstream &fout);
void read(std::ifstream &fin, std::vector<string> &length, std::vector<data> &studentai);
void enterMarkManually(data &temp);
