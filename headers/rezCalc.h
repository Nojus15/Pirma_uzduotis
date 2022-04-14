#pragma once

#include "data.h"
#include "inOut.h"

double galutinisVid(vector<int> paz, int egz);
double galutinisMed(vector<int> paz, int egz);
void calcRez(vector<data> &studentai, bool rez, bool manual);

double galutinisVid(list<int> paz, int egz);
double galutinisMed(list<int> paz, int egz);
void calcRez(list<data> &studentai, bool rez, bool manual);

double galutinisVid(deque<int> paz, int egz);
double galutinisMed(deque<int> paz, int egz);
void calcRez(deque<data> &studentai, bool rez, bool manual);

void sortStudents(vector<data> &kietiakai, vector<data> &vargsai, vector<data> &students);
void sortStudents(list<data> &kietiakai, list<data> &vargsai, list<data> &students);
void sortStudents(deque<data> &kietiakai, deque<data> &vargsai, deque<data> &students);

void sortStudents2(vector<data> &kietiakai, vector<data> &vargsai);
void sortStudents2(list<data> &kietiakai, list<data> &vargsai);
void sortStudents2(deque<data> &kietiakai, deque<data> &vargsai);
