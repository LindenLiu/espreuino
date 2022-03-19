# Espreuino
The Arduino based PID and control center for Espresso machine.

# Design Principals
1. Extensible: Different people have different sets of hardware, the software should be extensible to adapting different hardware. Like different display, different temperature sensors etc.
2. Efficient: It is a software running on the micro controller so efficiency is important. The code should be small and fast. Which means we may use some of the compilation tricks to include only minimal code on the chip. Functions should be trimmable. 

# Features
Here is the list of the features plan to implemented:
- **Temperature control**
- [ ] PID Control for Brewing
- [ ] PID Parameters Auto tuning
- [x] RTD Temperature sensor
- [ ] Steam Temperature control
- **Brewing**
- [x] Brew Switch detection
- [ ] Pressure Sensor integration
- [ ] Auto Preinfusion
- [ ] Manual Preinfusion
- [ ] Auto Pressure profile for brewing.
- [ ] Manual Pressure control for brewing.
- **Cleaning**
- [ ] Back flush (5 times caffeza, wait user confirm portafilter cleaned and 6 times clean water)
- [ ] Descale
- [ ] Cleaning reminder: by brewing times.
- **ESP32**
- [ ] Recording Manual pressure profile.
- [ ]   