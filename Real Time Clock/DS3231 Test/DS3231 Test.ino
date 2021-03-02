#include "Wire.h"
#include "Time.h"
#include "DS1307RTC.h"

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    tmElements_t tm;

    if (RTC.read(tm))
    {
        print2digits(tm.Hour);
        Serial.print(":");

        print2digits(tm.Minute);
        Serial.print(":");

        print2digits(tm.Second);
        Serial.print(" ");

        print2digits(tm.Day);
        Serial.print("/");

        print2digits(tm.Month);
        Serial.print("/");

        Serial.println(tmYearToCalendar(tm.Year));
    }

    else
    {
        if (RTC.chipPresent())
        {
            Serial.println("DS1307 is stopped");
        }

        else
        {
            Serial.println("DS1307 read error");
        }

        delay(9000);
    }

    delay(1000);
}

void print2digits(int number)
{
    if (number >= 0 && number < 10)
    {
        Serial.print("0");
    }

    Serial.print(number);
}
