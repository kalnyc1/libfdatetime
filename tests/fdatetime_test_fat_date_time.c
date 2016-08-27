/*
 * Library FAT date time type testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fdatetime_test_libfdatetime.h"
#include "fdatetime_test_libcerror.h"
#include "fdatetime_test_libcstring.h"
#include "fdatetime_test_macros.h"
#include "fdatetime_test_memory.h"
#include "fdatetime_test_unused.h"

/* Tests the libfdatetime_fat_date_time_initialize function
 * Returns 1 if successful or 0 if not
 */
int fdatetime_test_fat_date_time_initialize(
     void )
{
	libfdatetime_fat_date_time_t *fat_date_time = NULL;
	libcerror_error_t *error                    = NULL;
	int result                                  = 0;

	/* Test libfdatetime_fat_date_time_initialize without entries
	 */
	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "fat_date_time",
         fat_date_time );

        FDATETIME_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfdatetime_fat_date_time_free(
	          &fat_date_time,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FDATETIME_TEST_ASSERT_IS_NULL(
         "fat_date_time",
         fat_date_time );

        FDATETIME_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfdatetime_fat_date_time_initialize(
	          NULL,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	fat_date_time = (libfdatetime_fat_date_time_t *) 0x12345678UL;

	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	fat_date_time = NULL;

#if defined( HAVE_FDATETIME_TEST_MEMORY )

	/* Test libfdatetime_fat_date_time_initialize with malloc failing
	 */
	fdatetime_test_malloc_attempts_before_fail = 0;

	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	if( fdatetime_test_malloc_attempts_before_fail != -1 )
	{
		fdatetime_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		FDATETIME_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FDATETIME_TEST_ASSERT_IS_NULL(
		 "fat_date_time",
		 fat_date_time );

		FDATETIME_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfdatetime_fat_date_time_initialize with memset failing
	 */
	fdatetime_test_memset_attempts_before_fail = 0;

	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	if( fdatetime_test_memset_attempts_before_fail != -1 )
	{
		fdatetime_test_memset_attempts_before_fail = -1;
	}
	else
	{
		FDATETIME_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		FDATETIME_TEST_ASSERT_IS_NULL(
		 "fat_date_time",
		 fat_date_time );

		FDATETIME_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FDATETIME_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( fat_date_time != NULL )
	{
		libfdatetime_fat_date_time_free(
		 &fat_date_time,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfdatetime_fat_date_time_free function
 * Returns 1 if successful or 0 if not
 */
int fdatetime_test_fat_date_time_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfdatetime_fat_date_time_free(
	          NULL,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfdatetime_fat_date_time_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fdatetime_test_fat_date_time_copy_from_byte_stream(
     void )
{
	uint8_t byte_stream[ 4 ] = { 0x0c, 0x3d, 0xd0, 0xa8 };

	libfdatetime_fat_date_time_t *fat_date_time = NULL;
	libcerror_error_t *error                    = NULL;
	int result                                  = 0;

	/* Initialize test
	 */
	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	/* Test copy from byte stream
	 */
	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          byte_stream,
	          4,
	          LIBFDATETIME_ENDIAN_BIG,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FDATETIME_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          byte_stream,
	          4,
	          LIBFDATETIME_ENDIAN_LITTLE,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        FDATETIME_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          NULL,
	          byte_stream,
	          4,
	          LIBFDATETIME_ENDIAN_LITTLE,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          NULL,
	          4,
	          LIBFDATETIME_ENDIAN_LITTLE,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          byte_stream,
	          2,
	          LIBFDATETIME_ENDIAN_LITTLE,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          byte_stream,
	          4,
	          100,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfdatetime_fat_date_time_free(
	          &fat_date_time,
	          NULL );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( fat_date_time != NULL )
	{
		libfdatetime_fat_date_time_free(
		 &fat_date_time,
		 NULL );
	}
	return( 0 );
}


/* Tests the libfdatetime_fat_date_time_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fdatetime_test_fat_date_time_copy_to_utf8_string_with_index(
     void )
{
	uint8_t date_time_string[ 32 ];

	uint8_t byte_stream[ 4 ] = { 0x0c, 0x3d, 0xd0, 0xa8 };

	libfdatetime_fat_date_time_t *fat_date_time = NULL;
	libcerror_error_t *error                    = NULL;
	size_t string_index                         = 0;
	int result                                  = 0;

	/* Initialize test
	 */
	result = libfdatetime_fat_date_time_initialize(
	          &fat_date_time,
	          &error );

	result = libfdatetime_fat_date_time_copy_from_byte_stream(
	          fat_date_time,
	          byte_stream,
	          4,
	          LIBFDATETIME_ENDIAN_BIG,
	          &error );

	/* Test error cases
	 */
	result = libfdatetime_fat_date_time_copy_to_utf8_string_with_index(
	          NULL,
	          date_time_string,
	          32,
	          &string_index,
	          LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_to_utf8_string_with_index(
	          fat_date_time,
	          NULL,
	          32,
	          &string_index,
	          LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_to_utf8_string_with_index(
	          fat_date_time,
	          date_time_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfdatetime_fat_date_time_copy_to_utf8_string_with_index(
	          fat_date_time,
	          date_time_string,
	          32,
	          NULL,
	          LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
	          &error );

	FDATETIME_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        FDATETIME_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfdatetime_fat_date_time_free(
	          &fat_date_time,
	          NULL );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( fat_date_time != NULL )
	{
		libfdatetime_fat_date_time_free(
		 &fat_date_time,
		 NULL );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FDATETIME_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FDATETIME_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FDATETIME_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FDATETIME_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FDATETIME_TEST_UNREFERENCED_PARAMETER( argc )
	FDATETIME_TEST_UNREFERENCED_PARAMETER( argv )

	FDATETIME_TEST_RUN(
	 "libfdatetime_fat_date_time_initialize",
	 fdatetime_test_fat_date_time_initialize() )

	FDATETIME_TEST_RUN(
	 "libfdatetime_fat_date_time_free",
	 fdatetime_test_fat_date_time_free() )

	FDATETIME_TEST_RUN(
	 "libfdatetime_fat_date_time_copy_from_byte_stream",
	 fdatetime_test_fat_date_time_copy_from_byte_stream() )

	/* TODO: add test for libfdatetime_fat_date_time_copy_from_32bit */
	/* TODO: add test for libfdatetime_fat_date_time_get_string_size */
	/* TODO: add test for libfdatetime_fat_date_time_copy_to_utf8_string */

	FDATETIME_TEST_RUN(
	 "libfdatetime_fat_date_time_copy_to_utf8_string_with_index",
	 fdatetime_test_fat_date_time_copy_to_utf8_string_with_index() )

	/* TODO: add test for libfdatetime_fat_date_time_copy_to_utf16_string */
	/* TODO: add test for libfdatetime_fat_date_time_copy_to_utf16_string_with_index */
	/* TODO: add test for libfdatetime_fat_date_time_copy_to_utf32_string */
	/* TODO: add test for libfdatetime_fat_date_time_copy_to_utf32_string_with_index */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
