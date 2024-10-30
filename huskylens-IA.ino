#include <HUSKYLENS.h>
#include <Wire.h>
#include <Servo.h>

// Define servo pins
const byte servoPinHor = 9;  // Horizontal servo pin
const byte servoPinVert = 10; // Vertical servo pin

// Define servo parameters
const int startAngleHor = 90; // Start angle for horizontal servo
const int maxServoHor = 120;   // Max angle for horizontal servo
const float deltaHor = 1.5;    // Step size for horizontal servo

const int startAngleVert = 90; // Start angle for vertical servo
const int maxServoVert = 120;   // Max angle for vertical servo
const float deltaVert = 1.0;    // Step size for vertical servo

// Define tracking ID
const int trackID = 2; // The ID of the object to track

// Create servo objects
struct ServoType {
    Servo servo;
    int angle;
    float fAngle;
    float delta;
    int maxServoAngle;

    void init(byte aPin, int startAngle, float aDelta, int MaxServoAngle) {
        servo.attach(aPin);
        angle = startAngle;
        fAngle = startAngle;
        delta = aDelta;
        maxServoAngle = MaxServoAngle;
        servo.write(angle);
    }

    void movePlus() {
        move(1);
    }

    void moveMinus() {
        move(-1);
    }

    void move(int dir) {
        fAngle += dir * delta;
        angle = constrain(fAngle, 0, maxServoAngle);
        servo.write(angle);
    }
};

// Create HuskyLens and servo objects
HUSKYLENS huskylens;
ServoType horizontal;
ServoType vertical;

void setup() {
    // Initialize servos
    horizontal.init(servoPinHor, startAngleHor, deltaHor, maxServoHor);
    vertical.init(servoPinVert, startAngleVert, deltaVert, maxServoVert);

    // Start serial communication
    Serial.begin(115200);
    Wire.begin();

    // Initialize HuskyLens
    while (!huskylens.begin(Wire)) {
        Serial.println(F("HUSKYLENS not connected! "));
        delay(100);
    }
    huskylens.writeAlgorithm(ALGORITHM_FACE_RECOGNITION); // Set algorithm
}

void loop() {
    if (!huskylens.request()) return; // Request data from HuskyLens

    for (int i = 0; i < huskylens.countBlocks(); i++) {
        HUSKYLENSResult result = huskylens.getBlock(i); // Get block data
        printResult(result); // Print result for debugging

        if (result.ID == trackID) { // Check if the tracked ID matches
            handlePan(result.xCenter); // Handle horizontal movement
            handleTilt(result.yCenter); // Handle vertical movement
            delay(250); // Delay to allow servo to move
        }
    }
}

void handlePan(int xCenter) {
    byte mode = 0;
    if (xCenter > 10 && xCenter < 130) { mode = 1; } // Move right
    if (xCenter > 190) { mode = 2; } // Move left

    switch (mode) {
        case 0: // No movement
            break;
        case 1: // Increase servo angle
            horizontal.movePlus();
            break;
        case 2: // Decrease servo angle
            horizontal.moveMinus();
            break;
    }
}

void handleTilt(int yCenter) {
    byte mode = 0;
    if (yCenter > 10 && yCenter < 90) { mode = 1; } // Move down
    if (yCenter > 150) { mode = 2; } // Move up

    switch (mode) {
        case 0: // No movement
            break;
        case 1: // Increase servo angle
            vertical.movePlus();
            break;
        case 2: // Decrease servo angle
            vertical.moveMinus();
            break;
    }
}

void printResult(HUSKYLENSResult &result) {
    Serial.print("Object tracked at X: ");
    Serial.print(result.xCenter);
    Serial.print(", Y: ");
    Serial.print(result.yCenter);
    Serial.print(", Width: ");
    Serial.print(result.width);
    Serial.print(", Height: ");
    Serial.print(result.height);
    Serial.print(", Tracked ID: ");
    Serial.println(result.ID);
}