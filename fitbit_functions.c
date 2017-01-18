#include "fitbit_functions.h"

//Function that reads and parses data; stores in array
void read_file(FILE *infile, FitbitData todays_data[NUM_MINUTES])
{
  int counter = 0;
  while (!feof(infile))
  {
    //Reads in data
    char holder[50];
    fgets(holder, 50, infile);

    //Parses and stores the data
    if (counter > 0) //skips the description
    {
      //Holder and delimiter variables
      const char delim[2] = ",";
      double dub_holder = 0.0;
      unsigned int int_holder = 0;

      //Stores the minute
      char *temp = strtok(holder, delim);
      strcpy(todays_data[counter-1].minute, temp);

      //Stores the calories burned
      temp = strtok(NULL, delim);
      sscanf(temp, "%lf", &dub_holder);
      todays_data[counter].calories = dub_holder;
      //todays_data[counter-1].calories = (double) atof(temp);

      //Stores the distance walked
      temp = strtok(NULL, delim);
      sscanf(temp, "%lf", &dub_holder);
      todays_data[counter].distance = dub_holder;
      //todays_data[counter-1].distance = (double) atof(temp);

      //Stores the floors walked
      temp = strtok(NULL, delim);
      sscanf(temp, "%d", &int_holder);
      todays_data[counter].floors = int_holder;
      //todays_data[counter-1].floors = (unsigned int) atoi(temp);

      //Stores the heart rate
      temp = strtok(NULL, delim);
      sscanf(temp, "%d", &int_holder);
      todays_data[counter].heartRate = int_holder;
      //todays_data[counter-1].heartRate = (unsigned int) atoi(temp);

      //Stores the number of steps
      temp = strtok(NULL, delim);
      sscanf(temp, "%d", &int_holder);
      todays_data[counter].steps = int_holder;
      //todays_data[counter-1].steps = (unsigned int) atoi(temp);

      //Stores the sleep level
      temp = strtok(NULL, delim);
      //todays_data[counter-1].sleepLevel = 0;

      printf("COUNTER: %d   MINUTE: %s   Heart rate: %d\n",counter, todays_data[counter].minute, todays_data[counter].heartRate);
  }

    counter++;
  }
}
