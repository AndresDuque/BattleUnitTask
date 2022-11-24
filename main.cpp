#include "MapReader.h"
#include "Algorithm.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>

using json = nlohmann::json;

int main(int argc, char *argv[]) {
  if (argc == 1 || argc > 2) {
    std::cout << "Invalid input. Please introduce a map JSON format." << std::endl;
    return -1;
  }
  std::ifstream file(argv[1]);

  try {
    json map_json = json::parse(file);
    std::string map_str = map_json.dump(4);
    // I would like to have the consistent data of the sizes of the map coming from the file
    // In the given json map the tile height and width does not match. So I hardcoded the real map size which is 64x64
    std::shared_ptr<reader::MapReader> map_reader = std::make_shared<reader::MapReader>(64,
                                                                                        64,
                                                                                        map_str);
    auto map = map_reader->getMap();

    std::shared_ptr<finder::Algorithm> solver = std::make_shared<finder::Algorithm>();

    bool result = solver->DFS(map,
                              {map_reader->getInitialPosition().m_x, map_reader->getInitialPosition().m_y},
                              {map_reader->getTargetedPosition().m_x, map_reader->getTargetedPosition().m_y});
    if (result) {
      auto path = solver->getPath();
      // Print path
      for (auto node: path) {
        std::cout << "(" << node.m_x << "," << node.m_y << ")";
      }
    } else {
      std::cout << "Could not find a path from initial position to target." << std::endl;
    }
  } catch (json::parse_error &e) {
    // output exception information
    std::cout << "message: " << e.what() << '\n'
              << "exception id: " << e.id << '\n' << std::endl;
  }
  return 0;
}
