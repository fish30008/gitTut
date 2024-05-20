#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int date;
    int month;
    int year;
} date;

typedef struct {
    char* oname;
    char* isname;
    char* prname;
    char* manufacturer;
    date* ccdate;
    int whole_price;
    int unit_price;
    int quantity;
    int years_remaining;
    int months_remaining;
    int days_remaining;
} info;

char* names[] = {"Jasmine", "Liam", "Sophia", "Noah", "Isabella", "Ethan", "Olivia", "Mason", "Ava", "Logan"};
char* surnames[] = {"Rodriguez", "Patel", "Smith", "Johnson", "Kim", "Brown", "Martinez", "Jones", "Nguyen", "Garcia"};
char* manufacture_names[] = {"QuantumTech Industries", "Stellar Innovations", "Nexus Dynamics", "Vertex Manufacturing", "Horizon Enterprises", "OmniCorp", "TitanTech Solutions", "Aurora Creations", "Synergy Manufacturing Co.", "Nova Industries"};
char* product_names[] = {"PulseDrive 3000", "SkyLume Pro", "NanoGrip Gloves", "HydraCleanse 2.0", "SolarBoost Charger", "AeroShield Protector", "TitanX Fitness Tracker", "Zenith360 VR Headset", "AquaFlow Shower System", "TerraGlow Plant Growth Enhancer"};

// Function to generate a random date
date* generate_date() {
    date* d = malloc(sizeof(date));
    d->date = rand() % 31 + 1;
    d->month = rand() % 12 + 1;
    d->year = rand() % (2024 - 2010 + 1) + 2010;
    return d;
}

// Function to generate random information
info* generate_info() {
    info* inf = malloc(sizeof(info));
    inf->oname = names[rand() % (sizeof(names) / sizeof(names[0]))];
    inf->isname = surnames[rand() % (sizeof(surnames) / sizeof(surnames[0]))];
    inf->prname = product_names[rand() % (sizeof(product_names) / sizeof(product_names[0]))];
    inf->manufacturer = manufacture_names[rand() % (sizeof(manufacture_names) / sizeof(manufacture_names[0]))];
    inf->ccdate = generate_date();
    inf->whole_price = rand() % 1000 + 100;
    inf->unit_price = rand() % 100 + 10;
    inf->quantity = rand() % 1000 + 10;
    return inf;
}

// Function to calculate remaining time until ccdate
void calculate_remaining_time(info* inf) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    int current_year = tm_info->tm_year + 1900;
    int current_month = tm_info->tm_mon + 1;
    int current_day = tm_info->tm_mday;

    inf->years_remaining = inf->ccdate->year - current_year;
    inf->months_remaining = inf->ccdate->month - current_month;
    inf->days_remaining = inf->ccdate->date - current_day;

    if (inf->days_remaining < 0) {
        inf->months_remaining--;
        inf->days_remaining += 30; // Assuming each month has 30 days
    }
    if (inf->months_remaining < 0) {
        inf->years_remaining--;
        inf->months_remaining += 12;
    }
}

// Function to write info to output.txt sorted in descending order based on remaining time until ccdate
void write_output(info* info_array, int num_entries) {
    FILE* output_file = fopen("output1.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output1.txt\n");
        return;
    }

    // Calculate remaining time for each info structure
    for (int i = 0; i < num_entries; i++) {
        calculate_remaining_time(&info_array[i]);
    }

    // Sort info_array based on remaining time in descending order
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = 0; j < num_entries - i - 1; j++) {
            int days1 = info_array[j].years_remaining * 365 + info_array[j].months_remaining * 30 + info_array[j].days_remaining;
            int days2 = info_array[j + 1].years_remaining * 365 + info_array[j + 1].months_remaining * 30 + info_array[j + 1].days_remaining;
            if (days1 < days2) {
                // Swap
                info temp = info_array[j];
                info_array[j] = info_array[j + 1];
                info_array[j + 1] = temp;
            }
        }
    }

    // Write sorted info to output.txt
    for (int i = 0; i < num_entries; i++) {
        fprintf(output_file, "Owner Name: %s\n", info_array[i].oname);
        fprintf(output_file, "Owner Surname: %s\n", info_array[i].isname);
        fprintf(output_file, "Product Name: %s\n", info_array[i].prname);
        fprintf(output_file, "Manufacturer: %s\n", info_array[i].manufacturer);
        fprintf(output_file, "Creation Date: %d-%02d-%02d\n", info_array[i].ccdate->year, info_array[i].ccdate->month, info_array[i].ccdate->date);
        fprintf(output_file, "Whole Price: %d\n", info_array[i].whole_price);
        fprintf(output_file, "Unit Price: %d\n", info_array[i].unit_price);
        fprintf(output_file, "Quantity: %d\n", info_array[i].quantity);
        fprintf(output_file, "Remaining Time until CCDate: %d years, %d months, %d days\n\n", info_array[i].years_remaining, info_array[i].months_remaining, info_array[i].days_remaining);
    }

    fclose(output_file);
}

// Function to copy contents of output.txt to experiment.txt
void copy_output_to_experiment() {
    FILE* output_file = fopen("output1.txt", "r");
    if (output_file == NULL) {
        printf("Error opening output.txt\n");
        return;
    }

    FILE* experiment_file = fopen("experiment.txt", "w");
    if (experiment_file == NULL) {
        printf("Error opening experiment.txt\n");
        fclose(output_file);
        return;
    }

    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), output_file) != NULL) {
        fprintf(experiment_file, "%s", buffer);
    }

    fclose(output_file);
    fclose(experiment_file);
}

int main() {
    srand(time(NULL)); // Seed for random number generator

    // Dynamic allocation of array of structures
    int num_entries = 7;
    info* info_array = malloc(num_entries * sizeof(info));

    // Generate random information
    for (int i = 0; i < num_entries; i++) {
        info_array[i] = *generate_info();
    }

    // Write info to output.txt sorted in descending order based on remaining time until ccdate
    write_output(info_array, num_entries);

    // Copy contents of output.txt to experiment.txt
    copy_output_to_experiment();

    // Free dynamically allocated memory
    for (int i = 0; i < num_entries; i++) {
        free(info_array[i].ccdate);
    }
    free(info_array);

    return 0;
}
