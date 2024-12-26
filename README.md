#   Tic-Tac-Toe


Добро пожаловать в **Tic-Tac-Toe** (или "Крестики-нолики" для олдскульных игроков) — классическую игру на поле 3x3. Вы можете играть как с друзьями, так и против искусственного интеллекта, который будет менять сложность по вашему желанию. Если вдруг у вас нет друзей рядом, не переживайте — игра имеет встроенного бота, который будет рад вам составить компанию.

---


## **Как запустить?**

1. Скачайте репозиторий.
```bash
git clone https://github.com/SahibAlMowt/tic-tac-toe.git
```
2. Постройте проект в вашем любимом IDE (geany).
3. В командной строке или терминале запускайте:

```bash
g++ main.cpp game.cpp exception.cpp -o tictactoe
```
```bash
./tictactoe
```

4. Выберите режим игры (игра с другом или против бота).
5. Наслаждайтесь игрой!

---


## Как выбрать библиотеку?

В проекте используются как статические, так и динамические библиотеки. Вы можете выбрать тип библиотеки, изменив флаг в CMake.

### Статическая библиотека

Статическая библиотека включает весь код в исполняемый файл, что не требует дополнительных файлов при запуске программы.

#### Как собрать проект с статической библиотекой:
1. В `CMakeLists.txt` установите флаг:
```bash
   cmake -DBUILD_SHARED_LIBS=OFF ..
```
2. Выполните сборку:
```bash
   make
```
### Динамическая библиотека

Динамическая библиотека создается как отдельный файл, и исполняемые файлы (`tic-tac-toe` и `tests`) будут ссылаться на неё во время выполнения.

#### Как собрать проект с динамической библиотекой:
1. В `CMakeLists.txt` установите флаг:
```bash
   cmake -DBUILD_SHARED_LIBS=ON ..
```
2. Выполните сборку:
```bash
   make
```
### Проверка

- Для статической библиотеки: Исполняемые файлы включают всю библиотеку, и дополнительных файлов для запуска не требуется.
- Для динамической библиотеки: Убедитесь, что `.so` или `.dll` файлы доступны во время выполнения (например, в том же каталоге с исполняемым файлом или в системных путях).

---

## Как настроить игру?

1. При запуске программы вас попросят ответить, хотите ли вы сыграть в "Крестики-нолики" (введите `yes` или `no`).
2. Если вы выбрали `yes`:
   - Выберите формат игры: `3x3`, `4x4` или `5x5`.
   - Выберите режим игры:
     - Введите 1 для игры "игрок против игрока".
     - Введите 2 для игры "игрок против ИИ".
   - Если выбран режим "игрок против ИИ", выберите уровень сложности: `easy` или `medium`.
3. Введите свои никнеймы для игры:
   - Для режима `player vs player` нужно ввести два разных имени.
   - Для режима `player vs AI` введите только своё имя (вторым игроком будет ИИ).
4. Следуйте инструкциям для ввода ходов.
5. Для завершения игры можно ввести команду `stop` пока вы выбираете настройки игры и специальный код `666` во время игры и ввода ходов. Если при вводе останавливающей фразы программа выдает ошибку ввода, попробуйте другой код остановки(если ввели `stop` и выдало ошибку попробуйте `666`, если ввели `666` и выдало ошибку попробуйте `stop`)
6. После завершения игры вам будет показан счет за прошедшие игры, и далее будет предложено сыграть ещё один раунд или выйти.

---


## **Проект**

Проект разделен на несколько файлов для удобства:

1. **`game.h`** — заголовочный файл, содержащий описание классов, структур и необходимых функций.
2. **`exception.cpp`** — файл с обработкой исключений, проверками пользовательских вводов. Если игрок ввел что-то странное, он быстро узнает об этом!
3. **`game.cpp`** — основной файл с логикой игры.
4. **`main.cpp`** — центральная точка входа. Именно тут вы запускаете игру и выбираете, кто кого победит.
5. **`readme.md`** — ну, вы его уже читаете. 
---

## **Технические подробности**

Игра использует классы и структуры для представления игроков и игрового поля:

- **`Gamer`:** структура, представляющая игрока. Включает имя, символ (X или O), а также информацию о том, является ли игрок ботом.
- **`Tictactoe`:** класс, управляющий логикой игры. Он содержит методы для вывода поля, проверки победы, движения игроков и бота.

### Методы игрового класса:
- **`move(size_t row, size_t col, char sym)`** — делает ход на поле.
- **`play_vs()`** — режим игры для двух игроков.
- **`win(char sym)`** — проверяет, есть ли победитель.
- **`draw()`** — проверяет, закончилась ли игра ничьей.
- **`play_ai_easy()`** и **`play_ai_hard()`** — два уровня сложности для игры против бота.
- **`bot_move()`** и **`bot_cmove()`** — ходы бота в разных режимах.

### Вспомогательные функции:
- **`isvalid(const std::string& answer, int a)`** — проверяет, является ли пользовательский ввод корректным в зависимости от контекста.
- **`nowValid(std::string& expression)`** — форматирует пользовательский ввод: убирает пробелы и приводит символы к нижнему регистру.
- **`validateAnswer(const std::string& answer, int condition)`** — проверяет корректность ответа пользователя и выбрасывает исключение, если ввод недопустим.
- **`hello()`** — выводит приветствие и спрашивает у пользователя, хочет ли он сыграть.
- **`againHello()`** — выводит сообщение о повторной игре, если пользователь уже сыграл один раз.
- **`format()`** — предлагает пользователю выбрать размер игрового поля: 3x3, 4x4 или 5x5.
- **`mode()`** — запрашивает у пользователя выбор режима игры: "Игрок против игрока" или "Игрок против ИИ".
- **`level()`** — определяет сложность игры при игре с ботом: "easy" или "medium".
- **`question()`** — спрашивает у пользователя, хочет ли он сыграть еще раз или завершить игру.
- **`bye()`** — выводит прощальное сообщение.

---


## **Баги**

Наши боты, хоть и умные, но тоже могут ошибаться. Но зато багов меньше чем в Сталкере.

---


## **Авторы**
Хасанджанова Арина (arinahasandjanova) и я.

---


## **Заключение**

Tic-Tac-Toe — это не просто игра. Это маленькая ода дружбе, соперничеству и тому факту, что даже простая игра может приносить радость. Так что, наслаждайтесь процессом, смейтесь над ботом (но только если он проиграет), и помните, что жизнь — это не всегда крестики и нолики, но побеждать в них всегда приятно.

Удачи и приятной игры! 😊




