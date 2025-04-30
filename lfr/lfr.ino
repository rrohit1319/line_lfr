// Sensor and Motor Pin Definitions
#define LEFT_SENSOR 12
#define RIGHT_SENSOR 13

#define MOTOR_LEFT_FORWARD 11
#define MOTOR_LEFT_BACKWARD 10
#define MOTOR_RIGHT_FORWARD 9
#define MOTOR_RIGHT_BACKWARD 8

#define Left_LED 2
#define Right_LED 3

#define ENA_1 5  // PWM pin (previously A0, corrected)
#define ENA_2 6   // Use 4 as digital HIGH/LOW (or if needed, you can move to PWM pin 6, 9, 10, 11)

int speedControl = 90; // Motor speed (0-255)

void setup() {
    // Sensor Pins
    pinMode(LEFT_SENSOR, INPUT);
    pinMode(RIGHT_SENSOR, INPUT);

    // Motor Control Pins
    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);

    // Enable Pins
    pinMode(ENA_1, OUTPUT);
    pinMode(ENA_2, OUTPUT);

    // LEDs
    pinMode(Right_LED, OUTPUT);
    pinMode(Left_LED, OUTPUT);

    // Set Motor Speed
    analogWrite(ENA_1, speedControl);
    analogWrite(ENA_2, speedControl);  // If ENA_2 is on non-PWM pin like D4, just set HIGH for full speed
}

void loop() {
    int leftState = digitalRead(LEFT_SENSOR);
    int rightState = digitalRead(RIGHT_SENSOR);

    if (leftState == LOW && rightState == LOW) {
        moveForward();
    } else if (leftState == HIGH && rightState == LOW) {
        turnRight();
    } else if (leftState == LOW && rightState == HIGH) {
        turnLeft();
    } else {
        stopMotors();
    }

    delay(5); // Small delay to stabilize readings
}

void moveForward() {
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
    digitalWrite(Left_LED, LOW);
    digitalWrite(Right_LED, LOW);
}

void turnRight() {
    // Tight turn (left wheel forward, right wheel backward)
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
    digitalWrite(Left_LED, LOW);
    digitalWrite(Right_LED, HIGH);
}

void turnLeft() {
    // Tight turn (left wheel backward, right wheel forward)
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
    digitalWrite(Left_LED, HIGH);
    digitalWrite(Right_LED, LOW);
}

void stopMotors() {
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
    digitalWrite(Left_LED, HIGH);
    digitalWrite(Right_LED, HIGH);
}
