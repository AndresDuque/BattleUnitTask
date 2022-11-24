# Battle unit task

Small project for Globus

### Dependencies

- CMake 3.20 or greather
- JSON nlohmann library

### Build

Using CMake you can generate the Makefile using the build system generator desired.
I highly recommend to use the ABI for Linux or Windows.

#### Steps

- Inside the project, create a build directory and go inside:
  ``` mkdir build```
  ``` cd build```

- Run CMake
- ``` cmake ..```

#### Building in Linux

I think you can use ```make```

#### Building in Windows

- For debug:
  ```cmake --build . --config Debug --parallel 16```

- For release:
  ```cmake --build . --config Debug --parallel 16```

### Running the application

You can call the executable and pass the JSON file through argument

```./globus_task map.json``` as an example

### Solution

The solution to find a path between a given initialization point and a targeted one in tile map is to know the
algorithms
that you can use to find the shortest path from the source to the destination.

These algorithms are:

- Dijkstra algorithm
- A* algorithm

My main idea was to code the algorithms above. The main issue was time as I did not expect to have a big work load.

Other options easier to code:

- DFS
- BFS

The algorithms mentioned above are the ones that can tell you if there is path from the source to the destination.
Adding a parent-child relationship between the cells and performing the way back from the destination cell parent to the
source is the way to get the path with the traversal algorithms.

### Issues known

- The JSON file given does not match with the size of the map/matrix. JSON attributes tileheight and tilewidth are
  incorrect.
- Hardcoded size of 64x64 matrix because of the issue mentioned above.
- Now, the algorithm find the path and give back a path that is not the shortest one.

### Improvement

- The main improvement for the current version is to add the parent-child relationship between the cells.
- A* star algorithm implementation. I would like to transform the given map into a graph with weight of 1.

