int button = 2, v = 0, a = 0, a0 = 0;
long ar[100], ar2[100], ch[100];
int led = 9;
long long delay_mks = 10, d = 0, c = 0;
long k = 0, kv = 0, kn = 0, kp = 0, kz = 0;
void setup() {

pinMode(led, OUTPUT);

pinMode(button, INPUT);
  pinMode(A0, OUTPUT); digitalWrite(A0, 0);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT); digitalWrite(A2, 1);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(1, INPUT);
}

void loop() {
  digitalWrite(11, 1);
    delayMicroseconds(1500);
    digitalWrite(11, 0);
    if(digitalRead(8) == HIGH){
      long n = 1000000/(map(analogRead(A1), 0, 1024, 10, 1000000));
      Serial.println((long)n);
    }
    if(v==0){
    a = analogRead(A1);
    if(a<=100){
      delay_mks = map(a, 0, 10, 100, 1000);
      delayMicroseconds(delay_mks);
    }
    else{
      d = map(a, 100, 1024, 1, 1000);
      delay(d);
    }
     if (digitalRead(10) == HIGH) {
      v = 1;
      kn = map(analogRead(A1), 0, 1024, 10, 1000000);
    while(digitalRead(10) == HIGH);
    }
    }
    else
    if(v==1){
        a = analogRead(A1);
    if(a<=100){
      delay_mks = map(a, 0, 10, 100, 1000);
      delayMicroseconds(delay_mks);
    }
    else{
      d = map(a, 100, 1024, 1, 1000);
      delay(d);
    }
     if (digitalRead(10) == HIGH) {
      v = 2;
      kv = map(analogRead(A1), 0, 1024, 10, 1000000);
    while(digitalRead(10) == HIGH);
    }
    }
    else{
      if(v == 2){
      k = kn - kv;
      kp = 1000000/k;
      Serial.println((long)kp);
      kz = k/1000;
      if(k < 10000){
        delayMicroseconds(k);
      }
      else{
        delay(kz);
      }
      a0 = analogRead(A1);
      v = 3;
      }
      else{
        if(k < 10000){
        delayMicroseconds(k);
      }
      else{
        delay(kz);
      }
      a0 = analogRead(A1) - a0;
      delayMicroseconds(a0);
      }
    }
}

