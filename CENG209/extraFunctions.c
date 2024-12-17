#include <stdio.h>
#include "extraFunctions.h"

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}