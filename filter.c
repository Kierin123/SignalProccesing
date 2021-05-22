#include "filter.h"

int AvarageValue(int input)
{
    static int avgValues[6] = {0};

    avgValues[0] = avgValues[1];
    avgValues[1] = avgValues[2];
    avgValues[2] = avgValues[3];
    avgValues[3] = avgValues[4];
    avgValues[4] = avgValues[5];
    avgValues[5] = input;

    return (avgValues[0] + avgValues[1] + avgValues[2] + avgValues[3] + avgValues[4] + avgValues[5]) / 6;
}

int Low_pass_filter(int input)
{
    float beta = 0.125f;
    static int lastoutput;
    int output = beta * input + (1.0f - beta) * lastoutput;
    lastoutput = output;

    return output;
}