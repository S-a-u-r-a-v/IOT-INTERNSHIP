#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get temperature from the sensor (replace this with actual sensor code)
float get_temperature() {
    // Simulating temperature reading between 20 and 30 degrees Celsius
    return 20 + ((float)rand() / RAND_MAX) * 10;
}

// Function to calculate statistics from an array of temperature values
void calculate_statistics(float temperatures[], int size, float* min_temp, float* max_temp, float* avg_temp) {
    if (size == 0) {
        *min_temp = 0;
        *max_temp = 0;
        *avg_temp = 0;
        return;
    }

    *min_temp = temperatures[0];
    *max_temp = temperatures[0];
    float sum = temperatures[0];

    for (int i = 1; i < size; i++) {
        if (temperatures[i] < *min_temp)
            *min_temp = temperatures[i];
        if (temperatures[i] > *max_temp)
            *max_temp = temperatures[i];
        sum += temperatures[i];
    }

    *avg_temp = sum / size;
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    float temperature_data[100];  // Array to store temperature values
    int data_size = 0;            // Number of temperature values in the array

    while (1) {
        float temperature = get_temperature();  // Get temperature from the sensor
        printf("Temperature: %.2f\n", temperature);

        temperature_data[data_size] = temperature;  // Store temperature in the array
        data_size++;

        float min_temp, max_temp, avg_temp;
        calculate_statistics(temperature_data, data_size, &min_temp, &max_temp, &avg_temp);

        printf("Statistics:\n");
        printf("  Min Temperature: %.2f\n", min_temp);
        printf("  Max Temperature: %.2f\n", max_temp);
        printf("  Average Temperature: %.2f\n", avg_temp);

        // Add any necessary delay or sleep between readings
        // For demonstration purposes, we'll add a 1-second delay
        delay(1000);
    }

    return 0;
}
