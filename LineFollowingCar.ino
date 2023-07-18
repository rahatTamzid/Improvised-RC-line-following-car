#define left_sensor D1
#define right_sensor D2
#define front D7
#define back D8
#define left D4
#define right D3
#define echo D5
#define trig D6

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;


void setup() {

  Serial.begin(115200); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor,INPUT);
  pinMode(front,OUTPUT);
  pinMode(back,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);


}

void loop() {
  int left_sensor_status = digitalRead(left_sensor);
  int right_sensor_status = digitalRead(right_sensor);


 digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trig on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Reads the echo, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;

Serial.println(distanceCm);

if(distanceCm >=5){
  if(left_sensor_status==1 && right_sensor_status==1){

     Serial.println("Going Forward ");
     digitalWrite(left,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(front,LOW);
  
 
   }
   else if(left_sensor_status==1 && right_sensor_status==0){
      Serial.println(" Going Right");
    digitalWrite(left,HIGH);
     digitalWrite(right,LOW);
     digitalWrite(back,HIGH);
     digitalWrite(front,LOW);
   }else if(left_sensor_status==0 && right_sensor_status==1){
      Serial.println(" Going Left");
    digitalWrite(left,LOW);
     digitalWrite(right,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(front,LOW);
   }else if(left_sensor_status==0 && right_sensor_status==0){
    Serial.println(" No Object Car Stop");
    digitalWrite(left,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(front,HIGH);
   }

}else{
    
    Serial.println("Object Detected Car Stop");
    digitalWrite(left,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(front,HIGH);

}

 
   
   
   



}
