#ifndef RANDOM_H
#define RANDOM_H
#include <time.h>
int random(int min,int max, int multiplier)
{
    int r;
    srand(time(NULL));
    for (int i=0; i<multiplier; i++)
    {
        r = min+rand()%(max-min+1);
    }
    return r;
}
#endif