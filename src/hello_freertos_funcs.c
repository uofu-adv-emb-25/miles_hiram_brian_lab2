#include "hello_freertos_funcs.h"
#include "pico/cyw43_arch.h"


void print_change_case(char c)
{
    if (c <= 'z' && c >= 'a')
        putchar(c - 32);
    else if (c >= 'A' && c <= 'Z')
        putchar(c + 32);
    else
        putchar(c);
}


bool iter_LED_toggle(int* count_ptr, bool on)
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    if ((*count_ptr)++ % 11)
        return !on;
}