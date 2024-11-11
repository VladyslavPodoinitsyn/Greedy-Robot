#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_

#include <iostream>
#include <vector>
using namespace std;

class GreedyRobot
{
private:
    int current_x_;      // Current x-coordinate of the robot
    int current_y_;      // Current y-coordinate of the robot
    int goal_x_;         // x-coordinate of the treasure
    int goal_y_;         // y-coordinate of the treasure
    int max_distance_;   // Maximum distance the robot can move in a single direction
    vector<string> paths_; // Stores the found paths

    // Helper function for exploring all potential paths
    void explorePaths(int x, int y, int move_count, char last_move, int north_count, int south_count, int east_count, int west_count, string path_so_far);

public:
    // Constructors
    GreedyRobot();
    GreedyRobot(int max_distance, int current_x, int current_y, int goal_x, int goal_y);

    // Public Methods
    void FindPaths(); // Starts the process of finding all possible paths
    void DisplayPaths() const; // Outputs all the paths found
};

#endif
