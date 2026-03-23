.global main
.func main
.thumb_func

.equ    BUZZ, 1

.data
.balign 4
gpio_oe:    .word   0xd0000024
gpio_on:    .word   0xd0000014
gpio_off:   .word   0xd0000018

.text
.balign 4
main:
    movs    r0, #BUZZ
    bl  gpio_init
    movs    r0, #2
    ldr r1, =gpio_oe
    ldr r1, [r1]
    str r0, [r1]

forever:
    ldr r1, =gpio_on
    ldr r1, [r1]
    str r0, [r1]
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    ldr r1, =gpio_off
    ldr r1, [r1]
    str r0, [r1]
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    b forever