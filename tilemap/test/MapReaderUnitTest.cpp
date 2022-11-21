#include "MapReader.h"
#include <gtest/gtest.h>

class MapReaderUnitTest : public ::testing::Test {
protected:
  std::string m_filename = "map.json";

public:
  MapReaderUnitTest() = default;
  ~MapReaderUnitTest() override = default;
};

TEST_F(MapReaderUnitTest, ReaderWorksOkay) {}
