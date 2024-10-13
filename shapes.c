#include "raylib.h"
#include <stdio.h>

#define DELTA 10
#define W_HEIGHT 600
#define W_WIDTH 800


void moveRect(Rectangle* recMov, Rectangle* recImmov, int dir) {
    switch (dir) {
            case KEY_UP:
                if ((recMov->y - DELTA < recImmov->y + recImmov->height) && (recMov->y - DELTA > recImmov->y)  &&
                   !((recMov->x > recImmov->x + recImmov->width) || (recMov->x + recMov->width < recImmov->x))) 
                {
                    recMov->y = recImmov->y + recImmov->height + 1;
                } else {
                    recMov->y -= DELTA;
                }
                break;
            case KEY_RIGHT:
                if((recMov->x + recMov->width + DELTA > recImmov->x) &&  (recMov->x + recMov->width + DELTA < recImmov->x + recImmov->width)  &&
                    !((recMov->y + recMov->height < recImmov->y)||(recMov->y > recImmov->y + recImmov->height)))   
                { 
                    recMov->x = recImmov->x - recMov->width - 1;
                }
                else {
                    recMov->x += DELTA;
                }
                break;
            case KEY_DOWN:
                if ((recMov->y + recMov->height + DELTA > recImmov->y)  &&  (recMov->y + recMov->height + DELTA < recImmov->y + recImmov->height)  &&
                    !((recMov->x > recImmov->x + recImmov->width) || (recMov->x + recMov->width < recImmov->x)))
                { 
                    recMov->y = recImmov->y - recMov->height - 1;
                } else {
                    recMov->y += DELTA;
                }
                break;
            case KEY_LEFT:
                if ((recMov->x - DELTA < recImmov->x + recImmov->width) &&  (recMov->x - DELTA > recImmov->x)  &&
                    !((recMov->y + recMov->height < recImmov->y)||(recMov->y > recImmov->y + recImmov->height))) 
                { 
                    recMov->x = recImmov->x + recImmov->width + 1;
                } else {
                    recMov->x -= DELTA;
                }
                break;
    }
}


int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    Rectangle biba = {50, 50, 100, 100};
    Rectangle boba = {300, 150, 150, 300};
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_UP)) moveRect(&biba, &boba, KEY_UP);
        if (IsKeyDown(KEY_RIGHT)) moveRect(&biba, &boba, KEY_RIGHT);
        if (IsKeyDown(KEY_DOWN)) moveRect(&biba, &boba, KEY_DOWN);
        if (IsKeyDown(KEY_LEFT)) moveRect(&biba, &boba, KEY_LEFT);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(biba, BLUE);
        DrawRectangleRec(boba, RED);
        EndDrawing();
    }
    CloseWindow();
}