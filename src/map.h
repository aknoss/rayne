#ifndef MAP_H
#define MAP_H

class Map {
public:
  Map(int width, int height) : width(width), height(height) {}

private:
  int x, y, width, height;
};

#endif // MAP_H