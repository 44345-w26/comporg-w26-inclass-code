.global main
.func main
.thumb_func

.data
.balign 4
arr1:   .word   10,20,30,40
arr2:   .skip   20
msg:    .asciz  "val: %d\n"

.text
.balign 4
main:  
    bl stdio_init_all
loop:
    ldr r0, =1000
    bl sleep_ms
    ldr r0, =msg
    ldr r1, =arr1
    add r1, #4
    ldr r1, [r1, #4]
    bl printf
    b loop