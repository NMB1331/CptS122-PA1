#include "fitbit_functions.h"
#include "fitbit_functions.c"

int main(void)
{
  FILE *data = NULL;
  data = fopen("FitbitData.csv", "r");
  FitbitData todays_data[1445];
  if (data == NULL)
  {
    printf("ERROR OPENING FILE\n");
  }
  read_file(data, todays_data);

  return 0;
}
