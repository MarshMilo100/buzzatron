int switch_pin = 2;
int led_pin    = LED_BUILTIN;
int relay_pin  = 4;
int analog_pin = A7;

int threshold  = 200;

int read_val = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(switch_pin, INPUT);
  pinMode(analog_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);

  digitalWrite(relay_pin, LOW);
  digitalWrite(led_pin, LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (digitalRead(switch_pin))
  {
    digitalWrite(led_pin, HIGH);
    read_val = analogRead(analog_pin);
    Serial.println(read_val);

    if (read_val > threshold)
    {
      digitalWrite(relay_pin, HIGH);
      delay(1000);
    }
    else
    {
      digitalWrite(relay_pin, LOW);
    }
  }
  else
  {
    digitalWrite(led_pin, LOW);
  }

  delay(100);
}
