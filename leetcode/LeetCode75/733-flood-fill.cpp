#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int sr, int sc, int color, int newColor)
{
  if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color)
    return;
  image[sr][sc] = newColor;
  dfs(image, sr - 1, sc, color, newColor); // TOP
  dfs(image, sr, sc + 1, color, newColor); // RIGHT
  dfs(image, sr + 1, sc, color, newColor); // BOTTOM
  dfs(image, sr, sc - 1, color, newColor); // LEFT
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
  if (image[sr][sc] != color)
    dfs(image, sr, sc, image[sr][sc], color);
  return image;
}

int main()
{
  vector<vector<int>> image;
  image.push_back({1, 1, 1});
  image.push_back({1, 1, 0});
  image.push_back({1, 0, 1});
  int sr = 1, sc = 1, color = 2;

  vector<vector<int>> result = floodFill(image, sr, sc, color);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[0].size(); j++)
    {
      cout << result[i][j];
    }
    cout << endl;
  }

  return 0;
}