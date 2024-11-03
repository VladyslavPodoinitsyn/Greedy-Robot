#include "greedy_robot.h"
#include <cmath>
using namespace std;

// Recursive function to find all unique shortest paths
void findPaths(int x, int y, int xt, int yt, int maxDist, int northMoves, int eastMoves, string path, vector<string>& paths) {
    // Calculate remaining distance to the treasure
    int remainingDist = abs(x - xt) + abs(y - yt);

    // Base case: if the robot reaches the treasure, store the path
    if (remainingDist == 0) {
        paths.push_back(path);
        return;
    }

    // Recursive case: move in valid directions if within constraints
    if (y < yt && northMoves < maxDist && path.empty() || (path.back() != 'N')) // Move North
        findPaths(x, y + 1, xt, yt, maxDist, northMoves + 1, 0, path + "N", paths);
    
    if (y > yt && northMoves < maxDist && path.empty() || (path.back() != 'S')) // Move South
        findPaths(x, y - 1, xt, yt, maxDist, northMoves + 1, 0, path + "S", paths);
    
    if (x < xt && eastMoves < maxDist && path.empty() || (path.back() != 'E')) // Move East
        findPaths(x + 1, y, xt, yt, maxDist, 0, eastMoves + 1, path + "E", paths);
    
    if (x > xt && eastMoves < maxDist && path.empty() || (path.back() != 'W')) // Move West
        findPaths(x - 1, y, xt, yt, maxDist, 0, eastMoves + 1, path + "W", paths);
}

// Function to print all unique paths
void printPaths(const vector<string>& paths) {
    for (const auto& p : paths) {
        cout << p << endl;
    }
    cout << "Number of paths: " << paths.size() << endl;
}

// Main function to parse inputs and start path finding
int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Usage: greedy_robot <max_distance> <robot_x> <robot_y> <treasure_x> <treasure_y>" << endl;
        return 1;
    }

    // Parse input values
    int maxDist = stoi(argv[1]);
    int xr = stoi(argv[2]);
    int yr = stoi(argv[3]);
    int xt = stoi(argv[4]);
    int yt = stoi(argv[5]);

    vector<string> paths;
    findPaths(xr, yr, xt, yt, maxDist, 0, 0, "", paths);

    printPaths(paths);
    return 0;
}
