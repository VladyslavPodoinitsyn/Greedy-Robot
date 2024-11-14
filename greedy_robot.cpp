#include "greedy_robot.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Default constructor to initialize robot and goal coordinates, and max distance
GreedyRobot::GreedyRobot()
{
    max_dist_ = 0;       // Maximum allowed move distance (per direction)
    current_x_ = 0;      // Initial x-coordinate of the robot
    current_y_ = 0;      // Initial y-coordinate of the robot
    goal_x_ = 0;         // x-coordinate of the treasure (goal)
    goal_y_ = 0;         // y-coordinate of the treasure (goal)  
}

// Parameterized constructor to set the robot's starting position, goal, and max move distance
GreedyRobot::GreedyRobot(int max_dist, int xr, int yr, int xt, int yt)
{
    max_dist_ = max_dist;  // Set max allowed move distance
    current_x_ = xr;       // Set robot's starting x-coordinate
    current_y_ = yr;       // Set robot's starting y-coordinate
    goal_x_ = xt;          // Set goal (treasure) x-coordinate
    goal_y_ = yt;          // Set goal (treasure) y-coordinate
}

// Function to initiate the pathfinding process
void GreedyRobot::FindPaths()
{
    // Call the recursive helper function to begin pathfinding from the robot's starting point
    FindHelper(current_x_, current_y_, 0, '\0', 0, 0, 0, 0, ""); 
}

// Recursive helper function to explore all valid paths from the robot's current position to the goal
void GreedyRobot::FindHelper(int xr, int yr, int move_count, char last_m, int con_n, int con_s, int con_e, int con_w, string path) 
{
    // Base case: if the robot reaches the goal, add the current path to the list of paths
    if (xr == goal_x_ && yr == goal_y_) 
    {
        if (!path.empty()) // Only add non-empty paths
        {
            paths_.push_back(path); // Store the found path
        }
        return;
    }

    // Move South if robot is below the goal and max allowed moves in this direction is not exceeded
    if (yr > goal_y_) 
    {
        if (con_s < max_dist_)
        {
            FindHelper(xr, yr - 1, move_count + 1, 'S', 0, con_s + 1, 0, 0, path + "S");
        }
    }

    // Move North if robot is above the goal and max allowed moves in this direction is not exceeded
    if (yr < goal_y_) 
    {
        if (con_n < max_dist_)
        {
            FindHelper(xr, yr + 1, move_count + 1, 'N', con_n + 1, 0, 0, 0, path + "N");
        }
    }

    // Move West if robot is to the right of the goal and max allowed moves in this direction is not exceeded
    if (xr > goal_x_) 
    {
        if (con_w < max_dist_)
        {
            FindHelper(xr - 1, yr, move_count + 1, 'W', 0, 0, 0, con_w + 1, path + "W");
        }
    }

    // Move East if robot is to the left of the goal and max allowed moves in this direction is not exceeded
    if (xr < goal_x_) 
    {
        if (con_e < max_dist_)
        {
            FindHelper(xr + 1, yr, move_count + 1, 'E', 0, 0, con_e + 1, 0, path + "E");
        }
    }    
}

// Function to print all found paths and the total number of paths
void GreedyRobot::PrintPaths() const
{
    // Print each path stored in paths_
    for (int i = 0; i < paths_.size(); i++)
    {
        cout << paths_[i] << endl; // Output each path
    }

    // Print the total number of paths found
    cout << "Number of paths: " << paths_.size() << endl;
}
