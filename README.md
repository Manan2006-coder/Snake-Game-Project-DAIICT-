# Snake-Game-Project-DAIICT-
Snake game(course: IT206, DAIICT)

# Snake Game

## Table of Contents
1. Introduction
2. [Installation](#installation)
3. [Usage](#usage)
4. [Data Structure Analysis](#data-structure-analysis)
5. [Conclusion](#conclusion)

<h2>1. Introduction</h2>
<br>
Our project is on the snake game where the player controls a snake that grows in size as it consumes fruit. The game ends if the snake collides with itself or the boundaries of the play area.
<br>

## 2. Installation

To run the Snake game, follow the instructions below:

### Prerequisites:

- C++ compiler 
- Windows Operating System 

### Steps:

1. download the source code to your local machine.
2. Open a terminal in the directory where the source code is located.
3. Compile the code:
   - For g++, run: `g++ -o snake_game snake_game.cpp`
4. Run the compiled executable:
   - On Windows: `snake_game.exe`
   
## 3. Usage

After successfully installing and running the game, you can interact with it using the following controls:

- W: Move up
- A: Move left
- S: Move down
- D: Move right
- X: Quit the game
- R: Restart the game after game over

### Game Features:

- The snake moves in a grid and collects food represented by "F."
- The snake grows in size with each food it consumes.
- The game ends when the snake hits the boundaries or collides with itself.
- The score is displayed on the screen, and the high score is saved in `highscore.txt`.
   

## 4. Data Structure Analysis
   
The program uses the following data structures and object-oriented concepts to represent the game:
    
### Data Structures Used:

#### Arrays:
-We have used array to represent snake body and 2D array in form of nested form to represent grid.
- The `tailX[]` and `tailY[]` arrays store the positions of the snake's tail. These arrays are used in conjunction with the `nTail` variable to keep track of the snake’s growing body.

#### Enum:
- The `Direction` enum helps manage the snake's direction, making the code more readable and preventing errors with direction management.

#### Class-based structure:
- The game is divided into three classes: `Food`, `Snake`, and `Grid`. This class-based structure provides modularity, separation of concerns, and encapsulation of related data and behaviors.

### Object Relationships:

- The `Grid` object contains instances of both the `Food` and `Snake` objects. The `Grid` class manages the game’s state, including drawing the screen, handling user input, and updating the game logic.
- The `Snake` object is responsible for the movement of the snake and collision detection.
- The `Food` object randomly places food on the grid and generates new food when eaten by the snake.

## 5. Conclusion
   
This Snake game is an enjoyable and simple implementation that uses basic C++ programming concepts such as arrays, classes, and user input handling. It provides an interactive experience with a growing snake that tries to consume food while avoiding collisions with itself and the walls.


