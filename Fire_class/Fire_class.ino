class Fire {
    int ledPin;
    String fireType;
    int ledBrightness;
    int flickerSpeed;
    unsigned long currentMillis;
    unsigned long previousMillis;
    
    // Set the ledBrightness to the type of fire chosen
    int getBrightness(String fireType) {
      if (fireType == "lantern") {
        return random(200) + 55;
      } else if (fireType == "candle") {
        return random(240) + 10;
      } else {
        return random(120) + 135;
      }
    };

    // Get a random flicker rate
    int getFlickerSpeed() {
      return random(100);
    }


  public:
    // pin MUST be a PWM type pin
    // fireType is the type of fire requested: "lantern", "candle" (add more later)
    Fire(int pin, String fireType) {
      ledPin = pin;
      fireType = fireType;
      pinMode(pin, OUTPUT);
      flickerSpeed = getFlickerSpeed();
      currentMillis = 0;
      previousMillis = 0;
      ledBrightness = getBrightness(fireType);
    }

    void flicker() {
      currentMillis = millis();

      if (currentMillis - previousMillis >= flickerSpeed) {
        previousMillis = currentMillis;
        analogWrite(ledPin, ledBrightness);
        flickerSpeed = getFlickerSpeed();
        ledBrightness = getBrightness(fireType);
      }
    }
};


Fire barrelLantern(9, "lantern");
Fire candle(10, "candle");



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  barrelLantern.flicker();
  candle.flicker();
}
