#include "fitbit_functions.h"
#include "fitbit_functions.c"

int main(void)
{
  FILE *data = NULL;
  data = fopen("FitbitData.csv", "r");
  FitbitData todays_data[1440]
  if (data == NULL)
  {
    printf("ERROR OPENING FILE\n");
  }

  return 0;
}
