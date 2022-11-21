#include "MapReader.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

MapReader::MapReader(std::string_view json_str) { m_json_str = json_str; }

std::vector<std::vector<int>> MapReader::getMap() { return m_map; }

int MapReader::getMapHeight() const { return m_height; }

int MapReader::getMapWidth() const { return m_width; }

void MapReader::buildMap() {

}