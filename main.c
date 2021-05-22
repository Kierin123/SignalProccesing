#include <stdio.h>
#include <stdlib.h>
#include "filter.h"


int main(void)
{
    int readValueOpen = 0;
    int readValueClose = 0;
    int outputValue = 0;

    int threshold = 50; // Default thereshold

    // Create and open the files with signal value of EMG
    FILE *csvInput;
    FILE *csvOutput;

    csvOutput = fopen("EMGOutput.csv", "w");
    csvInput = fopen("EMGInput.csv", "r");

    // User setup the threshold of EMG to startup the prosthesis
    printf("Give the startup thereshold value of EMG: ");
    scanf("%d", &threshold);
    
    // Set the file iterator to the begining of the file
    fseek(csvInput, 0, SEEK_SET);
    fseek(csvOutput, 0, SEEK_SET);

    while (!feof(csvInput))
    {
        // Read values of two signals form the CSV file and arite it into the variables readValueOpen and readValueClose
        fscanf(csvInput, "%d,%d\n", &readValueOpen, &readValueClose); 

        // Check the threshold
        if ((readValueOpen > threshold) || (readValueClose > threshold))
        {
            // Check the direction of the move
            if (readValueOpen > readValueClose)
            {
                outputValue = -readValueOpen;
            }
            else
            {
                outputValue = readValueClose;
            }
        }
        else
        {
            outputValue = 0;
        }
        
        // Write filtered output value to the CSV output file   
        fprintf(csvOutput, "%d\n", Low_pass_filter(outputValue));

        //printf("O: %d C: %d OUT: %d\n", readValueOpen, readValueClose, outputValue);
    }

    fclose(csvInput);
    fclose(csvOutput);

    return 0;
}