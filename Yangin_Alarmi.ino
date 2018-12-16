
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

char auth[] = "TOKEN";

char ssid[] = "Wifi_ Adı";
char pass[] = "WiFi_Şifresi";

int alev = A0;
int alevdurum ;
int tur;
int buzzer = 5;     // Bağlı olduğu pinin GPIO karşılığını girin

WidgetLED led1 (V0);

void setup()
{
  pinMode (alev, INPUT);
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval (1000L, dongu);
}


void dongu ()
{
  alevdurum = analogRead (alev);

  if (alevdurum < 800)
  {
    tone (buzzer, 650);
    led1.on();
    tur = 1;

    if (tur == 1)
    {
      Blynk.notify ("DIKKAT !!! ALEV ALGILANDI");
      tur = 0;
    }
  }
  else
  {
    noTone (buzzer);
    led1.off();
    tur = 0;
  }
}


void loop()
{
  Blynk.run();
  timer.run ();
}

