#include <LiquidCrystal.h> // initialize the library with the numbers of the interface pins

LiquidCrystal lcd(8,9,4,5,6,7); // LCD connected to 8, 9, 4, 5, 6, 7 pins

int led1 = 13; // LED connected to digital pin 13
int photocellPin0 = 0; // Photocell connected to analog pin 0
int minLight0, maxLight0, lightLevel0,adjustedLightLevel0; // initialize max min and light level
int photocellPin1 = 1; // Photocell connected to analog pin 1
int minLight1, maxLight1, lightLevel1,adjustedLightLevel1; // initialize max min and light level

int led2 = 12; // LED connected to digital pin 12
int photocellPin2 = 2; // Photocell connected to analog pin 2
int minLight2, maxLight2, lightLevel2,adjustedLightLevel2; // initialize max min and light level
int photocellPin3 = 3; // Photocell connected to analog pin 3
int minLight3, maxLight3, lightLevel3,adjustedLightLevel3; // initialize max min and light level

int led3 = 11; // LED connected to digital pin 11
int photocellPin4 = 4; // Photocell connected to analog pin 4
int minLight4, maxLight4, lightLevel4,adjustedLightLevel4; // initialize max min and light level
int photocellPin5 = 5; // Photocell connected to analog pin 5
int minLight5, maxLight5, lightLevel5,adjustedLightLevel5; // initialize max min and light level

unsigned long previousMillis1 = 0;        // will store last time LED was updated
long onTime1 = 0;           // milliseconds of on-time
int rand1 = 0; // define random variable

unsigned long previousMillis2 = 0;        // will store last time LED was updated
long onTime2 = 0;           // milliseconds of on-time
int rand2 = 0; // define random variable

unsigned long previousMillis3 = 0;        // will store last time LED was updated
long onTime3 = 0;           // milliseconds of on-time
int rand3 = 0; // define random variable

unsigned long previousMillis4 = 0; 
long onTime4 = 10000;

int p1 = 0; // intiailize player 1 score to start from 0
int p2 = 0; // // intiailize player 2 score to start from 0

//initialise boolean values needed in future
boolean a = true;
boolean b = true;
boolean c = true;
boolean d = true;
boolean e = true;
boolean f = true;

int x,y,z,g,r,t,o,p = 0; // initialise int values needed in future

String stringOne =  String("P1: "); //output score for player 1 
String stringTwo =  String("P2: "); //output score for player 2
String player1 = String("P1 Score: ");
String player2 = String("P2 Score: ");

void setup()
{
  Serial.begin(9600); 
  Serial.println("The game is starting. Good Luck!!!");
  pinMode(led1, OUTPUT); // initialize the digital pin as an output.
  pinMode(photocellPin0, INPUT); // initialize the photocell pin as an input
  pinMode(photocellPin1, INPUT); // initialize the photocell pin as an input
  
  pinMode(led2, OUTPUT); // initialize the digital pin as an output.
  pinMode(photocellPin2, INPUT); // initialize the photocell pin as an input
  pinMode(photocellPin3, INPUT); // initialize the photocell pin as an input
  
  pinMode(led3, OUTPUT); // initialize the digital pin as an output.
  pinMode(photocellPin4, INPUT); // initialize the photocell pin as an input
  pinMode(photocellPin5, INPUT); // initialize the photocell pin as an input
  
  lightLevel0 = analogRead(photocellPin0);  // set up starting light levels
  lightLevel1 = analogRead(photocellPin1);  // set up starting light levels
  lightLevel2 = analogRead(photocellPin2);  // set up starting light levels
  lightLevel3 = analogRead(photocellPin3);  // set up starting light levels
  lightLevel4 = analogRead(photocellPin4);  // set up starting light levels
  lightLevel5 = analogRead(photocellPin5);  // set up starting light levels
  
  minLight0 = lightLevel0-20; //initialize min light = light level - (20)
  minLight1 = lightLevel1-20; //initialize min light = light level - (20)
  minLight2 = lightLevel2-20; //initialize min light = light level - (20)
  minLight3 = lightLevel3-20; //initialize min light = light level - (20)
  minLight4 = lightLevel4-20; //initialize min light = light level - (20)
  minLight5 = lightLevel5-20; //initialize min light = light level - (20)
  
  maxLight0 = lightLevel0; // initialize max light  = light level
  maxLight1 = lightLevel1; // initialize max light  = light level
  maxLight2 = lightLevel2; // initialize max light  = light level
  maxLight3 = lightLevel3; // initialize max light  = light level
  maxLight4 = lightLevel4; // initialize max light  = light level
  maxLight5 = lightLevel5; // initialize max light  = light level
  
  lcd.begin(16,2); // begin lcd at values 16,2
  
  randomSeed(analogRead(0)); //randomize
  }
// the loop routin ve runs over and over again forever
void loop()
{
  unsigned long currentMillis1 = millis(); // check to see if it's time to change the state of the LED
  unsigned long currentMillis2 = millis(); // check to see if it's time to change the state of the LED
  unsigned long currentMillis3 = millis(); // check to see if it's time to change the state of the LED
  unsigned long currentMillis4 = millis();
  
  lightLevel0 = analogRead(photocellPin0);  // adjust the max and minimum in real time
  if(minLight0>lightLevel0) minLight0 = lightLevel0;
  if(maxLight0<lightLevel0)maxLight0=lightLevel0;
  adjustedLightLevel0 = map(lightLevel0, minLight0, maxLight0, 0, 100); // map function
  
  lightLevel1 = analogRead(photocellPin1);  // set up starting light levels
  if(minLight1>lightLevel1) minLight1 = lightLevel1;
  if(maxLight1 < lightLevel1) maxLight1=lightLevel1;
  adjustedLightLevel1 = map(lightLevel1, minLight1, maxLight1, 0, 100); // map function
  
  lightLevel2 = analogRead(photocellPin2);  // set up starting light levels
  if(minLight2>lightLevel2) minLight2 = lightLevel2;
  if(maxLight2 < lightLevel2) maxLight2=lightLevel2;
  adjustedLightLevel2 = map(lightLevel2, minLight2, maxLight2, 0, 100); // map function
  
  lightLevel3 = analogRead(photocellPin3);  // set up starting light levels
  if(minLight3>lightLevel3) minLight3 = lightLevel3;
  if(maxLight3 < lightLevel3) maxLight3=lightLevel3;
  adjustedLightLevel3 = map(lightLevel3, minLight3, maxLight3, 0, 100); // map function
  
  lightLevel4 = analogRead(photocellPin4);  // set up starting light levels
  if(minLight4>lightLevel4) minLight4 = lightLevel4;
  if(maxLight4 < lightLevel4) maxLight4=lightLevel4;
  adjustedLightLevel4 = map(lightLevel4, minLight4, maxLight4, 0, 100); // map function
  
  lightLevel5 = analogRead(photocellPin5);  // set up starting light levels
  if(minLight5>lightLevel5) minLight5 = lightLevel5;
  if(maxLight5 < lightLevel5) maxLight5=lightLevel5;
  adjustedLightLevel5 = map(lightLevel5, minLight5, maxLight5, 0, 100); // map function
  
  if ((adjustedLightLevel1 < 25 && led1 != LOW)||(adjustedLightLevel0 < 25 && led1 != LOW))
  {
    rand1 = random(750,2500); //randomize between 0.75 and 2.5 seconds
    onTime1 = rand1;
    digitalWrite(led1,LOW); // turn the LED off by making the voltage LOW
    previousMillis1 = currentMillis1;
  }
  if ((adjustedLightLevel2 < 25 && led2 != LOW)||(adjustedLightLevel3 < 25 && led2 != LOW))
  {
    rand2 = random(750,2500);
    onTime2 = rand2; //randomize between 0.75 and 2.5 seconds
    digitalWrite(led2,LOW); // turn the LED off by making the voltage LOW
    previousMillis2 = currentMillis2;
   }
  if ((adjustedLightLevel4 < 25 && led3 != LOW)||(adjustedLightLevel5 < 25 && led3 != LOW))
  {
    rand3 = random(750,2500);
    onTime3 = rand3; //randomize between 0.75 and 2.5 seconds
    digitalWrite(led3,LOW); // turn the LED off by making the voltage LOW
    previousMillis3 = currentMillis3;
  }
  if(currentMillis1 - previousMillis1 >= onTime1)
  {
    digitalWrite(led1,HIGH); // turn the LED on (HIGH is the voltage level)
    a = true;
    
  }
  if(currentMillis2 - previousMillis2 >= onTime2)
  {
    digitalWrite(led2,HIGH); // turn the LED on (HIGH is the voltage level)
    b = true; 
  }
  if(currentMillis3 - previousMillis3 >= onTime3)
  {
    digitalWrite(led3,HIGH); // turn the LED on (HIGH is the voltage level)
    c = true; 
  }
  
  if(p1==10) 
  {
    for(r==0; r==0 ; r++)
    {
      Serial.println("First Player earned 10 points");
    }
  }
  if(p2==10)
  {
    for(t==0; t==0 ; t++)
    {
      Serial.println("Second Player earned 10 points");
    }
  }
  if(p1==25)
  {
    for(o==0; o==0 ; o++)
    {
      Serial.println("Congratulations!!! First player earned 25 points and won the game!!!");
    }
  }
  if(p2==25) 
  {
    for(p==0; p==0 ; p++)
    {
      Serial.println("Congratulations!!! Second player earned 25 points and won the game!!!");
    }
  }
  while (p1 >= 25 || p2 >= 25)
  {
    for (g==0; g==0; g++)
    {
      Serial.println("Game Over!!! Good Luck next time");
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    }
  }
  score(); // call method score
}
// This method checks light values on different sensors and in right cases calls such methods as player1Score, player2Score, player1Score1 and player2Score2 
void score()
{
  if (a == true && adjustedLightLevel0  <25) // if light is on and adjusted light level is less than 25
  {
    player1Score(); //call method player1Score
    x=1;
    delay(500); // wait 0.5 seconds
  }
  else if (a == true && adjustedLightLevel1  <25)
  {
    player2Score(); //call method player2Score
    x=1;
    delay(500); // wait 0.5 seconds
  }
  else if (b == true && adjustedLightLevel2  <25)
  {
    player1Score();
    y=1;
    delay(500); // wait 0.5 seconds
  }
  else if (b == true && adjustedLightLevel3  <25)
  {
    player2Score();
    y=1;
    delay(500); // wait 0.5 seconds
  }
  else if (c == true && adjustedLightLevel4  <25)
  {
    player1Score();
    z=1;
    delay(500); // wait 0.5 seconds
  }
  else if (c == true && adjustedLightLevel5  <25)
  {
    player2Score();
    z=1;
    delay(500); // wait 0.5 seconds
  }
  else if (d == true && adjustedLightLevel0  <25) // if light is off and agjusted light level is less than 25
  {
    for(x==1; x==1; x++)
    {
      player1Score1(); //call method player1Score1 only one time
    }  
  }
  else if (d == true && adjustedLightLevel1  <25)
  {
    for(x==1; x==1; x++)
    {
      player2Score1(); //call method player2Score1 only one time 
    }
  }
  else if (e == true && adjustedLightLevel2  <25)
  {
    for(y==1; y==1; y++)
    {
      player1Score1();
    }
  }
  else if (e == true && adjustedLightLevel3  <25)
  {
    for(y==1; y==1; y++)
    {
      player2Score1();
    } 
  }
  else if (f == true && adjustedLightLevel4  <25)
  {
    for(z==1; z==1; z++)
    {
      player1Score1();
    }
  }
  else if (f == true && adjustedLightLevel5  <25)
  {
    for(z==1; z==1; z++)
    {
      player2Score1();
    }
  }
}
// this method counts + points to the player's one score
void player1Score()
{
  p1=p1+1;
  lcd.setCursor(0,0); // set cursor on the first line
  lcd.print(stringOne);
  lcd.print(p1);  
  lcd.setCursor(0,1); // set cursor on the second line
  lcd.print(stringTwo);
  lcd.print(p2); 
  a = false;
  b = false;
  c = false;
}
// this method counts + points to the player's two score
void player2Score()
{
  p2=p2+1;
  lcd.setCursor(0,0); // set cursor on the first line
  lcd.print(stringOne);
  lcd.print(p1);
  lcd.setCursor(0,1); // set cursor on the secoind line
  lcd.print(stringTwo);
  lcd.print(p2);
  //Serial.println(stringTwo + p2);
  a = false;
  b = false;
  c = false;
}
// this method counts - points to the player's one score
void player1Score1()
{
  p1=p1-1;
  lcd.setCursor(0,0); // set cursor on the first line
  lcd.print(stringOne);
  lcd.print(p1);  
  lcd.setCursor(0,1); // set cursor on the second line
  lcd.print(stringTwo);
  lcd.print(p2);  
  d = true;
  e = true;
  f = true;
}
// this method counts - points to the player's two score
void player2Score1()
{
  p2=p2-1;
  lcd.setCursor(0,0); // set cursor on the first line
  lcd.print(stringOne);
  lcd.print(p1);
  lcd.setCursor(0,1); // set cursor on the second line
  lcd.print(stringTwo);
  lcd.print(p2);
  d = true;
  e = true;
  f = true;
}
  
