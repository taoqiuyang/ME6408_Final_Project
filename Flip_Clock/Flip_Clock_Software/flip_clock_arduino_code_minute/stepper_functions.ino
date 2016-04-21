void stepper_turn_steps(int steps) {
  for (int i = 0; i < steps; i++) {
    stepper_one_step();//delay included
  }
}

void stepper_turn_steps_rev(int steps) {
  for (int i = 0; i < steps; i++) {
    stepper_one_step_rev();//delay included
  }
}

void stepper_one_step() {
  //1
  if (stepper_status == 1) {
    digitalWrite(8, HIGH);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 1; In2 = 0; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 2;
  }
  //2
  if (stepper_status == 2) {
    digitalWrite(8, HIGH);  digitalWrite(9, HIGH);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 1; In2 = 1; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 3;
  }
  //3
  if (stepper_status == 3) {
    digitalWrite(8, LOW);  digitalWrite(9, HIGH);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 1; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 4;
  }
  //4
  if (stepper_status == 4) {
    digitalWrite(8, LOW);  digitalWrite(9, HIGH);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 1; In3 = 1; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 5;
  }
  //5
  if (stepper_status == 5) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 0; In3 = 1; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 6;
  }
  //6
  if (stepper_status == 6) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, HIGH);
    //In1 = 0; In2 = 0; In3 = 1; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 7;
  }
  //7
  if (stepper_status == 7) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, HIGH);
    //In1 = 0; In2 = 0; In3 = 0; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 8;
  }
  //8
  if (stepper_status == 8) {
    digitalWrite(8, HIGH);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, HIGH);
    //In1 = 1; In2 = 0; In3 = 0; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 1;
  }

}

void stepper_one_step_rev() {
  //1
  if (stepper_status == 8) {
    digitalWrite(8, HIGH);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 1; In2 = 0; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 1;
  }
  //2
  if (stepper_status == 7) {
    digitalWrite(8, HIGH);  digitalWrite(9, HIGH);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 1; In2 = 1; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 8;
  }
  //3
  if (stepper_status == 6) {
    digitalWrite(8, LOW);  digitalWrite(9, HIGH);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 1; In3 = 0; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 7;
  }
  //4
  if (stepper_status == 5) {
    digitalWrite(8, LOW);  digitalWrite(9, HIGH);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 1; In3 = 1; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 6;
  }
  //5
  if (stepper_status == 4) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    //In1 = 0; In2 = 0; In3 = 1; In4 = 0;
    delay(stepper_delay_time);
    stepper_status = 5;
  }
  //6
  if (stepper_status == 3) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, HIGH);
    //In1 = 0; In2 = 0; In3 = 1; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 4;
  }
  //7
  if (stepper_status == 2) {
    digitalWrite(8, LOW);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, HIGH);
    //In1 = 0; In2 = 0; In3 = 0; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 3;
  }
  //8
  if (stepper_status == 1) {
    digitalWrite(8, HIGH);  digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, HIGH);
    //In1 = 1; In2 = 0; In3 = 0; In4 = 1;
    delay(stepper_delay_time);
    stepper_status = 2;
  }

}
