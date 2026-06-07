#include <stdio.h>

/* IR Sensors */
//example addresses that IR sensors are mapped
#define FL_SENSOR (*(volatile unsigned int*)0x10000000)
#define FR_SENSOR (*(volatile unsigned int*)0x10000004)
#define RL_SENSOR (*(volatile unsigned int*)0x10000008)
#define RR_SENSOR (*(volatile unsigned int*)0x1000000C)

/* Motors */

#define LEFT_MOTOR  (*(volatile unsigned int*)0x10000010)
#define RIGHT_MOTOR (*(volatile unsigned int*)0x10000014)

/* Motor Functions */

void moveForward()
{
    LEFT_MOTOR = 100;
    RIGHT_MOTOR = 100;
}

void moveLeft()
{
    LEFT_MOTOR = 50;
    RIGHT_MOTOR = 100;
}

void moveRight()
{
    LEFT_MOTOR = 100;
    RIGHT_MOTOR = 50;
}

void stopRobot()
{
    LEFT_MOTOR = 0;
    RIGHT_MOTOR = 0;
}

int main()
{
    while(1)
    {
        unsigned int FL = FL_SENSOR;
        unsigned int FR = FR_SENSOR;
        unsigned int RL = RL_SENSOR;
        unsigned int RR = RR_SENSOR;

        /* Left Edge */

        if(FL == 0 || RL == 0)
        {
            printf("LEFT EDGE DETECTED\n");

            stopRobot();

            moveRight();
        }

        /* Right Edge */

        else if(FR == 0 || RR == 0)
        {
            printf("RIGHT EDGE DETECTED\n");

            stopRobot();

            moveLeft();
        }

        /* Safe */

        else
        {
            moveForward();
        }
    }

    return 0;
}