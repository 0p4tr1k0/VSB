#include <stdio.h>
#include <stdlib.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

// Struktura pro reprezentaci želvičky
typedef struct {
    int row;
    int col;
    int direction;
} Turtle;

// Funkce pro rotaci želvičky doleva
void rotateLeft(Turtle *turtle) {
    turtle->direction = (turtle->direction + 3) % 4;
}

// Funkce pro rotaci želvičky doprava
void rotateRight(Turtle *turtle) {
    turtle->direction = (turtle->direction + 1) % 4;
}

// Funkce pro posun želvičky
void moveTurtle(Turtle *turtle, int rows, int cols) {
    if (turtle->direction == RIGHT) {
        turtle->col = (turtle->col + 1) % cols;
    } else if (turtle->direction == LEFT) {
        turtle->col = (turtle->col - 1 + cols) % cols;
    } else if (turtle->direction == UP) {
        turtle->row = (turtle->row - 1 + rows) % rows;
    } else if (turtle->direction == DOWN) {
        turtle->row = (turtle->row + 1) % rows;
    }
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(cols * sizeof(char));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = '.';
        }
    }

    Turtle turtle;
    turtle.row = 0;
    turtle.col = 0;
    turtle.direction = RIGHT;

    int num_turtles = 1;

    char action;
    while (1) {
        scanf(" %c", &action);
        if (action == 'x') {
            break;
        } else if (action == 'r') {
            rotateRight(&turtle);
        } else if (action == 'l') {
            rotateLeft(&turtle);
        } else if (action == 'm') {
            moveTurtle(&turtle, rows, cols);
            grid[turtle.row][turtle.col] = 'o';
        } else if (action == 'o') {
            if (grid[turtle.row][turtle.col] == 'o') {
                grid[turtle.row][turtle.col] = '.';
            } else {
                grid[turtle.row][turtle.col] = 'o';
            }
        } else if (action == 'f' && num_turtles < 3) {
            num_turtles++;
            // Vytvořte novou želvičku na pozici (0, 0) směřující doprava
            Turtle new_turtle;
            new_turtle.row = 0;
            new_turtle.col = 0;
            new_turtle.direction = RIGHT;

            // Nastavte novou želvičku
            turtle = new_turtle;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // Uvolnění paměti pro mřížku
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}