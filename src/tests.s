/* Copyright (C) 2020  Adam Green (https://github.com/adamgreen)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/* Implementation of code to place known values in registers to verify context reading code. */
    .text
    .syntax unified

    .global testContextWithCrash
    .type testContextWithCrash, %function
    .thumb_func
    /* extern "C" void testContextWithCrash(void);
       Sets all of the registers to a known value to make sure that context is being read correctly.
    */
testContextWithCrash:
    push        {r4-r11}
    // Load known values into R0-R12
    mov     r0, #0
    mov     r1, #1
    mov     r2, #2
    mov     r3, #3
    mov     r4, #4
    mov     r5, #5
    mov     r6, #6
    mov     r7, #7
    mov     r8, #8
    mov     r9, #9
    mov     r10, #10
    mov     r11, #11
    mov     r12, #12
    // Crash on read from invalid memory.
    // "set var $pc=$pc+2" in GDB to resume.
    ldr     r0, =0xFFFFFFF0
    ldr     r0, [r0]
    // Restore non-volatile registers and return to caller.
    pop     {r4-r11}
    bx      lr
    // Let assembler know that we have hit the end of the function.
    .pool
    .size   testContextWithCrash, .-testContextWithCrash


/* Implementation of code to place known values in registers to verify context reading code. */
    .text
    .syntax unified

    .global testContextWithHardcodedBreakpoint
    .type testContextWithHardcodedBreakpoint, %function
    .thumb_func
    /* extern "C" void testContextWithHardcodedBreakpoint(void);
       Sets all of the registers to a known value to make sure that context is being read correctly.
    */
testContextWithHardcodedBreakpoint:
    push        {r4-r11}
    // Load known values into R0-R12
    mov     r0, #0
    mov     r1, #1
    mov     r2, #2
    mov     r3, #3
    mov     r4, #4
    mov     r5, #5
    mov     r6, #6
    mov     r7, #7
    mov     r8, #8
    mov     r9, #9
    mov     r10, #10
    mov     r11, #11
    mov     r12, #12
    // Hardcoded breakpoint.
    bkpt    #0
    // Restore non-volatile registers and return to caller.
    pop     {r4-r11}
    bx      lr
    // Let assembler know that we have hit the end of the function.
    .pool
    .size   testContextWithHardcodedBreakpoint, .-testContextWithHardcodedBreakpoint


    .text
    .syntax unified

    .global testStackingHandlerException
    .type testStackingHandlerException, %function
    .thumb_func
    /* extern "C" void testStackingHandlerException(void);
       Sets PSP to an invalid value which will cause a stacking exception that trigger mbed fault handler.
    */
testStackingHandlerException:
    mov         r0,#0xfffffff0
    msr         psp,r0
    bkpt        #0
    bx          lr
    // Let assembler know that we have hit the end of the function.
    .pool
    .size   testStackingHandlerException, .-testStackingHandlerException


    .end