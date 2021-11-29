// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
       clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    //for each row
    int k = d*d-1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (k==2) {
                if (d % 2 ==0) {
                    board[i][j] = 1;
                    board[i][j+1] = 2;
                    board[i][j+2] = 0;
                    j=d;
                    }
                else {
                    board[i][j] = k--;

                    }
                }
                else {
                    board[i][j] = k--;

                }

            }
        }
}

// Prints the board in its current state (when you print values in the correct locations - print the underscore in palce of the 0)
void draw(void) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] == 0) {
                printf(" _ ");
            }
            else {
                printf("%2i ",board[i][j]);
            }

        }
        printf("\n");
    }
}

// If tile borders the empty space, moves tile and returns true, else returns false
//move will be executed down here AFTER it passed possibility contraints. Don't need to see if the move is possible at this point.
bool move(int tile)
{
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] == tile) {
                if ( j != 0 ) {
                    if (board[i][j-1] == 0) {
                        board[i][j] = 0;
                        board[i][j-1] = tile;
                        return true;
                    }
                }
                if (j != d-1) {
                    if (board[i][j+1] == 0) {
                            board[i][j+1] = board[i][j];
                            board[i][j] = 0;
                            return true;
                        }

                }

                if (i != 0) {
                    if (board[i-1][j] == 0) {
                        board[i-1][j] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }
                if (i!=d-1) {
                    if (board[i+1][j] == 0) {
                        board[i+1][j] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false *for loop to iterate through the grid and if statement to see if the next value += the previous value + 1.
bool won(void)
{
    int last_visit = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] > last_visit) {
                last_visit = board[i][j];
            }
            else {
                if (i==d-1 && j==d-1 && board[i][j]==0) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
return false;
}