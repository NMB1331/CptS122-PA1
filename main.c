#include "fitbit_functions.h"
#include "fitbit_functions.c"

int main(void)
{
  //Array initialized; file read
  FILE *data = NULL, *results = NULL;
  data = fopen("FitbitData.csv", "r");
  results = fopen("Results.csv", "w");
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
  printf("The average heart rate for the day was %lf bpm\n", average_heart_rate);

  //Max steps taken in a minute
  unsigned int max_steps = compute_max_steps(todays_data);
  printf("The max steps taken in a minute was %d\n", max_steps);

  //Computes the range with the worst sleep_level
  char start_time[10], end_time[10];
  compute_worst_sleep(start_time, end_time, todays_data);


  //Writes results to outfile
  fprintf(results, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
  fprintf(results, "%lf,%lf,%d,%d,%lf,%d,%s:%s", total_calories, total_miles, total_floors, total_steps, average_heart_rate, max_steps, start_time, end_time);

  //Files closed
  printf("\n");
  fclose(data);
  fclose(results);
  return 0;
}
/*
minute,calories,distance,floors,heart,steps,sleep_level
*/
