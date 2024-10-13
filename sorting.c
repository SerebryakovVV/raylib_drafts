#include "raylib.h"

#define W_WIDTH 800
#define W_HEIGHT 600

int main() {
    int arr[] = {30, 50, 60, 10, 70, 20, 40, 90, 80};
    int recWidth = 20;
    int recGap = 5;
    int graphX = 100;
    int graphY = 500;
    int x, y;
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        for (int i = 0; i < 9; i++) {
            x = graphX + (recGap + recWidth) * i;
            y = graphY - arr[i];
            DrawRectangle(x, y, recWidth, arr[i], RED);
        }

        DrawRectangle(10, 10, 100, 200, RED);
        EndDrawing();
    }
    CloseWindow();
}