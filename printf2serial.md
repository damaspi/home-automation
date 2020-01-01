# The problem
With the nRF24L01, you never know if it is working and emitting, or just wrongly cabled and sitting there idle.
There is a .printDetails() method, but it prints details on stdout, and we have no stdout...
The "printf.h" file (from the RF24 library) redirects the standard output to the serial port.
It must be included after SPI.h that it uses, and the "printf_begin()" method must be called, after having initialized the Serial output.

```cpp
#include <SPI.h>
#include <printf.h>
(...)

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ");
  printf_begin();
  (...)
  radio.printDetails();
}
...
```

To do that, it uses the arduino method ```fdevopen( )``` that unfortunately does not always exist on other architectures.
So for other architectures, you can edit directly the RF24 library and add the following:

In RF24.cpp
```cpp
int printf_P_serial(const char* format, ...) 
{    
    char buffer[1000];

    va_list argptr;
    va_start(argptr, format);
    vsprintf_P(buffer, format, argptr);
    va_end(argptr);


    Serial.print(buffer);
}
```

and in RF24_config.h:
```cpp
#define printf_P printf_P_serial
```

You don't need to include "printf.h" nor call "printf_begin" for it to work.
