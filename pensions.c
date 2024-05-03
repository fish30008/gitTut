#include <stdio.h>

// Structure to represent information about a job
struct Job {
    float income;   // income
    int yearsOfWork; // years of work
    int monthsOfWork; // months of work
};

// Function to calculate the pension amount
float calculatePension(struct Job jobs[], int numJobs) {
    // Constant for the pension rate
    const float pensionRate = 1.35 / 100;
    float totalIncome = 0;
    float totalYearsOfWork = 0; // Use float to include months in the calculation

    // Summing income and years of work across all jobs
    for (int i = 0; i < numJobs; i++) {
        totalIncome += jobs[i].income;
        totalYearsOfWork += (jobs[i].yearsOfWork + jobs[i].monthsOfWork / 12.0); // Convert months to years
    }

    // Calculating the pension amount
    float pension = pensionRate * totalYearsOfWork * totalIncome;
    return pension;
}

int main() {
    // Minimum pension and standard years of work
    const float minPension = 2620;
    const int minYearsOfWork = 15;

    // Input the number of jobs
    int numJobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);

    // Creating an array of structures to store information about each job
    struct Job jobs[numJobs];

    // Input data for each job
    for (int i = 0; i < numJobs; i++) {
        printf("Enter the income for job %d: ", i + 1);
        scanf("%f", &jobs[i].income);
        printf("Enter the years of work for job %d: ", i + 1);
        scanf("%d", &jobs[i].yearsOfWork);
        printf("Enter the months of work for job %d: ", i + 1);
        scanf("%d", &jobs[i].monthsOfWork);
    }

    // Calculating the pension
    float pension = calculatePension(jobs, numJobs);

    // Output the result
    if (pension < minPension) {
        printf("Your pension is less than 50%% of the minimum pension and is %.2f lei.\n", pension);
    } else {
        printf("Your pension is %.2f lei.\n", pension);
    }

    return 0;
}
