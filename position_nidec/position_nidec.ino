// These two has to be interrupt pins.
#define ENCA 19 //21-PD0 //19-RX1
#define ENCB 18 //20-PD1 //18-TX1

int pos=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  //pinMode(brake, OUTPUT);
  //digitalWrite(brake, LOW);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly
  Serial.println(pos);
}

void readEncoder(){
  //Serial.print("read encoder");
  int b=digitalRead(ENCB);
  if (b>0){
    pos++;
  }
  else{
    pos--;
  }
}
