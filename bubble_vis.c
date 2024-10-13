#include "raylib.h"
#include <stdlib.h>

#define W_WIDTH 800
#define W_HEIGHT 600


void drawSort(int* arr, size_t len, int graphX, int graphY, int recWidth, int recGap) {
    int x, y;
    for (int i = 0; i < len; i++) {
        x = graphX + (recGap + recWidth) * i;
        y = graphY - arr[i];
        DrawRectangle(x, y, recWidth, arr[i], RED);
    }
}














void bubbleSort(size_t len, int *arr) {
    int maxEl = len-1;
    while (maxEl>0) {
        int largest = 0;
        int container;
        while (largest < maxEl) {
            if (arr[largest]>arr[largest+1]) {
                container = arr[largest];
                arr[largest] = arr[largest+1];
                arr[largest+1] = container;
            }
            largest++;
        }
        maxEl--;
    }
}

int main() {
    int arr[] = {90, 130, 50, 70, 20, 40, 120, 100, 10, 80, 30, 60};
    size_t len = sizeof(arr)/sizeof(arr[0]);
    float clock = 0;
    int maxEl = len -1;
    int largest = 0;
    int container;
    InitWindow(W_WIDTH, W_HEIGHT, "Hello");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        clock +=  GetFrameTime();
        if (clock > 0.1 && maxEl >= 0) {
            clock = 0;

                if (arr[largest]>arr[largest+1]) {
                container = arr[largest];
                arr[largest] = arr[largest+1];
                arr[largest+1] = container;
            }

            largest++;

            if (largest > maxEl-1) {
                largest = 0;
                maxEl--;
            }
        }

        drawSort(arr, len, 100, 500, 20, 5);

        
        EndDrawing();
    }
    CloseWindow();
    
    
	return 0;
}