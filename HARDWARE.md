# Hardware Setup Guide

This document provides detailed information about the hardware setup for the Arduino Auto-Water system.

## Wiring Diagram

### Basic Connection Schematic

```
Arduino                 Moisture Sensor
  A0 -------------------- Signal (Analog Output)
  5V -------------------- VCC
  GND ------------------- GND

Arduino                 Relay Module
  D7 -------------------- IN (Control Signal)
  5V -------------------- VCC
  GND ------------------- GND

Relay Module            Water Pump
  COM ------------------- Power Supply (+)
  NO --------------------- Pump (+)
  
Power Supply
  (+) ------------------- Relay COM
  (-) ------------------- Pump (-)
```

## Component Details

### 1. Moisture Sensor

**Recommended Types:**
- Capacitive soil moisture sensor (more durable, corrosion-resistant)
- Resistive soil moisture sensor (cheaper, needs replacement more often)

**Specifications:**
- Operating voltage: 3.3V - 5V
- Output: Analog (0-1023 on Arduino)
- Reading behavior: Lower value = wetter soil

**Placement:**
- Insert sensor 2-4 inches into soil
- Keep electronics above soil level
- Position near plant roots for accurate readings

### 2. Relay Module

**Recommended Specifications:**
- 5V single-channel relay module
- Optocoupler isolation
- Control signal: 5V TTL
- Switching capacity: Match or exceed your pump requirements

**Relay Logic:**
- This code uses: HIGH = OFF, LOW = ON
- Most relay modules use this "active low" configuration
- Some relays may be "active high" - adjust code if needed

**Important Notes:**
- Use a relay rated for your pump's voltage and current
- For AC pumps, use appropriate AC-rated relay
- For high-power pumps, consider using a contactor

### 3. Water Pump

**Selection Criteria:**
- Voltage: Match your power supply (3V, 5V, 12V common)
- Flow rate: Based on your watering needs
- Type: Submersible or inline
- Current draw: Must be within relay specifications

**Common Types:**
- **DC micro pumps** (3-12V): Good for small plants, low power
- **Peristaltic pumps**: Precise dosing, gentle flow
- **Submersible pumps**: For water reservoir systems

**Power Requirements:**
- Small pumps: 100-500mA (can share Arduino power supply)
- Larger pumps: 1A+ (need separate power supply)

### 4. Power Supply

**Arduino:**
- USB power (5V, 500mA) for development
- 7-12V DC adapter (recommended for permanent installation)
- Battery power for portable systems

**Pump:**
- Separate power supply recommended for pumps > 500mA
- Voltage must match pump specifications
- Current rating should exceed pump's max draw by 20%

## Assembly Steps

### Step 1: Prepare Components
1. Gather all components and tools
2. Test each component individually
3. Prepare jumper wires (use appropriate gauge for pump current)

### Step 2: Connect Moisture Sensor
1. Connect sensor VCC to Arduino 5V
2. Connect sensor GND to Arduino GND
3. Connect sensor Signal/Analog out to Arduino A0
4. Secure connections with heat shrink or electrical tape

### Step 3: Connect Relay Module
1. Connect relay VCC to Arduino 5V
2. Connect relay GND to Arduino GND
3. Connect relay IN to Arduino D7
4. Keep relay module away from moisture

### Step 4: Connect Pump to Relay
1. Connect power supply positive to relay COM
2. Connect relay NO (Normally Open) to pump positive
3. Connect pump negative to power supply negative
4. Verify all connections are secure

### Step 5: Final Check
- ✓ All grounds connected together
- ✓ No exposed conductors that could short
- ✓ Relay rated for pump voltage/current
- ✓ Sensor positioned correctly in soil
- ✓ Pump positioned in water reservoir

## Safety Guidelines

### Electrical Safety
- ⚠️ Never mix AC and DC without proper isolation
- ⚠️ Use proper gauge wire for current levels
- ⚠️ Ensure all connections are insulated
- ⚠️ Keep electronics away from water
- ⚠️ Use GFCI protection for AC circuits

### Water Safety
- Use waterproof enclosures for electronics
- Position Arduino above any water sources
- Ensure pump cannot run dry
- Use check valves to prevent backflow
- Test for leaks before leaving unattended

### Component Protection
- Add flyback diode across relay coil (often built-in)
- Consider fuse in pump power line
- Use optoisolated relay for additional protection
- Protect Arduino from reverse voltage

## Enclosure Recommendations

**For Indoor Use:**
- Plastic project box for Arduino
- Ventilation for heat dissipation
- Cable glands for wire entry
- Mounting holes for stability

**For Outdoor Use:**
- IP65+ rated enclosure
- Sealed cable entries
- UV-resistant materials
- Elevated mounting to avoid flooding

## Testing Procedure

### 1. Initial Power-Up Test
1. Upload code to Arduino
2. Power on (without pump connected)
3. Check Serial Monitor for startup message
4. Verify relay clicks off (HIGH state)

### 2. Sensor Test
1. Observe moisture readings in Serial Monitor
2. Test sensor in dry and wet soil
3. Verify readings change appropriately
4. Adjust threshold if needed

### 3. Relay Test
1. Connect pump to relay
2. Ensure water reservoir is filled
3. Manually trigger watering by adjusting threshold
4. Verify pump turns on and off correctly
5. Check for proper flow

### 4. System Integration Test
1. Set threshold to trigger watering
2. Wait for hourly check
3. Verify automatic operation
4. Monitor for several cycles

## Troubleshooting Hardware Issues

### Sensor Issues
- **Erratic readings**: Clean sensor, check connections
- **Always high/low**: Check voltage supply, sensor may be damaged
- **No change**: Verify analog pin connection

### Relay Issues
- **Won't switch**: Check control signal, verify 5V supply
- **Always on/off**: Check relay module orientation, verify code logic
- **Clicking but pump doesn't run**: Check pump power supply

### Pump Issues
- **Doesn't run**: Check power supply, test pump directly
- **Weak flow**: Check for blockages, verify voltage
- **Runs continuously**: Relay stuck closed, check relay

## Recommended Tools

- Multimeter (for testing voltages and continuity)
- Wire strippers
- Soldering iron (for permanent connections)
- Heat shrink tubing
- Cable ties
- Electrical tape
- Screwdriver set

## Bill of Materials (BOM)

| Component | Quantity | Approximate Cost (USD) |
|-----------|----------|----------------------|
| Arduino Uno | 1 | $20-25 |
| Moisture Sensor | 1 | $3-8 |
| 5V Relay Module | 1 | $2-5 |
| Water Pump (5V) | 1 | $5-15 |
| Jumper Wires | 10+ | $3-5 |
| Power Supply | 1 | $5-10 |
| Project Box | 1 | $5-10 |
| Tubing/Hose | As needed | $5-10 |
| **Total** | | **~$50-90** |

*Prices are approximate and may vary by location and supplier*

## Advanced Options

### Multiple Sensors
- Add more analog inputs (A1, A2, etc.)
- Modify code to read multiple sensors
- Use averaging or individual thresholds

### Multiple Pumps
- Add more relay channels
- Control different zones independently
- Stagger watering times

### LCD Display
- Add I2C LCD for local status display
- Show moisture level, next check time
- No computer needed for monitoring

### WiFi Integration
- Use ESP8266 or ESP32 instead of Arduino
- Send notifications
- Remote monitoring and control

### Solar Power
- Solar panel (6V, 2W+)
- Rechargeable battery
- Charge controller
- For fully autonomous outdoor systems
