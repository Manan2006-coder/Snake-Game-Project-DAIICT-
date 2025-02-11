# Snake-Game-Project-DAIICT-
Snake game(course: IT206, DAIICT)

# Snake Game

## Table of Contents
1. Introduction
2. [Installation](#installation)
3. [Usage](#usage)
4. [Contributing](#contributing)
5. [License](#license)
6. [Data Structure Analysis](#data-structure-analysis)
7. [Conclusion](#conclusion)

##1.Introduction
<br>
Our project is on the snake game where the player controls a snake that grows in size as it consumes fruit. The game ends if the snake collides with itself or the boundaries of the play area.
<br>

## 2. Installation

To run the Snake game, follow the instructions below:

### Prerequisites:

- C++ compiler (e.g., g++, MSVC, etc.)
- Windows Operating System (for system("cls") and Sleep() functions, as well as _kbhit() and _getch())

### Steps:

1. Clone or download the source code to your local machine.
2. Open a terminal or command prompt in the directory where the source code is located.
3. Compile the code:
   - For g++, run: `g++ -o snake_game snake_game.cpp`
4. Run the compiled executable:
   - On Windows: `snake_game.exe`
   
## 3. Usage

After successfully installing and running the game, you can interact with it using the following controls:

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **X**: Quit the game
- **R**: Restart the game after game over

### Game Features:

- The snake moves in a grid and collects food represented by "F."
- The snake grows in size with each food it consumes.
- The game ends when the snake hits the boundaries or collides with itself.
- The score is displayed on the screen, and the high score is saved in `highscore.txt`.
   
## 4. Contributing

We welcome contributions to the Snake Game. If you want to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Push to the branch and create a pull request.
5. Please make sure to test the game thoroughly before submitting any pull requests.

## 5. License
   
This project is licensed under the MIT License - see the LICENSE file for details.

## 6. Data Structure Analysis
   
The program uses the following data structures and object-oriented concepts to represent the game:

### Classes:

#### Food Class:
- **Attributes**:
  - `x`, `y`: Coordinates of the food on the grid.
- **Methods**:
  - `generate()`: Randomly generates the position of the food within the grid dimensions.
    
#### Snake Class:
- **Attributes**:
  - `x`, `y`: Coordinates of the snake's head.
  - `tailX[]`, `tailY[]`: Arrays that store the coordinates of each segment of the snake's tail.
  - `nTail`: The number of segments in the snake's tail.
  - `dir`: Enum for controlling the direction of the snake (STOP, LEFT, RIGHT, UP, DOWN).
- **Methods**:
  - `move()`: Updates the position of the snake by shifting the positions of the tail and moving the head according to the current direction.
               
#### Grid Class:
- **Attributes**:
  - `gameOver`: Boolean flag to check if the game is over.
  - `score`, `highScore`: Stores the current and highest score.
  - `snake`: An instance of the Snake class.
  - `food`: An instance of the Food class.
- **Methods**:
  - `loadHighScore()`: Loads the high score from a file.
  - `saveHighScore()`: Saves the current score as the new high score if applicable.
  - `draw()`: Displays the current state of the game grid.
  - `input()`: Handles user input for controlling the snake.
  - `logic()`: Contains the logic for moving the snake and detecting collisions.
    
### Data Structures Used:

#### Arrays:
- The `tailX[]` and `tailY[]` arrays store the positions of the snake's tail. These arrays are used in conjunction with the `nTail` variable to keep track of the snake’s growing body.

#### Enum:
- The `Direction` enum helps manage the snake's direction, making the code more readable and preventing errors with direction management.

#### Class-based structure:
- The game is divided into three classes: `Food`, `Snake`, and `Grid`. This class-based structure provides modularity, separation of concerns, and encapsulation of related data and behaviors.

### Object Relationships:

- The `Grid` object contains instances of both the `Food` and `Snake` objects. The `Grid` class manages the game’s state, including drawing the screen, handling user input, and updating the game logic.
- The `Snake` object is responsible for the movement of the snake and collision detection.
- The `Food` object randomly places food on the grid and generates new food when eaten by the snake.

## 7. Conclusion
   
This Snake game is an enjoyable and simple implementation that uses basic C++ programming concepts such as arrays, classes, and user input handling. It provides an interactive experience with a growing snake that tries to consume food while avoiding collisions with itself and the walls.

Feel free to contribute and enhance the game with new features, bug fixes, or improvements!
