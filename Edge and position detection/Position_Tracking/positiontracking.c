#include <stdio.h>
//mapped to example  addresses 
#define LEFT_ENCODER  (*(volatile unsigned int*)0x10000020)
#define RIGHT_ENCODER (*(volatile unsigned int*)0x10000024)

#define DIST_PER_PULSE 1.25f
#define PANEL_LENGTH 200

float getDistance()
{
    unsigned int leftCount  = LEFT_ENCODER;
    unsigned int rightCount = RIGHT_ENCODER;

    float avgCount =
        (leftCount + rightCount) / 2.0;

    return avgCount * DIST_PER_PULSE;
}

int main()
{
    while(1)
    {
        float position = getDistance();

        printf("Position = %.2f cm\n",
               position);

        if(position >= PANEL_LENGTH - 10)
        {
            printf("Near End Of Strip\n");
        }
    }

    return 0;
}