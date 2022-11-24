#include "Algorithm.h"
#include <gtest/gtest.h>
#include "MapReader.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

class AlgorithmUnitTest : public ::testing::Test {
 protected:
  std::shared_ptr<finder::Algorithm> m_graph;
  std::string m_filename = "map.json";
  std::shared_ptr<reader::MapReader> m_map_reader;
  std::string m_json_str;
 public:
  AlgorithmUnitTest() = default;
  ~AlgorithmUnitTest() override = default;
  void SetUp() override {
    std::ifstream file(m_filename);
    json object = json::parse(file);
    m_json_str = object.dump(4);
    m_map_reader = std::make_shared<reader::MapReader>(64, 64, m_json_str);
    m_graph = std::make_shared<finder::Algorithm>();
  }
};

TEST_F(AlgorithmUnitTest, DFSAlgorithmWorks) {

  auto map = m_map_reader->getMap();
  std::vector<std::vector<bool>> visited = {map.size(), std::vector<bool>(map.size(), false)};
  bool result = m_graph->DFS(map,
                             visited,
                             {m_map_reader->getInitialPosition().m_x, m_map_reader->getInitialPosition().m_y},
                             {m_map_reader->getTargetedPosition().m_x, m_map_reader->getTargetedPosition().m_y});
  EXPECT_TRUE(result);

}

TEST_F(AlgorithmUnitTest, SmallMapTest) {
  std::vector<std::vector<int>> test_small_map =
      {{0, -1, -1, 4, -1},
       {4, -1, -1, -1, -1},
       {4, -1, 4, -1, -1},
       {-1, -1, -1, -1, 6},
       {4, -1, -1, -1, -1}};
  int row, col;
  for (int i = 0; i < test_small_map.size(); ++i) {
    for (int j = 0; j < test_small_map.at(i).size(); ++j) {
      if (test_small_map[i][j] == 6) {
        row = i;
        col = j;
      }
    }
  }
  finder::Node dest(row, col);


//  EXPECT_TRUE(m_graph->BFS(test_small_map,
//                           {0, 0}, {4, 4}));
  std::vector<std::vector<bool>> visited = {test_small_map.size(), std::vector<bool>(5, false)};
  bool result = m_graph->DFS(test_small_map, visited, {0, 0}, dest);
  EXPECT_TRUE(result);
}