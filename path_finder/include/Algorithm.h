#pragma once

#include <vector>

namespace finder {

struct Node {
  int m_x;
  int m_y;
  double m_f_cost{};
  double m_g_cost{};
  double m_h_cost{};
  bool m_visited = false;
  Node(int x, int y) : m_x(x), m_y(y) {
  }
};

class Algorithm {
 private:
  // Initialize direction vectors
  std::vector<int> dRow = {0, 1, 0, -1};
  std::vector<int> dCol = {-1, 0, 1, 0};
  std::vector<Node> m_path;
  std::vector<std::vector<bool>> m_visited;
 public:
  Algorithm() = default;

  bool DFS(std::vector<std::vector<int>> &matrix,
           std::vector<std::vector<bool>> &visited,
           const Node &source,
           const Node &dest) const;

};

} // namespace finder

