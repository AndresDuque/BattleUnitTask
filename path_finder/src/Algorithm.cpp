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

bool Algorithm::BFS(std::vector<std::vector<int>> &matrix,
                    std::vector<std::vector<bool>> &visited,
                    const Node &source,
                    const Node &dest) const {
  std::queue<Node> bfs_queue;
  bfs_queue.push(source);

  while (!bfs_queue.empty()) {
    std::cout << bfs_queue.size() << std::endl;
    Node node = bfs_queue.front();
    bfs_queue.pop();
    int i = node.m_x;
    int j = node.m_y;

    // Coordinates are within the map
    if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix.at(0).size() && matrix[i][j] != 4) {

      // Checking if the value 6 is found
      if (matrix[i][j] == matrix[dest.m_x][dest.m_y]) {
        return true;
      }
      // marking as wall upon successful visitation
      visited[i][j] = true;

      for (int k = -1; k <= 1; k += 2) {
        bfs_queue.emplace(i + k, j);
        bfs_queue.emplace(i, j + k);
      }

    }

  }
  // BFS algorithm terminated without returning true
  return false;
}
std::vector<Node> Algorithm::AStar(std::vector<std::vector<int>> &matrix, const Node &source, const Node &dest) {
  std::vector<Node> open_list;
  std::vector<Node> closed_list;

  return m_path;
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
