#pragma once

#include <vector>

namespace finder {

struct Node {
  int m_x;
  int m_y;
  Node(int x, int y) : m_x(x), m_y(y) {
  }
};

class Algorithm {
 private:
  // Initialize direction vectors
  std::vector<int> m_row_directions = {0, 1, 0, -1};
  std::vector<int> m_col_directions = {-1, 0, 1, 0};
  std::vector<Node> m_path;
  std::vector<std::vector<bool>> m_visited;
 public:
  Algorithm() = default;

  bool DFS(std::vector<std::vector<int>> &matrix,
           const Node &source,
           const Node &dest);
  std::vector<Node> getPath() const;

  void printPath(std::vector<std::vector<int>> &matrix);

};

} // namespace finder

