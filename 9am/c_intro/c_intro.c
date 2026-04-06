#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED 26

int main()
{
    gpio_init(LED);
    gpio_set_dir(26, true);

    bool state = true;
    int myi;
    short mys = 5;
    long myl = 15;
    char myc = 'c';
    stdio_init_all();

    while (true) {
        gpio_put(LED, state);
        state = !state;
        printf("Hello, world!\n");
        printf("Size of short: %d\n", sizeof(mys));
        printf("Size of int: %d\n", sizeof(int));
        printf("Size of long: %d\n", sizeof(myl));
        printf("Size of long long: %d\n", sizeof(long long));
        printf("Size of char: %d\n", sizeof(myc));
        sleep_ms(1000);
    }
}
