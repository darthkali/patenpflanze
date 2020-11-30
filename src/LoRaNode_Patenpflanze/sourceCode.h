 int analogInput() {
        static int  analog = analogRead(A0);
        float adin = analogRead(A0)  ;
    
        analog = (analog * 49 + adin) /50;
    
        return analog;
    }

int getHum(){

  
  int hum = analogInput();
  hum = 1000 - hum; 
  Serial.println(hum);
  return hum;
}
