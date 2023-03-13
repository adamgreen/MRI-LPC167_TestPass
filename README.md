# MRI on mbed-LPC1768 Test Pass
This README documents the manual steps that I conduct in GDB when running a test pass on my [MRI library](https://github.com/adamgreen/mri). This repository also contains the source code for the [test program](src/main.cpp) that I run on the mbed LPC1768 device while running through the steps in this test pass.


## Build and Deploy Test Program
* First we should make sure that the latest MRI library sources have been built and deployed into the GCC4MBED tree used for building this test sample. This can be done by running ```./update_mri```
* Build the test program and deploy it to the mbed LPC1768 by running ```make deploy```
* Manually press the reset button on the mbed LPC1768 device to complete the deployment and start executing the new code.
* Connect to MRI with GDB by using this command on my machine: ```debug mri LPC1768```
* ```continue``` from the initial stop in ```_start()```.
```console
~/depots/MRI-LPC1768_TestPass$ ./update_mri
+ pushd ../mri
~/depots/mri ~/depots/MRI-LPC1768_TestPass
+ make clean arm
Cleaning MRI
Compiling core/buffer.c for no FPU
Compiling core/cmd_break_watch.c for no FPU
Compiling core/cmd_common.c for no FPU
Compiling core/cmd_continue.c for no FPU
Compiling core/cmd_file.c for no FPU
Compiling core/cmd_memory.c for no FPU
Compiling core/cmd_query.c for no FPU
Compiling core/cmd_registers.c for no FPU
Compiling core/cmd_step.c for no FPU
Compiling core/cmd_thread.c for no FPU
Compiling core/cmd_vcont.c for no FPU
Compiling core/context.c for no FPU
Compiling core/gdb_console.c for no FPU
Compiling core/libc.c for no FPU
Compiling core/memory.c for no FPU
Compiling core/mri.c for no FPU
Compiling core/packet.c for no FPU
Compiling core/token.c for no FPU
Compiling core/try_catch.c for no FPU
Compiling rtos/rtos_weak.c for no FPU
Compiling semihost/semihost.c for no FPU
Compiling semihost/newlib/semihost_newlib.c for no FPU
Assembling semihost/newlib/newlib_stubs.S for no FPU
Compiling semihost/mbed/semihost_mbed.c for no FPU
Compiling architectures/armv7-m/armv7-m.c for no FPU
Assembling architectures/armv7-m/armv7-m_asm.S for no FPU
Compiling memory/native/native-mem.c for no FPU
Compiling devices/lpc176x/lpc176x_init.c for no FPU
Compiling devices/lpc176x/lpc176x_uart.c for no FPU
Assembling devices/lpc176x/lpc176x_asm.S for no FPU
Compiling boards/mbed1768/mbed1768.c for no FPU
Assembling boards/mbed1768/mbed1768_asm.S for no FPU
Building lib/armv7-m/libmri_mbed1768.a
Compiling core/buffer.c for FPU
Compiling core/cmd_break_watch.c for FPU
Compiling core/cmd_common.c for FPU
Compiling core/cmd_continue.c for FPU
Compiling core/cmd_file.c for FPU
Compiling core/cmd_memory.c for FPU
Compiling core/cmd_query.c for FPU
Compiling core/cmd_registers.c for FPU
Compiling core/cmd_step.c for FPU
Compiling core/cmd_thread.c for FPU
Compiling core/cmd_vcont.c for FPU
Compiling core/context.c for FPU
Compiling core/gdb_console.c for FPU
Compiling core/libc.c for FPU
Compiling core/memory.c for FPU
Compiling core/mri.c for FPU
Compiling core/packet.c for FPU
Compiling core/token.c for FPU
Compiling core/try_catch.c for FPU
Compiling rtos/rtos_weak.c for FPU
Compiling semihost/semihost.c for FPU
Compiling semihost/newlib/semihost_newlib.c for FPU
Assembling semihost/newlib/newlib_stubs.S for FPU
Compiling semihost/mbed/semihost_mbed.c for FPU
Compiling architectures/armv7-m/armv7-m.c for FPU
Assembling architectures/armv7-m/armv7-m_asm.S for FPU
Compiling memory/native/native-mem.c for FPU
Compiling devices/lpc43xx/lpc43xx_init.c for FPU
Compiling devices/lpc43xx/lpc43xx_uart.c for FPU
Assembling devices/lpc43xx/lpc43xx_asm.S for FPU
Compiling boards/bambino210/bambino210.c for FPU
Building lib/armv7-m/libmri_bambino210.a
Compiling devices/nrf52/nrf52_init.c for FPU
Compiling devices/nrf52/nrf52_uart.c for FPU
Compiling boards/nrf52dk/nrf52dk.c for FPU
Building lib/armv7-m/libmri_nrf52dk_fpu_soft.a
Compiling core/buffer.c for FPU_HARD
Compiling core/cmd_break_watch.c for FPU_HARD
Compiling core/cmd_common.c for FPU_HARD
Compiling core/cmd_continue.c for FPU_HARD
Compiling core/cmd_file.c for FPU_HARD
Compiling core/cmd_memory.c for FPU_HARD
Compiling core/cmd_query.c for FPU_HARD
Compiling core/cmd_registers.c for FPU_HARD
Compiling core/cmd_step.c for FPU_HARD
Compiling core/cmd_thread.c for FPU_HARD
Compiling core/cmd_vcont.c for FPU_HARD
Compiling core/context.c for FPU_HARD
Compiling core/gdb_console.c for FPU_HARD
Compiling core/libc.c for FPU_HARD
Compiling core/memory.c for FPU_HARD
Compiling core/mri.c for FPU_HARD
Compiling core/packet.c for FPU_HARD
Compiling core/token.c for FPU_HARD
Compiling core/try_catch.c for FPU_HARD
Compiling rtos/rtos_weak.c for FPU_HARD
Compiling semihost/semihost.c for FPU_HARD
Compiling semihost/newlib/semihost_newlib.c for FPU_HARD
Assembling semihost/newlib/newlib_stubs.S for FPU_HARD
Compiling semihost/mbed/semihost_mbed.c for FPU_HARD
Compiling architectures/armv7-m/armv7-m.c for FPU_HARD
Assembling architectures/armv7-m/armv7-m_asm.S for FPU_HARD
Compiling memory/native/native-mem.c for FPU_HARD
Compiling devices/nrf52/nrf52_init.c for FPU_HARD
Compiling devices/nrf52/nrf52_uart.c for FPU_HARD
Compiling boards/nrf52dk/nrf52dk.c for FPU_HARD
Building lib/armv7-m/libmri_nrf52dk_fpu_hard.a
Compiling devices/stm32f429xx/stm32f429xx_init.c for FPU
Compiling devices/stm32f429xx/stm32f429xx_usart.c for FPU
Assembling devices/stm32f429xx/stm32f429xx_asm.S for FPU
Compiling boards/stm32f429-disco/stm32f429-disco.c for FPU
Building lib/armv7-m/libmri_stm32f429-disco.a
+ cp lib/armv7-m/libmri_mbed1768.a /Users/adamgreen/depots/MRI-LPC1768_TestPass/gcc4mbed/mri/
+ cp lib/armv7-m/libmri_bambino210.a /Users/adamgreen/depots/MRI-LPC1768_TestPass/gcc4mbed/mri/
+ cp lib/armv7-m/libmri_stm32f429-disco.a /Users/adamgreen/depots/MRI-LPC1768_TestPass/gcc4mbed/mri/
+ cp LICENSE /Users/adamgreen/depots/MRI-LPC1768_TestPass/gcc4mbed/mri
+ cat core/mri.h core/version.h
+ popd
~/depots/MRI-LPC1768_TestPass
~/depots/MRI-LPC1768_TestPass$ make deploy
Compiling src/main.cpp
In file included from gcc4mbed/external/mbed-os/mbed.h:56,
                 from src/main.cpp:2:
gcc4mbed/external/mbed-os/platform/mbed_application.h:25:5: warning: this use of "defined" may not be portable [-Wexpansion-to-defined]
   25 | #if MBED_APPLICATION_SUPPORT
      |     ^~~~~~~~~~~~~~~~~~~~~~~~
gcc4mbed/external/mbed-os/platform/mbed_application.h:25:5: warning: this use of "defined" may not be portable [-Wexpansion-to-defined]
gcc4mbed/external/mbed-os/platform/mbed_application.h:25:5: warning: this use of "defined" may not be portable [-Wexpansion-to-defined]
Compiling gcc4mbed/src/gcc4mbed.c
Linking LPC1768/mri_tests.elf
Extracting LPC1768/mri_tests.bin
Extracting LPC1768/mri_tests.hex
Extracting disassembly to LPC1768/mri_tests.disasm
   text	   data	    bss	    dec	    hex	filename
  44008	    504	   8368	  52880	   ce90	LPC1768/mri_tests.elf

Deploying to target.
~/depots/MRI-LPC1768_TestPass$ debug mri LPC1768
GNU gdb (GNU Arm Embedded Toolchain 9-2020-q4-major) 8.3.1.20191211-git
Copyright (C) 2019 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "--host=x86_64-apple-darwin10 --target=arm-none-eabi".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from LPC1768/mri_tests.elf...
Remote debugging using /dev/tty.usbmodem1102
_start () at gcc4mbed/src/gcc4mbed.c:40
40	            __debugbreak();
(gdb) c
Continuing.

1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38	        __debugbreak();
(gdb)
```


## Verify Correct XML for Registers & Memory
KernelDebug should expose XML dictating the register and memory layout of the device on which it is running.

There should be the expected r0-r12, sp, lr, pc, xpsr, msp, psp, primask, faultfmask, and control registers as seen below:
```console
(gdb) info all-reg
r0             0xa                 10
r1             0x10002528          268444968
r2             0x0                 0
r3             0x0                 0
r4             0xe000ed90          -536810096
r5             0x100002dc          268436188
r6             0x100002dc          268436188
r7             0x0                 0
r8             0x0                 0
r9             0x0                 0
r10            0x0                 0
r11            0x0                 0
r12            0x42e3              17123
sp             0x100013f0          0x100013f0 <thread_stack_main+4084>
lr             0x7733              0x7733 <_puts_r+154>
pc             0x218               0x218 <main()+60>
xpsr           0x41000000          1090519040
msp            0x10007fc0          268468160
psp            0x100013d0          268440528
primask        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0
control        0x0                 0
```

The various RAM and FLASH locations should also be exposed as seen next:
```console
(gdb) info mem
Using memory regions provided by the target.
Num Enb Low Addr   High Addr  Attrs
0   y  	0x00000000 0x00010000 flash blocksize 0x1000 nocache
1   y  	0x00010000 0x00080000 flash blocksize 0x8000 nocache
2   y  	0x10000000 0x10008000 rw nocache
3   y  	0x1fff0000 0x1fff2000 ro nocache
4   y  	0x2007c000 0x20084000 rw nocache
5   y  	0x2009c000 0x200a0000 rw nocache
6   y  	0x22000000 0x24000000 rw nocache
7   y  	0x40000000 0x40014000 rw nocache
8   y  	0x40018000 0x4004c000 rw nocache
9   y  	0x4005c000 0x40060000 rw nocache
10  y  	0x40088000 0x400a4000 rw nocache
11  y  	0x400a8000 0x400ac000 rw nocache
12  y  	0x400b0000 0x400b4000 rw nocache
13  y  	0x400b8000 0x400c0000 rw nocache
14  y  	0x400fc000 0x40100000 rw nocache
15  y  	0x42000000 0x44000000 rw nocache
16  y  	0x50000000 0x50008000 rw nocache
17  y  	0x5000c000 0x50010000 rw nocache
18  y  	0xe0000000 0xe0100000 rw nocache
```


## Verify Bit Shift for Interrupt Priorities
The correct number of bits that the interrupt priority values should be shifted left on the Cortex-M3 in the LPC1768 is **3** since it supports 32 priority levels:
```
(gdb) p mriCortexMState.priorityBitShift
$1 = 3
```


## Verify GDB Generated Memory Faults are Handled Properly
Try to read and write from an invalid address like **0xFFFFFFF0** to verify that MRI catches the fact that a memory access initiated by GDB has led to a HardFault:
```console
(gdb) set mem inaccessible-by-default off
(gdb) x/1wx 0xfffffff0
0xfffffff0:	Cannot access memory at address 0xfffffff0
(gdb) set var *(uint32_t*)0xfffffff0=0
Cannot access memory at address 0xfffffff0
(gdb) set mem inaccessible-by-default on
```


## Test Generated Hard Fault
Use GDB to set g_selection to 1 to run ```1) Set registers to known values and crash.```

```console
1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) set var g_selection =1
(gdb) c
Continuing.
```

This test should generate a Hard Fault caused by a precise data access to address 0xFFFFFFF0 as seen below:
```
**Hard Fault**
  Status Register: 0x40000000
    Forced
**Bus Fault**
  Status Register: 0x82
    Fault Address: 0xfffffff0
    Precise Data Access

Program received signal SIGSEGV, Segmentation fault.
testContextWithCrash () at src/tests.s:44
44          ldr     r0, [r0]
```

The registers should have known values at this time, most ascending as seen in the GDB session below:
```console
(gdb) info all-reg
r0             0xfffffff0          -16
r1             0x1                 1
r2             0x2                 2
r3             0x3                 3
r4             0x4                 4
r5             0x5                 5
r6             0x6                 6
r7             0x7                 7
r8             0x8                 8
r9             0x9                 9
r10            0xa                 10
r11            0xb                 11
r12            0xc                 12
sp             0x100013d0          0x100013d0 <thread_stack_main+4052>
lr             0x23d               0x23d <main()+96>
pc             0x2fc               0x2fc <testContextWithCrash+60>
xpsr           0x81000000          -2130706432
msp            0x10007fc0          268468160
psp            0x100013b0          268440496
primask        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0
control        0x0                 0
```

Once the register contents have been verified, we can skip over the crashing instruction and let the test continue executing:
```
(gdb) set var $pc=$pc+2
(gdb) c
Continuing.
```


## Test Generated Breakpoint
Use GDB to select ```2) Set registers to known values and stop at hardcoded bkpt.```

This test should generate a debug trap caused by a hardcoded breakpoint in the test routine as seen below:
```
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) set var g_selection =2
(gdb) c
Continuing.


Program received signal SIGTRAP, Trace/breakpoint trap.
testContextWithHardcodedBreakpoint () at src/tests.s:80
80          bkpt    #0
```

The registers should have known values at this time, most ascending as seen in GDB session below:
```
(gdb) info all-reg
r0             0x0                 0
r1             0x1                 1
r2             0x2                 2
r3             0x3                 3
r4             0x4                 4
r5             0x5                 5
r6             0x6                 6
r7             0x7                 7
r8             0x8                 8
r9             0x9                 9
r10            0xa                 10
r11            0xb                 11
r12            0xc                 12
sp             0x100013d0          0x100013d0 <thread_stack_main+4052>
lr             0x243               0x243 <main()+102>
pc             0x33c               0x33c <testContextWithHardcodedBreakpoint+56>
xpsr           0x81000000          -2130706432
msp            0x10007fc0          268468160
psp            0x100013b0          268440496
primask        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0
control        0x0                 0
(gdb) bt
#0  testContextWithHardcodedBreakpoint () at src/tests.s:80
#1  0x00000242 in main () at src/main.cpp:49
(gdb)
```

Single step over the breakpoint exception as this should just cause MRI to soft step over the instruction and immediately trap on the next instruction from which we can continue execution:
```
(gdb) si
82          pop     {r4-r11}
(gdb) c
Continuing.
```

Use GDB to select ```2) Set registers to known values and stop at hardcoded bkpt``` again and then just issue a ```continue``` to let the test program resume execution. MRI will first single step over the hardcoded breakpoint and then resume execution.
```
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:36
36	        __debugbreak();
(gdb) set var g_selection =2
(gdb) c
Continuing.

Program received signal SIGTRAP, Trace/breakpoint trap.
testContextWithHardcodedBreakpoint () at src/tests.s:80
80	    bkpt    #0
(gdb) c
Continuing.
```


## Test Handler and Thread Mode Breakpoints
MRI can set breakpoints in both handler and thread mode code.

Start by setting a breakpoint in an interrupt handler that we know will be executed on a regular basis, ```SysTick_Handler``` and verifying that it gets hit soon after execution is resumed.
```console
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) break SysTick_Handler
Breakpoint 1 at 0x5f90: file HAL_CM3.S, line 315.
(gdb) c
Continuing.
Note: automatically using hardware breakpoints for read-only addresses.

Breakpoint 1, SysTick_Handler () at HAL_CM3.S:315
315     HAL_CM3.S: No such file or directory.
(gdb) bt
#0  SysTick_Handler () at HAL_CM3.S:315
#1  <signal handler called>
#2  main () at src/main.cpp:39
(gdb)
```

Now we can test breakpoints set in thread mode code by disabling the ```SysTick_Handler``` one, setting one on ```breakOnMe()``` instead, and then running test 3 which calls this function. Verify that it stops at the ```breakOnMe()``` breakpoint.
```console
(gdb) delete
Delete all breakpoints? (y or n) y
(gdb) break breakOnMe()
Breakpoint 1 at 0x10c: file src/main.cpp, line 77.
(gdb) set var g_selection=3
(gdb) c
Continuing.
Note: automatically using hardware breakpoints for read-only addresses.

Delaying 10 seconds...

Breakpoint 1, breakOnMe () at src/main.cpp:77
77          g_global++;
(gdb) bt
#0  breakOnMe () at src/main.cpp:77
#1  0x00000256 in main () at src/main.cpp:54
(gdb)
```


## Test Watchpoints
The following tests are similar to the previous except that they make sure that watchpoints work as well.

Start with a write watchpoint:
```console
(gdb) delete
Delete all breakpoints? (y or n) y
(gdb) c
Continuing.

1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) watch g_global
Hardware watchpoint 2: g_global
(gdb) set var g_selection=3
(gdb) c
Continuing.

Delaying 10 seconds...

Hardware watchpoint 2: g_global

Old value = 1
New value = 2
main () at src/main.cpp:55
55                      break;
```

Run the same test as above but for a read watchpoint:
```
(gdb) delete
Delete all breakpoints? (y or n) y
(gdb) c
Continuing.

1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) rwatch g_global
Hardware read watchpoint 3: g_global
(gdb) set var g_selection=3
(gdb) c
Continuing.

Delaying 10 seconds...

Hardware read watchpoint 3: g_global

Value = 3
breakOnMe () at src/main.cpp:78
78          __DSB();
```


## Test Threaded Single Stepping
When single stepping through a thread with GDB, KernelDebug will typically disable interrupts that would allow context switching to other threads. When single stepping over functions (next/nexti) then the other threads will be allowed to run. This test shows debug output spew being generated from 2 threads while single stepping through one of them.

Set a breakpoint on "thread2Func" and then use GDB to select ```4) Run 2 threads at normal priority```

```console
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
(gdb) delete
Delete all breakpoints? (y or n) y
(gdb) c
Continuing.

1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:36
36	        __debugbreak();
(gdb) break thread2Func
Breakpoint 1 at 0x120: file src/main.cpp, line 112.
(gdb) set var g_selection=4
(gdb) c
Continuing.
Note: automatically using hardware breakpoints for read-only addresses.

Set g_stop to true to end test...

Breakpoint 5, thread2Func (pv=0x0 <osRegisterForOsEvents>) at src/main.cpp:112
112     {
(gdb) bt
#0  thread2Func (pv=0x0 <osRegisterForOsEvents>) at src/main.cpp:112
#1  0x00004364 in ?? () at gcc4mbed/external/mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_CMSIS.c:1537
Backtrace stopped: previous frame identical to this frame (corrupt stack?)
(gdb) n
115             wait_ms(2000);
(gdb)
Thread1 Output

116             printf("Thread2 Output\n");
(gdb)
Thread2 Output
113         while (true )
(gdb)
115             wait_ms(2000);
(gdb)
Thread1 Output
Thread1 Output
116             printf("Thread2 Output\n");
(gdb)
Thread2 Output
113         while (true )
(gdb) ni
115             wait_ms(2000);
(gdb)
0x00000128      115             wait_ms(2000);
(gdb)
Thread1 Output

Thread1 Output
116             printf("Thread2 Output\n");
(gdb)
0x0000012e      116             printf("Thread2 Output\n");
(gdb)
Thread2 Output
113         while (true )
(gdb)
115             wait_ms(2000);
(gdb)
0x00000128      115             wait_ms(2000);
(gdb)
Thread1 Output
Thread1 Output
116             printf("Thread2 Output\n");
```


# CTRL+C During Long Single Step
When stepping over the ```delay(2000)``` calls, try pressing CTRL+C to break in and dump the callstack.

```console
(gdb) n
Thread2 Output
113         while (true )
(gdb)
115             wait_ms(2000);
(gdb)
Thread1 Output
^C
Program received signal SIGINT, Interrupt.
0x000001b2 in runThreads (thread2Priority=<optimized out>, thread1Priority=osPriorityNormal) at src/main.cpp:93
93          while (!g_stop)
(gdb) bt
#0  0x000001b2 in runThreads (thread2Priority=<optimized out>, thread1Priority=osPriorityNormal) at src/main.cpp:93
#1  0x0000025e in main () at src/main.cpp:57
```

Set ```g_stop``` to 1 to stop the current test.
```console
(gdb) set var g_stop=1
(gdb) c
Continuing.

1) Set registers to known values and crash.
2) Set registers to known values and stop at hardcoded bkpt.
3) Call breakOnMe() to increment g_global
4) Run 2 threads at normal priority
5) Run Semi-Hosting tests
6) Trigger mbed hard fault handler
Set selection in g_selection:

Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:38
38              __debugbreak();
```


## Semi-Hosting
MRI is able to redirect mbed LocalFileSystem I/O to access the local filesystem on the GDB host.

Use GDB to select ```5) Run Semi-Hosting tests``` and verify that all of its tests run successfully.

```console
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:36
36              __debugbreak();
(gdb) set var g_selection =5
(gdb) c
Continuing.
LocalFileSystem/Semi-hosting Tests
Test 1: fopen() for write
Test 2: fprintf()
Test 3: fclose() on written file
Test 4: fopen() for read
Test 5: fscanf()
Contents of /local/out.txt: Hello
Test 6: Determine size of file through fseek and ftell calls
Test 7: fclose() on read file
Test 8: remove()

Test completed
```

## HardFault in Handler Mode
MRI can debug crashes encountered in handler mode code.

Use GDB to select ```6) Trigger mbed hard fault handler```

This should lead to a stacking exception as seen below:

```console
Program received signal SIGTRAP, Trace/breakpoint trap.
main () at src/main.cpp:35
35              __debugbreak();
(gdb) set var g_selection=6
(gdb) c
Continuing.


**Hard Fault**
  Status Register: 0x40000000
    Forced
**Bus Fault**
  Status Register: 0x10
    Stacking Error w/ SP = 0xffffffd0

Program received signal SIGSEGV, Segmentation fault.
0xdeaddeac in ?? ()
(gdb) info all-reg
r0             0xdeaddead          -559030611
r1             0xdeaddead          -559030611
r2             0xdeaddead          -559030611
r3             0xdeaddead          -559030611
r4             0x100002dc          268436188
r5             0x100002dc          268436188
r6             0x0                 0
r7             0x0                 0
r8             0x0                 0
r9             0x0                 0
r10            0x0                 0
r11            0x0                 0
r12            0xdeaddead          -559030611
sp             0x9908              0x9908 <g_targetXml+4>
lr             0xdeaddead          0xdeaddead
pc             0xdeaddead          0xdeaddead
xpsr           0xdeaddead          -559030611
msp            0x10007fc0          268468160
psp            0xffffffd0          -48
primask        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0
control        0x0                 0
```
