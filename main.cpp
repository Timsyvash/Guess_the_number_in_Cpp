#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
  // Ініціалізація генератора випадкових чисел
  srand(time(0));

  cout << "Ласкаво просимо до гри ʼВгадай числоʼ\n";
  cout << "Виберіть складність:\n";
  cout << "1. Легка (1-100, 20 спроб)\n";
  cout << "2. Середня (1-200, 10 спроб)\n";
  cout << "3. Складна (1-300, 7 спроб)\n";
  cout << "4. Важка (1-400, 4 спроби)\n";
  cout << "Ваш вибір: ";

  short choice;
  while (!(cin >> choice) || choice < 1 || choice > 4) {
    cout << "Невірний вибір. Введіть число від 1 до 4: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }

  int max_num = 100, attempts = 20;

  switch (choice) {
    case 1:
      max_num = 100;
      attempts = 20;
      break;
    case 2:
      max_num = 200;
      attempts = 10;
      break;
    case 3:
      max_num = 300;
      attempts = 7;
      break;
    case 4:
      max_num = 400;
      attempts = 4;
      break;
  }

  int rand_num = 1 + rand() % max_num;
  int user_num = 0;

  cout << "\nГра почалася! Вгадайте число від 1 до " << max_num << ". У вас є " << attempts << " спроб.\n";

  while (attempts > 0) {
    cout << "Залишилось спроб: " << attempts << ". Введіть число: ";

    // Захист від введення символів замість числа
    while (!(cin >> user_num)) {
      cout << "Помилка, введіть саме число, не символ: ";
      cin.clear();
      cin.ignore(10000, '\n');
    }

    // Перевірка діапазону
    if (user_num < 1 || user_num > max_num) {
      cout << "Невірно, введіть число в діапазоні від 1 до " << max_num << "!\n";
      continue; // Повертаємося на початок циклу без втрати спроби
    }

    if (user_num > rand_num) {
      attempts--;
      cout << "Забагато!\n";
    } else if (user_num < rand_num) {
      attempts--;
      cout << "Замало!\n";
    } else {
      cout << "Вітаємо! Ви виграли! Загадане число: " << rand_num << "\n";
      break;
    }

    if (attempts == 0) {
      cout << "Ви програли! Загадане число було: " << rand_num << "\n";
      break;
    }
  }

  return 0;
}
