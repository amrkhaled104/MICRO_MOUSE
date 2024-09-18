#include "algorithm.h"
#include "walls.h"


    


// Array to store directions and their corresponding movements
    const int dx[] = {0, 0, -1, 1}; // Left, Right
    const int dy[] = {-1, 1, 0, 0}; // Up, Down
// Check if there is a wall between two adjacent cells

int cellNumber(int x, int y) {
    return y * MAZE_SIZE + x; // Assuming MAZE_SIZE is the width of the grid
}

bool hasWall(int x1, int y1, int x2, int y2) {
    // Ensure the cells are adjacent
    if (isValidCell(x1, y1) && isValidCell(x2, y2)) {
        if (x1 == x2 && abs(y1 - y2) == 1) {  // Same row, adjacent columns
            return walls[cellNumber(x1, y1)][cellNumber(x2, y2)];
        } else if (y1 == y2 && abs(x1 - x2) == 1) {  // Same column, adjacent rows
            return walls[cellNumber(x1, y1)][cellNumber(x2, y2)];
        } else {
            std::cerr << "Cells are not adjacent." << std::endl;
            return false;
        }
    } else {
        std::cerr << "Invalid cell coordinates." << std::endl;
        return false;
    }
}
void addWall(int x1, int y1, int x2, int y2) {
  int cell1 = cellNumber(x1, y1);
    int cell2 = cellNumber(x2, y2);

    if (cell1 < 0 || cell1 >= WALL_ARRAY_SIZE || cell2 < 0 || cell2 >= WALL_ARRAY_SIZE) {
        std::cerr << "Invalid cell numbers." << std::endl;
        return;
    }

    walls[cell1][cell2] = true;
    walls[cell2][cell1] = true; // The wall between the two cells is bidirectional
}

bool isValidCell(int x, int y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE;
}

void updateWalls(short robot_x, short robot_y, short direction) {
  // تحديث الجدران بناءً على المستشعرات
  if (wallFront()) {
    if (direction == NORTH && isValidCell(robot_x - 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x - 1, robot_y);
    } else if (direction == SOUTH && isValidCell(robot_x + 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x + 1, robot_y);
    } else if (direction == EAST && isValidCell(robot_x, robot_y + 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y + 1);
    } else if (direction == WEST && isValidCell(robot_x, robot_y - 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y - 1);
    }
  }

  if (wallRight()) {
    if (direction == NORTH && isValidCell(robot_x, robot_y + 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y + 1);
    } else if (direction == SOUTH && isValidCell(robot_x, robot_y - 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y - 1);
    } else if (direction == EAST && isValidCell(robot_x + 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x + 1, robot_y);
    } else if (direction == WEST && isValidCell(robot_x - 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x - 1, robot_y);
    }
  }

  if (wallLeft()) {
    if (direction == NORTH && isValidCell(robot_x, robot_y - 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y - 1);
    } else if (direction == SOUTH && isValidCell(robot_x, robot_y + 1)) {
      addWall(robot_x, robot_y, robot_x, robot_y + 1);
    } else if (direction == EAST && isValidCell(robot_x - 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x - 1, robot_y);
    } else if (direction == WEST && isValidCell(robot_x + 1, robot_y)) {
      addWall(robot_x, robot_y, robot_x + 1, robot_y);
    }
  }
}

/*void bfs(short centerPoints[][2]) {
  // تنفيذ خوارزمية BFS (بحث العرض أولاً) لحساب أقصر المسافات داخل المتاهة
  // هنا سنقوم بإعادة تهيئة المتاهة أولاً
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze[i][j] = 9999; // قيمة عالية جداً تمثل أن المكان غير معروف بعد
    }
  }
  
  // إعداد قائمة للانتظار لاستخدامها في BFS
  struct Queue {
    short x, y, distance;
  } queue[MAZE_SIZE * MAZE_SIZE];

  int front = 0, rear = 0;

  // بدء الخوارزمية من النقاط المركزية (نقاط الهدف)
  for (int i = 0; i < 4; i++) {
    short cx = centerPoints[i][0];
    short cy = centerPoints[i][1];
    queue[rear++] = {cx, cy, 0};
    maze[cx][cy] = 0; // المسافة إلى المركز تساوي صفر
  }

  while (front < rear) {
    short x = queue[front].x;
    short y = queue[front].y;
    short dist = queue[front].distance;
    front++;

    for (int d = 0; d < 4; d++) {
      short nx = x + dx[d];
      short ny = y + dy[d];
      if (isValidCell(nx, ny) && !walls[nx][ny] && maze[nx][ny] > dist + 1) {
        maze[nx][ny] = dist + 1;
        queue[rear++] = {nx, ny, dist + 1};
      }
    }
  }
}
*/
void bfs(std::vector<std::pair<int, int>>& startPoints) {
    std::queue<std::pair<int, int>> q;

    // تهيئة مصفوفة المسافات بقيم عالية (مثل قيمة لا نهائية)
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 9999; // قيمة أولية عالية
        }
    }
  
  

    // بدء BFS من الخلايا المحددة
    for (const auto& point : startPoints) {
        q.push(point);
        maze[point.first][point.second] = 0;
    }

    // المتجهات للحركة في 4 اتجاهات
    int dx[] = {0, 0, -1, 1};  // Left, Right
    int dy[] = {-1, 1, 0, 0};  // Up, Down

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        int x = current.first;
        int y = current.second;
        q.pop();

        // فحص جميع الاتجاهات الأربعة
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // التأكد من أن الخلية الجديدة صالحة ولا يوجد جدار
            if (isValidCell(nx, ny) && !hasWall(x, y, nx,ny) && maze[nx][ny] > maze[x][y] + 1) {
                maze[nx][ny] = maze[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void findBestCell(short robot_x, short robot_y, short direction, short& best_x, short& best_y, int& min_value) {
  // إيجاد الخلية ذات القيمة الأدنى (أي الأقرب إلى المركز)
     best_x = robot_x;
    best_y = robot_y;

    
    const short directions[] = {WEST, EAST, NORTH, SOUTH};
  for (int d = 0; d < 4; d++) {
    short nx = robot_x + dx[d];
    short ny = robot_y + dy[d];

    if (isValidCell(nx, ny) && maze[nx][ny] < min_value && !walls[nx][ny]) {
      min_value = maze[nx][ny];
      best_x = nx;
      best_y = ny;
    }
  }
}

void moveToBestCell(short& robot_x, short& robot_y, short& direction) {
  short best_x, best_y;
  int min_value = 9998;
  findBestCell(robot_x, robot_y, direction, best_x, best_y, min_value);

  if (best_x < robot_x) {
    if (direction == NORTH) {
      moveForward(100);
    } else if (direction == WEST) {
      turnRight();
      moveForward(100);
    } else if (direction == SOUTH) {
      turnLeft();
      turnLeft();
      moveForward(100);
    } else if (direction == EAST) {
      turnLeft();
      moveForward(100);
    }
    direction = NORTH;
    robot_x--;
  } else if (best_x > robot_x) {
    if (direction == NORTH) {
      turnLeft();
      turnLeft();
      moveForward(100);
    } else if (direction == WEST) {
      turnLeft();
      moveForward(100);
    } else if (direction == SOUTH) {
      moveForward(100);
    } else if (direction == EAST) {
      turnRight();
      moveForward(100);
    }
    robot_x++;
    direction = SOUTH;
  } else if (best_y > robot_y) {
    if (direction == NORTH) {
      turnRight();
      moveForward(100);
    } else if (direction == WEST) {
      turnRight();
      turnRight();
      moveForward(100);
    } else if (direction == SOUTH) {
      turnLeft();
      moveForward(100);
    } else if (direction == EAST) {
      moveForward(100);
    }
    robot_y++;
    direction = EAST;
  } else if (best_y < robot_y) {
    if (direction == NORTH) {
      turnLeft();
      moveForward(100);
    } else if (direction == WEST) {
      moveForward(100);
    } else if (direction == SOUTH) {
      turnRight();
      moveForward(100);
    } else if (direction == EAST) {
      turnRight();
      turnRight();
      moveForward(100);
    }
    robot_y--;
    direction = WEST;
  } else {
    bfs(centerPoints);
  }
} 
