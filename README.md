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
