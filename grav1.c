#include "raylib.h"
#include <stdio.h>

#define W_HEIGHT 900
#define W_WIDTH 800


typedef struct Circle {
    float x;
    float y;
    float radius;
    Color color;
} Circle;


int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    Circle circ = {100, 100, 3, BLACK};
    float currentTime = 0;
    while (!WindowShouldClose()) {
        currentTime += GetFrameTime();
        circ.y = 0.5 * 9.8 * currentTime * currentTime;
        
        printf("%f ", currentTime);
        printf("%f\n", circ.y);

        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)circ.x, (int)circ.y, circ.radius, circ.color);
        EndDrawing();
    }
    CloseWindow();
}




        // printf("%f ", currentTime);
        // printf("%d ", circ.y);

//  d = (1/2) * g * t²; where "d" is the distance fallen, "g" is the acceleration due to gravity (approximately 9.8 m/s² on Earth), and "t" is the time elapsed.