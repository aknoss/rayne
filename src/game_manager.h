#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "render_manager.h"
#include <SDL3/SDL.h>

class GameManager {
private:
  RenderManager renderManager;
  bool running;
  void handleEvents();
  void update();

public:
  GameManager();
  ~GameManager();

  int run();
};

#endif // GAME_MANAGER_H
