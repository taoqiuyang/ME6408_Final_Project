
//-----Timer-------------------------------
uint32_t time_got_command = 0;
#define COMMAND_EXPIRATION 5000

//
float stepper_delay_time = 4;
int stepper_status = 1;
int motor1, motor2, motor3;

int previous_minute = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

String command;

void loop()
{
  if (Serial.available())
  {
    char c = Serial.read();
    if (c == '\n')
    {
      time_got_command = millis();
      parseCommand(command);
      command = "";
      delay(50);
    }
    else
    {
      command += c;
    }
  }

  if (motor2 >= previous_minute) {  //0->1, 1->2, 2->3, ... 58->59
    stepper_turn_steps_rev(int ((motor2 - previous_minute) * 3550.0 / 60.0));
  } else {                          //59->0
    stepper_turn_steps_rev(int ((1) * 3550.0 / 60.0));
  }

  previous_minute = motor2;
}


void parseCommand(String com)
{
  int commaIndex = com.indexOf(',');
  //  Search for the next comma just after the first
  int secondCommaIndex = com.indexOf(',', commaIndex + 1);

  motor1 = com.substring(0, commaIndex).toInt();
  motor2 = com.substring(commaIndex + 1, secondCommaIndex).toInt();
  motor3 = com.substring(secondCommaIndex + 1).toInt();

  Serial.println(motor1);
  Serial.println(motor2);
  Serial.println(motor3);
}

