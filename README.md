# SWO Example
SWO library example for Mbed OS.

## Requirements
### Hardware requirements
The following boards are required:
- Any Zest Core with SWO output on JTAG connector

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

- Set Mbed project root path:
  ```shell
  mbed config root .
  ```

Define your target (eg. `ZEST_CORE_STM32L4A6RG`) and toolchain:
```shell
mbed target ZEST_CORE_STM32L4A6RG
mbed toolchain GCC_ARM
```

Export to Eclipse IDE with:
```shell
mbed export -i eclipse_6tron
```

## Working from command line
Compile the project:
```shell
mbed compile
```

Program the target device (eg. `STM32L4A6RG` for the Zest_Core_STM32L4A6RG) with a J-Link
debug probe:
```shell
python dist/program.py STM32L4A6RG BUILD/ZEST_CORE_STM32L4A6RG/GCC_ARM/swo-example.elf
```

Debug on the target device (eg. `STM32L4A6RG` for the Zest_Core_STM32L4A6RG) with a
J-Link debug probe.

- First, start the GDB server:
  ```shell
  JLinkGDBServer -device STM32L4A6RG
  ```

- Then, in another terminal, start the debugger:
  ```shell
  arm-none-eabi-gdb BUILD/ZEST_CORE_STM32L4A6RG/GCC_ARM/swo-example.elf
  ```

*Note:* You may have to adjust your [GDB auto-loading safe path](https://sourceware.org/gdb/onlinedocs/gdb/Auto_002dloading-safe-path.html#Auto_002dloading-safe-path)
or disable it completely by adding a .gdbinit file in your $HOME folder containing:
```conf
set autoload safe-path /
```
