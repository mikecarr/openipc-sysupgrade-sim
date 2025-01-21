#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void print_header() {
    printf("OpenIPC System Updater Simulator v1.0.0\n\n");
}

void print_command_and_args(int argc, char *argv[]) {
    printf("Command: %s\n", argv[0]); // Print the program name (command)

    printf("Arguments:\n");
    for (int i = 1; i < argc; i++) {
        printf("  Arg %d: %s\n", i, argv[i]);
    }

    printf("\n"); // Add a blank line for readability
}


void print_system_info() {
    printf("Vendor\tsigmastar\n");
    printf("SoC\tssc338q\n");

    // Simulate dynamic time for Kernel and RootFS
    time_t now = time(NULL);
    struct tm *tm_info = gmtime(&now);
    char kernel_time[20], rootfs_time[30];
    strftime(kernel_time, sizeof(kernel_time), "%H:%M:%S %Y-%m-%d", tm_info);
    strftime(rootfs_time, sizeof(rootfs_time), "master+7d4e451, %Y-%m-%d", tm_info);

    printf("Kernel\t%s\n", kernel_time);
    printf("RootFS\t%s\n\n", rootfs_time);
}

void print_time_sync_errors() {
    printf("Synchronizing time\n");
    for (int i = 0; i < 4; i++) {
        printf("ntpd: bad address '%d.pool.ntp.org'\n", i);
        sleep(1); // Simulate delay
    }
    for (int i = 3; i >= 0; i--) {
        printf("ntpd: bad address '%d.pool.ntp.org'\n", i);
        sleep(1); // Simulate delay
    }
    printf("Alarm clock\n");
    printf("Mon Jan 20 03:33:26 GMT 2025\n\n");
}

void print_sysupgrade_check() {
    printf("Checking for sysupgrade update...\n\n");
    sleep(1); // Simulate processing
    printf("Version checking failed, proceeding with the installed version.\n\n");
}

void print_service_shutdown() {
    printf("Stop services, sync files, free up memory\n");
    printf("Stopping crond: OK\n");
    printf("Stopping ntpd: OK\n");
    printf("Stopping klogd: OK\n");
    printf("Stopping syslogd: OK\n\n");
}

void print_system_stats() {
    printf("Uptime:\n");
    printf(" 03:33:28 up 3 min,  load average: 12.51, 5.94, 2.31\n\n");

    printf("Memory:\n");
    printf("              total        used        free      shared  buff/cache   available\n");
    printf("Mem:          90.7M       25.5M       38.7M       19.4M       26.4M       42.0M\n");
    printf("Swap:             0           0           0\n\n");

    printf("Processes:\n");
    printf("PID   USER     TIME  COMMAND\n");
    printf("    1 root      0:01 init\n");
    printf("  585 root      0:00 udhcpc -x hostname:openipc-ssc338q -A 0 -T 1 -t 5 -R -b -O search -p /var/run/udhcpc.eth0.pid -i eth0\n");
    printf("  595 root      0:00 dropbear -R -B -k -p 22 -K 300\n");
    printf("  699 root      1:05 majestic -s\n");
    printf("  832 root      0:19 wfb_tx -p 0 -u 5600 -R 456000 -K /etc/drone.key -B 20 -M 1 -S 0 -L 0 -G long -k 8 -n 12 -T 0 -i 7669206 -f data -C 8000 wlan0\n");
    printf("  844 root      0:00 mavfwd --channels 8 --master /dev/ttyS2 --baudrate 115200 -p 100 -t -a 15 --out 127.0.0.1:14550 --in 127.0.0.1:14551\n");
    printf("  845 root      0:00 telemetry_rx -p 144 -u 14551 -K /etc/drone.key -i 7669206 wlan0\n");
    printf("  846 root      0:00 telemetry_tx -p 16 -u 14550 -K /etc/drone.key -B 20 -M 1 -S 1 -L 1 -G long -k 1 -n 2 -T 0 -i 7669206 -f data wlan0\n");
    printf("  855 root      0:00 tunnel_rx -p 160 -u 5800 -K /etc/drone.key -i 7669206 wlan0\n");
    printf("  856 root      0:00 tunnel_tx -p 32 -u 5801 -K /etc/drone.key -M 1 -S 0 -L 0 -k 8 -n 12 -i 7669206 wlan0\n");
    printf("  857 root      0:00 wfb_tun -a 10.5.0.10/24\n");
    printf("  866 root      0:00 /sbin/getty -L console 0 vt100\n");
    printf(" 1032 root      0:00 dropbear -R -B -k -p 22 -K 300\n");
    printf(" 1033 root      0:00 -sh\n");
    printf(" 1087 root      0:00 {sysupgrade} /bin/sh /usr/sbin/sysupgrade --kernel=/tmp/uImage.ssc338q --rootfs=/tmp/rootfs.squashfs.ssc338q -n\n");
    printf(" 1149 root      0:00 ps\n\n");
}

void simulate_erasing_blocks(int total_blocks) {
    for (int i = 1; i <= total_blocks; i++) {
        // Calculate the progress percentage
        int percentage = (i * 100) / total_blocks;

        // Print the current progress
        printf("\rErasing block: %d/%d (%d%%)", i, total_blocks, percentage);
        fflush(stdout); // Ensure the output is updated in the terminal

        // Add a small delay to simulate the process
        usleep(200000); // 200 milliseconds
    }
    printf("\n"); // Move to the next line after completing the loop
}

void simulate_writing_kb(int total_kb) {
    for (int i = 1; i <= total_kb; i++) {
        int percentage = (i * 100) / total_kb;

        printf("\rWriting kb: %d/%d (%d%%)", i, total_kb, percentage);
        fflush(stdout);
        usleep(1000); // Small delay for simulation (1ms per KB)
    }
    printf("\n");
}

void simulate_verifying_kb(int total_kb) {
    for (int i = 1; i <= total_kb; i++) {
        int percentage = (i * 100) / total_kb;

        printf("\rVerifying kb: %d/%d (%d%%)", i, total_kb, percentage);
        fflush(stdout);
        usleep(1000); // Small delay for simulation (1ms per KB)
    }
    printf("\n");
}

void simulate_erasing_memory(int start_address, int end_address, int step_size) {
    for (int address = start_address; address <= end_address; address += step_size) {
        // Calculate the percentage based on progress
        int percentage = ((address - start_address) * 100) / (end_address - start_address);

        // Print the progress
        printf("\rErasing 64 Kibyte @ %06x - %d%% complete.", address, percentage);
        fflush(stdout);

        // Simulate a cleanmarker write
        printf(" Cleanmarker written at %06x.", address);
        fflush(stdout);

        // Add a small delay for simulation
        usleep(200000); // 200ms delay
    }
    printf("\n");
}

void print_firmware_update() {
    printf("Unmounting SD card\n\n");

    printf("Kernel\n");
    printf("Update kernel from /tmp/uImage.ssc338q\n");
    printf("SoC OK\n");
    printf("New version, going to update\n");
    simulate_erasing_blocks(32);
    simulate_writing_kb(1990);
    simulate_verifying_kb(1990);

    printf("Kernel updated to 00:33:42 2025-01-19\n\n");

    printf("RootFS\n");
    printf("Update rootfs from /tmp/rootfs.squashfs.ssc338q\n");
    printf("SoC OK\n");
    printf("New version, going to update\n");
    simulate_erasing_blocks(32);
    simulate_writing_kb(7896);
    simulate_verifying_kb(7896);
    printf("RootFS updated to master+6e59077, 2025-01-19\n\n");

    printf("OverlayFS\n");
    printf("Erase overlay partition\n");

    // Simulate erasing memory with specific addresses
    simulate_erasing_memory(0x580000, 0x5b0000, 0x5000);

    printf("Unconditional reboot\n");
}

int main(int argc, char *argv[]) {
    print_command_and_args(argc, argv);
    print_header();
    print_system_info();
    print_time_sync_errors();
    print_sysupgrade_check();
    print_service_shutdown();
    print_system_stats();
    print_firmware_update();

    return 0;
}
