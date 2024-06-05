#ifndef TASK_H
#define TASK_H
#include <vector>


int findPersonWithBroom(int n, int time);

bool canReachTarget(int sx, int sy, int fx, int fy, unsigned int t);

std::string solveEquation(const std::string &equation);

int timeToMinutes(const std::string& time);
int findMinTimeDiff(const std::vector<std::string>& times);

bool canReach(unsigned int tx, unsigned int ty);

int calculateExpression(const std::string& expression);

#endif