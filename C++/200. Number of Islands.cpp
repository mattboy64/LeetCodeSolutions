

/*
Did it in a non-recursive way for practice. The flood function was taking too long (timing out), so
I mark the location as filled before pushing to the stack. Hopefully that avoids things getting pushed more than once.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m_size = grid.size(); // row size
        int n_size = grid[0].size(); // column size

        int island_count = 0;

        for (int m = 0; m < m_size; ++m){
            for (int n = 0; n < n_size; ++n){
                // Check to see if this grid location needs to be checked
                if (grid[m][n] == '1'){
                    island_count++;
                    floodIslandLocation(m, n, grid);
                }
            }
        }

        return island_count;    
    }

    void floodIslandLocation(int m, int n, vector<vector<char>>& grid){
        queue<pair<int, int>> gridQueue;
        grid[m][n] = '0';
        gridQueue.push({m,n});

        int i;
        int j;

        while(!gridQueue.empty()){
            pair curr_coord = gridQueue.front();
            gridQueue.pop();

            i = curr_coord.first;
            j = curr_coord.second;

            // Fill North
            if (i > 0 && grid[i-1][j] == '1'){
                grid[i-1][j] = '0';
                gridQueue.push({i-1,j});
            }

            // Fill East
            if (j < grid[i].size()-1 && grid[i][j+1] == '1'){
                grid[i][j+1] = '0';
                gridQueue.push({i,j+1});
            }

            // Fill South
            if (i < grid.size()-1 && grid[i+1][j] == '1'){
                grid[i+1][j] = '0';
                gridQueue.push({i+1,j});
            }

            // Fill West
            if (j > 0 && grid[i][j-1] == '1'){
                grid[i][j-1] = '0';
                gridQueue.push({i,j-1});
            }
        }

    }
};

/*
Recursive way. Made sense, but I'm not a huge recursive fan, so did it using a queue
above as well for practice.
*/
class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m_size = grid.size(); // row size
        int n_size = grid[0].size(); // column size

        int island_count = 0;

        for (int m = 0; m < m_size; ++m){
            for (int n = 0; n < n_size; ++n){
                // Check to see if this grid location needs to be checked
                if (grid[m][n] == '1'){
                    island_count++;
                    fillIslandLocation(m, n, grid);
                }
            }
        }

        return island_count;
    }

    void fillIslandLocation(int m, int n, vector<vector<char>>& grid){
        grid[m][n] = '0';
        // Fill North
        if (m > 0 && grid[m-1][n] == '1'){
            fillIslandLocation(m-1, n, grid);
        }

        // Fill East
        if (n < grid[m].size()-1 && grid[m][n+1] == '1'){
            fillIslandLocation(m, n+1, grid);
        }

        // Fill South
        if (m < grid.size()-1 && grid[m+1][n] == '1'){
            fillIslandLocation(m+1, n, grid);
        }

        // Fill West
        if (n > 0 && grid[m][n-1] == '1'){
            fillIslandLocation(m, n-1, grid);
        }
    }
};