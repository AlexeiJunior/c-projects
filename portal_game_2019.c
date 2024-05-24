#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define height 10
#define width 10

void initVector(char vet[height][width]) {
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
           vet[i][j] = ' ';
        }
    }
}

void printVector(char vet[height][width]) {
    system("clear");
    
    int i, j;
    for(i = 0; i < height; i++){
        printf("|");
        for(j = 0; j < width; j++){
           printf("%c", vet[i][j]);
        }
        printf("|\n");
    }
}

void initPlayer(char vet[height][width], int playerX, int playerY) {
    vet[playerX][playerY] = '*';
}

void setPortal(char vet[height][width], int playerX, int playerY) {
    int portalX, portalY;
    
    do {
        portalX = (rand() % height);
        portalY = (rand() % width);
    } while (portalX == playerX && portalY == playerY);
    
    vet[portalX][portalY] = 'O';
}

bool canWalk(char button, int playerX, int playerY) {
    if (button != 'w' && button != 's' && button != 'd' && button != 'a' && button != 'p') return false;
    
    if (button == 'w' && playerX-1 < 0) return false;
    if (button == 's' && playerX+1 > height-1) return false;
    if (button == 'a' && playerY-1 < 0) return false;
    if (button == 'd' && playerY+1 > width-1) return false;
    
    return true;
}

bool walk(char button, char vet[height][width], int *playerX, int *playerY) {
    vet[*playerX][*playerY] = ' ';

    if (button == 'w') (*playerX)--;
    if (button == 's') (*playerX)++;
    if (button == 'a') (*playerY)--;
    if (button == 'd') (*playerY)++;
    
    bool win = vet[*playerX][*playerY] == 'O';
    
    if (win) vet[*playerX][*playerY] = '@';
    else vet[*playerX][*playerY] = '*';
    
    return win;
}

void main()
{
    srand(time(NULL));
    
    char vet[height][width];
    int playerX = 0;
    int playerY = 0;

    initVector(vet);
    initPlayer(vet, playerX, playerY);
    setPortal(vet, playerX, playerY);
    printVector(vet);
    
    int button;
    bool win;

    // WASD and P to QUIT
    while ((button = getchar()) != 'p') {
        if (!canWalk(button, playerX, playerY)) continue;
        
        win = walk(button, vet, &playerX, &playerY);
        
        printVector(vet);
        
        if (win){
            setPortal(vet, playerX, playerY);
            printf("You win: @:");
        }
    }
}
