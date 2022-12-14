#include "MapReader.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace reader{

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

Coordinates MapReader::findPosition(int value) {
  Coordinates coordinates{};
  for (int i = 0; i < m_map.size(); i++) {
    for (int j = 0; j < m_map.at(i).size(); j++) {
      if (m_map[i][j] == value) {
        coordinates.m_x = i;
        coordinates.m_y = j;
      }
    }
  }
  return coordinates;
}
Coordinates MapReader::getInitialPosition() {
  return findPosition(0); }
Coordinates MapReader::getTargetedPosition() { return findPosition(6); }

}