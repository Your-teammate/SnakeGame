#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "game.h"

int main() {
  // default launch options
  std::size_t kFramesPerSecond{60};
  std::size_t kScreenWidth{640};
  std::size_t kScreenHeight{640};
  std::size_t kGridWidth{32};
  std::size_t kGridHeight{32};
  // changing launch options if user wants that
  std::cout << "Do you want to change launch options (they will not be saved and may cause incorrect work of the game)? If yes, type \"yes\" (without quotes) and press Enter: ";
  std::string answer;
  getline(std::cin, answer); // using getline to handle empty input
  if (answer == "yes") {
    std::cout << "Framerate: ";
    std::cin >> kFramesPerSecond;
    std::cout << "Screen width: ";
    std::cin >> kScreenWidth;
    std::cout << "Screen height: ";
    std::cin >> kScreenHeight;
    std::cout << "Grid width: ";
    std::cin >> kGridWidth;
    std::cout << "Grid height: ";
    std::cin >> kGridHeight;
  }
    
  const std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  
  AudioPlayer audio_player;
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}