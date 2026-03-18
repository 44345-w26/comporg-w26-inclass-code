.global main
.func main
.thumb_func

.equ    LED, 26

.data
.balign 4
gpio_oe:    .word   0xd0000024
gpio_on:    .word   0xd0000014
gpio_off:   .word   0xd0000018
delay:  .word   1000

.text
.balign 4
main:
    movs    r0, #LED @ equiv to #26
    bl gpio_init
    movs    r1, #1
    lsl r1, #LED
    ldr r2, =gpio_oe
    ldr r2, [r2]
    str r1, [r2]
    ldr r2, =gpio_on
    ldr r2, [r2]
    str r1, [r2]
    ldr r0, =delay
    ldr r0, [r0]
    bl sleep_ms
    movs    r1, #1
    lsl r1, #LED
    ldr r2, =gpio_off
    ldr r2, [r2]
    str r1, [r2]