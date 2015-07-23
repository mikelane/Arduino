#include <math.h>

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
float hue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  randomSeed(analogRead(0));
  float H = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(" ");
  Serial.print("H: ");
  //Serial.println(H);
  float S = 100; //random(0, 100);
  Serial.print("S: ");
  Serial.println(S);
  Serial.println(" ");
  /*
    Serial.println("******* Test ********");
    Serial.print(RGB[0]);
    Serial.print(",");
    Serial.print(RGB[1]);
    Serial.print(",");
    Serial.println(RGB[2]);
    Serial.println("******* Test ********");
  */
  pulse(hue++, 100);
}

void pulse(float H, float S)
{
  int R = 0, G = 0, B = 0;
  for (int i = 0; i <= 100; ++i)
  {
    HSV_to_RGB(H, S, i, R, G, B);
    Serial.print("U ");
    Serial.print(R);
    Serial.print(",");
    Serial.print(G);
    Serial.print(",");
    Serial.print(B);
    Serial.println(" ");
    analogWrite(RED_PIN, R);
    analogWrite(GREEN_PIN, G);
    analogWrite(BLUE_PIN, B);
    delay(25);
  }

  Serial.print("M ");
  Serial.print(R);
  Serial.print(",");
  Serial.print(G);
  Serial.print(",");
  Serial.print(B);
  Serial.println(" ");
  analogWrite(RED_PIN, R);
  analogWrite(GREEN_PIN, G);
  analogWrite(BLUE_PIN, B);

  delay(1000);

  for (int i = 100; i >= 0; --i)
  {
    HSV_to_RGB(H, S, i, R, G, B);
    Serial.print("D ");
    Serial.print(R);
    Serial.print(",");
    Serial.print(G);
    Serial.print(",");
    Serial.print(B);
    Serial.println(" ");
    analogWrite(RED_PIN, R);
    analogWrite(GREEN_PIN, G);
    analogWrite(BLUE_PIN, B);
    delay(25);
  }
}

void HSV_to_RGB(float H, float S, float V, int & R, int & G, int & B)
{
  S /= 100;
  V /= 100;
  float C = V * S;
  H /= 60;
  float X = C * (1 - abs(fmod(H, 2) - 1));
  float r = 0, g = 0, b = 0;
  if (H >= 0 && H < 1)
  {
    r = C;
    g = X;
    b = 0;
  } else if (H >= 1 && H < 2)
  {
    r = X;
    g = C;
    b = 0;
  } else if (H >= 2 && H < 3)
  {
    r = 0;
    g = C;
    b = X;
  } else if (H >= 3 && H < 4)
  {
    r = 0;
    g = X;
    b = C;
  } else if (H >= 4 && H < 5)
  {
    r = X;
    g = 0;
    b = C;
  } else if (H >= 5 && H < 6)
  {
    r = C;
    g = 0;
    b = X;
  } else
  {
    r = g = b = 0;
  }
  float m = V - C;

  r += m;
  g += m;
  b += m;

  r *= 255;
  g *= 255;
  b *= 255;

  R = (int) r;
  G = (int) g;
  B = (int) b;

}

