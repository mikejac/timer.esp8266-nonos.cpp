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

#include "timer.h"

//
// 32bit max value = 4,294,967,295 => 4,294,967,295 us = 4,294,967.295 ms == 4.294 seconds = 71 minutes
//

/**
 * 
 * @param timer
 * @return 
 */
char expired(Timer* timer)
{
    if(timer->interval_ms == 0) {
        return 0;
    }
    
    return (millis() - timer->interval_start_ms >= timer->interval_ms) ? 1 : 0;
}
/**
 * 
 * @param timer
 * @return 
 */
char enabled(Timer* timer)
{
    return (timer->interval_ms == 0) ? 0 : 1;
}
/**
 * 
 * @param timer
 * @param timeout
 */
void countdown_ms(Timer* timer, unsigned long ms)
{
    timer->interval_ms       = ms;
    timer->interval_start_ms = millis();
}
/**
 * 
 * @param timer
 * @param seconds
 */
void countdown(Timer* timer, unsigned int seconds)
{
    countdown_ms(timer, (unsigned long)seconds * 1000L);
}
/**
 * 
 * @param timer
 * @return 
 */
int left_ms(Timer* timer)
{
    return millis() - (timer->interval_start_ms + timer->interval_ms);
    //return timer->interval_end_ms - millis();
}
/**
 * 
 * @param timer
 */
void InitTimer(Timer* timer)
{
    timer->interval_ms       = 0;
    timer->interval_start_ms = 0;
}
