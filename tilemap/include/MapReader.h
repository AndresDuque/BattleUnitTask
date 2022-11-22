#pragma once

#include <string>
#include <vector>

namespace reader{
struct Coordinates{
  int m_x;
  int m_y;
};

class MapReader {
private:
  std::string m_json_str;
  std::vector<std::vector<int>> m_map;
  int m_width = 64;
  int m_height = 64;
  Coordinates m_initial_position;
  Coordinates m_target_position;

  void buildMap();
  Coordinates findPosition(int value);

public:
  explicit MapReader(int map_height, int map_width, std::string_view json_str);
  std::vector<std::vector<int>> getMap();
  int getMapHeight() const;
  int getMapWidth() const;
  Coordinates getInitialPosition() ;
  Coordinates getTargetedPosition() ;
};
}
