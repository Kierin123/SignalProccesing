# Test Assignment - Prosthesis speed control

Author: Marcin Kierinkiewicz
email: kierinkiewicz.marcin@gmail.com

Program to recalculating input data from the two EMG sensors. The data has to be delivered in CSVInput.csv file. In .csv file need to be two columns of data separeted by comm (','). In first column are sensor values to opening the prosthesis and second column are sensor values to close the prosthesis. Calculation is perform to receive more clear sinal to output of the prothesis control system. The signal after processing is without noise and provide two direcional move in range[-1000,1000]. The output data is created in CSVOutput.csv file.

# Files

The program was written in Linux enviroment - architecture x86_64. Program consists 4 files in main folder:
- main.c
- filter.h
- filter.c
- makefile

filter.h is the header file to use filtering noise functions. Library consists two functions: 
- AvarageValue() - simple filtering data by calculate avarage value of few neigbouring read values. To set how many values has to be taken into account change '#define AVG_ELEMENTS' to your value.
- Low_pass_filter() - simple fitering by calculating the output by using current read value and previous value. The function use the equasion: 
    y(x) = B * input + (1 - B) * y(x-1), 
        where: x - current step; B - smoothing factor, here set constantly to 0.2f

The program need the data file in .csv format. It was delivered with the program in CSVInput.csv. If you want to use your data file rename as CSVInput.csv and copy to the main folder. 

# Compilation and startup

To start the program on Linux and Windows it is necessery to have gcc compiler and makefile interpreter. To build the program use 'make' command in terminal. After compilation use ./output command to start program(.\output.exe on Windows). 