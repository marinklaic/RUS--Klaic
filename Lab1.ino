#define BUTTON0 18
#define BUTTON1 19
#define BUTTON2 21

#define LED0 2
#define LED1 4
#define LED2 5
#define LED_TIMER 15
#define LED_ALERT 13

#define TRIG_PIN 22
#define ECHO_PIN 23

volatile bool flag0 = false;
volatile bool flag1 = false;
volatile bool flag2 = false;
volatile bool timerFlag = false;

hw_timer_t *timer = NULL;

void IRAM_ATTR ISR_INT0() { flag0 = true; }
void IRAM_ATTR ISR_INT1() { flag1 = true; }
void IRAM_ATTR ISR_INT2() { flag2 = true; }

void IRAM_ATTR onTimer() {
  timerFlag = true;
}

void setup() {
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED_TIMER, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED_TIMER, LOW);
  digitalWrite(LED_ALERT, LOW);

  attachInterrupt(BUTTON0, ISR_INT0, FALLING);
  attachInterrupt(BUTTON1, ISR_INT1, FALLING);
  attachInterrupt(BUTTON2, ISR_INT2, FALLING);

  timer = timerBegin(1000000);
  timerAttachInterrupt(timer, &onTimer);
  timerWrite(timer, 0);
  timerAlarm(timer, 1000000, true, 0);

  Serial.begin(115200);
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

void loop() {

  if (timerFlag) {
    digitalWrite(LED_TIMER, HIGH);
    delay(100);
    digitalWrite(LED_TIMER, LOW);
    timerFlag = false;
    return;
  }

  float distance = measureDistance();

  if (distance > 0 && distance < 100) {
    digitalWrite(LED_ALERT, HIGH);
  } else {
    digitalWrite(LED_ALERT, LOW);
  }

  if (flag0) {
    digitalWrite(LED0, HIGH);
    delay(200);
    digitalWrite(LED0, LOW);
    flag0 = false;
  }
  else if (flag1) {
    digitalWrite(LED1, HIGH);
    delay(200);
    digitalWrite(LED1, LOW);
    flag1 = false;
  }
  else if (flag2) {
    digitalWrite(LED2, HIGH);
    delay(200);
    digitalWrite(LED2, LOW);
    flag2 = false;
  }
}