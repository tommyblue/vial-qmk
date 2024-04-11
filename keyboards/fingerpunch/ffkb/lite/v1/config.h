/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

// wiring
#ifdef FP_CONVERT_TO_SVLINKY
#define MATRIX_ROW_PINS \
    { GP0, GP1, GP23, GP21 }
#define MATRIX_COL_PINS \
    { GP8, GP7, GP6, GP5, GP4, GP9, GP29, GP28, GP27, GP26, GP22, GP20 }
#else
#define MATRIX_ROW_PINS \
    { D3, D2, B2, B6 }
#define MATRIX_COL_PINS \
    { B4, E6, D7, C6, D4, B5, F4, F5, F6, F7, B1, B3 }
#endif