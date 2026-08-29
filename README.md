# TitanCore-RT: Industrial Real-Time Embedded Control Platform

An industrial-grade, MISRA-C compliant, modular embedded platform, RTOS microkernel, and flight control unit with over 57,000+ lines of production C code.

---

## Dependencies

The platform is self-contained and requires only a standard C99/C11 cross-compiler or native host toolchain:
- **C Compiler**: GCC (arm-none-eabi-gcc 10.3+ or native gcc 9.0+), Clang 11+, or MSVC 2019+
- **Build Systems**: GNU Make 4.0+ or CMake 3.16+
- **Tooling & Linter**: Node.js & npm (optional, for code formatting tools)
- **Host Simulation**: POSIX compliant shell or Windows PowerShell

---

## Installation

Clone the repository and install developer validation tools:

```bash
# Clone the repository
git clone https://github.com/Hash-153/emb.git
cd emb

# (Optional) Install developer linters and formatters
npm install
```

---

## Build

You can build the target firmware or host simulator using either **CMake** or **GNU Make**:

### Using CMake:
```bash
# Generate build files
cmake -B build -S .

# Compile the firmware and simulator
cmake --build build --config Release
```

### Using GNU Make:
```bash
# Build the embedded platform and simulation binaries
make all
```

---

## Run

Execute the host simulator or run the test verification suite:

### Run Host Simulation:
```bash
# Run using CMake output
./build/titan_sim

# Or run using Make output
./bin/titan_test_runner
```

### Run Automated Unit Test Suites:
```bash
make test
```

---

## Usage

### 1. Task Creation & Preemptive Kernel Startup
```c
#include "kernel/titan_scheduler.h"
#include "kernel/titan_task.h"

static titan_tcb_t s_nav_tcb;
static u8_t s_nav_stack[2048];

void navigation_task(void *arg) {
    while (1) {
        /* Run 500Hz navigation loop */
        titan_task_delay_ms(2);
    }
}

int main(void) {
    titan_sched_init();
    titan_task_create(&s_nav_tcb, "nav_500hz", navigation_task, NULL, 15, s_nav_stack, sizeof(s_nav_stack));
    titan_sched_start();
    return 0;
}
```

### 2. High-Voltage BMS & Telemetry Logging
```c
#include "drivers/titan_drv_bms.h"
#include "storage/titan_blackbox.h"

titan_bms_pack_status_t bms_status;
titan_bms_update_measurements(&bms_status);
titan_bms_run_cell_balancing(&bms_status);
```

---

## System Directory Layout
- `include/core/` & `src/core/`: Platform primitives, fixed-point Q15/Q31 math, CRCs, ring buffers.
- `include/kernel/` & `src/kernel/`: Preemptive RTOS scheduler, TCBs, priority-inheritance mutexes, zero-copy queues, TLSF dynamic heap.
- `include/hal/` & `src/hal/`: Hardware register abstraction, DMA, GPIO, UART, SPI, I2C, CAN-FD, Timers, ADC.
- `include/drivers/` & `src/drivers/`: IMU, Barometer, Magnetometer, HV-BMS, Flash NOR, NMEA GNSS, Current monitors.
- `include/protocols/` & `src/protocols/`: CANopen (CiA 301/402), Modbus RTU/TCP, ISO-TP / UDS (ISO 14229), COBS Framer.
- `include/storage/` & `src/storage/`: Flash Wear-Leveling File System, NVRAM Key-Value store, Blackbox logger.
- `include/dsp/` & `src/dsp/`: Biquad IIR filters, FFT vibration analysis, Madgwick AHRS, 15-State Navigation EKF, Cascaded PID, FOC SVPWM.
- `include/safety/` & `src/safety/`: March C- RAM BIST, Flash CRC, 2oo3 Triple Modular Redundancy voter, Failsafe state machine.
- `include/app/` & `src/app/`: Master supervisory state machine, VT100 CLI shell, flight control matrix, 250+ redundant avionics channels.
- `sim/`: Host desktop simulator and synthetic 6-DOF physics engine.
- `tests/`: Zero-dependency test harness and comprehensive test suites.
- `linker/` & `startup/`: Cortex-M linker scripts (`titan_cortex_m4.ld`) and vector table startup assembly (`startup_titan.s`).
