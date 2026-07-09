class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Find all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2)
                    q.push({i, j});

                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            while (size--) {

                auto [x, y] = q.front();
                q.pop();

                for (auto d : dir) {

                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;

                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};