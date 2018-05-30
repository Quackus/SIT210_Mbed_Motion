#include "mbed.h"
#include "ultrasonic.h"

//Serial pc(USBTX,USBRX);
DigitalOut led1(LED1);
int currentDistance;
int newDistance;

void dist(int distance)
{
    //pc.printf("Distance changed to %dmm/r/n", distance);
    if (currentDistance - 20 > newDistance || currentDistance + 20 < newDistance)
    {
        led1 = true;
        wait(0.1);
        led1 = false;
    }
    currentDistance = newDistance;
}

ultrasonic mu(p10,p11,.1,1,&dist);

int main()
{
    led1 = false;
    mu.startUpdates();
    currentDistance = mu.getCurrentDistance();
    while(1)
    {
        newDistance = mu.getCurrentDistance();
        mu.checkDistance();
    }
}