
#include <bits/stdc++.h>
using namespace std;
// static int count = 0;
#define ROW 5
#define COL 5
 static int cnt=0;

int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{

    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

int DFS(int M[][COL], int row, int col,
        bool visited[][COL])
{

    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[row][col] = true;

    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
        {
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
            cnt++;
        }
    return cnt;
}

int countIslands(int M[][COL])
{

    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int c = INT_MIN;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            if (M[i][j] && !visited[i][j])
            {
                // cout<<count;

                c =max (c, DFS(M, i, j, visited));
                cnt=0;
            }

    return c;
}

int main()
{
    int M[][COL] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);

    return 0;
}
