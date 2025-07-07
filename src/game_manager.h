#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL3/SDL.h>

constexpr const char *APP_NAME{"Rayne"};
constexpr const char *APP_VERSION{"0.0.1"};
constexpr const char *APP_IDENTIFIER{"com.rayne"};
constexpr int WINDOW_WIDTH{800};
constexpr int WINDOW_HEIGHT{600};
constexpr int TARGET_FPS{60};
constexpr int FRAME_DELAY_MS{1000 / TARGET_FPS};
constexpr float FRAME_DELAY_S{(float)FRAME_DELAY_MS / 1000};

class GameManager {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;

  bool initialize();
  void handleEvents();
  void update();
  void render();
  void cleanup();

public:
  GameManager();
  ~GameManager();

  int run();
};

#endif // GAME_MANAGER_H