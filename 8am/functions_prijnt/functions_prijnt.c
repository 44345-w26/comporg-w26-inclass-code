#include <stdio.h>
#include "pico/stdlib.h"
int var; // Bad Idea (tm)

const float GRAVITY = 9.8; // Good Idea (tm)
const int ONE = 2; // TOO FAR!!!

void print_numbers(int a, int b);
void swapi(int * a, int * b);

struct weather {
    int temperature; // 4B
    float humidity; // 4B
    char temp_label; // 1B
    bool is_raining; // 1B
};

int main()
{
    int x = 5;
    int y = 32;
    // pointer
    int * x_addr;
    x_addr = &x;



    struct weather today; // today: .skip 12
    today.temperature = 56;
    today.humidity = 63.2;
    today.is_raining = false;

    stdio_init_all();

    while (true) {
        /*printf("Hello, world!\n");
        printf("size of bool: %d\n", sizeof(bool));
        printf("size of weather: %d\n", sizeof(today));*/
        /*printf("Address of today's temperature: 0x%X\n",
               &(today.temperature));
        printf("Address of today's humidity: 0x%X\n",
               &(today.humidity));
        printf("Address of today's temp_label: 0x%X\n",
               &(today.temp_label));
        printf("Address of today's is_raining: 0x%X\n",
               &(today.is_raining));
        // & means address of
        printf("Address of today: 0x%X\n", &today);*/
        print_numbers(x, y);
        swapi(&x, &y);
        //printf("x: %d\n", x);
        printf("x's address: 0x%x\n", &x);
        printf("x_addr: 0x%x\n", x_addr);
        // dereference the pointer
        printf("value at x_addr: %d\n", *x_addr);
        *x_addr += 1;
        sleep_ms(1000);
    }
}

// pass by value
void print_numbers(int a, int b)
{
    printf("Numbers are: %d, %d\n", a, b);
}

// pass by "reference"
void swapi(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
