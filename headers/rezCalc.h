#pragma once

#include "data.h"

double galutinisVid(vector<int> paz, int egz);
double galutinisMed(vector<int> paz, int egz);
void calcRez(vector<data> &studentai, bool rez, bool manual);

double galutinisVid(list<int> paz, int egz);
double galutinisMed(list<int> paz, int egz);
void calcRez(list<data> &studentai, bool rez, bool manual);

double galutinisVid(deque<int> paz, int egz);
double galutinisMed(deque<int> paz, int egz);
void calcRez(deque<data> &studentai, bool rez, bool manual);

void sortStudents(std::stringstream &kietiakai, std::stringstream &vargsai, vector<data> &students);
void sortStudents(std::stringstream &kietiakai, std::stringstream &vargsai, list<data> &students);
void sortStudents(std::stringstream &kietiakai, std::stringstream &vargsai, deque<data> &students);