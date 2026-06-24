#include <Keyboard.h>

void setup() {
  Serial1.begin(115200);
	Keyboard.begin();
}

void loop()
{
	if (Serial1.available())
    {
			char c = Serial1.read();
			switch (c)
        {
				case '/':
					Keyboard.press(KEY_RIGHT); delay(50); Keyboard.releaseAll(); break;
				case ',':   
					Keyboard.press(KEY_LEFT); delay(50); Keyboard.releaseAll(); break;
				case '.':   
					Keyboard.press(KEY_DOWN); delay(50); Keyboard.releaseAll(); break;
				case ';':  
					Keyboard.press(KEY_UP); delay(50); Keyboard.releaseAll(); break;

				case 'm': //mark
					Keyboard.press(KEY_LEFT_CTRL); delay(30); Keyboard.press('m'); delay(100); Keyboard.releaseAll(); delay(100); break;

				case 'j':  //play
					Keyboard.press(KEY_SPACE); delay(50); Keyboard.releaseAll(); break;
		
				case 'k': //stop
					Keyboard.press(KEY_LEFT_CTRL); delay(30); Keyboard.press('s'); delay(100); Keyboard.releaseAll(); delay(100); break;

				case 'l': //record
					Keyboard.press(KEY_LEFT_CTRL); delay(30); Keyboard.press('r'); delay(100); Keyboard.releaseAll(); delay(100); break;

				case 'x': // file transfer
					Keyboard.press(KEY_LEFT_CTRL); delay(30); Keyboard.press('f'); delay(100); Keyboard.releaseAll(); delay(100); break;

				case 'w':
					Keyboard.press(KEY_Q); delay(50); Keyboard.releaseAll(); break;
				case 'e':
					Keyboard.press(KEY_W); delay(50); Keyboard.releaseAll(); break;
				case 'r':
					Keyboard.press(KEY_E); delay(50); Keyboard.releaseAll(); break;
				case 'a':
					Keyboard.press(KEY_A); delay(50); Keyboard.releaseAll(); break;
				case 's':
					Keyboard.press(KEY_S); delay(50); Keyboard.releaseAll(); break;
				case 'd':
					Keyboard.press(KEY_D); delay(50); Keyboard.releaseAll(); break;

				case '7': //mute
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('1'); delay(10); Keyboard.releaseAll(); break;
				case '8':
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('2'); delay(10); Keyboard.releaseAll(); break;
				case '9':
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('3'); delay(10); Keyboard.releaseAll(); break;
				case '0':
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('4'); delay(10); Keyboard.releaseAll(); break;
				case '-':
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('5'); delay(10); Keyboard.releaseAll(); break;
				case '=':
					Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('6'); delay(10); Keyboard.releaseAll(); break;

				case 'u': // solo
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('1'); delay(10); Keyboard.releaseAll(); break;
				case 'i':
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('2'); delay(10); Keyboard.releaseAll(); break;
				case 'o':
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('3'); delay(10); Keyboard.releaseAll(); break;
				case 'p':
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('4'); delay(10); Keyboard.releaseAll(); break;                                
				case '[':
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('5'); delay(10); Keyboard.releaseAll(); break;
				case ']':
					Keyboard.press(KEY_LEFT_ALT);
					Keyboard.press('6'); delay(10); Keyboard.releaseAll(); break;

				case '\n':
					Keyboard.press(KEY_ENTER); delay(50); Keyboard.releaseAll(); break;
				case '`':
					Keyboard.press(KEY_ESC); delay(50); Keyboard.releaseAll(); break;
				case '\'':
					Keyboard.press(KEY_ESC); delay(50); Keyboard.releaseAll(); break;
				case '\\':
					Keyboard.press(KEY_F1); delay(50); Keyboard.releaseAll(); break;
				case 'h':
					Keyboard.press(KEY_F12); delay(50); Keyboard.releaseAll(); break;
				case 'f':
					Keyboard.press(KEY_F2); delay(50); Keyboard.releaseAll(); break;
				case 'v':
					Keyboard.press(KEY_F3); delay(50); Keyboard.releaseAll(); break;

				case ' ':
					Keyboard.press(KEY_SPACE); delay(50); Keyboard.releaseAll(); break;
				case '\b':
					Keyboard.press(KEY_BACKSPACE); delay(50); Keyboard.releaseAll(); break;
				case 'q': //*
					Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('8'); delay(50); Keyboard.releaseAll(); break;

				case 'z':
					Keyboard.press(KEY_1); 
					Keyboard.press(KEY_2); 
					Keyboard.press(KEY_3); delay(50); Keyboard.releaseAll(); break;

				default:
					Keyboard.write(c); break;
        }

    }
}
