PROJECT           := mri_tests
DEVICES           := LPC1768
SRC               := src
GCC4MBED_DIR      := gcc4mbed
NO_FLOAT_SCANF    := 1
MRI_ENABLE        := 1

include $(GCC4MBED_DIR)/build/gcc4mbed.mk
