# Aether Biomedical - Test assignment

Author: Marcin Kierinkiewicz
email: kierinkiewicz.marcin@gmail.com
phone: +48 519 857 067

Program to calculating input data from the two EMG sensors. One signal is to opening the prosthesis and second is to close the prosthesis. Calculation is made to send more clear sinal to output of the prothesis. The signal after processing is without noise and provide two directions of move.

Input data is read from delivered CSVInput.csv file.(Values of the sensors are random create by the developer) The file consists data from two sensors. The output data is delivered in CSVOutput.csv file. The output data is in range [-1000,1000].

# Compilation and startup

The program was written in Linux enviroment. Program consists 4 files:
- main.c
- filter.h
- filter.c
- makefile

To start the program on Linux and Windows it is necessery to have gcc compiler and makefile interpreter. To build the program use 'make' and then ./output to start program(or .\output.exe on Windows). 




