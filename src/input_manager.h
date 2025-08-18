#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

class Game;

class InputManager {
private:
  Game *game;

public:
  InputManager(Game *g);
  ~InputManager();
  void readInput();
};

#endif // INPUT_MANAGER_H
