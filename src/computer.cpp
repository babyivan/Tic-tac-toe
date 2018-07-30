//
// Created by null on 26.07.2018.
//

#include <ctime>
#include "computer.h"
#include "vars.h"

computer::computer() {
#ifdef G_DEBUG
  std::cout << "computer()" << std::endl;
#endif
}

computer::~computer() {
#ifdef G_DEBUG
  std::cout << "~computer()" << std::endl;
#endif
}

computer::computer(const std::string &name, const char &id)
    : player(name, id) {
#ifdef G_DEBUG
  std::cout << "computer() with params" << std::endl;
#endif
  srand(static_cast<unsigned int>(time(nullptr)));

  ai_mode = 0;
  // Определяем уровень сложности
  init_ai();
}

void computer::init_ai() {
  std::cout << std::endl;
  std::cout << "Choose AI(" << get_name() << ") difference:" << std::endl;
  std::cout << "1. Easy" << std::endl;
  std::cout << "2. Hard" << std::endl;
  std::cout << std::endl;

  while (ai_mode != 1 && ai_mode != 2)
    std::cin >> ai_mode;
}

int computer::move(const char (&game_board)[9], const int &iter) {
  return (ai_mode == 1 ? ai_easy(game_board, iter) : ai_medium(game_board, iter));
}

int computer::ai_easy(const char (&game_board)[9], const int &iter) {
  int ret = find_random_free_cell(game_board);
  // Последний ход
  if (iter == 8) {
    for (int i = 0; i < 9; i++) {
      if (game_board[i] == CELL_EMPTY) {
        ret = i;
        break;
      }
    }
  }
  // При проверке мы проверяем значения пользователя, а они начинаюся с 1
  return (ret + 1);
}

int computer::ai_medium(const char (&game_board)[9], const int &iter) {
  int result = 0;
  // При первом и третем шаге всегда занимаем угол
  if (iter == 0 || iter == 2)
    result = find_free_angle(game_board);
    // При шаге второго игрока стараемся занять центр
  else if (iter == 1) {
    if (game_board[4] == CELL_EMPTY)
      result = 4;
      //Иначе ищем любой пустой угол
    else
      result = find_free_angle(game_board);
  } else if (iter >= 3 && iter <= 8) {
    // Все возможные победные комбинации
    const int win_comb[][8] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    // Сканируем наше игровое поле на возможные выигрышные комбинации
    for (int a = 0; a < 8; a++) {
      int count_me = 0;
      int count_enemy = 0;

      for (int b = 0; b < 3; b++) {
        if (game_board[win_comb[a][b]] == get_id())
          count_me++;
        else if (game_board[win_comb[a][b]] != get_id() && game_board[win_comb[a][b]] != CELL_EMPTY)
          count_enemy++;
      }
      // Нашли совпадение 2х последовательных "Х" или "О"
      if ((count_me == 2 && count_enemy == 0) || (count_me == 0 && count_enemy == 2)) {
        // Ищем пустую ячейку в комбинации
        for (int c = 0; c < 3; c++) {
          if (game_board[win_comb[a][c]] == CELL_EMPTY) {
            result = win_comb[a][c];
            break;
          }
        }
        // Останавливаем основной цикл
        break;
      }
    }
    // Вдруг получилось так что мы не смогли найти победную комбинацию - ищем рандомную
    if (result == 0) {
      result = find_random_free_cell(game_board);
    }
  }
  // Всегда + 1 ибо масив с "0" а ходы с "1"
  return (result + 1);
}

int computer::find_free_angle(const char (&game_board)[9]) {
  // Возможные углы
  const int arr[] = {1, 3, 7, 9};
  int pos = 0;

  while (true) {
    pos = rand() % 4;
    if (game_board[pos] == CELL_EMPTY)
      break;
  }
  return pos;
}

int computer::find_random_free_cell(const char (&game_board)[9]) {
  int pos = 0;

  while (true) {
    pos = rand() % 9;
    if (game_board[pos] == CELL_EMPTY)
      break;
  }
  return pos;
}