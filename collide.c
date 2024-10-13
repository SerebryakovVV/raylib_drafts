#include "raylib.h"
#include <stdio.h>

#define DELTA 10
#define W_HEIGHT 600
#define W_WIDTH 800


void moveRect(Rectangle* rec, int dir) {
    switch (dir) {
            case KEY_UP:
                if ((rec->y - DELTA) > 0) {
                    rec->y -= DELTA;
                } else {
                    rec->y = 0;
                }
                break;
            case KEY_RIGHT:
                if ((rec->x + rec->width + DELTA) < W_WIDTH) {
                    rec->x += DELTA;
                } else {
                    rec->x = W_WIDTH - rec->width;
                }
                break;
            case KEY_DOWN:
                if ((rec->y + rec->height + DELTA) < W_HEIGHT) {
                    rec->y += DELTA;
                } else {
                    rec->y = W_HEIGHT - rec->height;
                }
                break;
            case KEY_LEFT:
                if ((rec->x - DELTA) > 0) {
                    rec->x -= DELTA;
                } else {
                    rec->x = 0;
                }
                break;
    }
}


int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    Rectangle biba = {100, 100, 100, 100};
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_UP)) moveRect(&biba, KEY_UP);
        if (IsKeyDown(KEY_RIGHT)) moveRect(&biba, KEY_RIGHT);
        if (IsKeyDown(KEY_DOWN)) moveRect(&biba, KEY_DOWN);
        if (IsKeyDown(KEY_LEFT)) moveRect(&biba, KEY_LEFT);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(biba, BLACK);
        EndDrawing();
    }
    CloseWindow();
}