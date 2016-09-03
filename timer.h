/* 
 * The MIT License (MIT)
 * 
 * ESP8266 Non-OS Firmware
 * Copyright (c) 2015 Michael Jacobsen (github.com/mikejac)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <github.com/mikejac/misc.esp8266-nonos.cpp/espmissingincludes.h>
#include "user_interface.h"

#define millis()    (system_get_time() / 1000)

typedef struct {
    uint32_t interval_start_ms;
    uint32_t interval_ms;
} Timer;

#define Timer_initializer { 0, 0 }

/**
 * 
 * @param timer
 * @return 
 */
char expired(Timer* timer);
/**
 * 
 * @param timer
 * @return 
 */
char enabled(Timer* timer);
/**
 * 
 * @param timer
 * @param timeout
 */
void countdown_ms(Timer* timer, unsigned long ms);
/**
 * 
 * @param timer
 * @param seconds
 */
void countdown(Timer* timer, unsigned int seconds);
/**
 * 
 * @param timer
 * @return 
 */
int left_ms(Timer* timer);
/**
 * 
 * @param timer
 */
void InitTimer(Timer* timer);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

