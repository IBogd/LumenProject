//initialize libraries
import processing.serial.*;
import twitter4j.conf.*;
import twitter4j.*;
import twitter4j.auth.*;
import twitter4j.api.*;
import java.util.*;

Twitter twitter; //// create instance of Twitter object
Serial port;  // Create object from Serial class
String val; // Data received from the serial port

void setup() 
{
  String portName = Serial.list()[0];
  println(Serial.list());// show which one port you can use
  port = new Serial(this, portName, 9600);
  //Authentication on Twitter
  ConfigurationBuilder cb = new ConfigurationBuilder();
  cb.setOAuthConsumerKey("tdoKaop0q0B5zMNxSiaeg4HCK");
  cb.setOAuthConsumerSecret("XYnwYHO03ic7vRDIezdrTXaVGjkkHk2zW4Ts1U6yxPN9UWxVTf");
  cb.setOAuthAccessToken("3084240857-neyTeeXO2kBtPMJQLtqHJBHE8Fnak67PYFqJPa2");
  cb.setOAuthAccessTokenSecret("A0IndeT9a6hHkgiGC1VvfSrRx5UD2jsBVYXCwxGTBywOu");   
  TwitterFactory tf = new TwitterFactory(cb.build());
  twitter = tf.getInstance();
}

void draw()
{
  if ( port.available() > 0) {  // If data is available,
    val = port.readStringUntil('\n');        // read it and store it in val
    tweet();
  }
  
 }
  
void tweet(){
    if(val != null)
   {
    try 
    {
        Status status = twitter.updateStatus(val);
        System.out.println("Status  to [" + status.getText() + "].");
    }
    catch (TwitterException te)
    {
        System.out.println("Error: "+ te.getMessage()); 
    }
   }
}

