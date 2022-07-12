#include <bits/stdc++.h>
using namespace std;

void eraseIsLands(vector<vector<char>> &grid, int i, int j)
{
  int row = grid.size();
  int col = grid[0].size();
  if (i < 0 || j < 0 || i == row || j == col || grid[i][j] == '0')
    return;
  grid[i][j] = '0';

  eraseIsLands(grid, i - 1, j);
  eraseIsLands(grid, i, j + 1);
  eraseIsLands(grid, i + 1, j);
  eraseIsLands(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
  int row = grid.size(), col = row ? grid[0].size() : 0, isLand = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
    {
      if (grid[i][j] == '1')
      {
        isLand++;
        eraseIsLands(grid, i, j);
      }
    }
  return isLand;
}

int main()
{
  vector<vector<char>> grid;
  grid.push_back({'1', '1', '1', '1', '0'});
  grid.push_back({'1', '1', '0', '1', '0'});
  grid.push_back({'1', '1', '0', '0', '0'});
  grid.push_back({'1', '1', '0', '0', '0'});

  int result = numIslands(grid);
  cout << result;
  return 0;
}