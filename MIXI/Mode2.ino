//mode 2
boolean mode2LEDs = false;
boolean mode2Toggle[] = {false, false, false, false, false, false};
int mode2Pots[] = {0, 0, 0, 0};
int mode2PotTol = 5;


void mode2() {
  if (!mode2LEDs) {
    mode2LEDs = true;
    animation2();
  }

  for (int i = 0; i < 8; i++) {
    int thisButton = buttonStates[i];
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      mode2Toggle[i] = !mode2Toggle[i];
      if (mode2Toggle[i]) {
        usbMIDI.sendControlChange(i + 20, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i + 20, 0, 1);
      }
    }

    if (buttonStates[i] == 1 && i == 7) {
      switchVal = 1;
      mode2LEDs = false;
    }

    if (thisButton == 1 && i == 4) {
      switchVal = 3;
      mode2LEDs = false;
            Serial.println("pushed");

    }
  }

  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - mode2Pots[i]) > mode2PotTol) {
      usbMIDI.sendControlChange(i + 23, thisPot, 1);
      mode2Pots[i] = thisPot;
    }
  }
}

void animation2() {
  if (mode2LEDs == true) {
    strip.setPixelColor(0, 255, 150, 150);
    strip.setPixelColor(1, 255, 150, 150);
    strip.setPixelColor(2, 255, 150, 150);
    strip.setPixelColor(3, 255, 150, 150);
    strip.setPixelColor(4, 75, 150, 255);
    strip.setPixelColor(5, 255, 150, 150);
    strip.setPixelColor(6, 255, 150, 150);
    strip.setPixelColor(7, 150, 100, 220);
  }
    strip.show();

}
