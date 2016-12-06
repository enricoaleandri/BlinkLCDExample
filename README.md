# Blink LCD example

## Running on ESP NodeMCU

To programm the ESP, use the [Arduino IDE](https://www.arduino.cc/en/Main/Software), then follow this step :

* Go on **File** > **Preferences**, and change the URL of Board Manager with "http://arduino.esp8266.com/package_esp8266com_index.json", then click OK
* Now go on **Tools** > **Board:Arduino one** > **Board Managers**
* Search For "esp8266" and Click Install ( it will take a while )
* After installation go back on **Tools** > **Board:Arduino one** and click on **"NodeMCU 0.9 (ESP-12E Module)"**
* Now you can connect it and lunch the Load process

## Installing LyquidCrystal_I2C

To run the display use this library  :

![alt tag](http://www.slumberjer.com/myardu/wp-content/uploads/2016/03/library.png)

Then connect the I2C module to NodeMCU  as here:

* D1(Nodemcu - SCL) –> SCL(LCD)
* D2(Nodemcu - SDA)–> SDA(LCD)
* +ve 5V power supply –> VCC(LCD)
* ground -ve –> GND(LCD)

![alt tag](https://www.losant.com/hs-fs/hubfs/Blog/connect-lcd-nodemcu/wiring.jpg?noresize=true&t=1480964054139&width=640&name=wiring.jpg)


### Simple Example

Here a simple example you can use to test the library and the LCD.
```cpp
#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library >
LiquidCrystal_I2C lcd(0x27, 16, 2); // If you are not sure of wich address your device has ( 0x27 for me),
                                    //use a simple I2C scanner to find out ( have a look here --> http://www.mauroalfieri.it/elettronica/i2c-scanner.html)

void setup()
{
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight
  lcd.setCursor(0, 0);
  lcd.print("Hello"); // Start Print text to Line 1
  lcd.setCursor(0, 1);
  lcd.print("WORLD"); // Start Print Test to Line 2
}

void loop()
{
  // Nothing Absolutely Nothing!
}
```


### Note

If you have problem with address of your I2C ( as I wrote in the comment of above snippet), you can run a simple I2C
 scanner, like this : http://www.mauroalfieri.it/elettronica/i2c-scanner.html, and you will findout.


