#include <M5Cardputer.h>
#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverMAC[] =  {0xAC, 0xA7, 0x04, 0x00, 0x3E, 0xE0};

void sendChar(char c)
{
  esp_now_send(receiverMAC, (uint8_t *)&c, 1);
}

void setup()
{
  auto cfg = M5.config();
  M5Cardputer.begin(cfg);
  M5.Display.setBrightness(76);
  
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    while (1);
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Peer add failed");
    while (1);
  }

  M5Cardputer.Display.fillScreen(BLACK);
  M5Cardputer.Display.setTextSize(2);
  M5Cardputer.Display.setCursor(10, 10);
  M5Cardputer.Display.println("ACHTSAM KONTROL");
}

String tx = "";
String rx = "";

void loop()
{
  M5Cardputer.update();

  if (M5Cardputer.Keyboard.isChange())
    {
      auto keys = M5Cardputer.Keyboard.keysState();
 
      if (keys.enter)
	{
	  M5.Speaker.tone(1000, 30);
	  sendChar('\n'); tx = "ENT"; rx = "OK";
	}

      if (keys.del)
	{
	  M5.Speaker.tone(1000, 30);
	  sendChar('\b'); tx = "BS"; rx = "BACKSPACE";
	}
 
      for (auto c : keys.word)
	{
	  M5.Speaker.tone(1000, 30);
	  sendChar(c);
	  tx = String(c);

	  switch (c)
	    {
	    case '`':	      rx = "ESC";	      break;
	    case '\'':	      rx = "ESC";	      break;	      
	    case '\\':	      rx = "MENU";	      break;
	    case 'h':	      rx = "HOME";	      break;
	    case 'f':	      rx = "FILE";	      break;
	    case 'v':	      rx = "VIEW";	      break;	      

	    case 'j':	      rx = "PLAY";	      break;
	    case 'k':	      rx = "STOP";	      break;
	    case 'l':	      rx = "RECORD";	      break;
	    case ' ':	      tx = "SPC"; rx = "PLAY";	      break;

	      
	    case 'm':	      rx = "CUE MARK";	      break;
	    case 'x':	      rx = "FILE TRANSFER";   break;	      	      

	    case '/':	      rx = "RIGHT";	      break;
	    case ',':	      rx = "LEFT";	      break;
	    case ';':	      rx = "UP";	      break;
	    case '.':	      rx = "DOWN";	      break;
	      
	    case 'w':	      rx = "1 |X| | |";	      break;
	    case 'e':	      rx = "1 | |X| |";	      break;
	    case 'r':	      rx = "1 | | |X|";	      break;
	    case 'a':	      rx = "2 |X| | |";	      break;
	    case 's':	      rx = "2 | |X| |";	      break;
	    case 'd':	      rx = "2 | | |X|";	      break;

	    case '1':	      rx = "CH 1";	      break;
	    case '2':	      rx = "CH 2";	      break;	      	      
	    case '3':	      rx = "CH 3";	      break;
	    case '4':	      rx = "CH 4";	      break;
	    case '5':	      rx = "CH 5";	      break;
	    case '6':	      rx = "CH 6";	      break;

	    case '7':	      rx = "MUTE CH 1";	      break;
	    case '8':	      rx = "MUTE CH 2";	      break;
	    case '9':	      rx = "MUTE CH 3";	      break;
	    case '0':	      rx = "MUTE CH 4";	      break;
	    case '-':	      rx = "MUTE CH 5";	      break;
	    case '=':	      rx = "MUTE CH 6";	      break;
	      
	    case 'u':	      rx = "SOLO CH 1";	      break;
	    case 'i':	      rx = "SOLO CH 2";	      break;
	    case 'o':	      rx = "SOLO CH 3";	      break;
	    case 'p':	      rx = "SOLO CH 4";	      break;
	    case '[':	      rx = "SOLO CH 5";	      break;
	    case ']':	      rx = "SOLO CH 6";	      break;
	      
	    case 'q':	      rx = "* SHORTCUT";      break;
	    case 'z':	      rx = "FRONT PANEL";     break;	      	      

	    default:	      rx = String(c);	      break;
	    }
	}
      
      M5Cardputer.Display.fillRect(0, 30, 320, 120, BLACK);
      M5Cardputer.Display.setCursor(10, 50);
      if (rx.length() > 0)
	{
	  M5Cardputer.Display.printf("%s -> %s", tx.c_str(), rx.c_str());
	}
      else
	{
	  M5Cardputer.Display.printf("%s", tx.c_str());
	}
    }
}
