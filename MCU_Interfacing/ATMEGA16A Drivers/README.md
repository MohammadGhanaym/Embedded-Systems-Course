# Set Up AVR MCU (ATMEGA16A)

**USBasp Programmer**

1. **Download Zadig**:
    - If you haven't already, download Zadig from the official website: [https://zadig.akeo.ie/](https://zadig.akeo.ie/)
2. **Launch Zadig**:
    - Run the Zadig program that you downloaded.
3. **Choose Options and Select List All Devices**:
    - In Zadig, click on the "Options" menu at the top and select "List All Devices." This option will show all available USB devices, including those without drivers.
4. **Connect the USBasp Programmer**:
    - Connect the USBasp programmer to an available USB port on your laptop.
5. **Select the USBasp Device**:
    - In Zadig, you should now see a list of USB devices, including the USBasp programmer. Look for the entry that corresponds to your USBasp device.
6. **Install the Driver**:
    - In Zadig, select the USBasp entry in the list.
    - In the upper left corner, you'll see a dropdown list with driver options. Choose the appropriate driver for your USBasp device. It may be labeled as "libusbK" or "WinUSB." The exact label may vary depending on your device.
    - Click the "Install Driver" button to install the selected driver for the USBasp device.
7. **Driver Installation Complete**:
    - Zadig will display a message indicating that the driver installation is complete. You can now close Zadig.
8. **Verify Driver Installation**:
    - To verify that the driver installation was successful, you can disconnect and reconnect the USBasp programmer. Windows should recognize it without any driver installation prompts.

Once the USBasp driver is installed, you should be able to use it with software tools like AVRDUDE to program AVR microcontrollers. Make sure to select the correct programmer (USBasp) and microcontroller model when using programming software.

Keep in mind that these instructions are based on the typical usage of Zadig for installing drivers for USBasp programmers. The specific steps and driver names may vary depending on your system configuration and the exact USBasp device you are using. Always exercise caution when working with drivers, and ensure that you are using the appropriate driver for your hardware.

---

**AVRDUDE** 

1. Download and install WinAVR → [https://youtu.be/bEfjFJlrGxs](https://youtu.be/bEfjFJlrGxs)

---

**Connect USBasp to AVR MCU**

There is an arrow that points to **MOSI** pin

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled.png)

Regardless of whether the 6-pin cable or 10-pin cable is used, and it really doesn't matter, there are 6 pins we are really wiring up and these are the MISO, SCK, RST, VTG, MOSI, and GND connections.

Basically, we're connecting the USBASP to the AVR chip's **MISO, SCK, RST, VTG, MOSI, and GND** connections that we are programming. This allows direct communication between the USBASP and the target AVR chip.

The table below explains each of the pins and their function.

| Pin Name | Description | Comment |
| --- | --- | --- |
| MOSI | Master Out Slave In | This allows the master device (the USBASP) to send data to the slave device (target AVR being programmed). |
| MISO | Master In Slave Out | This allows the slave device (target AVR being programmed) to send information to the master device (the USBASP programmer). |
| SCK | Serial Clock | This is the mutual clock shared between the master and slave device for synchronized communication. |
| Reset | Target AVR MCU Reset | The reset pin for the AVR chip being programmed must be put in active low in order for programming to occur. |
| Vcc | Power | The master and slave device both need power in order to operate. |
| GND | Common Ground | The master and slave device must share a common power ground. for operation. |

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled%201.png)

**Test that AVR is connected** 

We use this line in avrdude to test it

`avrdude -c usbasp -p m16`

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled%202.png)

`avrdude -p?` this line will return all short names of MCU

`avrdude -c?` this line will return all names of programmers

---

**Clock Frequency**

When using the `#include <util/delay.h>` library in AVR C/C++ programming, it's essential to specify the clock frequency using the `#define F_CPU` macro accurately. The `F_CPU` macro is used internally by the delay functions in `<util/delay.h>` to calculate the correct timing based on the clock frequency of the microcontroller.

Here are the steps to follow when using `<util/delay.h>`:

1. **Check the Datasheet**: The first step is to check the datasheet of your AVR microcontroller to determine the default clock source and frequency. The datasheet provides information about the oscillator configuration and clock frequency options for your specific microcontroller model.
2. **Specify `F_CPU` Macro**: Once you know the clock frequency, specify the `F_CPU` macro in your code. For example, if your microcontroller is running at 1 MHz (1,000,000 Hz), you can define it as follows:
    
    ```c
    #define F_CPU 1000000UL
    
    ```
    
    - The `UL` at the end of the value is used to indicate an unsigned long integer.
3. **Include `<util/delay.h>`**: Include the `<util/delay.h>` header file in your code using `#include <util/delay.h>`.
4. **Use `_delay_ms()` or `_delay_us()` Functions**: You can now use the `_delay_ms()` and `_delay_us()` functions provided by `<util/delay.h>` to introduce delays in your code. These functions will use the `F_CPU` value you specified to calculate the correct delay duration.
    
    Example usage:
    
    ```c
    #include <avr/io.h>
    #include <util/delay.h>
    
    int main(void) {
        // Initialize your AVR microcontroller settings here
    
        while (1) {
            // Your code here
    
            _delay_ms(500); // Delay for 500 milliseconds
        }
    
        return 0;
    }
    
    ```
    

By accurately specifying the `F_CPU` macro based on your microcontroller's clock frequency, you ensure that the delay functions provided by `<util/delay.h>` produce the correct timing in your application. This is crucial for precise timing in tasks such as blinking LEDs or controlling time-sensitive operations.

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled%203.png)

---

**I/O Ports**

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled%204.png)

![Untitled](Set%20Up%20AVR%20MCU%20(ATMEGA16A)%2072e4a7e174074105ad17251918bd67f7/Untitled%205.png)

---

**Using AVRDUDE to burn the code**

To burn a HEX code to an AVR ATmega16A microcontroller using AVRDUDE, you'll need to use the command line. AVRDUDE is a versatile command-line tool for programming AVR microcontrollers. Here are the steps to burn a HEX file to an ATmega16A using AVRDUDE:

1. **Install AVRDUDE**:
    - Ensure you have AVRDUDE installed on your computer. If it's not installed, you can download and install it from the official website or through your package manager if you're using a Linux distribution.
2. **Connect Your Programmer**:
    - Connect your AVR programmer (e.g., USBasp, AVR ISP, etc.) to your computer and to the target ATmega16A microcontroller on your hardware setup.
3. **Identify the Programmer**:
    - Determine the name of the programmer you're using (e.g., `usbasp`, `avrisp`, `usbtiny`, etc.). This is the `c` option you'll specify in the AVRDUDE command.
4. **Identify the Microcontroller Model**:
    - Determine the specific microcontroller model you're using (ATmega16A). This is the `p` option you'll specify in the AVRDUDE command.
5. **Specify the Communication Port (if needed)**:
    - If your programmer connects to your computer through a specific communication port (e.g., `/dev/ttyUSB0` or `COM3`), you'll need to specify it using the `P` option in the AVRDUDE command.
6. **Specify the HEX File**:
    - Provide the path to the HEX file that you want to burn to the microcontroller.
7. **Run the AVRDUDE Command**:
    - Open a command prompt or terminal window.
    - Use the following AVRDUDE command as a template, replacing the placeholders with your specific programmer, microcontroller, port (if needed), and HEX file path:
        
        ```
        avrdude -c PROGRAMMER -p MCU_MODEL -P PORT -U flash:w:HEX_FILE.hex
        
        ```
        
        - `c PROGRAMMER`: Replace `PROGRAMMER` with the name of your programmer (e.g., `usbasp`).
        - `p MCU_MODEL`: Replace `MCU_MODEL` with the microcontroller model (e.g., `m16a` for ATmega16A).
        - `P PORT` (optional): If your programmer requires specifying a port, replace `PORT` with the appropriate port identifier (e.g., `/dev/ttyUSB0` or `COM3`).
        - `U flash:w:HEX_FILE.hex`: This option specifies the action to take. The `flash:w:HEX_FILE.hex` part tells AVRDUDE to write (`w`) the specified HEX file to the flash memory of the microcontroller.
8. **Execute the Command**:
    - Execute the AVRDUDE command in your command prompt or terminal.
9. **Monitor Progress**:
    - AVRDUDE will provide feedback on the programming process, including any errors or warnings.
10. **Verify Programming**:
    - After the programming process is complete, you can verify that the code was successfully programmed by reading back the flash memory using AVRDUDE.

Be cautious when using AVRDUDE, and double-check your connections, microcontroller model, and programmer settings to avoid programming errors.

This line burn the code to **atmega16a** using **USBasp**

`avrdude -c usbasp -p m16 -U flash:w:app.X.production.hex`