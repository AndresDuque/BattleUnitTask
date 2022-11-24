#include <iostream>
#include "Algorithm.h"
#include <queue>
#include <stack>

namespace finder {
bool isValid(std::vector<std::vector<bool>> &visited,
             int row, int col) {
  // If cell is out of bounds
  if (row < 0 || col < 0
      || row >= visited.size() || col >= visited.at(0).size())
    return false;

  // If the cell is already visited
  if (visited[row][col])
    return false;

  // Otherwise, it can be visited
  return true;
}

bool Algorithm::DFS(std::vector<std::vector<int>> &matrix,
                    std::vector<std::vector<bool>> &visited,
                    const Node &source,
                    const Node &dest) const {
  Node start = source;
  std::stack<Node> dfs_stack;
  dfs_stack.push(start);
  while (!dfs_stack.empty()) {
    auto node = dfs_stack.top();
    dfs_stack.pop();
    if (!isValid(visited, node.m_x, node.m_y))
      continue;
    if (matrix[node.m_x][node.m_y] == 4) {
      continue;
    }
    std::cout << "(" << node.m_x << "," << node.m_y << ") ";
    if (matrix[node.m_x][node.m_y] == matrix[dest.m_x][dest.m_y]) {
      return true;
    }

    visited[node.m_x][node.m_y] = true;

    // Print the element at
    // the current top cell

    // Push all the adjacent cells
    for (int i = 0; i < 4; i++) {
      int adjx = node.m_x + dRow[i];
      int adjy = node.m_y + dCol[i];
      dfs_stack.push({adjx, adjy});
    }
  }
  return false;
}

}
