#include "fitbit_functions.h"

//Function that reads and parses data; stores in array
void read_file(FILE *infile, FitbitData todays_data[NUM_MINUTES])
{
  int counter = 0;
  while (!feof(infile))
  {
    //Reads in data
    char holder[50];
    char delim[2] = ",";
    double dub = 0.0;
    unsigned int int_h = 0;
    fgets(holder, 50, infile);

    //Parses and stores the data

    //Stores the minutes
    char * temp = strtok(holder, delim);
    strcpy(todays_data[counter].minute, temp);
    printf("%s\n", todays_data[counter].minute);

    //Stores the calories burned
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      dub = atof(temp);
      todays_data[counter].calories = dub;
    }
    printf("Calories: %lf\n", todays_data[counter].calories);

    //Stores the distance traveled
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      dub = atof(temp);
      todays_data[counter].distance = dub;
    }
    printf("Distance: %lf\n", todays_data[counter].distance);

    //Stores the floors walked
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      int_h = atoi(temp);
      todays_data[counter].floors = int_h;
    }
    printf("Floors: %d\n", todays_data[counter].floors);

    //Stores the heart rate
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      int_h = atoi(temp);
      todays_data[counter].heartRate = int_h;
    }
    printf("Heart Rate: %d\n", todays_data[counter].heartRate);

    //Stores the steps walked
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      int_h = atoi(temp);
      todays_data[counter].steps = int_h;
    }
    printf("Steps: %d\n", todays_data[counter].steps);

    //Stores the sleep level
    temp = strtok(NULL, delim);
    if (temp != '\0')
    {
      int_h = atoi(temp);
      todays_data[counter].sleepLevel = int_h;
    }
    printf("Sleep Level: %d\n\n", todays_data[counter].sleepLevel);

    counter++;
  }
}

//Function that computes the total calories burned
double compute_total_calories(FitbitData todays_data[NUM_MINUTES])
{
  double total_calories = 0.0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    total_calories += todays_data[i].calories;
  }

  return total_calories;
}

//Function that computes the total distance walked (miles)
double compute_distance_walked(FitbitData todays_data[NUM_MINUTES])
{
  double total_miles = 0.0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    total_miles += todays_data[i].distance;
  }

  return total_miles;
}

//Function that computes the total floors walked
unsigned int compute_floors_walked(FitbitData todays_data[NUM_MINUTES])
{
  unsigned int total_floors = 0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    total_floors += todays_data[i].floors;
  }

  return total_floors;
}

//Function that computes the total steps taken
unsigned int compute_steps_taken(FitbitData todays_data[NUM_MINUTES])
{
  unsigned int total_steps = 0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    total_steps += todays_data[i].steps;
  }

  return total_steps;
}

//Function that computes the average heart rate
double compute_average_heartrate(FitbitData todays_data[NUM_MINUTES])
{
  double counter = 0;
  double average_sum = 0.0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    average_sum += todays_data[i].heartRate;
    if (todays_data[i].heartRate != 0)
    {
      counter++;
    }
  }
  return average_sum / counter;
}

//Function that calculates the max number of steps taken
unsigned int compute_max_steps(FitbitData todays_data[NUM_MINUTES])
{
  unsigned int max_steps = 0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    if (todays_data[i].steps >= max_steps)
    {
      max_steps = todays_data[i].steps;
    }

  }
  return max_steps;
}

//Function that determines the period of best and worst sleep
void compute_worst_sleep(char *start_time, char *end_time, FitbitData todays_data[NUM_MINUTES])
{
  int counter = 0, current_sum = 0;
  int max_start = 0, max_end = 0, max_sum = 0;
  for (int i=0; i<NUM_MINUTES; i++)
  {
    if (todays_data[i].sleepLevel > 1)
    {
      counter = i;
      while (todays_data[counter].sleepLevel > 1)
      {
        current_sum += todays_data[counter].sleepLevel;
        counter++;
      }
      if (current_sum > max_sum)
      {
        max_start = i;
        max_end = counter;
        max_sum = current_sum;
      }

    }
    current_sum = 0;
  }
  strncpy(start_time, todays_data[max_start].minute, 9);
  strncpy(end_time, todays_data[max_end].minute, 9);
  printf("The period of worst sleep was %s to %s\n", start_time, end_time);
}
