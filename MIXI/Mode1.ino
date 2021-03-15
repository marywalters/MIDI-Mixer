//Mode 1 - 2nd Mode

boolean mode1LEDs = false;
boolean mode1Toggle[] = {false, false, false, false, false, false};


int mode1Pots[] = {0, 0, 0, 0};
int mode1PotTol = 5;

void mode1() {
  if (!mode1LEDs) {
    mode1LEDs = true;
    animation();
  }

  for (int i = 0; i < 8; i++) {
    int thisButton = buttonStates[i];
    
    if (thisButton == 1 && i != 7 && i != 4) {
      mode1Toggle[i] = !mode1Toggle[i];
      if (mode1Toggle[i]) {
        usbMIDI.sendControlChange(i, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i, 0, 1);
      }
    }

    if (thisButton == 1 && i == 3) {
      switchVal = 2;
      mode1LEDs = false;
      Serial.println("pushed");
    }

    if (thisButton == 1 && i == 4) {
      switchVal = 3;
      mode1LEDs = false;
      Serial.println("3");

    }
  }

  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - mode1Pots[i]) > mode1PotTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      mode1Pots[i] = thisPot;
    }
  }
}

void animation() {
  if (mode1LEDs == true) {
    strip.setPixelColor(0, 150, 100, 220);
    strip.setPixelColor(1, 150, 100, 220);
    strip.setPixelColor(2, 150, 100, 220);
    strip.setPixelColor(3, 255, 150, 150);;
    strip.setPixelColor(4, 75, 150, 255);
    strip.setPixelColor(5, 150, 100, 220);
    strip.setPixelColor(6, 150, 100, 220);
    strip.setPixelColor(7, 150, 100, 220);;
  }
  strip.show();

}
