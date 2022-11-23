#pragma once

#include <vector>
#include <set>
#include <queue>

namespace finder {

struct Node {
  int m_x;
  int m_y;
  double m_f_cost{};
  double m_g_cost{};
  double m_h_cost{};
  Node(int x, int y) : m_x(x), m_y(y) {
  }
};

class Algorithm {
 private:
  std::vector<Node> m_path;
 public:
  Algorithm() = default;
  bool BFS(std::vector<std::vector<int>> &matrix, const Node &source, const Node &dest) const;
  std::vector<Node> AStar(std::vector<std::vector<int>> &matrix, Node source, Node dest);
};

} // namespace finder

