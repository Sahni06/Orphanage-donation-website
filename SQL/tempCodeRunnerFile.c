#include <stdio.h>

void fcfs(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1]; // Calculate waiting time
    }
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Calculate turnaround time
    }
}

void calculate_average(int n, int wt[], int tat[], float* avg_wt, float* avg_tat) {
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];     // Sum waiting times
        total_tat += tat[i];   // Sum turnaround times
    }
    *avg_wt = (float)total_wt / n;   // Average waiting time
    *avg_tat = (float)total_tat / n; // Average turnaround time
}

int main() {
    int n;
    int bt[10], at[10], wt[10], tat[10];
    float avg_wt, avg_tat;
    char name[200], enrollmentNo[100];

    // Get user details
    printf("Name: ");
    scanf("%s", name);
    printf("Enrollment No: ");
    scanf("%s", enrollmentNo);

    // Input: number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input: burst time, arrival time for each process
    printf("\nEnter Burst Time, Arrival Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
    }

    // First-Come, First-Served (FCFS)
    fcfs(n, bt, wt, tat);
    calculate_average(n, wt, tat, &avg_wt, &avg_tat);

    // Output results
    printf("\nFCFS Scheduling: AWT = %.2f, ATAT = %.2f\n", avg_wt, avg_tat);

    return 0;
}
