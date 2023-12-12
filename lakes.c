#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>  // Add this header for strcpy

// Function to perform DFS to mark and count the connected water cells
static void exploreLake(char **map, int x, int y, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '#' || map[y][x] == 'x') {
        return;  // Ignore ground cells or already visited cells
    }
    map[y][x] = 'x';  // Mark the current water cell as visited

    // Recursively explore horizontally and vertically adjacent water cells
    exploreLake(map, x + 1, y, width, height);
    exploreLake(map, x - 1, y, width, height);
    exploreLake(map, x, y + 1, width, height);
    exploreLake(map, x, y - 1, width, height);
}

// Main function to count the number of lakes
int lakes(char **map, int width, int height) {
    int lakeCount = 0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (map[y][x] == '.') {
                // Found an unvisited water cell, start exploring the lake
                exploreLake(map, x, y, width, height);
                ++lakeCount;
            }
        }
    }

    return lakeCount;
}
