# Electronic Cats Arduino Core for mbed enabled devices

The repository contains the Arduino APIs and IDE integration files targeting a generic mbed-enabled board

## Features Electronic Cats version Vs Arduino Original version

- Support for [Adafruit Bootloader UF2](https://github.com/ElectronicCats/Adafruit_nRF52_Bootloader) only MBR Bootloader (Unsupport SoftDevice)
- Upload firmware via [adafruit-nrfutil](https://github.com/adafruit/Adafruit_nRF52_nrfutil)

## Nice features from Arduino

- Based in Arduino mbedOS
- Support library [ArduinoBLE](https://github.com/arduino-libraries/ArduinoBLE)
- Support Library Arduino Tensorflow Lite

##  Easy Install

To add board support for our products, start Arduino and open the Preferences window (**File** > **Preferences**). Now copy and paste the following URL into the 'Additional Boards Manager URLs' input field:

	https://electroniccats.github.io/Arduino_Boards_Index/package_electroniccats_index.json


- If there is already an URL from another manufacturer in that field, click the button at the right end of the field. This will open an editing window allowing you to paste the above URL onto a new line.

- Press the "OK" button.
- Open the "boards manager" that is in tools --> Board --> board manager.
- Now write "Electronic Cats" (without quotes) in the search bar.
- Click in install, jus wait to finish to install and only close the window. 


## Manual Installation

Clone the repository in `$sketchbook/hardware/arduino`

```bash
mkdir -p $sketchbook/hardware/arduino
cd $sketchbook/hardware/arduino
git clone git@github.com:arduino/ArduinoCore-mbed mbed
```

Then clone https://github.com/arduino/ArduinoCore-API in a directory at your choice. Checkout `namespace_arduino` branch.

```bash
git clone git@github.com:arduino/ArduinoCore-API -b namespace_arduino
```

Remove the symlink to `api` you can find in  `$sketchbook/hardware/arduino/mbed/cores/arduino` and replace it with a symlink to `ArduinoCore-API/api`

Open Arduino IDE; you should now see three new targets under `MBED boards` label

## Supported boards

 * [BastBLE low cost development board](https://www.electroniccats.com)
 * [Arduino Nano 33 BLE ](https://store.arduino.cc/usa/nano-33-ble-sense)

## Adding an mbed target

Adding a target is a mostly automatic procedure that involves running https://github.com/arduino/ArduinoCore-mbed/blob/master/mbed-os-to-arduino after setting `BOARDNAME` and `ARDUINOCORE` env variables.
Actions marked as TODO must be executed manually.

**Minimum Example**: `./mbed-os-to-arduino -r /home/alex/projects/arduino/cores/mbed-os-h747 ENVIE_M7:ENVIE_M7`

### How to build a debug version of the Arduino mbed libraries
* Modify `mbed-os-to-arduino `
```diff
mbed_compile () {
-       PROFILE_FLAG=""
        if [ x"$PROFILE" != x ]; then
                PROFILE_FLAG=--profile="$ARDUINOVARIANT"/conf/profile/$PROFILE.json
                export PROFILE=-${PROFILE^^}
+       else
+               export PROFILE="-DEBUG"
+               PROFILE_FLAG="--profile=debug"
        fi
```

## Using this core as an mbed library

You can use this core as a standard mbed library; all APIs are under `arduino` namespace (so they must be called like `arduino::digitalWrite()` )

The opposite is working as well; from any sketch you can call mbed APIs by prepending `mbed::` namespace.


