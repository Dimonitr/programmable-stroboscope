int button = 2, v = 0, a = 0, a0 = 0;
//long ar[100], ar2[100], ch[100];
int led = 9;
long long delay_mks = 10, d = 0, c = 0;
long k = 0, kv = 0, kn = 0, kp = 0, kz = 0;
char port1 = 0;





bool mas[256] = {0};
int pos = -1;
byte tmp;
 










void setup() {

pinMode(led, OUTPUT);

pinMode(button, INPUT);
  pinMode(A0, OUTPUT); digitalWrite(A0, 0);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT); digitalWrite(A2, 1);
  pinMode(13, OUTPUT);
  pinMode(1, INPUT);
   Serial.begin(9600);
}

int gate = 0, key = 0;
int ar[5]; 

void loop() {
  if(Serial.available() > 0)
  {
      port1 = Serial.read();
      if((port1 == 'o')&(gate == 0)){
          gate = 1;
          key = 0;
      }
      else
      {
          if((port1 != 'o')&(gate == 1)&(key<4)&(port1 != 'e')){
              ar[k] = port1 - 48; 
              key++;
              digitalWrite(13, LOW);
              delay(1000);
              digitalWrite(13, HIGH);
          }
          else
          {
              if(port1 == 'e')
              {
                  gate = 0;
              digitalWrite(13, LOW);
              delay(100);
              digitalWrite(13, HIGH);
              }    
          }
       }
  }
   if(key == 4){
       d = ar[0]*10000+ar[1]*1000+ar[2]*100+ar[3]*10+ar[4];
       key = 0;
       digitalWrite(13,LOW);
       delay(500);
       digitalWrite(13, HIGH);
   }
   digitalWrite(13,1);
   delay(100);
   digitalWrite(13,0);
   delay(d);
}
