#define LEFT_SENSOR 11
#define RIGHT_SENSOR 12
#define MOTOR_LEFT_FORWARD 5
#define MOTOR_LEFT_BACKWARD 6
#define MOTOR_RIGHT_FORWARD 9
#define MOTOR_RIGHT_BACKWARD 10
#define Left_LED 2
#define Right_LED 3
#define ENA_1 A0
#define ENA_2 A1
int speed = 150;

void setup() {
    pinMode(LEFT_SENSOR, INPUT);
    pinMode(RIGHT_SENSOR, INPUT);
    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
    pinMode(ENA_1, OUTPUT);
    pinMode(ENA_2, OUTPUT);
    pinMode(Right_LED, OUTPUT);
    pinMode(Left_LED, OUTPUT);

    analogWrite(ENA_1, 100);
    analogWrite(ENA_2, 100);
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
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
    digitalWrite(Left_LED, LOW);
    digitalWrite(Right_LED, HIGH);
}

void turnLeft() {
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
