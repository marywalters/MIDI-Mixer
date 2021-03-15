//mode 3
boolean mode3LEDs = false;
boolean mode3Toggle[] = {false, false, false, false, false, false};
int mode3Pots[] = {0, 0, 0, 0};
int mode3PotTol = 5;

void mode3() {
  if (!mode3LEDs) {
    mode3LEDs = true;
    animation3();
  }

  for (int i = 0; i < 8; i++) {
    int thisButton = buttonStates[i];
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      mode3Toggle[i] = !mode3Toggle[i];
      if (mode3Toggle[i]) {
        usbMIDI.sendControlChange(i + 33, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i + 33, 0, 1);
      }
    }

    if (buttonStates[i] == 1 && i == 7) {
      switchVal = 1;
      mode3LEDs = false;
    }

    if (thisButton == 1 && i == 3) {
      switchVal = 2;
      mode3LEDs = false;
            Serial.println("pushed");

    }
  }

  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - mode3Pots[i]) > mode3PotTol) {
      usbMIDI.sendControlChange(i + 48, thisPot, 1);
      mode3Pots[i] = thisPot;
    }
  }
}

void animation3() {
  if (mode3LEDs == true) {
    strip.setPixelColor(0, 75, 150, 255);
    strip.setPixelColor(1, 75, 150, 255);
    strip.setPixelColor(2, 75, 150, 255);
    strip.setPixelColor(3, 255, 150, 150);;
    strip.setPixelColor(4, 75, 150, 255);
    strip.setPixelColor(5, 75, 150, 255);
    strip.setPixelColor(6, 75, 150, 255);
    strip.setPixelColor(7, 150, 100, 220);;
  }
  strip.show();
}
