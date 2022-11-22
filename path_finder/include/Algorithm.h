#pragma once

#include <vector>

namespace finder {
using Position = std::pair<int, int>;
using Path = std::vector<std::pair<int, int>>;

class Algorithm {
  Path m_path;

public:
  Algorithm() = default;
  void pathFinder(const std::vector<std::vector<int>> &map,
                  Position initial_position, Position targeted_position);
};

} // namespace finder

