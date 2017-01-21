#include "fitbit_functions.h"
#include "fitbit_functions.c"

int main(void)
{
  //Array initialized; file read
  FILE *data = NULL;
  data = fopen("FitbitData.csv", "r");
  FitbitData todays_data[1441];
  if (data == NULL)
  {
    printf("ERROR OPENING FILE\n");
  }
  read_file(data, todays_data);

  //Calories calculated
  double total_calories = compute_total_calories(todays_data);
  printf("%lf Calories were burned today\n", total_calories);

  //Distance walked (miles)
  double total_miles = compute_distance_walked(todays_data);
  printf("%lf miles were walked today\n", total_miles);

  //Floors walked
  unsigned int total_floors = compute_floors_walked(todays_data);
  printf("%d floors were walked today\n", total_floors);

  //Steps taken
  unsigned int total_steps = compute_steps_taken(todays_data);
  printf("%d steps were taken today\n", total_steps);

  //Average heart rate
  double average_heart_rate = compute_average_heartrate(todays_data);
  printf("The average heart rate for the day was %lf\n", average_heart_rate);



  //Files closed
  printf("\n");
  fclose(data);
  return 0;
}
/*
minute,calories,distance,floors,heart,steps,sleep_level
*/
