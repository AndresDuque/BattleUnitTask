#pragma once

#include <string>
#include <vector>

class MapReader {
private:
  std::string m_json_str;
  std::vector<std::vector<int>> m_map;
  int m_width = 64;
  int m_height = 64;
  void buildMap();

public:
  explicit MapReader(std::string_view json_str);
  std::vector<std::vector<int>> getMap();
  int getMapHeight() const;
  int getMapWidth() const;
};
