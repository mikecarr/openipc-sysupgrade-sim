# SysUpgrade Simulator

The SysUpgrade Simulator is a tool designed to simulate a system upgrade process, providing detailed logs and progress updates to mimic real-world firmware upgrade scenarios. The simulator generates realistic output logs, including memory operations, kernel and RootFS updates, and system reboot sequences.


 ## Features

* Dynamic Simulation of Firmware Upgrade:
	* Simulates erasing, writing, and verifying operations for kernel and RootFS.
	* Displays memory address updates with percentages.
* Realistic Logs:
	* Mimics actual system logs with timestamps, operation statuses, and detailed process outputs.
* Customizable Behavior:
	* Easily adjust the number of blocks, KB sizes, and delays to simulate different upgrade scenarios.
* Real-Time Progress:
	* Uses dynamic output (\r and fflush) to update progress in place.



## Sample Output
```bash
OpenIPC System Updater v1.0.43

Vendor    sigmastar
SoC       ssc338q
Kernel    03:33:16 2025-01-20
RootFS    master+7d4e451, 2025-01-20

Synchronizing time
ntpd: bad address '0.pool.ntp.org'
ntpd: bad address '1.pool.ntp.org'
ntpd: bad address '2.pool.ntp.org'
ntpd: bad address '3.pool.ntp.org'
Alarm clock
Mon Jan 20 03:33:26 GMT 2025

Checking for sysupgrade update...

Version checking failed, proceeding with the installed version.

Stop services, sync files, free up memory
Stopping crond: OK
Stopping ntpd: OK
Stopping klogd: OK
Stopping syslogd: OK

Kernel
Update kernel from /tmp/uImage.ssc338q
SoC OK
New version, going to update
Erasing block: 1/32 (3%)... Erasing block: 32/32 (100%)
Writing kb: 1/1990 (0%)... Writing kb: 1990/1990 (100%)
Verifying kb: 1/1990 (0%)... Verifying kb: 1990/1990 (100%)
Kernel updated to 00:33:42 2025-01-19

RootFS
Update rootfs from /tmp/rootfs.squashfs.ssc338q
SoC OK
New version, going to update
Erasing block: 1/124 (1%)... Erasing block: 124/124 (100%)
Writing kb: 1/7896 (0%)... Writing kb: 7896/7896 (100%)
Verifying kb: 1/7896 (0%)... Verifying kb: 7896/7896 (100%)
RootFS updated to master+6e59077, 2025-01-19

OverlayFS
Erase overlay partition
Erasing 64 Kibyte @ 580000 - 96% complete. Cleanmarker written at 580000.
Erasing 64 Kibyte @ 590000 - 97% complete. Cleanmarker written at 590000.
Erasing 64 Kibyte @ 5a0000 - 98% complete. Cleanmarker written at 5a0000.
Erasing 64 Kibyte @ 5b0000 - 100% complete. Cleanmarker written at 5b0000.

Unconditional reboot
```

## Requirements

* Operating System: Linux or macOS (requires gcc).
* Compiler: GCC with support for C99 (gcc version 4.9 or higher).

## How to Build

1. Clone or download the repository.
	```
	git clone <repository-url>
	cd sysupgrade-sim
	```
2. Build the project using the provided Makefile:
	```Makefile
	make
	```
3. Run the simulator:
	```bash
	./sysupgrade
	```