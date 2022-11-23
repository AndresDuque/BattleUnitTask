#include "MapReader.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <gtest/gtest.h>

using json = nlohmann::json;

class MapReaderUnitTest : public ::testing::Test {
protected:
  std::string m_filename = "map.json";
  std::shared_ptr<reader::MapReader> m_map_reader;
  std::string m_json_str;

public:
  MapReaderUnitTest() = default;
  ~MapReaderUnitTest() override = default;
  void SetUp() override {
    std::ifstream file(m_filename);
    json object = json::parse(file);
    m_json_str = object.dump(4);
    m_map_reader = std::make_shared<reader::MapReader>(64, 64, m_json_str);
  }
};

TEST_F(MapReaderUnitTest, ReaderWorksOkay) {

  auto map = m_map_reader->getMap();
  EXPECT_EQ(map.size(), 64);
  EXPECT_EQ(map.at(0).size(), 64);

  std::ifstream file(m_filename);
  json object = json::parse(file);
  auto data = object["layers"][0]["data"].get<std::vector<int>>();
  std::vector<int> json_vector;
  for (auto const &i : map) {
    for (int j : i) {
      json_vector.push_back(j);
    }
  }
  EXPECT_EQ(json_vector.size(), data.size());
  EXPECT_EQ(json_vector, data);
}

TEST_F(MapReaderUnitTest, FindPositionsWorks) {
  EXPECT_NO_THROW(m_map_reader->getInitialPosition());
  EXPECT_NO_THROW(m_map_reader->getTargetedPosition());
}