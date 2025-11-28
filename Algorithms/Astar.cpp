#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// A single cell in the grid
struct Cell {
    int x, y; // grid pos
    int f;    // f = g + h, smaller is better, for bfs only g
};

// priority queue as a sorted vector, will ascend by f
// we need to use this priority queue implementation for the algorithm
std::vector<Cell> open_list;

void enqueue(const Cell& cell) {
    open_list.push_back(cell);
    int i = (int)open_list.size() - 2;
    // shift cells right while their f is larger than new f
    while (i >= 0 && open_list[i].f > cell.f) {
        open_list[i + 1] = open_list[i];
        i--;
    }
    // place value at the correct spot
    open_list[i + 1] = cell;
}

// pop the best from front
Cell pop_front() {
    Cell best = open_list.front();
    open_list.erase(open_list.begin());
    return best;
}

// manhattan distance for heuristic
int h(int x, int y, int gx, int gy) {
    return std::abs(x - gx) + std::abs(y - gy);
}

// -------------------------------------------------------
// Generic A* on a 2D grid
//
// grid: 2D map made of chars
//   - free cell: anything except 'wall' char, default '#'
//   - you cna decide what S/G/etc are outside this function
//
// start_x, start_y: coordinates of start
// goal_x, goal_y : coordinates of goal
//
// out_path: list of (y,x) cells from start to goal, inclusive
// out_distance: total g-cost from start to goal, each step costs 1 here
// wall: which character is considered blocked
//
// returns true if path was found
// -------------------------------------------------------
bool astar(const std::vector<std::string>& grid,
           int start_x, int start_y,
           int goal_x, int goal_y,
           std::vector<std::pair<int, int>>& out_path,
           int& out_distance,
           char wall = '#') {
    const int height = (int)grid.size();
    if (!height) return false; // empty grid
    const int width = (int)grid[0].size();

    // movement cost grid (G) and previous pointer grid
    const int inf = 1000000000;
    std::vector<std::vector<int>> g(height, std::vector<int>(width, inf));
    std::vector<std::vector<std::pair<int, int>>> prev(
        height,
        std::vector<std::pair<int, int>>(width, std::make_pair(-1, -1))
    );

    // 4-directional movement
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int d_len = 4;

    // reset global priority queue so we can reuse A* for many tasks
    open_list.clear();

    // start setup
    g[start_y][start_x] = 0;
    // for A* f = g + h, for BFS you could enqueue only g
    enqueue({start_x, start_y, h(start_x, start_y, goal_x, goal_y)});

    // main loop
    while (!open_list.empty()) {
        Cell current = pop_front();
        int x = current.x;
        int y = current.y;

        // for safety, skip if outside
        if (x < 0 || x >= width || y < 0 || y >= height) continue;

        // skip stale entries, older, worse f for this cell
        if (g[y][x] == inf) continue;
        int best_f_here = g[y][x] + h(x, y, goal_x, goal_y);
        if (current.f != best_f_here) continue;

        // goal reached
        if (x == goal_x && y == goal_y) break;

        // explore neighbor cells
        for (int dir = 0; dir < d_len; ++dir) {
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];

            if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height)
                continue; // out of bounds
            if (grid[new_y][new_x] == wall)
                continue; // walls

            // g: movement cost so far, here every move costs 1
            int tentative_g = g[y][x] + 1;

            // if we found a better ,shorter path to neighbor
            if (tentative_g < g[new_y][new_x]) {
                g[new_y][new_x] = tentative_g;
                // store where we came from, prev cell
                prev[new_y][new_x] = std::make_pair(y, x);
                int f = tentative_g + h(new_x, new_y, goal_x, goal_y);
                enqueue({new_x, new_y, f});
            }
        }
    }

    if (g[goal_y][goal_x] == inf) return false; // no path

    // reconstruct path from goal back to start
    out_path.clear();
    int y = goal_y;
    int x = goal_x;

    // go backwards until we reach the start cell
    while (!(x == start_x && y == start_y)) {
        out_path.push_back({y, x});
        std::pair<int, int> p = prev[y][x];
        if (p.first == -1 && p.second == -1) break; // safety
        y = p.first;
        x = p.second;
    }
    // include the start cell
    out_path.push_back({start_y, start_x});
    std::reverse(out_path.begin(), out_path.end());

    out_distance = g[goal_y][goal_x];
    return true;
}

int main(void) {
    // the map, a grid
    // ' ' = free, # = wall, S = start, G = goal
    std::vector<std::string> grid = {
        "S     ####         #####              ",
        "## ##     ##   ##       #######       ",
        "##    ###      ##   ##       ##       ",
        "##   #### ##   ##   ##   ##  ##   ### ",
        "##        ##        ##   ##       ##  ",
        "###### ###########  ##   ##########   ",
        "##         ##       ##         ##     ",
        "##   #######   ########   ########### ",
        "##   ##            ###          ##    ",
        "###  #########   #######   ########   ",
        "##        ##   ###      ###       ##  ",
        "########  ##   ##   ##   ##   ##  ##  ",
        "##        ##        ##        ##  ##  ",
        "##   ########   ########   ########   ",
        "##          ##          ##            ",
        "##########  ##########   #########    ",
        "##              ##                    ",
        "##   ########   ##   ########   ####  ",
        "##       ##         ##               G",
        "######################################"
    };

    const int height = (int)grid.size();
    const int width = (int)grid[0].size();
    int start_x = -1, start_y = -1, goal_x = -1, goal_y = -1;

    // find start and goal coordinates
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 'S') {
                start_x = x;
                start_y = y;
            }
            if (grid[y][x] == 'G') {
                goal_x = x;
                goal_y = y;
            }
        }

    // if not found, cannot continue
    if (start_x == -1 || goal_x == -1)
        throw std::runtime_error("start or goal is missing");

    std::cout << "start: " << start_x << ',' << start_y
              << " goal: " << goal_x << ',' << goal_y << '\n';

    std::vector<std::pair<int, int>> path;
    int distance = 0;

    // run the A* on the grid
    bool ok = astar(grid, start_x, start_y, goal_x, goal_y, path, distance);
    if (!ok) {
        std::cout << "no path found.\n";
        return 0;
    }

    // mark path on a copy of the grid
    auto out = grid;
    for (auto [y, x] : path) {
        if (out[y][x] != 'S' && out[y][x] != 'G') out[y][x] = '*';
    }

    // print grid and distance
    for (auto& row : out) std::cout << row << '\n';
    std::cout << "Walked distance: " << distance << '\n';

    return 0;
}