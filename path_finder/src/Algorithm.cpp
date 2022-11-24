#include "Algorithm.h"
#include <queue>
#include <stack>
#include <iostream>

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
                    const Node &source,
                    const Node &dest) {
  Node start = source;
  std::stack<Node> dfs_stack;

  m_visited = {matrix.size(), std::vector<bool>(matrix.size(), false)};

  dfs_stack.push(start);
  while (!dfs_stack.empty()) {
    auto node = dfs_stack.top();
    dfs_stack.pop();
    if (!isValid(m_visited, node.m_x, node.m_y))
      continue;
    if (matrix[node.m_x][node.m_y] == 4) {
      continue;
    }
    m_path.push_back({node.m_x, node.m_y});
    if (matrix[node.m_x][node.m_y] == matrix[dest.m_x][dest.m_y]) {
      return true;
    }

    m_visited[node.m_x][node.m_y] = true;

    m_path.push_back({node.m_x, node.m_y});
    // Push all the adjacent cells
    // 4 means NORTH, WEST, EAST, SOUTH
    for (int i = 0; i < 4; i++) {
      int neighbor_x = node.m_x + m_row_directions[i];
      int neighbor_y = node.m_y + m_col_directions[i];
      dfs_stack.push({neighbor_x, neighbor_y});
    }
  }
  return false;
}
std::vector<Node> Algorithm::getPath() const {
  return m_path;
}
void Algorithm::printPath(std::vector<std::vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; i < matrix.size(); ++j) {
      std::cout << matrix[i][j] << std::endl;
    }
  }

}

}
