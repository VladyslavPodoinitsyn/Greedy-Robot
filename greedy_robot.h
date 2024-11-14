#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <vector>
using namespace std;

class GreedyRobot
{
    private:
    
    int current_x_; // Current x-coordinate of the robot
    int current_y_; // Current y-coordinate of the robot
    int goal_x_;    // x-coordinate of the treasure (goal)
    int goal_y_;    // y-coordinate of the treasure (goal)
    int max_dist_;  // Maximum allowed distance per move in any direction
    vector<string> paths_; // Stores all found unique paths to the treasure

    // Recursive helper function to explore all possible paths to the goal
    void FindHelper(int xr, int yr, int move_count, char last_m, int con_s, int con_n, int con_w, int con_e, string path);

    public:
    
    // Default constructor, initializes all member variables to default values
    GreedyRobot();
    
    // Parameterized constructor to initialize the robot's position, goal, and max move distance
    GreedyRobot(int max_dist_, int xr, int yr, int xt, int yt);

    // Initiates the pathfinding process by calling the recursive helper function
    void FindPaths(); 
    
    // Prints all the found paths to the console, followed by the total number of paths
    void PrintPaths() const;
};

#endif
