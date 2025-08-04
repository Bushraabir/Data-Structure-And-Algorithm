/*
 * Problem Statement: Rat in a Maze
 *
 * You are given an N×N maze represented by a 2D grid of 0s and 1s:
 * - 1 indicates an open cell the rat can move into.
 * - 0 indicates a blocked cell.
 *
 * The rat starts at (0,0) and must reach (N-1,N-1).
 * It can move in four directions: Down (D), Left (L), Right (R), Up (U).
 * You must find all possible paths (as strings of 'D','L','R','U') from start to finish
 * without revisiting any cell in a single path. Return them in lexicographical order.
 *
 * Approach: Backtracking with Recursion
 * - Maintain a visited[N][N] matrix to avoid revisits in the current path.
 * - From each cell, try moving in the order D, L, R, U to ensure lex order.
 * - Use delta arrays (di, dj) and a direction string to streamline moves.
 * - For each move:
 *     • Check boundaries, open cell, and not visited.
 *     • Mark visited, append direction, recurse.
 *     • On return, unmark visited, remove last direction (backtrack).
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Direction vectors and corresponding chars (Down, Left, Right, Up)
const int di[4] = {1, 0, 0, -1};
const int dj[4] = {0, -1, 1, 0};
const char dirChar[4] = {'D', 'L', 'R', 'U'};

// Recursive backtracking to explore all paths
void dfsMaze(int i, int j,
             const vector<vector<int>>& maze,
             vector<vector<bool>>& visited,
             string& path,
             vector<string>& result) {
    int n = maze.size();
    // Base case: reached bottom-right
    if (i == n-1 && j == n-1) {
        result.push_back(path);
        return;
    }
    
    // Try each direction in D, L, R, U order for lexicographical output
    for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        // Check move validity: in bounds, open cell, not yet visited
        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
            maze[ni][nj] == 1 && !visited[ni][nj]) {
            visited[ni][nj] = true;      // mark
            path.push_back(dirChar[d]);  // record move
            dfsMaze(ni, nj, maze, visited, path, result);
            path.pop_back();             // backtrack path
            visited[ni][nj] = false;     // unmark
        }
    }
}

// Public API to solve the maze
vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> result;
    if (n == 0 || maze[0][0] == 0) return result;
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path;
    visited[0][0] = true;              // mark start
    dfsMaze(0, 0, maze, visited, path, result);
    sort(result.begin(), result.end()); // lexicographical order
    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    auto paths = ratInMaze(maze);
    if (paths.empty()) {
        cout << "No path found\n";
    } else {
        cout << "Possible paths:\n";
        for (auto& p : paths) {
            cout << p << "\n";
        }
    }
    
    return 0;
}
