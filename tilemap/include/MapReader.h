#pragma once

#include <string>
#include <vector>

class MapReader {
private:
  std::string m_json_str;
  std::vector<std::vector<int>> m_map;
  int m_width{};
  int m_height{};

public:
  explicit MapReader(std::string_view json_str);
  std::vector<std::vector<int>> getMap();
  void buildMap();
  int getMapHeight() const;
  int getMapWidth() const;
};
