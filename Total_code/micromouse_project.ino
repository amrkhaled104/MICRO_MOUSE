#include <vector>
#include "algorithm.h"
#include "encoder.h"
#include "gyroscope.h"
#include "Movement.h"
#include "walls.h"

// Algorithm variables
short direction = NORTH;
short robot_x = 15;
short robot_y = 0;

float anglez = 0.0f, lasttime = 0.0f, dt = 0.0f;

std::vector<std::pair<int, int>> centerPoints = {
    {MAZE_SIZE / 2 - 1, MAZE_SIZE / 2 - 1},
    {MAZE_SIZE / 2 - 1, MAZE_SIZE / 2},
    {MAZE_SIZE / 2, MAZE_SIZE / 2 - 1},
    {MAZE_SIZE / 2, MAZE_SIZE / 2}
};

// Pin mode configuration for sensors and motors
void setupPinModes() {
    // IR sensors
    pinMode(FRONT_SENSOR_PIN, INPUT);
    pinMode(RIGHT_SENSOR_PIN, INPUT);
    pinMode(LEFT_SENSOR_PIN, INPUT);

    // Motor control pins
    pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
    pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
    pinMode(MOTOR_LEFT_PIN1, OUTPUT);
    pinMode(MOTOR_LEFT_PIN2, OUTPUT);
}

// Encoder setup
void encoderSetup() {
    // Attach encoder interrupt pins (example commented out)
    // attachInterrupt(digitalPinToInterrupt(encoderPinA), ISR_encoder, RISING);
}

// Setup function
void setup() {
    Serial.begin(115200);

    // Initialize pin modes, encoder, and gyroscope
    setupPinModes();
    EncoderSetup();
    initgyro();

    anglez = 0.0f;
    lasttime = millis();

    // Perform BFS to initialize the maze exploration
    bfs(centerPoints);
}

// Main loop function
void loop() {
    // Continue navigating the maze until the robot reaches the goal
    /*
    while (maze[robot_x][robot_y] != 0) {
        updateWalls(robot_x, robot_y, direction);
        bfs(centerPoints);
        moveToBestCell(robot_x, robot_y, direction);
    }
    *//*
        // Decision-making based on wall detection
    if (wallFront() && !wallRight() && wallLeft()) {
        turnRight();
        delay(1000);
        moveForward(18.0);
        //delay(3000);
        Serial.println("moveright");
    } 
moveForward(18.0);
   */
     if (!wallRight()) {
        turnRight();
        // Stop motors after moving
    digitalWrite(MOTOR_RIGHT_PIN1, LOW);
    digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    digitalWrite(MOTOR_LEFT_PIN1, LOW);
    digitalWrite(MOTOR_LEFT_PIN2, LOW);
 
    delay(1000);
        moveForward(18.0);
    } 
    moveForward(18.0);
    
    delay(1000); // Short delay for stability
}
