#include <Keyboard.h>
HardwareSerial Serial2(PA3, PA2);
int in_byte = 0;

void setup()
{
  Keyboard.begin();
  Serial2.begin(115200);
  while (!Serial2)
  {
  }
  Serial2.println("Keyboard starting..");
}

void loop()
{
  if (Serial2.available() > 0)
  {
    in_byte = Serial2.read();
    Serial2.write(in_byte);
    if (in_byte == '\r')
    {
      Serial2.write('\n');
      Keyboard.write(176);
    }
    else
      Keyboard.write(in_byte);
  }
}