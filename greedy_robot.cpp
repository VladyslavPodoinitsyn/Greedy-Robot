#include "greedy_robot.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

GreedyRobot::GreedyRobot()
{
    // Initialize all member variables to default values
    current_x_ = 0;
    current_y_ = 0;
    goal_x_ = 0;
    goal_y_ = 0;
    max_distance_ = 0;
}

GreedyRobot::GreedyRobot(int max_distance, int current_x, int current_y, int goal_x, int goal_y)
{
    // Initialize member variables with provided values
    this->current_x_ = current_x;
    this->current_y_ = current_y;
    this->goal_x_ = goal_x;
    this->goal_y_ = goal_y;
    this->max_distance_ = max_distance;
}

void GreedyRobot::FindPaths()
{
    // Begin the pathfinding process starting from the initial robot position
    startPathfinding(current_x_, current_y_, 0, '\0', 0, 0, 0, 0, "");
}

void GreedyRobot::startPathfinding(int current_x, int current_y, int move_count, char last_move, int north_count, int south_count, int east_count, int west_count, string current_path)
{
    // Base case: if the robot reaches the treasure, store the path
    if (current_x == goal_x_ && current_y == goal_y_)
    {
        if (!current_path.empty()) // Only add non-empty paths
        {
            paths_.emplace_back(current_path);  // Save the current valid path
        }
        return;
    }

    // Try moving North if the treasure is to the north of the robot
    if (current_y < goal_y_)
    {
        if (north_count < max_distance_)  // Ensure we do not exceed max distance in a direction
        {
            startPathfinding(current_x, current_y + 1, move_count + 1, 'N', north_count + 1, 0, 0, 0, current_path + "N");
        }
    }

    // Try moving South if the treasure is to the south of the robot
    if (current_y > goal_y_)
    {
        if (south_count < max_distance_)  // Ensure we do not exceed max distance in a direction
        {
            startPathfinding(current_x, current_y - 1, move_count + 1, 'S', 0, south_count + 1, 0, 0, current_path + "S");
        }
    }

    // Try moving West if the treasure is to the west of the robot
    if (current_x > goal_x_)
    {
        if (west_count < max_distance_)  // Ensure we do not exceed max distance in a direction
        {
            startPathfinding(current_x - 1, current_y, move_count + 1, 'W', 0, 0, 0, west_count + 1, current_path + "W");
        }
    }

    // Try moving East if the treasure is to the east of the robot
    if (current_x < goal_x_)
    {
        if (east_count < max_distance_)  // Ensure we do not exceed max distance in a direction
        {
            startPathfinding(current_x + 1, current_y, move_count + 1, 'E', 0, 0, east_count + 1, 0, current_path + "E");
        }
    }
}

void GreedyRobot::DisplayPaths() const
{
    // Output each valid path found by the robot
    for (const auto& path : paths_)
    {
        cout << path << endl;
    }

    // Output the total number of paths found
    cout << "Total number of paths found: " << paths_.size() << endl;
}
