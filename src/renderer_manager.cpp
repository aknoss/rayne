#include "renderer_manager.h"
#include <stdexcept>

RendererManager::RendererManager() : window(nullptr), renderer(nullptr) {
  SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER);

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
    throw std::runtime_error("SDL could not initialize!");
  };

  if (!SDL_CreateWindowAndRenderer(APP_NAME, WINDOW_WIDTH, WINDOW_HEIGHT, 0,
                                   &window, &renderer)) {
    SDL_Log("SDL could not create window and renderer: %s", SDL_GetError());
    throw std::runtime_error("SDL could not create window and renderer");
  };

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

RendererManager::~RendererManager() {
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  SDL_Quit();
}

void RendererManager::waitNextFrame() { SDL_Delay(FRAME_DELAY_MS); }
