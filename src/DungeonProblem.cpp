#include <iostream>
#include <vector>
#include <queue>

#define TRUE 1
#define FALSE 0

using namespace std;

const int dn[4] = {-1, +1, 0, 0};
const int dm[4] = {0, 0, -1, +1};


int DungeonProblem(int** matrix,
                int rows,
                int columns,
                pair<int, int> start, 
                pair<int, int> end)
{
    // 
    int move_count = 1;
    bool reached_end = false;

    // The Queue for BFS 
    std::queue<pair<int, int>> bfsqueue;

    // Create visited matrix
    int** visited = new int*[rows];
    for(int i=0; i<rows; i++)
    {
        visited[i] = new int[columns];
        for(int j=0; j < columns; j++)
        {
            visited[i][j] = FALSE;
        }
    }

    // Push the first node & mark it as visited
    bfsqueue.push(start);
    visited[start.first][start.second] = TRUE;

    while(bfsqueue.size() > 0)
    {
        auto current = bfsqueue.front();
        bfsqueue.pop();

        int n = current.first;
        int m = current.second;
        
        // If the end is reached, break
        if(n == end.first && m == end.second)
        {
            reached_end = true;
            break;
        }

        // Explore neighbours
        for(int i = 0; i < 4; i++)
        {
            int nighbour_n = n + dn[i];
            int nighbour_m = m + dm[i];
            if(nighbour_n < 0 || nighbour_n > rows ||
                    nighbour_m < 0 || nighbour_m > columns )
            {
                continue;
            }
            if(matrix[nighbour_n][nighbour_m] != '#' && matrix[nighbour_n][nighbour_m] != 'E')
            {
                bfsqueue.push(make_pair(nighbour_n, nighbour_m));
            }
        }

    }

    if(reached_end)
    {
        return move_count;
    }
    return -1;
}
