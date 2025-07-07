#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
  Object(int x, int y) : x(x), y(y) {}
  int getX() const { return x; }
  int getY() const { return y; }
  void setX(int newX) { x = newX; }
  void setY(int newY) { y = newY; }

private:
  int x, y;
};

#endif // OBJECT_H