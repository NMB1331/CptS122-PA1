#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
  NONE = 0, ASLEEP = 1, AWAKE = 2, REALLY_AWAKE = 3
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

void read_file(FILE *infile);
