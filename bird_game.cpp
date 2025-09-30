//the game is without any graphical interface.
#include <iostream>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include <ctime>

using namespace std;

// Game constants
#define HEIGHT 10
#define WIDTH 20
#define GAP 4 // Gap between pipes

// Game variables
int birdY;      // Bird's Y position
int pipeX;      // Pipe's X position
int gapY;       // Gap's Y position
int score;      // Player's score
int maxScore = 0; // Maximum score across games
bool gameOver;  // Game state

// Function to draw the game screen
void draw()
{
    system("cls"); // Clear console screen
    
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == birdY && j == 2)
                cout << "O"; // Draw the bird
            else if (j == pipeX && (i < gapY || i > gapY + GAP))
                cout << "|"; // Draw the pipes
            else
                cout << " ";
        }
        cout << endl;
    }
    
    // Display score and instructions
    cout << "Score: " << score << "  Max Score: " << maxScore << endl;
    cout << "Press SPACE to Jump!" << endl;
}

// Function to update the game logic
void update()
{
    if (_kbhit()) // Check if a key is pressed
    {
        char ch = _getch();
        if (ch == ' ')
            birdY -= 2; // Bird jumps when space is pressed
    }
    
    birdY++; // Gravity effect: bird falls
    pipeX--; // Move pipes to the left
    
    // Reset pipe when it moves off-screen
    if (pipeX < 0)
    {
        pipeX = WIDTH - 1; // Reset pipe position
        gapY = rand() % (HEIGHT - GAP); // Randomize gap position
        score++; // Increase score when pipe is cleared
    }
    
    // Collision detection (Game Over conditions)
    if (birdY >= HEIGHT || birdY < 0 || (pipeX == 2 && (birdY < gapY || birdY > gapY + GAP)))
    {
        gameOver = true;
    }
}

// Function to run the game loop
void playGame()
{
    // Initialize game variables
    birdY = HEIGHT / 2;
    pipeX = WIDTH - 1;
    gapY = rand() % (HEIGHT - GAP);
    score = 0;
    gameOver = false;
    
    while (!gameOver)
    {
        draw(); // Render game state
        update(); // Update game logic
        Sleep(100); // Control game speed
    }
    
    // Update max score if the current score is higher
    if (score > maxScore)
        maxScore = score;
    
    // Display Game Over message
    cout << "Game Over! Your Score: " << score << "  Max Score: " << maxScore << endl;
    cout << "Press any key to exit..." << endl;
    _getch();
}

int main()
{
    srand((unsigned int)time(0)); // Seed random number generator
    while (true) // Allow multiple game runs
    {
        playGame(); // Start the game
        cout << "Press 'r' to restart or any other key to exit..." << endl;
        if (_getch() != 'r')
            break;
    }
    return 0;
}  