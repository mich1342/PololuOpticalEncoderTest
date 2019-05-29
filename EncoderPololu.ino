bool A, B, prevA, prevB;
int state = 0;
int prevstate = -9999;
int Step = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  langkah();
  if(Step < 40){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH); 
  } else if (Step > 40){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}

void langkah(){
  A = digitalRead(A0);
  B = digitalRead(A1);

  switch (state) {
    case 0: // 0 0
      if (state != prevstate) {
        if (prevstate == 3) {
          Serial.println("maju");
          Step = Step + 1;
          Serial.println(Step);
        }
        else if (prevstate == 1) {
          Serial.println("mundur");
          Step = Step - 1;
          Serial.println(Step);
        }
        prevstate = state;
      }

      if (A == 1) {
        state = 1;
      }

      if (B == 1) {
        state = 3;
      }
      break;

    case 1: // 1 0
      if (state != prevstate) {
        if (prevstate == 0) {
          Serial.println("maju");
          Step = Step + 1;
          Serial.println(Step);
        }
        else if (prevstate == 2) {
          Serial.println("mundur");
          Step = Step - 1;
          Serial.println(Step);
        }
        prevstate = state;
      }

      if (B == 1) {
        state = 2;
      }
      if (A == 0) {
        state = 0;
      }
      break;

    case 2: // 1 1
      if (state != prevstate) {
        if (prevstate == 1) {
          Serial.println("maju");
          Step = Step + 1;
          Serial.println(Step);
        }
        else if (prevstate == 3) {
          Serial.println("mundur");
          Step = Step - 1;
          Serial.println(Step);
        }
        prevstate = state;
      }

      if (A == 0) {
        state = 3;
      }
      if (B == 0) {
        state = 1;
      }
      break;

    case 3: // 0 1
      if (state != prevstate) {
        if (prevstate == 2) {
          Serial.println("maju");
          Step = Step + 1;
          Serial.println(Step);
          
        }
        else if (prevstate == 0) {
          Serial.println("mundur");
          Step = Step - 1;
          Serial.println(Step);
        }
        prevstate = state;
      }

      if (B == 0) {
        state = 0;
      }
      if(A == 1){
        state = 2;
      }
      break;
  }
}
