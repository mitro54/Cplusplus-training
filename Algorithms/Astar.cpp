#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Cell {
    int x, y; // grid pos
    int f; // f = g + h, priority = smaller better, for bfs only g
};

// priority queue as a sorted vector, will ascend by f
// we need to use this priority queue implementation for the algorithm
std::vector<Cell> open_list;

void enqueue(const Cell& cell) {
    open_list.push_back(cell);
    int i = open_list.size() - 2;
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

// equation F = G + H , G movement cost from point A to given square on grid
// following the path generated to get there, 10 for x or y, 14 for x & y
// H is the estimated movemenet cost to move from that given square on the grid to the final destination point B
// often referred as the heuristic, its a guess

// we need to implement bfs (breadth first search first), for that we need a grid

int main(void) {
    // the map, a grid
    // ' ' = free, # = wall, S = start, G = goal
    std::vector<std::string> grid = {
        "S    ###",
        "####    ",
        "G###### ",
        " #      ",
        "   ##   "
    };
    // need grids size for loops
    const int height = grid.size();
    const int width = grid[0].size();
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
    if (start_x == -1 || goal_x == -1) throw std::runtime_error("start or goal is missing");

    std::cout << start_x << ',' << start_y << ' ' << goal_x << ',' << goal_y << '\n';

    int g[height][width];
    std::pair<int, int> prev[height][width];
    int inf = 1e9;

    // the 4-directional movement
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int d_len = sizeof(dx) / sizeof(dx[0]); 

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            g[y][x] = inf;
            prev[y][x] = {-1, -1};
        }

    // the start setup
    g[start_y][start_x] = 0;
    enqueue({start_x, start_y, 0}); // f = g = 0

    // the bfs loop
    while (!open_list.empty()) {
        Cell current = pop_front();
        int x = current.x, y = current.y;

        if (x == goal_x && y == goal_y) break;

    // explores the neighbor cells
    for (int dir = 0; dir < d_len; dir++) {
        int new_x = x + dx[dir], new_y = y + dy[dir];
        if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height) continue; // skip out of bounds cells
        if (grid[new_y][new_x] == '#') continue; // and skip walls
        if (g[new_y][new_x] > g[y][x] + 1) {
            g[new_y][new_x] = g[y][x] + 1;
            prev[new_y][new_x] = {y, x};
            enqueue({new_x, new_y, g[new_y][new_x]});
            }
        }
    }

    if (g[goal_y][goal_x] == inf) throw std::runtime_error("no path found.");

    // reconstructs path
    std::vector<std::pair<int, int>> path;
    for (int y = goal_y, x = goal_x; !(x == start_x && y == start_y);) {
        path.push_back({y, x});
        auto p = prev[y][x];
        y = p.first; x = p.second;
    }
    reverse(path.begin(), path.end()); // reverse path to go from start to goal

    // mark path on the copy
    auto out = grid;
    for (auto [y, x] : path) {
        if (out[y][x] != 'S' && out[y][x] != 'G') out[y][x] = '*';
    }

    for (auto& row : out) std::cout << row << "\n";
    std::cout << "Walked distance: " << g[goal_y][goal_x] << "\n";
    return 0;
}