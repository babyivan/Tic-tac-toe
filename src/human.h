//
// Created by null on 26.07.2018.
//

#ifndef XO_HUMAN_H
#define XO_HUMAN_H

#include "player.h"

class human : public player {
 public:
  human();
  ~human() override;
  human(const std::string &name, const char &id);

  int move(const char (&game_board)[9], const int &iter) override;
};

#endif //XO_HUMAN_H