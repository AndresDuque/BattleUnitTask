#include "MapReader.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

MapReader::MapReader(int map_height, int map_width, std::string_view json_str) {
  m_json_str = json_str;
  m_height = map_height;
  m_width = map_width;
  buildMap();
}

std::vector<std::vector<int>> MapReader::getMap() { return m_map; }

int MapReader::getMapHeight() const { return m_height; }

int MapReader::getMapWidth() const { return m_width; }

void MapReader::buildMap() {
  json object = json::parse(m_json_str);
  auto data = object["layers"][0]["data"].get<std::vector<int>>();
  for (int i = 0; i < data.size();) {
    std::vector<int> row;
    for (int j = 0; j < m_width; ++j) {
      row.push_back(data[i]);
      i++;
    }
    m_map.push_back(row);
  }
}