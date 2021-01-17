char* const getButtonPhrase()
{
  static char buttonSentence[4]; // if 3 buttons pressed return "ABC" and need space for trailing '\0'

  static uint8_t previousA = 0xFF;
  static uint8_t previousB = 0xFF;
  static uint8_t previousC = 0xFF;
  static uint8_t previousD = 0xFF;
  static uint8_t previousE = 0xFF;
  static uint8_t previousF = 0xFF;
  

  uint8_t currentA, currentB, currentC, currentD, currentE, currentF;

  currentA = digitalRead(33);
  currentB = digitalRead(35);
  currentC = digitalRead(34);
  currentD = digitalRead(32);
  currentE = digitalRead(25);
  currentF = digitalRead(26);

  memset(buttonSentence, '\0', 4); // erase previous sentence

  // check if HIGH to LOW transition
  if ((currentA == LOW) && (previousA == HIGH)) strcat(buttonSentence, "A");
  if ((currentB == LOW) && (previousB == HIGH)) strcat(buttonSentence, "B");
  if ((currentC == LOW) && (previousC == HIGH)) strcat(buttonSentence, "C");
  if ((currentD == LOW) && (previousD == HIGH)) strcat(buttonSentence, "D");
  if ((currentE == LOW) && (previousE == HIGH)) strcat(buttonSentence, "E");
  if ((currentF == LOW) && (previousF == HIGH)) strcat(buttonSentence, "F");

  previousA = currentA;
  previousB = currentB;
  previousC = currentC;
  previousD = currentD;
  previousE = currentE;
  previousF = currentF;

  return buttonSentence;
}

void setup()
{
  pinMode(33, INPUT_PULLUP); // 2 <<--->> button <<--->> GND
  pinMode(25, INPUT_PULLUP); // 3 <<--->> button <<--->> GND
  pinMode(32, INPUT_PULLUP); // 4 <<--->> button <<--->> GND
  pinMode(35, INPUT_PULLUP); // 4 <<--->> button <<--->> GND
  pinMode(26, INPUT_PULLUP); // 4 <<--->> button <<--->> GND
  pinMode(34, INPUT_PULLUP); // 4 <<--->> button <<--->> GND

  Serial.begin(115200);
}

void loop()
{
  char* const s = getButtonPhrase();
  if (strlen(s) != 0) Serial.println(s);
  delay(50); // will also serve as anti-bounce
}
