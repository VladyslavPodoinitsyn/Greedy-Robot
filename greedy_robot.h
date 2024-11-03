#ifndef GREEDYROBOT_H
#define GREEDYROBOT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findPaths(int x, int y, int xt, int yt, int maxDist, int northMoves, int eastMoves, string path, vector<string>& paths);
void printPaths(const vector<string>& paths);

#endif
