#include "greedy_robot.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argument_count, char* argument_vector[]) {

    // Convert command-line arguments to integers
    int max_distance = atoi(argument_vector[1]);  // Maximum allowed steps in any direction
    int robot_x = atoi(argument_vector[2]);  // Robot's starting X-coordinate
    int robot_y = atoi(argument_vector[3]);  // Robot's starting Y-coordinate
    int treasure_x = atoi(argument_vector[4]);  // Treasure's X-coordinate
    int treasure_y = atoi(argument_vector[5]);  // Treasure's Y-coordinate

    // Create a GreedyRobot object using the input values
    GreedyRobot robot(max_distance, robot_x, robot_y, treasure_x, treasure_y);

    // Start finding paths from the robot's current position to the treasure
    robot.FindPaths();  // This will initiate the pathfinding process

    // Output all the paths found by the robot
    robot.PrintPaths();  // Prints the valid paths along with the number of paths found

    return 0;
}
