/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// tiles
int t;

// blank space
int b[2];

// prototypes
void clear(void);
void greet(void);
void swap(int r1, int c1, int r2, int c2);
void init(void);
void draw(void);
void tilepos(int tile, int* x, int* y);
bool islegal(int tile, int x, int y);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
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

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // checks for tile number
        if (tile < 1 || tile > t)
        {
            printf("\nUnknown tile number.\n");
            usleep(500000);
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}

/**
 * Swaps two values with an array.
 */
void swap(int r1, int c1, int r2, int c2)
{
    int temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init()
{
    // calculate the number of tiles (t) on the board
    t = (d * d) - 1;

    // fill the board in descending order
    int i, j;
    int n = t;
    for(i = 0; i < d; ++i)
    {
        for(j = 0; j < d; ++j)
        {
            board[i][j] = n;
            --n;
        }
    }

    // swap 1 and 2 if t is odd
    --i;
    --j;
    if(t % 2 != 0)
        swap(i, j-1, i, j-2);

    // set blank space position
    b[0] = i;
    b[1] = j;
}

/**
 * Prints the board in its current state.
 */
void draw()
{
    int i, j;
    for(i = 0; i < d; ++i)
    {
        printf("\n");
        for(j = 0; j < d; ++j)
        {
            if(board[i][j] == 0)
                printf("  _ ");
            else
                printf(" %2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Returns tie position on board.
 */
void tilepos(int tile, int* x, int* y)
{
    for(int i = 0; i < d; ++i)
    {
        for(int j = 0; j < d; ++j)
        {
            if(board[i][j] == tile)
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

/**
 * Checks if the move is legal.
 */
bool islegal(int tile, int x, int y)
{
    return (abs(x - b[0]) + abs(y - b[1])) == 1;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // get tile position
    int x, y;
    x = y = d;
    tilepos(tile, &x, &y);
    
    // check for movement legality
    bool legal = islegal(tile, x, y);

    // make move on legality
    if(legal)
    {
        swap(x, y, b[0], b[1]);
        b[0] = x;
        b[1] = y;
    }

    return legal;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    bool won = true;

    // get all board values in one array
    int bench[t];
    int k = 0;
    for(int i = 0; i < d && won; ++i)
    {
        for(int j = 0; j < d && k < t && won; ++j)
        {
            if(!board[i][j] == 0)
            {
                bench[k] = board[i][j];
                ++k;
            }
            else
            {
                won = false;
            } 
        }
    }

    // check for a lost
    if(won)
    {
        for(int i = 0; i < t-1 && won; ++i)
        {
            if(bench[i] > bench[i+1])
                won = false;
        }
    }

    return won;
}