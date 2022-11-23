#include "Algorithm.h"
#include <gtest/gtest.h>
#include "MapReader.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

class GraphUnitTest : public ::testing::Test {
 protected:
  std::shared_ptr<finder::Algorithm> m_graph;
  std::string m_filename = "map.json";
  std::shared_ptr<reader::MapReader> m_map_reader;
  std::string m_json_str;
 public:
  GraphUnitTest() = default;
  ~GraphUnitTest() override = default;
  void SetUp() override {
    std::ifstream file(m_filename);
    json object = json::parse(file);
    m_json_str = object.dump(4);
    m_map_reader = std::make_shared<reader::MapReader>(64, 64, m_json_str);
    m_graph = std::make_shared<finder::Algorithm>();
  }
};

TEST_F(GraphUnitTest, GraphBuilderWorks) {

  auto map = m_map_reader->getMap();
  std::cout << m_graph->BFS(map,
                            {m_map_reader->getInitialPosition().m_x, m_map_reader->getInitialPosition().m_y},
                            {m_map_reader->getTargetedPosition().m_x, m_map_reader->getTargetedPosition().m_y});
}

TEST_F(GraphUnitTest, SmallMapTest) {
  std::vector<std::vector<int>> test_small_map =
      {{0, -1, -1, 4, -1}, {4, -1, -1, -1, -1}, {4, -1, 4, -1, -1}, {-1, -1, -1, -1, 6}};
  std::cout << m_graph->BFS(test_small_map,
                            {0, 0}, {static_cast<int>(test_small_map.size() - 1), static_cast<int>(test_small_map.size() - 1)});
}