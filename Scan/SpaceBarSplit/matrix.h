/* Copyright (C) 2016 by Glen Hertz
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
 */

#pragma once

// ----- Includes -----

// Project Includes
#include <matrix_setup.h>
// ----- Matrix Definition -----

// Freescale ARM MK20's support GPIO PTA, PTB, PTC, PTD and PTE 0..31
// Not all chips have access to all of these pins (most don't have 160 pins :P)
//
// NOTE:
// Before using a pin, make sure it supports being a GPIO *and* doesn't have a default pull-up/pull-down
// Checking this is completely on the ownness of the user

// Slothman
//
// Column (Strobe) - 16 total
//  Pin 0..15 (see https://github.com/kiibohd/controller/blob/master/Lib/pin_map.teensy3)
//
// Rows (Sense) - 5 Total
//  Pin 16..20

// Define Rows (Sense) and Columns (Strobes)
GPIO_Pin Matrix_cols[] = { 
//From Pin 15 to 0 (Esc to backspace)
gpio(C,0),  // Pin 15 (Far left, from outside)
gpio(D,1),  // Pin 14
gpio(D,6),  // Pin 21
gpio(C,7),  // Pin 12
gpio(C,6),  // Pin 11
gpio(C,4),  // Pin 10
gpio(C,3),  // Pin  9
gpio(D,3),  // Pin  8
gpio(D,2),  // Pin  7
gpio(D,4),  // Pin  6
gpio(D,7),  // Pin  5
gpio(A,13), // Pin  4
gpio(A,12), // Pin  3
gpio(D,0),  // Pin  2
gpio(B,17), // Pin  1
gpio(B,16)  // Pin  0 (Far right)
};
GPIO_Pin Matrix_rows[] = { 
// From Pin 20 to 16 (Bot to top):
gpio(D,5),  // Pin 20
gpio(B,2),  // Pin 19
gpio(C,1),  // Pin 22
gpio(B,1),  // Pin 17
gpio(B,0)   // Pin 16
 };

// Define type of scan matrix
Config Matrix_type = Config_Pulldown;

