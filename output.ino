int left_front_forward = 5;
int left_front_backward = 4;
int right_front_forward = 2;
int right_front_backward = 6;
int left_back_forward = 9;
int left_back_backward = 10;
int right_back_forward = 11;
int right_back_backward = 12;
int echoUS = A5;
int triggerUS = A4;
int timeUS = 0;
int distanceUS = 0;

void setup() {
    // put your setup code here, to run once:
pinMode(left_front_forward,OUTPUT);
pinMode(left_front_backward,OUTPUT);
pinMode(right_front_forward,OUTPUT);
pinMode(right_front_backward,OUTPUT);
pinMode(left_back_forward,OUTPUT);
pinMode(left_back_backward,OUTPUT);
pinMode(right_back_forward,OUTPUT);
pinMode(right_back_backward,OUTPUT);
pinMode(echoUS,INPUT);
pinMode(triggerUS,OUTPUT);

}
int get_US() {
digitalWrite(triggerUS, LOW);
   delayMicroseconds(2);
   digitalWrite(triggerUS, HIGH);
   delayMicroseconds(10);
   digitalWrite(triggerUS, LOW);
   timeUS = pulseIn(echoUS, HIGH);
   distanceUS = timeUS / 58;  return distanceUS;
}

void set_engine(int direction) {
if (direction == 0) {
  digitalWrite(left_front_forward, 0);
   digitalWrite(left_front_backward, 0);
   digitalWrite(right_front_forward, 0);
   digitalWrite(right_front_backward, 0);
   digitalWrite(left_back_forward, 0);
   digitalWrite(left_back_backward, 0);
   digitalWrite(right_back_forward, 0);
   digitalWrite(right_back_backward, 0);
   Serial.print("STOP! ");
   } else if (direction == 1) {
  digitalWrite(left_front_forward, 0);
   digitalWrite(left_front_backward, 1);
   digitalWrite(right_front_forward, 0);
   digitalWrite(right_front_backward, 1);
   digitalWrite(left_back_forward, 0);
   digitalWrite(left_back_backward, 1);
   digitalWrite(right_back_forward, 0);
   digitalWrite(right_back_backward, 1);
   Serial.print("Forward");
   }
}

void loop() {
    // put your main code here, to run repeatedly:
   if (get_US() < 10) {
  set_engine(0);
   } else {
   set_engine(1);
   }
}
