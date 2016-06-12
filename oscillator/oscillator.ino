int coilPin_up=5;
int coilPin_down=9;
int trig=2;
int echo=3;

int freq = 1000;
float Setpoint ;
void setup() {
  pinMode(coilPin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  digitalWrite(echo,LOW);
  
}

float ultrasonic()
{
    digitalWrite(trig,LOW);
    digitalWrite(echo,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig,LOW);

    long double duration = pulseIn(echo,HIGH);
    float distance = duration/2/29.1; 
    return distance ;
}

void checkSerial()
{
  if (Serial.available()){
    char ch=Serial.read();
    if(ch=='s'){
      Setpoint=Setpoint-0.10;
    }
    if(ch='S'){
      Setpoint=Setpoint+0.10;
    }
  }
}

void oscillator(int freq)
{
    while(1)
    {
      digitalWrite(coilPin_up;,1);
      delay(1000/freq);
      digitalWrite(coil_down,1);
      delay(1000/freq);
     }
}

void loop()
{
    float ultrasonic_read = ultrasonic();
    Serial.println(ultrasonic_read);
    if(abs(ultrasonic_read-Setpoint)<2)    
    {
     Serial.print("oscilatting...."); 
     oscillator(freq); 
    }
    checkSerial();
    
  
}
