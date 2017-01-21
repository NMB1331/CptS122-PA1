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
* Date Created: 1/17/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Reads/parses csv data; stores in array       *
* Input parameters: Pointer to file, Fitbit array           *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void read_file(FILE *infile, FitbitData todays_data[NUM_MINUTES]);

/*************************************************************
* Function: compute_total_calories                          *
* Date Created: 1/20/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Calculates total calories burned             *
* Input parameters: Fitbit array                            *
* Returns: Calories burned                                  *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
double compute_total_calories(FitbitData todays_data[NUM_MINUTES]);

/*************************************************************
* Function: compute_distance_walked                         *
* Date Created: 1/20/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Calculates the distance walked               *
* Input parameters: Fitbit array                            *
* Returns: Number of miles walked                           *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
double compute_distance_walked(FitbitData todays_data[NUM_MINUTES]);

/*************************************************************
* Function: compute_floors_walked                           *
* Date Created: 1/20/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Calculates the floors walked                 *
* Input parameters: Fitbit array                            *
* Returns: Number of floors walked                          *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
unsigned int compute_floors_walked(FitbitData todays_data[NUM_MINUTES]);

/*************************************************************
* Function: compute_steps_taken                             *
* Date Created: 1/20/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Calculates the steps taken                   *
* Input parameters: Fitbit array                            *
* Returns: Number of steps taken                            *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
unsigned int compute_steps_taken(FitbitData todays_data[NUM_MINUTES]);

/*************************************************************
* Function: compute_average_heartrate                       *
* Date Created: 1/20/2017                                   *
* Date Last Modified: 1/20/2016                             *
* Description: Calculates the average heartrate             *
* Input parameters: Fitbit array                            *
* Returns: Average heart rate (double)                      *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
double compute_average_heartrate(FitbitData todays_data[NUM_MINUTES]);

#endif
