/*
909. Snakes and Ladders
Medium

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

 

Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.
*/


/*
Search Algorithms!
What to use? We know that we care abot the lowest 
number of moves (or dice roles). Since there is no
cost associated with a dice role (1 step), dijkstras
turns into BFS (dijkstras with a uniform cost IS BFS!)
A* MIGHT give a faster result (heuristic distance to goal),
but I'm going to just go with BFS for now. 

SO MANY LITTLE THINGS TO TRIP YOU UP! This wasn't a difficult
problem, but there are a TON of tiny gotchas. Not really 
suitable for a whiteboard problem. It was fun, but doing
it without a debugger made it frustrating and HARD!
*/

class Solution {
protected:
    // Snake and Ladders Board Dimentions
    int n = 0; // row/column count
    int n_sqr = 0;
    const int NORMAL_SQUARE = -1;

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> squareQ;
        n = board.size();
        n_sqr = n*n;
        vector<bool> visited = vector(n_sqr+1, false);

        squareQ.push({1,0}); // starting location
        visited[1] = true;

        while (!squareQ.empty()){
            int curr_sqr = squareQ.front().first;
            int curr_lvl = squareQ.front().second;
            squareQ.pop();

            //cout << "||| Spot: " << curr_sqr;

            // If the square had a chute or ladder, start there
            int squareValue = GetSquareValue(board, curr_sqr);
            // if (squareValue != NORMAL_SQUARE){
            //     curr_sqr = squareValue;
            // }

            //cout << " to " << squareValue << " level: " << curr_lvl << endl;

            // See if we arrived at our target
            if (curr_sqr == n_sqr){
                return curr_lvl;
            }

            int last_sqr = min(curr_sqr+6, n_sqr);
            
            // Add all (up to) 6 possible locations to the queue
            for (int i = curr_sqr+1; i <= last_sqr; ++i){
                if (visited[i] == false){
                    //cout << "Pushing " << i;
                    int squareValue = GetSquareValue(board, i);
                    if (squareValue != NORMAL_SQUARE){
                        //cout << " as " << squareValue << endl;
                        squareQ.push({squareValue, curr_lvl+1});
                    }
                    else{
                        //cout << endl;
                        squareQ.push({i, curr_lvl+1});
                    }
                    visited[i] = true; // we still mark the original square as visited and NOT the final location
                }
            }
        }

        // If we got here, then we've exhausted all our targets without reaching the goal.
        return -1;
    }

    int GetSquareValue(const vector<vector<int>>& board, int squareNumber){
        squareNumber -= 1; // 0 based indexes so bring it down 1
        int row = (n-1) - squareNumber / n; // starts at the bottom left, so need to go backwards
        int column = squareNumber % n;

        // since we are using a Boustrophedon style board,
        // adjust the column every other line

        // even rows, odd lines are backwards
        if (n % 2 == 1){
            if (row % 2 == 1){
                column = (n-1)-column;
            }
        } 
        else{ // odd rows, even lines are backwards
            if (row % 2 == 0){
                column = (n-1)-column;
            }
        }

        return board[row][column];
    }
};