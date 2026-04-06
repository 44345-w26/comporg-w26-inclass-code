.global main
.func main
.thumb_func

.equ    BUZZ, 1

.data
.balign 4
gpio_oe:    .word   0xd0000024
gpio_on:    .word   0xd0000014
gpio_off:   .word   0xd0000018
clockdelay: .word   62500000
freq:   .word   440

.text
.balign 4
main:
    movs    r0, #BUZZ
    bl  gpio_init
    movs    r4, #2
    ldr r1, =gpio_oe
    ldr r1, [r1]
    str r4, [r1]

    ldr r0, =freq
    ldr r0, [r0]

forever:
    ldr r1, =gpio_on
    ldr r1, [r1]
    str r4, [r1]

    bl freqsleep
    
    ldr r1, =gpio_off
    ldr r1, [r1]
    str r4, [r1]
    
    bl freqsleep

    b forever

freqsleep:
    push {lr}
    ldr r1, =clockdelay
    ldr r1, [r1]
    lsr r1, #2
delayloop:
    sub r1, r1, r0
    cmp r1, r0
    bge delayloop

    pop {pc}