#ifndef FILTER_H
#define FILTER_H

#define BETA 0.2f
#define AVG_ELEMENTS 5

// Avarage_Value() - function to calculate avarage value of some neighbouring values
// AVG_ELEMENTS defines how many elements has to be taken into account during calculation

int Avarage_Value(const int input);

// Low_pass_filter() - function takes two values(current and previous) to get a rid of the noise from the signal
// As input we need to put the current value. Parameter BETA defines how much the signal should be filtered - smoothing factor
// BETA is equivalent of time constant RC in electrical loops

int Low_pass_filter(const int input);

#endif