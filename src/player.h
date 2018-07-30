//
// Created by null on 26.07.2018.
//

#ifndef XO_PLAYER_H
#define XO_PLAYER_H

#include <string>
#include <iostream>

class player {
 public:
  player();
  virtual ~player();
  player(std::string name, char id);

  virtual int move(const char (&game_board)[9], const int &iter) = 0;

  const char &get_id();
  const std::string &get_name();

 private:
  std::string name;
  char id;
};

#endif //XO_PLAYER_H
