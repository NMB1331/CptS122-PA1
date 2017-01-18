#ifndef FITBIT_H
#define FITBIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MINUTES 1440

typedef enum sleep
{
     NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
 char minute[9];
 double calories;
 double distance;
 unsigned int floors;
 unsigned int heartRate;
 unsigned int steps;
 Sleep sleepLevel;
} FitbitData;

/*************************************************************
* Function: read_file                                       *
* Date Created: 12/1/2016                                   *
* Date Last Modified: 12/1/2016                             *
* Description: Reads/parses csv data; stores in array       *
* Input parameters: Pointer to file, Fitbit array           *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void read_file(FILE *infile, FitbitData todays_data[NUM_MINUTES]);

#endif
