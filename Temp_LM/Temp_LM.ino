/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Temperature Fan LM35**************
***********20-07-2019**************
*/
#define pwm 9
const int sensor=A0; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
int sig;  //variable to store temperature in Fahreinheit 
float vout; 
float perc;
float avg;
float totavg;
long i;//temporary variable to hold sensor reading

void setup()
  {
    pinMode(sensor,INPUT); // Configuring pin A1 as input
    Serial.begin(9600);
    i=2;
    delay(500);
  }
    void loop() 
    {
      vout=analogRead(sensor);
      vout=(vout*500)/1024.0;
      tempc=vout; // Storing value in Degree Celsius
      Serial.print("in Degree Celsius = ");
      Serial.println(tempc);
      sig= map(tempc, 25 , 35, 0 , 255);
      analogWrite(pwm, sig);
      Serial.print("Fan Speed: ");
      perc = (float(sig)/255.0)*100;
      Serial.print(perc);
      Serial.print("% avg = ");
      delay(1000);
      avg=(avg+tempc);
      Serial.println(totavg);
      totavg = avg/i;
      i++;
    }
