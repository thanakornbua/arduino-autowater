# Arduino Auto-Water

A non-blocking Arduino irrigation controller that automatically waters plants based on soil moisture levels. The system checks soil moisture every hour and activates a water pump when the soil is too dry.

## Features

- **Non-blocking operation**: Uses `millis()` for timing instead of `delay()`, allowing the Arduino to remain responsive
- **Hourly checks**: Monitors soil moisture every 1 hour (configurable)
- **Automatic watering**: Activates pump relay when soil is dry
- **Serial logging**: Provides detailed status updates via Serial Monitor
- **Configurable thresholds**: Easy to adjust moisture levels and timing

## Hardware Requirements

### Components
- Arduino board (Uno, Nano, Mega, etc.)
- Soil moisture sensor (analog output)
- Relay module (for pump control)
- Water pump
- Power supply (appropriate for your pump)
- Jumper wires

### Pin Configuration

| Component | Arduino Pin | Notes |
|-----------|-------------|-------|
| Moisture Sensor | A0 | Analog input (low value = wet) |
| Pump Relay | D7 | Digital output (HIGH = OFF, LOW = ON) |

## Installation

1. **Connect the hardware** according to the pin configuration above
2. **Open the sketch** in Arduino IDE:
   - File → Open → `arduino-autowater.ino`
3. **Select your board**:
   - Tools → Board → Select your Arduino model
4. **Select the port**:
   - Tools → Port → Select the appropriate COM/USB port
5. **Upload the sketch**:
   - Click the Upload button or press Ctrl+U

## Configuration

You can customize the behavior by modifying these constants in the code:

```cpp
// Timing Constants
const unsigned long CHECK_INTERVAL_MS = 3600000;  // 1 hour (in milliseconds)
const unsigned long WATER_DURATION_MS = 500;      // Pump run time (in milliseconds)

// Threshold Constants
const int DRY_THRESHOLD = 700;    // Moisture level above which soil is considered dry
```

### Adjusting Moisture Threshold

The `DRY_THRESHOLD` value determines when watering occurs:
- **Higher values** (e.g., 800): Water less frequently (drier soil)
- **Lower values** (e.g., 600): Water more frequently (moister soil)

To calibrate for your sensor:
1. Open Serial Monitor (9600 baud)
2. Observe moisture readings in dry and wet soil
3. Set threshold between these values

### Adjusting Timing

- **CHECK_INTERVAL_MS**: Change how often moisture is checked
  - 3600000 ms = 1 hour (default)
  - 1800000 ms = 30 minutes
  - 7200000 ms = 2 hours
  
- **WATER_DURATION_MS**: Change how long the pump runs
  - Start with 500ms and adjust based on your pump and plant needs

## Usage

1. **Power on** the Arduino
2. **Open Serial Monitor** (Tools → Serial Monitor) at 9600 baud
3. **Monitor the output**:
   - System startup message
   - Moisture readings every hour
   - Watering events when soil is dry

### Serial Monitor Output Example

```
Arduino Non-Blocking Irrigation System Started
Check interval: 1 hour
Dry threshold: 700
Moisture reading: 650
Soil moisture adequate - no watering needed
Moisture reading: 750
Soil is dry - watering...
Watering complete
```

## How It Works

1. **Initialization**: On startup, the system initializes Serial communication and sets the pump relay to OFF
2. **Non-blocking loop**: The main loop continuously runs without blocking
3. **Hourly checks**: Every hour, the system:
   - Reads the moisture sensor value
   - Compares it to the dry threshold
   - If dry (reading > threshold): activates pump for configured duration
   - Resets the timer for the next check
4. **Timing accuracy**: Uses `millis()` for precise, non-blocking timing

## Troubleshooting

### Pump doesn't turn on
- Verify relay connections (check if HIGH = OFF or HIGH = ON for your relay)
- Check power supply to the pump
- Confirm moisture reading exceeds the threshold
- Test relay manually: `digitalWrite(7, LOW);`

### Incorrect moisture readings
- Check sensor connections to A0
- Clean sensor contacts
- Calibrate threshold by observing readings in Serial Monitor
- Some sensors read inverse values (adjust threshold accordingly)

### System doesn't check every hour
- Verify `CHECK_INTERVAL_MS` value
- Check if Arduino is resetting unexpectedly
- Monitor Serial output for timing messages

## Safety Notes

⚠️ **Important Safety Information**
- Never run the pump dry (without water)
- Ensure proper electrical isolation between Arduino and pump circuits
- Use appropriate power supply for your pump
- Don't submerge electronic components in water
- Test the system before leaving it unattended

## Technical Details

- **Non-blocking design**: Uses millis() timing to avoid blocking the main loop
- **Timing drift prevention**: Resets timer with fresh millis() call after watering
- **Immediate startup check**: Checks moisture immediately on boot for quick response
- **Relay logic**: Inverted logic (HIGH = OFF) for safety - pump defaults to OFF

## License

This project is open source and available for modification and distribution.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve the project.