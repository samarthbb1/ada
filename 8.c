#include <stdio.h>
int max_profit = 0;
int n, capacity;
int weights[100], values[100];
// Bounding function to estimate maximum possible profit in a subtree
float calculate_bound(int index, int current_weight, int current_profit) {
 if (current_weight >= capacity) return 0;
 float bound = (float)current_profit;
 int total_weight = current_weight;
 int i = index;
 // Greedily fill the remaining capacity to find an upper bound
 while (i < n && total_weight + weights[i] <= capacity) {
 total_weight +=weights[i];
 bound += values[i];
 i++;
 }
 // If there is still capacity, add the fractional part of the next item
 if (i < n) {
 bound += (float)(capacity - total_weight) * values[i] / weights[i];
 }
 return bound;
}
void solve_knapsack(int index, int current_weight, int current_profit) {
 // Base case: all items considered
 if (index == n) {
 if (current_profit > max_profit) {
 max_profit = current_profit;
 }
 return;
 }
 // Branch 1: Include current item (if it fits)
 if (current_weight + weights[index] <= capacity) {
 solve_knapsack(index + 1, current_weight + weights[index], current_profit +
values[index]);
 }
 // Branch 2: Exclude current item (only if the potential bound > current max_profit)
 if (calculate_bound(index + 1, current_weight, current_profit) > max_profit) {
 solve_knapsack(index + 1, current_weight, current_profit);
 }
 }
int main() {
 printf("Enter number of items and capacity: ");
 scanf("%d %d", &n, &capacity);
 printf("Enter weights and values:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d %d", &weights[i], &values[i]);
 }
 // Start backtracking from the first item
 k(0, 0, 0);
 printf("Maximum Profit: %d\n", max_profit);
 return 0;
}