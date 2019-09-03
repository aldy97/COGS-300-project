#define RIGHTMOTORA 6 // right 
 #define RIGHTMOTORB 5 // right
 #define LEFTMOTORA 10 // left
 #define LEFTMOTORB 9 // left
 #include <NewPing.h>;

 int left_sen = A0; // A = left
 int center_sen = A1; // B= center
 int right_sen = A2; // C = right
 int ValSens_A = 0;
 int ValSens_B = 0;
 int ValSens_C = 0;

 int vl;
 int vr;
 int vc;
  
 
 // FRONT SENSOR
 #define TRIGGER_FRONT 3
 #define ECHO_FRONT 4

 // LEFT SENSOR
 #define TRIGGER_LEFT 12
 #define ECHO_LEFT 13

 // Max distance
 #define MAX_DISTANCE 200

 NewPing leftsonar (TRIGGER_LEFT, ECHO_LEFT, MAX_DISTANCE);
 NewPing frontsonar(TRIGGER_FRONT, ECHO_FRONT, MAX_DISTANCE);

 #define LEFTTHRESHOLD 1000
 #define FRONTTHRESHOLD 1000
 #define centerThres 100
 #define leftThres 100
 #define rightThres 100
void setup() {

  /*
   * SET YOUR MOTORS AND YOUR SENSORS
   */
   pinMode(RIGHTMOTORA, OUTPUT);
   pinMode(RIGHTMOTORB, OUTPUT);
   pinMode(LEFTMOTORA, OUTPUT);
   pinMode(LEFTMOTORB, OUTPUT);
   pinMode(TRIGGER_FRONT, OUTPUT);
   pinMode(ECHO_FRONT, INPUT);
   pinMode(TRIGGER_LEFT, OUTPUT);
   pinMode(ECHO_LEFT, INPUT);
  
  Serial.begin(9600);
}

void loop(){
 /*
  * CALL YOUR FUNCTIONS
  * EXAMPLE BELOW
  * 
  * // call the forward function for 1 second
  * // the delay is 1000 ms
  * 
  * forward();
  * delay(1000);
  */
  
  vl=analogRead(left_sen);
  vr=analogRead(right_sen);
  vc=analogRead(center_sen);

  if(vl<leftThres || vr<rightThres || vc<centerThres){
    
  if(vl<leftThres && vr<rightThres &&vc<centerThres){
    Forward();
    }
  else{
    if(vl>=leftThres && vr>=rightThres){
     Stop();
      Backward();
      delay(100);
      }
    if(vl>=leftThres){
      Stop();
      Left();
      delay(100);
      }
    if(vr>=rightThres){
      Stop();
      Right();
      delay(100);
      }
  }
  
  }
  
  
  else{
      
    if(frontsonar.ping()>1000){
    Forward();
    delay(100);}
    
    if(frontsonar.ping()<400){
     Stop();
      Backward();
      delay(200);
      if(leftsonar.ping()>1000){
        Stop();
        Left();
        delay(200);}
        else{
          Stop();
          Right();
      delay(300);}
      }
    
    if (leftsonar.ping()<LEFTTHRESHOLD){
 
    if (frontsonar.ping() >= FRONTTHRESHOLD){
    Stop();
    Forward();
    delay(100);}
    

   else {
    Stop();
    Right();
    delay(100);

  }
  }
 
  
 else {
  Stop();
  Left();
  delay(100);

}
}



}
/*
 * WRITE FUNCTIONS HERE
 * EXAMPLE BELOW 
 * 
  */
void Backward() {
  //LEFT MOTOR
  analogWrite(LEFTMOTORA, 100);
  analogWrite(LEFTMOTORB, 0);
  //RIGHT MOTOR
  analogWrite(RIGHTMOTORA, 100);
  analogWrite(RIGHTMOTORB, 0);
        }
void Forward(){
  // LEFT MOTOR
  analogWrite(LEFTMOTORA, 0);
  analogWrite(LEFTMOTORB, 100);
  // RIGHT MOTOR
  analogWrite(RIGHTMOTORA, 0);
  analogWrite(RIGHTMOTORB, 100);
}
void Right(){
  //LEFT MOTOR
  analogWrite(LEFTMOTORA, 0);
  analogWrite(LEFTMOTORB, 100);
  //RIGHT MOTOR
  analogWrite(RIGHTMOTORA, 0);
  analogWrite(RIGHTMOTORB, 0);
  }
 void Left() {
  // LEFT MOTOR
  analogWrite(LEFTMOTORA, 0);
  analogWrite(LEFTMOTORB, 0);
  // RIGHT MOTOR
  analogWrite(RIGHTMOTORA, 0);
  analogWrite(RIGHTMOTORB, 100);
  }
 void Stop() {
  // LEFT MOTOR
  digitalWrite(LEFTMOTORA, 0);
  digitalWrite(LEFTMOTORB, 0);
  // RIGHT MOTOR
  digitalWrite(RIGHTMOTORA, 0);
  digitalWrite(RIGHTMOTORB, 0);}
