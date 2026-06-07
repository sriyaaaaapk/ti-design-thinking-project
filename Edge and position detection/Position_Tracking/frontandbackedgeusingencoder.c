#include <stdio.h>

#define PANEL_LENGTH 200.0
#define SAFETY_MARGIN 10.0
#define DIST_PER_PULSE 1.25

volatile long encoder_count = 0;

float getDistance()
{
    return encoder_count * DIST_PER_PULSE;
}

int main()
{
    for(encoder_count = 0;
        encoder_count <= 200;
        encoder_count += 10)
    {
        float pos = getDistance();

        printf("Position = %.2f cm\n", pos);

        if(pos >= PANEL_LENGTH - SAFETY_MARGIN)
            printf("Near Front Edge\n");

        if(pos <= SAFETY_MARGIN)
            printf("Near Back Edge\n");
    }

    return 0;
}