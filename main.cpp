#include "greedy_robot.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argument_count, char* argument_vector[]) {

    // Parse input arguments and assign to corresponding variables
    int max_dist_ = atoi(argument_vector[1]);  // Maximum allowed move distance per direction
    int xr = atoi(argument_vector[2]);         // Robot's starting x-coordinate
    int yr = atoi(argument_vector[3]);         // Robot's starting y-coordinate
    int xt = atoi(argument_vector[4]);         // Treasure (goal) x-coordinate
    int yt = atoi(argument_vector[5]);         // Treasure (goal) y-coordinate

    // Create an instance of the GreedyRobot with the provided arguments
    GreedyRobot robot(max_dist_, xr, yr, xt, yt);

    // Start the pathfinding process by calling FindPaths method
    robot.FindPaths(); // This will recursively find all possible paths to the treasure

    // Output the found paths and the total number of paths
    robot.PrintPaths(); // Print the paths and the total number of unique paths

    return 0; // Exit the program successfully
}
