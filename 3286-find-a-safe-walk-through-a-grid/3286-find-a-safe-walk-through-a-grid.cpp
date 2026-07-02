class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int rows = grid.size();
        int cols = grid[0].size();

        // If the starting cell is unsafe, lose 1 health.
        int remainingHealth = health - grid[0][0];

        // If health becomes 0 or negative, we cannot even start.
        if (remainingHealth <= 0)
            return false;

        // best[i][j] stores the maximum health left when reaching (i,j)
        vector<vector<int>> best(rows, vector<int>(cols, -1));

        // Queue stores:
        // {row, column, remaining health}
        queue<vector<int>> q;

        q.push({0, 0, remainingHealth});
        best[0][0] = remainingHealth;

        // Four possible directions
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            vector<int> current = q.front();
            q.pop();

            int row = current[0];
            int col = current[1];
            int healthLeft = current[2];

            // Destination reached
            if (row == rows - 1 && col == cols - 1)
                return true;

            // Visit all four neighbors
            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Ignore cells outside the grid
                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;

                // Calculate health after entering the new cell
                int newHealth = healthLeft - grid[newRow][newCol];

                // We can move only if health stays positive
                if (newHealth <= 0)
                    continue;

                // Visit this cell only if we reached it with more health
                if (newHealth > best[newRow][newCol]) {

                    best[newRow][newCol] = newHealth;

                    q.push({newRow, newCol, newHealth});
                }
            }
        }

        return false;
    }
};