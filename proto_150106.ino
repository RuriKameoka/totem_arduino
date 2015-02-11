/*
int Trig = 2;
 int Echo = 3;
 int Duration;
 float Distance;
 int IntDistance; //convert float into int
 */

int Trig[3];
int Echo[3];
int Duration[3];
float Distance[3];
int IntDistance[3];

void setup() {
  Serial.begin(9600);
  
  for(int i=0; i<3; i++){
    Trig[i] = i * 2 + 2;
    Echo[i] = i * 2 + 3;
    pinMode(Trig[i],OUTPUT);
    pinMode(Echo[i],INPUT);
  }
  /*
  Trig[0] = 2;
  Echo[0] = 3;
  pinMode(Trig[0], OUTPUT);
  pinMode(Echo[0], INPUT);
  Trig[1] = 4;
  Echo[1] = 5;
  pinMode(Trig[1], OUTPUT);
  pinMode(Echo[1], INPUT);
  Trig[2] = 6;
  Echo[2] = 7;
  pinMode(Trig[2], OUTPUT);
  pinMode(Echo[2], INPUT);
  */
}

void loop() {
  for(int i=0; i<3; i++){
    digitalWrite(Trig[i],LOW);
    delayMicroseconds(1);
    digitalWrite(Trig[i],HIGH);
    delayMicroseconds(1);
    digitalWrite(Trig[i],LOW);
    Duration[i] = pulseIn(Echo[i],HIGH);
    if (Duration[i]>0) {
      Distance[i] = Duration[i]/2;
      Distance[i] = Distance[i]*340*100/1000000; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us 
      IntDistance[i] = (int) Distance[i];
      //Serial.write(IntDistance);
      //Serial.println(IntDistance[i]);
    }
  }
  Serial.print(IntDistance[0]);
  Serial.print(",");
  Serial.print(IntDistance[1]);
  Serial.print(",");
  Serial.println(IntDistance[2]);
  delay(1000);
}

