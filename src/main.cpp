/*
 * Copyright (c) 2020-2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "swo.h"

using namespace sixtron;

namespace {
#define PERIOD_MS 1000
}

static DigitalOut led1(LED1);
static SWO swo;

int main()
{
    while (true) {
        led1 = !led1;
        if (led1) {
            swo.printf("Alive!\n");
        }
        ThisThread::sleep_for(PERIOD_MS / 2);
    }
}
