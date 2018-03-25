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
#include <time.h>
#include <string.h>

#include "libfifteen.h"

// boards
int board[DIM_MAX][DIM_MAX];
int solved_board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// tiles
int t;

// blank space
int b[2];

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(int square[DIM_MAX][DIM_MAX]);
bool move(int tile);
bool won(void);

void setsolvedstate(void);
int manhattan_distance(int x1, int y1, int x2, int y2);
int heuristic(int square[DIM_MAX][DIM_MAX]);
void swap(int r1, int c1, int r2, int c2);
bool contains(int* array, int size, int value);
bool torow(int* row);
bool issolvable(int* row);
void shuffle(int* row);
void tileposition(int square[DIM_MAX][DIM_MAX], int tile, int* x, int* y);
bool islegal(int tile, int x, int y);
void lowest_f_node(node* list, node* lowest_f);
void solve_game(node* winning_sequence);
void godmode(void);

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
        draw(board);

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
        string input = GetString();
        int tile = atoi(input);

        if(tile == 0 && strlen(input) != 3)
        {
            printf("\nInvalid input.\n");
            usleep(500000);
            continue;
        }

        if (strcmp("GOD", input) == 0)
        {
            godmode();
            break;
        } 
        
        // quit if user inputs 0 (for testing)
        // if (tile == 0)
        // {
        //     break;
        // }

        // checks for tile number
        if (tile < 1 || tile > t)
        {
            printf("\nUnknown tile number.\n");
            usleep(500000);
            continue;
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

/*
* Set solved_board with the game solved state.
*/
void setsolvedstate(void)
{
    int k = 0;
    for(int i = 0; i < d; ++i)
    {
        for(int j = 0; j < d; ++j)
        {
            // check for last/blank tile
            if(k == t)
            {
                solved_board[i][j] = 0;
                break;
            }
            // assign values for the solved state
            solved_board[i][j] = k + 1;
            k++;
        }
    }
}

/*
* The Manhattan/Taxicab distance between two tiles according to their coordinates.
*/
int manhattan_distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

/*
* Implementation of Linear Conflict + Manhattan Distance/Taxicab geometry algorithm.
*/
int heuristic(int square[DIM_MAX][DIM_MAX])
{
    int x, y, sum;
    x = y = -1;
    sum = 0;
    // iterate through all tiles of the current state of the board
    for(int i = 0; i < d; ++i)
    {
        for(int j = 0; j < d; ++j)
        {
            int tile = square[i][j];
            // get correct position of the tile
            tileposition(solved_board, tile, &x, &y);
            // if tile not in correct position, return taxicab distance
            if(x != i || y != j)
                sum += manhattan_distance(i, j, x, y);
        }
    }

    return sum;
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

/*
* Checks if an array (of integer) contains an integer.
*/
bool contains(int* array, int size, int value)
{
    for(int i = 0; i < size; i++)
        if(array[i] == value)
            return true;
    
    return false;
}

/*
* Converts the board to a row.
*/
bool torow(int* row)
{
    bool flag = true;

    // get all board values in one array
    int bench[t];
    int k = 0;
    for(int i = 0; i < d && flag; ++i)
    {
        for(int j = 0; j < d && k < t && flag; ++j)
        {
            if(!board[i][j] == 0)
            {
                bench[k] = board[i][j];
                ++k;
            }
            else
            {
                flag = false;
            } 
        }
    }
    row = bench;
    return flag;
}

/*
* Checks if the pseudorandom configuration of the board is solvable.
*/
bool issolvable(int* row)
{
    int number_of_inversions = 0;
    
    // compute the number of inversions
    for(int i = 0, count = t - 2; i < count; i++)
    {
        if(row[i] > row[i+1])
            number_of_inversions += 1;
    }

    // check solvability
    if(number_of_inversions % 2 == 0)
        return true;
    return false;
}

/*
* Shuffles elements in the array.
*/
void shuffle(int* array)
{
    // seed drand48 with current time
    srand(time(NULL));
    // Fisher-Yates shuffle algorithm (Richard Durstenfeld version)
    for(int i = t-1; i > 0; i--)
    {
        int j = (int)(rand() % (i+1));
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init()
{
    // calculate the number of tiles (t) on the board
    t = (d * d) - 1;

    // put all board values in an array (desc)
    int bench[t];
    for(int i = 0; i < t; i++)
    {
        bench[i] = t - i;
    }

    // fill the board with bench values
    int i, j;

    do
    {
        // shuffle the array
        shuffle(bench);
        int k = 0;
        for(i = 0; i < d; ++i)
        {
            for(j = 0; j < d; ++j)
            {
                // check for last/blank tile
                if(k == t)
                {
                    board[i][j] = 0;
                    break;
                }
                // assign shuffled bench values to board
                board[i][j] = bench[k];
                k++;
            }
        }
        j += 1;

        // swap 1 and 2 if t is odd
        --i;
        --j;
        if(t % 2 != 0)
            swap(i, j-1, i, j-2);
    }
    while(!issolvable(bench));

    // set blank space position
    b[0] = i;
    b[1] = j;
}

/**
 * Prints the board in its current state.
 */
void draw(int square[DIM_MAX][DIM_MAX])
{
    int i, j;
    for(i = 0; i < d; ++i)
    {
        printf("\n");
        for(j = 0; j < d; ++j)
        {
            if(square[i][j] == 0)
                printf("  _ ");
            else
                printf(" %2d ", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Returns tie position on board.
 */
void tileposition(int square[DIM_MAX][DIM_MAX], int tile, int* x, int* y)
{
    for(int i = 0; i < d; ++i)
    {
        for(int j = 0; j < d; ++j)
        {
            if(square[i][j] == tile)
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
    return (manhattan_distance(x, y, b[0], b[1]) == 1);
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
    tileposition(board, tile, &x, &y);
    
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
    int bench[t];

    // get all board tiles in a row
    if(!torow(bench))
        won = false;

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

/*
* Returns the node with the lowest f from the list of nodes.
*/
void lowest_f_node(node* list, node* lowest_f)
{
    // point to the first element in the list
    node* current = list;
    // consider the first element as the lowest f node
    lowest_f = current;
    // point to the second element in the list
    current = current->child;
    // traverse the list
    while(current != NULL)
    {
        // check for lower f nodes
        if(lowest_f->f > current->f)
            lowest_f = current;
        current = current->child;
    }
}

/*
* Solves the game automatically.
*/
void solve_game(node* winning_sequence)
{
    node* current = winning_sequence;
    while(current != NULL)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(current->board);

        current = current->child;
    }
    printf("ftw!\n");
}

/*
* Generates neighboring nodes, different board states according to legal moves.
*/
void generate_neighbors(node* principal, node* neighbors)
{
    node* current = neighbors;

}

/*
* Implements god mode: The computer solves the puzzle automatically.
*/
void godmode(void)
{
    // the state of the board before god mode
    node* start = malloc(sizeof(node));
    board_copy(start->board, board, d);
    start->g = 0;
    start->h = heuristic(start->board);
    start->f = start->g + start->h;

    // the final, solved/win state
    node* goal = malloc(sizeof(node));
    board_copy(goal->board, solved_board, d);

    // explored nodes with neighbours discovered
    node* evaluated_nodes = NULL;

    // all selected but unexplored nodes
    node* nodes_to_evaluate = NULL;
    node_add(nodes_to_evaluate, start);

    // the optimal path to goal
    node* optimal_path = NULL;

    // whilst there are nodes to evaluate
    while(node_count(nodes_to_evaluate) > 0)
    {
        node* current = NULL;
        // get current, the node with lowest f among the nodes to evaluate
        lowest_f_node(nodes_to_evaluate, current);
        // check for the goal node
        if(board_compare(current->board, solved_board, d))
            solve_game(optimal_path);
        node_remove(nodes_to_evaluate, current, d);
        node_add(evaluated_nodes, current);
    }
}