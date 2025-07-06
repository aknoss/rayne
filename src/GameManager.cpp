#include "GameManager.h"
#include <SDL3/SDL.h>

GameManager::GameManager()
    : window(nullptr), renderer(nullptr), running(false) {}

GameManager::~GameManager() { cleanup(); }

bool GameManager::initialize() {
  int i;

  SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER);

  // Initialize SDL
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
    return false;
  }

  if (!SDL_CreateWindowAndRenderer(APP_NAME, WINDOW_WIDTH, WINDOW_HEIGHT, 0,
                                   &window, &renderer)) {
    SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
    return false;
  }

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  running = true;
  return true;
}

void GameManager::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_QUIT) {
      running = false;
    }
  }
}

void GameManager::update() {}

void GameManager::render() {}

void GameManager::cleanup() {
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

int GameManager::run() {
  if (!initialize()) {
    return -1;
  }

  while (running) {
    handleEvents();
    update();
    render();
    SDL_Delay(FRAME_DELAY_MS);
  }

  return 0;
}