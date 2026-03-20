.global main
.func main
.thumb_func

.equ LED, 26

.data
.balign 4
gpio_oe:    .word   0xd0000024
gpio_on:    .word   0xd0000014
gpio_off:   .word   0xd0000018
gpio_in:    .word   0xd0000004
delay:  .word   1000

.text
.balign 4
main:
    movs    r0, #LED @ #26
    bl gpio_init
    movs    r0, #27
    bl gpio_init
    movs    r0, #4
    bl gpio_init
    movs    r0, #3
    lsl r0, #LED
    ldr r1, =gpio_oe
    movs    r0, #1
    lsl r0, #LED
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
loop:
    ldr r1, =gpio_in
    ldr r1, [r1]
    ldr r0, [r1]
    lsr r0, #4
    lsl r0, #LED
    ldr r1, =gpio_on
    ldr r1, [r1]
    str r0, [r1]
    lsr r0, #LED
    mov r1, #1
    eor r0, r1
    lsl r0, #LED
    ldr r1, =gpio_off
    ldr r1, [r1]
    str r0, [r1]
    b loop