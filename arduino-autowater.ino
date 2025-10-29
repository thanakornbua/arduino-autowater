// Arduino Non-Blocking Irrigation System
// Uses millis() for non-blocking timing

// Hardware Configuration
const int SENSOR_PIN = A0;        // Moisture sensor on A0 (low=wet)
const int PUMP_RELAY_PIN = 7;     // Pump relay on D7 (HIGH=OFF)

// Timing Constants
const unsigned long CHECK_INTERVAL_MS = 3600000;  // 1 hour in milliseconds
const unsigned long WATER_DURATION_MS = 500;      // Water for 500ms

// Threshold Constants
const int DRY_THRESHOLD = 700;    // Above this value means soil is dry

// State Variables
unsigned long lastCheckTime = 0;  // Time of last moisture check

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Configure pump relay pin as output
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  
  // Ensure pump is OFF initially (HIGH = OFF)
  digitalWrite(PUMP_RELAY_PIN, HIGH);
  
  Serial.println("Arduino Non-Blocking Irrigation System Started");
  Serial.println("Check interval: 1 hour");
  Serial.print("Dry threshold: ");
  Serial.println(DRY_THRESHOLD);
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check if it's time to check moisture (non-blocking)
  if (currentTime - lastCheckTime >= CHECK_INTERVAL_MS) {
    // Read moisture sensor
    int moistureReading = analogRead(SENSOR_PIN);
    
    Serial.print("Moisture reading: ");
    Serial.println(moistureReading);
    
    // Check if soil is dry
    if (moistureReading > DRY_THRESHOLD) {
      Serial.println("Soil is dry - watering...");
      
      // Turn pump ON (LOW = ON)
      digitalWrite(PUMP_RELAY_PIN, LOW);
      
      // Water for specified duration (brief delay is okay per requirements)
      delay(WATER_DURATION_MS);
      
      // Turn pump OFF (HIGH = OFF)
      digitalWrite(PUMP_RELAY_PIN, HIGH);
      
      Serial.println("Watering complete");
      
      // Reset timer immediately after watering finishes
      lastCheckTime = millis();
    } else {
      Serial.println("Soil moisture adequate - no watering needed");
      
      // Reset timer after check
      lastCheckTime = currentTime;
    }
  }
  
  // Non-blocking loop continues
}
