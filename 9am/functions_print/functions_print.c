#include <stdio.h>
#include "pico/stdlib.h"

void print_numbers(int a, int b);
void swapi(int * a, int * b);

double myvar; // Bad Idea (tm)
const float PI = 3.1415; // Good Idea (tm)
const double GRAVITY = 9.8;
const int EIGHT = 9; // TOO FAR

struct weather {
    int temperature; // 4B
    double humidity; // 8B
    bool is_raining; // 1B
    char temp_label; // 1B
}; 



int main()
{
    int x = 5;
    int y = 32;
    // pointers
    int *x_addr;
    x_addr = &x;

    struct weather today; // today: .skip 24

    stdio_init_all();

    today.temperature = 62;
    today.humidity = 59.4;

    while (true) {
        /*printf("Hello, world!\n");
        printf("Function Address: %x\n", print_numbers);
        printf("Size of weather: %d\n", sizeof(today));
        printf("Address of today: 0x%X\n", &today);
        printf("Address of today's temperature: 0x%X\n",
               &(today.temperature));
        printf("Address of today's humidity: 0x%X\n",
               &(today.humidity));
        printf("Address of today's is_raining: 0x%X\n",
               &(today.is_raining));
        printf("Address of today's temp_label: 0x%X\n",
               &(today.temp_label));
        print_numbers(8, 10);*/
        print_numbers(x, y);
        printf("x is %d\n", x);
        printf("Address of x is 0x%x\n", &x);
        printf("x_addr is 0x%x\n", x_addr);
        // dereference
        printf("thing at x_addr is %d\n", *x_addr);
        swapi(&x, &y);
        *x_addr += 1;
        sleep_ms(1000);
    }
}

// pass by value
void print_numbers(int a, int b)
{
    printf("The numbers are %d, %d\n", a, b);
}

// pass by "reference"
void swapi(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}