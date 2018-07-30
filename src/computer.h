//
// Created by null on 26.07.2018.
//

#ifndef XO_COMPUTER_H
#define XO_COMPUTER_H

#include "player.h"

class computer : public player {
 public:
  computer();
  ~computer() override;
  computer(const std::string &name, const char &id);

  int move(const char (&game_board)[9], const int &iter) override;

 private:
  //углы - 1, 3, 7, 9
  int find_free_angle(const char (&game_board)[9]);
  // Поиск свободной рандомной ячейки на игровом поле
  int find_random_free_cell(const char (&game_board)[9]);
  // Выбираем сложность AI в момент создания класса
  void init_ai();
  // Алгоритмы для победы
  int ai_easy(const char (&game_board)[9], const int &iter);
  int ai_medium(const char (&game_board)[9], const int &iter);

 private:
  int ai_mode;
};

#endif //XO_COMPUTER_H