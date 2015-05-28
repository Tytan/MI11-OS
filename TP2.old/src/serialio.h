/*
 Copyright 2012 Stéphane Bonnet (bonnetst@utc.fr)

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef SERIALIO_H_
#define SERIALIO_H_

#include <stdarg.h>
#include "imx_serial.h"

int getchar(void);
int putchar(int c);
int puts(const char *s);

/* printf et sprintf supportent les formats s, d, x, X, u et c et les options
 * de padding associées.
 */
int printf(const char *format, ...);
int sprintf(char *out, const char *format, ...);

#endif /* SERIALIO_H_ */
