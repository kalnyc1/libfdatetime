/*
 * The internal type definitions
 *
 * Copyright (c) 2009-2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFDATETIME_INTERNAL_TYPES_H )
#define _LIBFDATETIME_INTERNAL_TYPES_H

#include <common.h>
#include <types.h>

/* Define HAVE_LOCAL_LIBFDATETIME for local use of libfdatetime
 * The definitions in <libfdatetime/types.h> are copied here
 * for local use of libfdatetime
 */
#if defined( HAVE_LOCAL_LIBFDATETIME )

/* The following type definitions hide internal data structures
 */
typedef intptr_t libfdatetime_fat_date_time_t;
typedef intptr_t libfdatetime_fat_date_t;
typedef intptr_t libfdatetime_fat_time_t;
typedef intptr_t libfdatetime_filetime_t;
typedef intptr_t libfdatetime_nsf_timedate_t;

#endif

#endif

