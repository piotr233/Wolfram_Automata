//
// Created by piotr on 05/10/2021.
//

#ifndef COA_SFML_WINDOW_WINDOW_H_
#define COA_SFML_WINDOW_WINDOW_H_


#include <SFML/Window/Event.hpp>

#include "coord.h"
#include "slicer.h"
#include <mutex>
#include <queue>
#include <vector>
class Window {
 public:
  Window() = delete;
  Window(int width, int height);
  Window(const Coord &position, int width, int height);
  Window(const Window &other);;
  Window &operator=(const Window &other);;
  Slicer PopFrame();
  void PushFrame(const Slicer &new_frame);

  int GetQueueSize();

  void SetWindowLabel(const std::string &label);

  /// main window loop
  void MainLoop();

 protected:
  int width_;
  int height_;
  unsigned no_frame_;

  std::string current_window_title_ = "Wolfram's Automata";

  std::mutex event_queue_mutex_;
  std::queue<Slicer> frame_queue_;
  sf::Event event_;

  /// position of window on the screen
  Coord position_;
};

#endif//COA_SFML_WINDOW_WINDOW_H_
