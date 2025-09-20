# How to set up the test scenario
1. Clone the repo
2. Build the project using `make build`
3. Connect pico w to computer in BOOTSEL mode
4. Flash the executable onto the pico w using `make flash FILE=build/src/hello_freertos.uf2`

# How to exercise the system
1. Connect to pico w via serial monitor
2. Input the following strings into the serial monitor input:
    a. `Hello World`
    b. `$$$`

# Expected behavior
1. Input: `Hello World`    Expected Output: `hELLO wORLD`
2. Input: `$$$`            Expected Output: `$$$`
3. LED should blink 5 times, then pause for 1 second, then repeat infinitely
