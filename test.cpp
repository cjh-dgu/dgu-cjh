#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

void ledtwinkle(int LEDpin);
void runBeel(int beel);
int main(int argc, char **argv)
{
    wiringPiSetup();
    int pinBeed = 20;
    int pinLed = 21;
    int pinVB = 22;
    pinMode(pinBeed, OUTPUT); 
    pinMode(pinLed, OUTPUT);    
    pinMode(pinVB, INPUT);      
    /*Init output*/
    digitalWrite(pinBeed, HIGH);
    digitalWrite(pinLed, LOW);
    int count = 0;

    while (1)
    {
        int vbsignal = digitalRead(pinVB);
        if (vbsignal == 1)
        {
            sleep(1);
            if (digitalRead(pinVB))
            {
                count++;
            }
            else
            {
                count--;
                if (count < 0)
                {
                    count = 0;
                }
            }

        }
        if (count > 3)
        {
            runBeel(pinBeed);
            ledtwinkle(pinLed);
        }
    }
    return 0;
}

void ledtwinkle(int LEDpin)
{
    while (1)
    {
        digitalWrite(LEDpin, HIGH);
        delay(500);
        digitalWrite(LEDpin, LOW);
        delay(500);
    }
}
void runBeel(int beel)
{
    digitalWrite(beel, LOW);
}