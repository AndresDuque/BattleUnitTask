#include <iostream>
#include "Algorithm.h"

namespace finder {

bool Algorithm::BFS(std::vector<std::vector<int>> &matrix, const Node &source, const Node &dest) const {
  std::queue<Node> bfs_queue;
  bfs_queue.push(source);
  while (!bfs_queue.empty()) {
    std::cout << bfs_queue.size() << std::endl;
    Node node = bfs_queue.front();
    bfs_queue.pop();
    int i = node.m_x;
    int j = node.m_y;

    // Coordinates are within the map
    if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix.at(0).size()) {

      // Check elevated terrain.
      if (matrix[i][j] == 4) {
        continue;
      }
      // Checking if the value 6 is found
      if (matrix[i][j] == matrix[dest.m_x][dest.m_y]) {
        return true;
      }
      // marking as wall upon successful visitation
      matrix[i][j] = 0;

      for (int k = -1; k <= 1; k += 2) {
        bfs_queue.emplace(i + k, j);
        bfs_queue.emplace(i, j + k);
      }

    }

  }
  // BFS algorithm terminated without returning true
  return false;
}
std::vector<Node> Algorithm::AStar(std::vector<std::vector<int>> &matrix, Node source, Node dest) {
  std::vector<Node> open_list;
  std::vector<Node> closed_list;

  return m_path;
}

}
