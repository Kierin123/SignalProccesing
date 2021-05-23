#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filter.h"

int main(void)
{

    unsigned int readValueOpen = 0;  // Read value of the signal to open prothesis
    unsigned int readValueClose = 0; // Read value of the signal to close prothesis
    int outputValue = 0;             // output value to write into CSVOutput
    unsigned int threshold = 0;      // Default thereshold

    char *end;                       // End pointer to end of read string from keyboard
    char readBuffer[10];             // Buffer for read dat from keyboard

    // Create and open the files with signal value of EMG
    FILE *csvInput;
    FILE *csvOutput;

    csvOutput = fopen("EMGOutput.csv", "w");
    if (csvOutput == NULL)
    {
        printf("Cannot open EMGOutput.csv! \n");
        return -1;
    }

    csvInput = fopen("EMGInput.csv", "r");
    if (csvInput == NULL)
    {
        printf("Cannot open EMGInput.csv! \n");
        return -1;
    }

    // User setup the threshold of EMG to startup the prosthesis
    // User can only put integer value in range [15,500]
    // Characters, strings are neglected

    while ((threshold < 15) || (threshold > 500))
    {
        do
        {
            threshold = 0;
            printf("Give the startup thereshold value of EMG in range [15,500]: ");

            if (!fgets(readBuffer, sizeof readBuffer, stdin))
                break;

            // remove \n
            readBuffer[strlen(readBuffer) - 1] = 0;
            threshold = strtod(readBuffer, &end);
        } while (end != readBuffer + strlen(readBuffer));
    }

    // Set the file iterator to the begining of the file (not necessery)
    fseek(csvInput, 0, SEEK_SET);
    fseek(csvOutput, 0, SEEK_SET);

    while (!feof(csvInput))
    {
        // Read values of two signals form the CSV file and write it into the variables readValueOpen and readValueClose
        fscanf(csvInput, "%u,%u\n", &readValueOpen, &readValueClose);

        // Check the threshold
        if ((readValueOpen > threshold) || (readValueClose > threshold))
        {
            // Check the direction of the move and eliminate weaker signal
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
    }

    fclose(csvInput);
    fclose(csvOutput);

    return 0;
}