/*
Hello world! Today i made a Open Source C# Windows application to control 8 relays, in the video i just used 4 relays because my 8 channel relays are in use. 
The code for arduino and the C# code are both coded to control 8 relays, you can add more yourself if you like because the source is open to modify.
The arduino code is very simple, You just build the arduino device upload the code and plug it into the usb, choose the com port on the windows app and connect it.

(I used visual studio 2013 for this.)

Files you modify in the C# source are the following. Form1.cs & Form.1Designer.cs

To modify the look of the Application you simply double click on Form1.cs and the Form1.cs [Design] should pop up. 
You can now drag and drop buttons and whatever you want from the toolbox, and change background in the properties etc. 
If adding a button for example, double click the button to give it a function, Double clicking it will bring you to the part of the code that belongs to the button. 
I made a few buttons that direct to my FB, instructables and YouTube channel as example. You can find it at the bottom in Form1.cs

private void button4_Click(object sender, EventArgs e) { System.Diagnostics.Process.Start("https://www.facebook.com/ArduinoProjects101/"); }

You can also change the about box by double clicking on the about box AboutBox1.cs, You can change background, font, colors etc.

To change company name, version etc. you can double click Properties in the [solution explorer]. And then at [application] click on [assembly information], 
you can also modify AssemblyInfo.cs directly.

Buy sensors here: http://arduinosensors.nl

See more on my blog! http://blog.arduinosensors.nl/
 */

#include <LiquidCrystal.h> // comment when using I2C
//#include <LiquidCrystal_I2C.h>//uncomment when using a I2C instead of lcd shield.

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";

int Relay1Pin = 19; // if you are using a UNO instead of a mega change these pins
int Relay2Pin = 20;
int Relay3Pin = 21;
int Relay4Pin = 22;
int Relay5Pin = 23;
int Relay6Pin = 24;
int Relay7Pin = 25;
int Relay8Pin = 26;

boolean isConnected = false;

LiquidCrystal lcd(8,9,4,5,6,7); //for use with a lcd shield

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //for use with a 16x2 screen instead of a LCD shield

//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);// Uncomment when using a I2C instead of LCD shield
//make sure you set the right adress. here are the most common ones.
//PCF8574 = 0x20, PCF8574A = 0x38, PCF8574AT = 0x3F.


void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2); 
  lcd.setCursor(0,0); 
  lcd.print("BlUECORE TECH");
  lcd.setCursor(0,2); 
  lcd.print("HOME AUTOMATION");
  delay(3000);
  
  pinMode(Relay1Pin,OUTPUT);
  pinMode(Relay2Pin,OUTPUT);
  pinMode(Relay3Pin,OUTPUT);
  pinMode(Relay4Pin,OUTPUT);
  pinMode(Relay5Pin,OUTPUT);
  pinMode(Relay6Pin,OUTPUT);
  pinMode(Relay7Pin,OUTPUT);
  pinMode(Relay8Pin,OUTPUT);
  initDisplay();
}

void loop() {

if(stringComplete)
{
  stringComplete = false;
  getCommand();
  
  if(commandString.equals("STAR"))
  {
    lcd.clear();
    lcd.print("Connected");
  }
  if(commandString.equals("STOP"))
  {
    turnLedOff(Relay1Pin);
    turnLedOff(Relay2Pin);
    turnLedOff(Relay3Pin);
    turnLedOff(Relay4Pin);
    turnLedOff(Relay5Pin);
    turnLedOff(Relay6Pin);
    turnLedOff(Relay7Pin);
    turnLedOff(Relay8Pin);
    lcd.clear();
    lcd.print("Not Connected");    
  }
  else if(commandString.equals("TEXT"))
  {
    String text = getTextToPrint();
    printText(text);
  }
  ///////////////////////////////////////////////
  else if(commandString.equals("LED1"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay1Pin);
      lcd.clear();
      lcd.print("LAMP1 ON");
    }else
    {
      turnLedOff(Relay1Pin);
      lcd.clear();
      lcd.print("LAMP1 OFF");
    }   
  }
  ///////////////////////////////////////////////
    else if(commandString.equals("LED2"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay2Pin);
      lcd.clear();
      lcd.print("LAMP2 ON");
    }else
    {
      turnLedOff(Relay2Pin);
      lcd.clear();
      lcd.print("LAMP2 OFF");
    }   
  }
  ///////////////////////////////////////////////
    else if(commandString.equals("LED3"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay3Pin);
      lcd.clear();
      lcd.print("LAMP3 ON");
    }else
    {
      turnLedOff(Relay3Pin);
      lcd.clear();
      lcd.print("LAMP3 OFF");
    }   
  }
  ///////////////////////////////////////////////
    else if(commandString.equals("LED4"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay4Pin);
      lcd.clear();
      lcd.print("LAMP4 ON");
    }else
    {
      turnLedOff(Relay4Pin);
      lcd.clear();
      lcd.print("LAMP4 OFF");
    }   
  }
  ///////////////////////////////////////////////
    else if(commandString.equals("LED5"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay5Pin);
      lcd.clear();
      lcd.print("LAMP5 ON");
    }else
    {
      turnLedOff(Relay5Pin);
      lcd.clear();
      lcd.print("LAMP5 OFF");
    }   
  }
  /////////////////////////////////////////////
    else if(commandString.equals("LED6"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay6Pin);
      lcd.clear();
      lcd.print("LAMP6 ON");
    }else
    {
      turnLedOff(Relay6Pin);
      lcd.clear();
      lcd.print("LAMP6 OFF");
    }   
  }
  /////////////////////////////////////////////
    else if(commandString.equals("LED7"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay7Pin);
      lcd.clear();
      lcd.print("LAMP7 ON");
    }else
    {
      turnLedOff(Relay7Pin);
      lcd.clear();
      lcd.print("LAMP7 OFF");
    }   
  }
  /////////////////////////////////////////////
    else if(commandString.equals("LED8"))
  {
    boolean LedState = getLedState();
    if(LedState == true)
    {
      turnLedOn(Relay8Pin);
      lcd.clear();
      lcd.print("LAMP8 ON");
    }else
    {
      turnLedOff(Relay8Pin);
      lcd.clear();
      lcd.print("LAMP8 OFF");
    }   
  }
  /////////////////////////////////////////////
    
  inputString = "";
}

}

void initDisplay()
{
  lcd.begin(16, 2);
  lcd.print("Not Connected");
}

boolean getLedState()
{
  boolean state = false;
  if(inputString.substring(5,7).equals("ON"))
  {
    state = true;
  }else
  {
    state = false;
  }
  return state;
}

void getCommand()
{
  if(inputString.length()>0)
  {
     commandString = inputString.substring(1,5);
  }
}

void turnLedOn(int pin)
{
  digitalWrite(pin,HIGH);
}

void turnLedOff(int pin)
{
  digitalWrite(pin,LOW);
}


String getTextToPrint()
{
  String value = inputString.substring(5,inputString.length()-2);
  return value;
}

void printText(String text)
{
  lcd.clear();
  lcd.setCursor(0,0);
    if(text.length()<16)
    {
      lcd.print(text);
    }else
    {
      lcd.print(text.substring(0,16));
      lcd.setCursor(0,1);
      lcd.print(text.substring(16,32));
    }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
