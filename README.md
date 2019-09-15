# function-generator
A function generator with variable frequency and different typical signals to choose from(sine, triangle, saw and square).
the project is based on STM32F051K8 microcontroller which features built-in DAC. Shematics and layout were designed using Autodesk Eagle software. For the most part shematics were designed according to datasheets of used components. The resulting analog signal is ‘cleaned’ from high frequency component with calculated passive low-pass filter.
Software part of the project was executed in C using STM32Cube for configuration and Keil µVision as IDE. Project uses standard HAL drivers and own code for digital-to-analog processing with wavetables generated in Matlab, that are converted to analog values on the output of device. Modified OpenSource library is used for indication on the OLED screen.
Software still needs a lot of tuning, but that's just a part of a bigger project involving DSP on low-end STM32 MCUs so I'm working on it ;)
