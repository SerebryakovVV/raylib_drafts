// https://chatgpt.com/c/670586ff-9914-8008-a70b-d8434e15e567

#include "raylib.h"
#include <stdio.h>

#define W_HEIGHT 900
#define W_WIDTH 800


typedef struct Line {
    float x1;
    float y1;
    float x2;
    float y2;
} Line;


int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    Line a = {0, 0, 300, 100};
    Line b = {0, 0, 50, 300};

    Line c;
    c.x1 = 0;
    c.y1 = 0;


    c.x2 = (a.x2-a.x1) + (b.x2 - b.x1) + c.x1;
    c.y2 = (a.y2-a.y1) + (b.y2 - b.y1) + c.y1;
    // c.y2 = 700;


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLine(a.x1, a.y1, a.x2, a.y2, BLACK);
        DrawLine(b.x1, b.y1, b.x2, b.y2, BLACK);
        DrawLine(c.x1, c.y1, c.x2, c.y2, BLACK);
        EndDrawing();
    }
    CloseWindow();
}



