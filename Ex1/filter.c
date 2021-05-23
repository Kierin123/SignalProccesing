#include "filter.h"

int Avarage_Value(const int input)
{
    static int avgValues[AVG_ELEMENTS];
    int sum = 0;

    for (int i = 0; i < AVG_ELEMENTS - 1; i++)
    {
        sum += avgValues[i];
        avgValues[i] = avgValues[i + 1];
    }
    avgValues[AVG_ELEMENTS - 1] = input;
    sum += avgValues[AVG_ELEMENTS - 1];

    return sum / AVG_ELEMENTS;
}

int Low_pass_filter(const int input)
{
    static int lastoutput;
    int output = BETA * input + (1.0f - BETA) * lastoutput;
    lastoutput = output;

    return output;
}