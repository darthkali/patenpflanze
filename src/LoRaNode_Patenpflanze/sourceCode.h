int getHum(){
  int hum = analogRead(A0);
  hum = 1000 - hum; 
  Serial.println(hum);
  return hum;
}
