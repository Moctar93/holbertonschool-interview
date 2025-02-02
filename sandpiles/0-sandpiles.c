#include "sandpiles.h"
#include <stdio.h>

/**
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid to check
 * Return: true if stable, false otherwise
 */
bool is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid to print
 */
void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid (will contain the result)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Step 1: Sum the two grids
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Step 2: Topple until stable
    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);

        int temp[3][3] = {{0}};

        // Distribute grains for unstable cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    temp[i][j] -= 4;
                    if (i > 0) temp[i - 1][j]++;
                    if (i < 2) temp[i + 1][j]++;
                    if (j > 0) temp[i][j - 1]++;
                    if (j < 2) temp[i][j + 1]++;
                }
            }
        }

        // Apply the toppling changes
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid1[i][j] += temp[i][j];
            }
        }
    }
}
