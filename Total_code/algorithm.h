#ifndef ALGORITHM_FUNCTIONS_H
#define ALGORITHM_FUNCTIONS_H

#include <vector>
#include <queue>
#include <iostream>

#include "movement.h"
///////
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
////////// algo macros
#define MAZE_SIZE 16
#define WALL_ARRAY_SIZE 256

////////algor var
short direction = NORTH;
short robot_x = 15;
short robot_y = 0;

int visited[MAZE_SIZE][MAZE_SIZE] = {0};
int maze[MAZE_SIZE][MAZE_SIZE]; 
bool walls[MAZE_SIZE][MAZE_SIZE] = {false};



//////
std::vector<std::pair<int, int>> centerPoints = {
        {MAZE_SIZE / 2 - 1, MAZE_SIZE / 2 - 1},
        {MAZE_SIZE / 2 - 1, MAZE_SIZE / 2},
        {MAZE_SIZE / 2, MAZE_SIZE / 2 - 1},
        {MAZE_SIZE / 2, MAZE_SIZE / 2}
    };
    
int cellNumber(int x, int y) ;
bool hasWall(int x1, int y1, int x2, int y2);
void addWall(int x1, int y1, int x2, int y2);
bool isValidCell(int x, int y);
void updateWalls(short robot_x, short robot_y, short direction);
void bfs(short centerPoints[][2]);
void findBestCell(short robot_x, short robot_y, short direction, short& best_x, short& best_y, int& min_value);
void moveToBestCell(short& robot_x, short& robot_y, short& direction);



#endif
