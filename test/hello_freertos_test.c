#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include <pico/cyw43_arch.h>
#include "hello_freertos_funcs.h"

void setUp(void) {}

void tearDown(void) {}

void test_change_case()
{
    TEST_ASSERT_EQUAL('h', change_case('H'));
    TEST_ASSERT_EQUAL('h' - 1, change_case('H' - 1));
    TEST_ASSERT_EQUAL('E', change_case('e'));
    TEST_ASSERT_EQUAL('l', change_case('L'));
    TEST_ASSERT_EQUAL('L', change_case('l'));
    TEST_ASSERT_EQUAL('O', change_case('o'));
    TEST_ASSERT_EQUAL(112, change_case('Z' - 10));
    TEST_ASSERT_EQUAL('!', change_case('!'));
    TEST_ASSERT_EQUAL('%', change_case('%'));
    TEST_ASSERT_EQUAL('*', change_case('*'));
    TEST_ASSERT_EQUAL('4', change_case('4'));
    TEST_ASSERT_EQUAL('9', change_case('9'));
    TEST_ASSERT_EQUAL('+', change_case('+'));
}

void test_iter_LED_toggle(void)
{
    int count = 0;
    bool on = 0;
    for (int i = 0; i < 100; i++)
    {
        int prev_count = count;
        bool prev_on = on;

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        int led_status = cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN);
        TEST_ASSERT_EQUAL_MESSAGE(led_status, on, "GPIO LED state does not match boolean flag");

        iter_LED_toggle(&count, &on);

        TEST_ASSERT_EQUAL_MESSAGE(count, (prev_count+1), "Count did not increment by 1");

        if (prev_count % 11)
            TEST_ASSERT_NOT_EQUAL_MESSAGE(on, prev_on, "LED on flag did not toggle values properly");
        else
            TEST_ASSERT_EQUAL_MESSAGE(on, prev_on, "LED blink did not delay after 5 blinks");      

    }
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    hard_assert(cyw43_arch_init() == PICO_OK);
    while (1)
    {
        printf("Start tests\n");
        UNITY_BEGIN();
        RUN_TEST(test_change_case);
        RUN_TEST(test_iter_LED_toggle);
        sleep_ms(5000);
        UNITY_END();
    }
}
