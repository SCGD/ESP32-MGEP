/*
 * Working Towards a gerneric Main Input Display
 * 
 * 
 */

#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h> // SPI main Library


TFT_eSPI tft = TFT_eSPI();  // Invoke library

const int RIGHTBUTTON = 12;
const int MIDBUTTON = 13;
const int LEFTBUTTON = 14;


int screenTextFill = 11; // This can be found out by code but for the time I am setting a constant
int typedText = 0;
void setup() 
{
  tft.init();
  tft.setRotation(0);

  pinMode(LEFTBUTTON, INPUT);
  pinMode(MIDBUTTON, INPUT);
  pinMode(RIGHTBUTTON, INPUT);
}

void loop() 
{
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.println("Button Output Display");

  tft.setTextColor(TFT_YELLOW);
  tft.setTextFont(4);
  
  while(true)
  {
    if (digitalRead(RIGHTBUTTON) == 1)
    {
      while(digitalRead(RIGHTBUTTON) == 1);
      tft.println("RIGHT Pressed");
      typedText++;
    }
    if (digitalRead(MIDBUTTON) == 1)
    {
      while(digitalRead(MIDBUTTON) == 1);
      tft.println("MIDDLE Pressed");
      typedText++;
    }
    if (digitalRead(LEFTBUTTON) == 1)
    {
      while(digitalRead(LEFTBUTTON) == 1);
      tft.println("LEFT Pressed");
      typedText++;
    }
    if (typedText == screenTextFill)
    {
      typedText = 0;
      break;
    }
  }
  

}
