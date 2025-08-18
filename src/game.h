#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "renderer_manager.h"
#include <SDL3/SDL.h>

class Game {
private:
  RendererManager rendererManager;
  bool running;
  void handleEvents();
  void update();

public:
  Game();
  ~Game();

  void run();
  void exit();
};

#endif // GAME_MANAGER_H
