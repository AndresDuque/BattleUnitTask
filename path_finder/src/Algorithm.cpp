#include "Algorithm.h"

namespace finder {


bool Algorithm::BFS(std::vector<std::vector<int>> &matrix, finder::Node source, finder::Node dest) {
  std::queue<Node> bfs_queue;
  bfs_queue.push(source);
  while (!bfs_queue.empty()) {
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
        bfs_queue.push(Node(i + k, j));
        bfs_queue.push(Node(i, j + k));
      }

    }

  }
  // BFS algorithm terminated without returning true
  return false;
}

}
