.global main
.func main
.thumb_func

.equ LED, 26

.data
.balign 4
gpio_oe:    .word   0xd0000024
gpio_on:    .word   0xd0000014
gpio_off:   .word   0xd0000018
delay:  .word   1000

.text
.balign 4
main:
    movs    r0, #LED @ #26
    bl gpio_init
    movs    r0, #1
    lsl r0, #LED
    ldr r1, =gpio_oe
    ldr r1, [r1]
    str r0, [r1]
    ldr r1, =gpio_on
    ldr r1, [r1]
    str r0, [r1]
    ldr r0, =delay
    ldr r0, [r0]
    bl sleep_ms
    movs    r0, #1
    lsl r0, #LED
    ldr r1, =gpio_off
    ldr r1, [r1]
    str r0, [r1]