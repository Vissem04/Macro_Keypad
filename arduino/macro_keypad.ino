#include <Keyboard.h>

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
bool lastButtonStates[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
bool isProcessing = false; 

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    if (lastButtonStates[i] == HIGH && currentState == LOW) {
      if (!isProcessing) { 
        isProcessing = true; 
        executeFunction(i);  
        isProcessing = false; 
      }
    }
    lastButtonStates[i] = currentState;
  }
  delay(30); 
}

void executeFunction(int index) {
  switch (index) {
    case 0: 
      openUrl("https://gemini.google.com/app"); 
      break;

    case 1: 
      openUrl("https://www.youtube.com/"); 
      break;

    case 2: 
      openUrl("https://music.youtube.com/"); 
      break;

    case 3: 
      openUrl("https://www.instagram.com/"); 
      break;

    case 4: 
      Keyboard.press(KEY_LEFT_GUI);   
      Keyboard.press(KEY_LEFT_ALT);   
      Keyboard.press('r');            
      delay(100);                     
      Keyboard.releaseAll();          
      break;

    case 5: 
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      delay(50);
      Keyboard.print("Hello"); 
      delay(50);
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      break;

    case 6: 
      Keyboard.print("ID@gmail.com");
      delay(200);
      Keyboard.press(KEY_TAB);
      delay(50);
      Keyboard.release(KEY_TAB);
      delay(200);
      Keyboard.print("PW");
      delay(100);
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      break;

    case 7: 
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('w');
      delay(100);
      Keyboard.releaseAll();
      break;
  }
}

void openUrl(String url) {
  Keyboard.press(KEY_LEFT_GUI); 
  Keyboard.press('r');         
  delay(150);                  
  Keyboard.releaseAll();       
  
  delay(400);                  
  
  Keyboard.print(url);
  delay(100);
  
  Keyboard.press(KEY_RETURN);  
  Keyboard.releaseAll();       
}





