/*
 * Problem Statement: Flood Fill Algorithm in a 2D Grid
 *
 * You are given a 2D grid (image) of size n x m, where each cell contains an integer representing a pixel color.
 * Given a starting pixel (sr, sc) and a new color, recolor the starting pixel and all pixels
 * connected 4-directionally (up, down, left, right) to it that share the same initial color.
 *
 * Example Input:
 * n = 3, m = 3
 * Image:
 * 1 1 1
 * 2 0 2
 * 2 2 2
 * Starting Pixel: sr = 2, sc = 0
 * newColor = 3
 *
 * Key Observations:
 * - The problem is equivalent to coloring a connected component in a grid.
 * - Only 4-directional neighbors are considered (no diagonals).
 * - DFS or BFS can be used to traverse the connected component.
 *
 * Intuition:
 * - Record the initial color of the starting pixel.
 * - Use a visited check (or the modified color) to avoid revisiting pixels.
 * - Recursively (DFS) or iteratively (BFS) explore all valid connected neighbors and recolor them.
 *
 * Edge Cases:
 * - The starting pixel already has the newColor → no operation needed.
 * - Grid with only one pixel → recolor if necessary.
 *
 * Time Complexity:
 * - O(n * m), since each pixel is visited at most once.
 *
 * Space Complexity:
 * - O(n * m) for recursion stack in DFS (worst-case scenario).
 * - O(n * m) if a copy of the image is made to preserve the original.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function for Flood Fill
// ---------------------------
void dfs(int row, int col, vector<vector<int>> &image, int newColor, int initialColor) {
    int n = image.size();
    int m = image[0].size();

    // Base case: check boundaries and color match
    if (row < 0 || row >= n || col < 0 || col >= m) return;
    if (image[row][col] != initialColor) return;

    // Recolor the current pixel
    image[row][col] = newColor;

    // 4-directional moves: up, right, down, left
    int delta_row[] = {-1, 0, 1, 0};
    int delta_col[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int n_row = row + delta_row[i];
        int n_col = col + delta_col[i];
        dfs(n_row, n_col, image, newColor, initialColor);
    }
}

// ---------------------------
// Flood Fill Function
// ---------------------------
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    if (initialColor != newColor) { // Avoid infinite recursion if newColor is same as initial
        dfs(sr, sc, image, newColor, initialColor);
    }
    return image;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {2, 0, 2},
        {2, 2, 2}
    };

    int sr = 2, sc = 0, newColor = 3;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto &row : result) {
        for (int pixel : row) cout << pixel << " ";
        cout << "\n";
    }

    return 0;
}
