# Clean and configure the build (from project root) 
rm -rf build
cmake -S . -B build

 
# Build the project 
cmake --build build -j

 
# Flash the UF2 onto the Pico (requires sudo for USB access) 
sudo picotool load build/src/hello_freertos.uf2 -f

 
# Reboot the Pico into application mode (again needs sudo) 
sudo picotool reboot