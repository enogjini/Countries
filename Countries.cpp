#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int solution(vector<vector<int>>& A) {
        int N = A.size();
        if (N == 0) return 0;  // Edge case: empty matrix
        int M = A[0].size();

        // Track which cells have already been assigned to a country
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int countries = 0;

        // 4-directional vectors: up, down, left, right
        int dr[] = { -1, 1, 0, 0 };
        int dc[] = { 0, 0, -1, 1 };

        // Scan every cell in the grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                // If this cell hasn't been visited, it's the start of a new country
                if (!visited[i][j]) {
                    countries++;

                    // BFS queue holds (row, col) pairs to explore
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    visited[i][j] = true;

                    // Remember the color of this country
                    int color = A[i][j];

                    // Expand outward to all connected cells of the same color
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        // Check all 4 neighbors
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d];  // Neighbor row
                            int nc = c + dc[d];  // Neighbor col

                            // Add neighbor if:
                            // 1. Within grid bounds
                            // 2. Not yet visited
                            // 3. Same color as current country
                            if (nr >= 0 && nr < N &&
                                nc >= 0 && nc < M &&
                                !visited[nr][nc] &&
                                A[nr][nc] == color) {
                                visited[nr][nc] = true;  // Mark before pushing to avoid duplicates
                                q.push({ nr, nc });
                            }
                        }
                    }
                    // BFS complete — entire country has been marked
                }
            }
        }
        return countries;  // Total number of distinct connected regions
    }
};

int main() {
    Solution sol;

    // ── Test 1: Problem example ──────────────────────────────
    // 7x3 matrix with 5 colors → should form 11 distinct countries
    vector<vector<int>> A = {
        {5, 4, 4},
        {4, 3, 4},
        {3, 2, 4},
        {2, 2, 2},
        {3, 3, 4},
        {1, 4, 4},
        {4, 1, 1}
    };
    cout << "Result:       " << sol.solution(A) << "  (expected 11)" << endl;

    // ── Test 2: All cells same color ─────────────────────────
    // Every cell is connected → only 1 country
    vector<vector<int>> B = {
        {1, 1},
        {1, 1}
    };
    cout << "All same:     " << sol.solution(B) << "  (expected 1)" << endl;

    // ── Test 3: All cells different colors ───────────────────
    // No two adjacent cells share a color → 4 countries
    vector<vector<int>> C = {
        {1, 2},
        {3, 4}
    };
    cout << "All different: " << sol.solution(C) << " (expected 4)" << endl;

    // ── Test 4: Single cell ──────────────────────────────────
    // Trivial case — one cell = one country
    vector<vector<int>> D = { {42} };
    cout << "Single cell:  " << sol.solution(D) << "  (expected 1)" << endl;

    return 0;
}