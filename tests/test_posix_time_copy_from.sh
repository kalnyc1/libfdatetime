#!/bin/bash
#
# Date and time library POSIX time copy from testing script
#
# Copyright (c) 2009-2012, Joachim Metz <jbmetz@users.sourceforge.net>
#
# Refer to AUTHORS for acknowledgements.
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.
#

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

test_posix_time_copy_from()
{ 
	echo "Testing POSIX time copy from function";

	./${FDATETIME_TEST_POSIX_TIME_COPY_FROM};

	RESULT=$?;

	echo "";

	return ${RESULT};
}

FDATETIME_TEST_POSIX_TIME_COPY_FROM="fdatetime_test_posix_time_copy_from";

if ! test -x ${FDATETIME_TEST_POSIX_TIME_COPY_FROM};
then
	FDATETIME_TEST_POSIX_TIME_COPY_FROM="fdatetime_test_posix_time_copy_from.exe";
fi

if ! test -x ${FDATETIME_TEST_POSIX_TIME_COPY_FROM};
then
	echo "Missing executable: ${FDATETIME_TEST_POSIX_TIME_COPY_FROM}";

	exit ${EXIT_FAILURE};
fi

if ! test_posix_time_copy_from;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

