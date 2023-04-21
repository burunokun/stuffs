#include <stdio.h>
#include <stdbool.h>

// Solving a maze using recursion


// Some constants
#define ROW 6
#define COL 12
#define UP { -1, 0 }
#define RIGHT { 0, 1 }
#define DOWN { 1, 0 }
#define LEFT { 0, -1 }

// Array data structure
typedef struct {
    char arr[ROW][COL];
} Array;

// Point(x, y)
typedef struct {
    int x;
    int y;
} Point;

// Direction[up, right, down, left]
typedef struct {
    Point arr[4];
} Direction;

static const Direction dir = {
    .arr = { UP, RIGHT, DOWN, LEFT },
};

// create a maze map
// 'x' is a wall
Array create_maze() {
    Array m = {
        .arr = {
            { 'x','x','x','x','x','x','x','x','x','x',' ','x' },
            { 'x',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x' },
            { 'x',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x' },
            { 'x',' ','x','x','x','x','x','x','x','x',' ','x' },
            { 'x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x' },
            { 'x',' ','x','x','x','x','x','x','x','x','x','x' },
        }
    };
    return m;
}

// print the array map
void print(Array maze, Point p) {

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (i == p.x && j == p.y) {
                printf("\033[0;31m");
                printf("x");
                printf("\033[0m");
            } else {
                printf("%c", maze.arr[i][j]);
            }
        }
        printf("\n");
    }

}

// walk recursively the maze towards the solution
bool walk(Array maze, char wall, Point curr, Point end, Array *seen) {

    // base cases
    // if off bounds
    if (curr.x < 0 || curr.x > ROW ||
         curr.y < 0 || curr.y > COL) {
        return false;
    }
    // if its a wall
    if (maze.arr[curr.x][curr.y] == 'x') {
        return false;
    }
    // if reaches end
    if (curr.x == end.x && curr.y == end.y) {
        print(maze, curr);
        return true;
    }
    // if already seen
    if (seen->arr[curr.x][curr.y]) {
        return false;
    }
    seen->arr[curr.x][curr.y] = 1;

    // loop over the directions
    // looking for a valid direction to move into
    int length = sizeof(dir.arr) / sizeof(dir.arr[0]);
    for (int i = 0; i < length; ++i) {
        printf("dir: %d, %d\n", dir.arr[i].x, dir.arr[i].y);
        print(maze, curr);

        int x = dir.arr[i].x;
        int y = dir.arr[i].y;
        curr.x += x;
        curr.y += y;

        // recursion
        // if reaches the end it returns
        if (walk(maze, wall, curr, end, seen)) {
            return true;
        } else {
            // otherwise, go back one step
            // and try again another direction
            curr.x -= x;
            curr.y -= y;
            print(maze, curr);
        }
    }

    // if none of the cases above returns
    // fallback return
    return false;
}

// solve maze function
void solve_maze(Array maze, char wall, Point start, Point end) {
    // array map of seen Points
    // to not recursively walk
    // the same spot over and over again
    Array seen = {
        .arr = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        }
    };

    walk(maze, wall, start, end, &seen);
    return;
}

int main() {

    Array maze = create_maze();
    // our starting point
    Point start = {
        .x = 0,
        .y = 10,
    };

    // our goal
    Point end = {
        .x = 5,
        .y = 1,
    };

    printf("START\n");
    solve_maze(maze, 'x', start, end);
    printf("END\n");
    printf("MAZE SOLVED!\n");

    return 0;

}
