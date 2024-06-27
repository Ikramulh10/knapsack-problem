#include <stdio.h>
int main() {
    float weight[7] = {2, 3, 5, 7, 1, 4, 1};
    float profit[7] = {10, 5, 15, 7, 6, 18, 3};
    float ratio[7], Totalvalue = 0.0, temp;
    float capacity = 15.0;
    int n = 7, i, j;

    // Calculate the ratio (profit/weight) for each item
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort the items based on the ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Calculate the maximum value that can be carried
    printf("Knapsack problems using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            Totalvalue += profit[i];
        } else {
            Totalvalue += (profit[i] / weight[i]) * capacity;
            break;
        }
    }

    printf("The maximum value is: %.2f\n", Totalvalue);

    return 0;
}
