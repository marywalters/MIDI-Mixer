void initLEDs() {
     strip.setBrightness(60);

          for (int i = 0; i < 8; i++){
          strip.setPixelColor(i, 150, 100, 2205);
           strip.show();
           delay(100);
          }
          for (int i = 0; i < 8; i++){
                    strip.setPixelColor(i, 255, 150, 150);
                     strip.show();
                     delay(100);
          }
          for (int i = 0; i < 8; i++){
                    strip.setPixelColor(i, 75, 150, 255);
                     strip.show();
                     delay(100);
          }
}
