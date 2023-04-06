# SWO Example
SWO library example for Mbed OS.

## Requirements
### Hardware requirements
The following boards are required:
- Any Zest_Core board with SWO output on JTAG connector

### Software requirements
SWO Example makes use of the following libraries (automatically imported
by `mbed deploy` or `mbed import`):
- [SWO library](https://github.com/catie-aq/mbed_swo)

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target and toolchain definition:
```shell
mbed import https://github.com/catie-aq/mbed_swo-example.git swo-example
```

Alternatively:

- Clone to "swo-example" and enter it:
  ```shell
  git clone https://github.com/catie-aq/mbed_swo-example.git swo-example
  cd swo-example
  ```

- Deploy software requirements with:
  ```shell
  mbed deploy
  ```

- Clone custom target repository if necessary:
  ```shell
  git clone YOUR_CUSTOM_TARGET_REPOSITORY your-custom-target
  ```

Define your target and toolchain:
```shell
cp your-custom-target/custom_targets.json . # In case of custom target
mbed target YOUR_MBED_OS_TARGET
mbed toolchain GCC_ARM
```

Compile the project:
```shell
mbed compile
```

Program the target device with a Segger J-Link debug probe and
[`sixtron_flash`](https://github.com/catie-aq/6tron_flash) tool:
```shell
sixtron_flash YOUR_JLINK_DEVICE BUILD/YOUR_MBED_OS_TARGET/GCC_ARM/mbed_swo-example.elf
```

Debug on the target device with the probe and Segger
[Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger)
software.
