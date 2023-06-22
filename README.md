# 3.2_Touchsy_Breakout_Resistive_Software
<img src="https://github.com/sbcshop/3.2_Touchsy_HAT_Resistive_Software/blob/main/images/Touchsy%20banner.jpg">
3.2" Touchsy Resistive Breakout - the perfect display solution for users who prefer use their favourite Arduino UNO/Mega/Nano or any other controllers. Here also you have the choice between resistive and capacitive touchscreens to suit your specific requirements.

With Touchsy Resistive Breakout, you can easily program your display with the Arduino IDE and use it in various projects and applications, from DIY electronics to robotics. The level shifter ensures compatibility with various hardware options, and the support for both 3.3V and 5V makes it versatile and flexible.
Both SPI and Parallel data pins available on this Breakout. So you get flexibility of interfacing either SPI or 8 bit Parallel mode for faster operation. 

Here are the features and specifications that make 3.2" Touchsy Resistive Breakout a unique and must-have accessory:

### Features:
- Perfect for Arduino community with 3/4 wire SPI interface, 8- bit parallel interface
- The level shifter for compatibility with various hardware options
- Supports both 3.3V and 5V, making it versatile and flexible
- Compatibility: Arduino or other controllers
- Connectivity: 3/4 wire SPI interface, 8- bit parallel interface


### Specifications:
- 3.2” Display with resolution 240 × 320
- Operating voltage of pins compatible for both 3.3V and 5V
- ILI934 Display Driver
- XPT2046 resistive touch controller
- Appearance: RGB
- Colors: 65K/262K
- Viewing Angle(in degree): Left:70, Right:70, Up:50, Down:70 
- Operating Temperature is -20℃~70℃
- Storage Temperature is -30℃~80℃

## Getting Started with 3.2 Touchsy Resistive Breakout
### Pinout
<img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/Touchsy%20ESP32%20Res%20pinout.jpg">

- (1) 3.2” Resistive Touch Display 
- (2) Extra GPIO breakout
- (3) Buzzer 
- (4) Battery connection port
- (5) Power pins breakout 
- (6) Type C for Programming and Power both
- (7) Additional GPIO breakout 
- (8) SD card slot 
- (9) ESP32 S3 module
- (10) Boot Button
- (11) Reset Button
- (12) Two Programmable Buttons


### Interfacing Details
- Display and Resistive Touch controller interfacing with ESP32
    | ESP32 | Display | Code variables | Function |
    |---|---|---|---|
    | IO14 | DC/SCL SPI  | _sclk   |Clock pin of SPI interface for Display|
    | IO13 | SDI SPI/SDA | _mosi   | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO12 | SDO SPI     | _miso   | MISO (Master IN Slave OUT) data pin of SPI interface|
    | IO15 | CS/SPI CS   | TFT_CS  | Chip Select pin of SPI interface|
    | IO21 | WR/SPI D/C  | TFT_DC  | Data/Command pin of SPI interface|
    | EN   | RESET       | TFT_RST | Display Reset pin, Directly connected to enable pin|
    | IO5  |Driven via Transistor  | TFT_BACKLIGHT_PIN |Backlight of display|

    | ESP32 | Resistive Touch | Code variables | Function |
    |---|---|---|---|
    | IO14 | DCLK   | _sclk         |Clock pin of SPI interface for touch controller|
    | IO13 | DIN    | _mosi         | MOSI (Master OUT Slave IN) data pin of SPI interface|
    | IO12 | DOUT   | _miso         | MISO (Master IN Slave OUT) data pin of SPI interface|
    | IO47 | CS     | TOUCH_CS_PIN  | Chip Select pin of SPI interface|
    | IO0  | PENIRQ | TOUCH_IRQ_PIN | Touch controller Interrupt pin|

  Display setting code snippets view:
  ```
    //Define common SPI interfacing pins
    #define _sclk              14
    #define _mosi              13 
    #define _miso              12
    
    //for Display with ESP32
    #define TFT_DC             21
    #define TFT_CS             15 
    #define TFT_RST            -1   // connected to enable pin of esp32 
    
    //for Touch controller with ESP32
    #define TOUCH_CS_PIN       47
    #define TOUCH_IRQ_PIN      0
    
    #define TFT_BACKLIGHT_PIN   5

    // to access various display methods
    Adafruit_ILI9341 tft = Adafruit_ILI9341( TFT_CS, TFT_DC, TFT_RST );

    // to access resistive touch related method
    XPT2046_Touchscreen touch( TOUCH_CS_PIN, TOUCH_IRQ_PIN );
  ```

- ESP32 and micro SD card interfacing
    | ESP32| microSD Card | Function |
    |---|---|---|
    |IO42 | SCLK |Clock pin of SPI interface for microSD card |
    |IO2 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
    |IO41 | DOUT | MISO (Master IN Slave OUT) data pin of SPI interface|
    |IO1 | CS   | Chip Select pin of SPI interface|

  Sdcard setting code snippets view:
  ```
   //Define SPI interfacing pins for micro SD card with ESP32
    #define SD_MOSI 2
    #define SD_MISO 41
    #define SD_SCK 42
    #define SD_CS 1
  ```
  
- Buttons, Buzzer and LED Interfacing with ESP32
    | ESP32 | Buttons | Function |
    |---|---|---|
    |IO4 | BT1 |Programmable button|
    |IO6 | BT2 |Programmable button|
    |IO0 | Boot | Boot Button|
  
    | ESP32 | Hardware |
    |---|---|
    |IO40 | Buzzer |
    |IO3 | LED |

  Code snippets:
  ``` 
    const int buzzerPin = 40; //create variable for buzzer pin connected at GPIO40
    const int userButton1 = 4; //for programmable button 1 at GPIO4
    const int userButton2 = 6; //for programmable button 1 at GPIO6
    const int LED = 3;
  ```
- Breakout GPIOs
  
    Breakout 1
    | ESP32 |Physical Pin | Multi-Function |
    |---|---|---|
    |D- | 13 | RTC_GPIO19, GPIO19, U1RTS, ADC2_CH8, CLK_OUT2, USB_D- |
    |D+ | 14 | RTC_GPIO20, GPIO20, U1CTS, ADC2_CH9, CLK_OUT1, USB_D+ |
    |GP9 | 4 | RTC_GPIO9, GPIO9, TOUCH9, ADC1_CH8, FSPIHD |
    |GP7 | 5 | RTC_GPIO7, GPIO7, TOUCH7, ADC1_CH6 |
    |GP46 | 16 | GPIO46 |
    |GP10 | 18 | RTC_GPIO10, GPIO10, TOUCH10, ADC1_CH9, FSPICS0, FSPIIO4 |

    Breakout 2
    | ESP32 |Physical Pin | Multi-Function |
    |---|---|---|
    |3V3  | - | Positive Supply 3.3V |
    |GP43 | 37 | U0TXD, GPIO43, CLK_OUT1 |
    |GP44 | 36 | U0RXD, GPIO44, CLK_OUT2 |
    |GP8  | 12 | RTC_GPIO8, GPIO8, TOUCH8, ADC1_CH7  |
    |GP16 | 9 | RTC_GPIO16, GPIO16, U0CTS, ADC2_CH5, XTAL_32K_N |
    |GND  | - | Ground pin |

### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 board support into IDE, for this first you need to add below link into preference:
     ``` https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">


## Resources
  * [Schematic](https://github.com/sbcshop/3.2_Touchsy_Breakout_Resistive_Hardware/blob/main/Design%20Data/Sch%203.2%20inch%20Touchsy%20Breakout(resistive).pdf)
  * [Hardware Files](https://github.com/sbcshop/3.2_Touchsy_Breakout_Resistive_Hardware)
  * [Step File](https://github.com/sbcshop/3.2_Touchsy_Breakout_Resistive_Hardware/blob/main/Mechanical%20Data/STEP%203.2%20inch%20Touchsy%20Breakout(resistive).step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/documents/esp32-s3_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)


## Related Products
   * [3.2" Touchsy ESP32](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-based-on-esp32-mcu) - 3.2" Touchsy ESP32 with Resistive and Capacitive version. 
   * [3.2" Touchsy Pico W](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-based-on-pico-w) - 3.2" Touchsy Pico W with Resistive and Capacitive version.
   * [3.2" Touchsy Breakout](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-breakout-board) - 3.2" Touchsy Breakout with Resistive and Capacitive version.
   * [3.2" Touchsy HAT](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-for-raspberry-pi) - 3.2" Touchsy HAT with Resistive version for Raspberry Pi.


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
