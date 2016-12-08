
 
#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 
LiquidCrystal_I2C lcd(0x27, 16, 2);

int blink_time = 100;
int deblink_time = blink_time/2;
 
byte eye[8] = 
{
    B01000,
    B00100,
    B00110,
    B00110,
    B01111,
    B01111,
    B11111,
    B01110
};


byte happy_eye[8] = 
{
    B00000,
    B01110,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001
};

byte blinked_happy_eye[8] = 
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B00000
};

byte half_blinked_eye[8] =
{
    B00000,
    B00000,
    B00000,
    B11110,
    B01111,
    B01111,
    B11111,
    B01110
};

byte blinked_eye[8] =
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B00110,
    B00000
};


byte cute_eyebrows_1[8] =
{
    B00000,
    B00000,
    B00000,
    B00000,
    B00001,
    B00010,
    B00100,
    B00000
};

byte cute_eyebrows_2[8] =
{
    B00000,
    B00000,
    B01110,
    B10001,
    B00000,
    B00000,
    B00000,
    B00000
};

byte cute_eyebrows_3[8] =
{
    B00000,
    B00000,
    B00000,
    B00000,
    B10000,
    B01000,
    B00100,
    B00000
};

byte heart_1[8] =
{
    B01110,
    B11111,
    B11111,
    B01111,
    B00111,
    B00011,
    B00001,
    B00000
};

byte heart_2[8] =
{
    B01110,
    B11111,
    B11111,
    B11110,
    B11100,
    B11000,
    B10000,
    B00000
};


static int y_left_eye_position = 3;
static int y_right_eye_position = 12;
static int x_eye_position = 1;


void setup()
{
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
  
  lcd.createChar(1,eye);
  lcd.createChar(2,blinked_eye);
  lcd.createChar(3,happy_eye);
  lcd.createChar(4,blinked_happy_eye);
  lcd.createChar(5,cute_eyebrows_1);
  lcd.createChar(6,cute_eyebrows_2);
  lcd.createChar(7,cute_eyebrows_3);
  
  //lcd.setCursor(y_left_eye_position, x_eye_position);
  //lcd.write(1);
  //lcd.print("14CORE | 16x2 LCD TEST"); // Start Print text to Line 1
  //lcd.setCursor(y_right_eye_position, x_eye_position);   
  //lcd.write(1);   
  //lcd.print("-----------------------"); // Start Print Test to Line 2
}
void draw_normal_eyebrowns(int startPosizionY, int startPositionX){
    lcd.setCursor(startPosizionY, startPositionX);
    lcd.write(5);
    lcd.setCursor(startPosizionY+1, startPositionX);
    lcd.write(6);
    lcd.setCursor(startPosizionY+2, startPositionX);
    lcd.write(7);
}

void draw_angry_eyebrowns_left(int startPosizionY, int startPositionX){
    //lcd.setCursor(startPosizionY, startPositionX);
    //lcd.write(5);
    lcd.setCursor(startPosizionY+1, startPositionX);
    lcd.write(6);
    lcd.setCursor(startPosizionY+2, startPositionX);
    lcd.write(7);
}

void draw_angry_eyebrowns_right(int startPosizionY, int startPositionX){
    lcd.setCursor(startPosizionY, startPositionX);
    lcd.write(5);
    lcd.setCursor(startPosizionY+1, startPositionX);
    lcd.write(6);
    //lcd.setCursor(startPosizionY+2, startPositionX);
    //lcd.write(7);
}

void draw_cute_eyebrowns_left(int startPosizionY, int startPositionX){
    lcd.setCursor(startPosizionY, startPositionX);
    lcd.write(5);
    lcd.setCursor(startPosizionY+1, startPositionX);
    lcd.write(6);
    //lcd.setCursor(startPosizionY+2, startPositionX);
    //lcd.write(7);
}

void draw_cute_eyebrowns_right(int startPosizionY, int startPositionX){
    //lcd.setCursor(startPosizionY, startPositionX);
    //lcd.write(5);
    lcd.setCursor(startPosizionY+1, startPositionX);
    lcd.write(6);
    lcd.setCursor(startPosizionY+2, startPositionX);
    lcd.write(7);
}
void blinkEyesNormal(){
  lcd.clear();
  for(int i = 1; i<=2; i++){
    lcd.clear(); 
    draw_normal_eyebrowns(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_normal_eyebrowns(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position);   
    lcd.write(i); 
    delay(blink_time);
  } 

  for(int i = 2; i>=1; i--){
    lcd.clear();   
    draw_normal_eyebrowns(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_normal_eyebrowns(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position); 
    lcd.write(i);
    delay(deblink_time);
  } 
}


void blinkHappyEyes(){
  lcd.clear();
  for(int i = 3; i<=4; i++){
    lcd.clear(); 
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    lcd.setCursor(y_right_eye_position, x_eye_position);   
    lcd.write(i); 
    delay(blink_time);
  } 

  for(int i = 4; i>=3; i--){
    lcd.clear();   
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    lcd.setCursor(y_right_eye_position, x_eye_position); 
    lcd.write(i);
    delay(deblink_time);
  } 
}

void blinkEyesHangry(){
  lcd.clear();
  for(int i = 1; i<=2; i++){
    lcd.clear(); 
    draw_angry_eyebrowns_left(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_angry_eyebrowns_right(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position);   
    lcd.write(i); 
    delay(blink_time);
  } 

  for(int i = 2; i>=1; i--){
    lcd.clear();   
    draw_angry_eyebrowns_left(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_angry_eyebrowns_right(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position); 
    lcd.write(i);
    delay(deblink_time);
  } 
}


void blinkEyesCute(){
  lcd.clear();
  for(int i = 1; i<=2; i++){
    lcd.clear(); 
    draw_cute_eyebrowns_left(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_cute_eyebrowns_right(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position);   
    lcd.write(i); 
    delay(blink_time);
  } 

  for(int i = 2; i>=1; i--){
    lcd.clear();   
    draw_cute_eyebrowns_left(y_left_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_left_eye_position, x_eye_position);
    lcd.write(i);
    draw_cute_eyebrowns_right(y_right_eye_position-1,x_eye_position-1);
    lcd.setCursor(y_right_eye_position, x_eye_position); 
    lcd.write(i);
    delay(deblink_time);
  } 
}

void loop(){
  // Just to simulate a normal blinking. With casual timing of delay and casual expression.
  int timeDelay = random(500, 2500);
  int typeBlink = random(1, 5);
  switch(typeBlink){
    case 1 : {
        blinkEyesNormal();
        break;
    }
    case 2 : {
        blinkEyesCute();
        break;
    }
    case 3 : {
        blinkEyesHangry();
        break;
    }
    case 4 : {
        blinkHappyEyes();
        break;
    }
  }
  
  delay(timeDelay);
}
