#include "SPI.h"
#include "SD.h"

const int chipSelect = 4;

void setup()
{
    Serial.begin(9600);

    if (!SD.begin(chipSelect))
    {
        Serial.println("Card failed, or not present");
        return;
    }

    String dataString = "Electronic Device Development Club";

    File dataFile = SD.open("EDDC.txt", FILE_WRITE);

    if (dataFile)
    {
        dataFile.println(dataString);
        dataFile.close();

        Serial.println("Success!");
    }

    else
    {
        Serial.println("Error opening file!");
    }
}

void loop() {}
