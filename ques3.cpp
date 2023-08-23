#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
  int row, col;
  Point(int r, int c) : row(r), col(c) {}
};
 
int moveInGrid(vector<vector<int>> &grid, int startRow, int startCol)
{
  int rows = grid.size();
  int cols = grid[0].size();
  int totalValue = 0;
 
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  queue<Point> q;
 
  q.push(Point(startRow, startCol));
  visited[startRow][startCol] = true;
 
  int dr[] = {1, 1, -1, -1};
  int dc[] = {1, -1, -1, 1};
 
  while (!q.empty())
  {
    Point current = q.front();
    q.pop();

    totalValue += grid[current.row][current.col];

    for (int i = 0; i < 3; i++)
    {
      int newRow = current.row + dr[i];
      int newCol = current.col + dc[i];

      if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol])
      {
        q.push(Point(newRow, newCol));
        visited[newRow][newCol] = true;
        break;
      }
    }
  }

  return totalValue;
}

int main()
{
  vector<vector<int>> grid = {
      {-12, 33, -4},
      {12, -1, 15},
      {49, -4, 10}};

  int startRow = 0;
  int startCol = 1;

  int result = moveInGrid(grid, startRow, startCol);
  cout << result << endl;

  return 0;
}
