AC_PREREQ( 2.59 )

AC_INIT(
 [libfdatetime],
 [20161107],
 [joachim.metz@gmail.com])

AC_CONFIG_SRCDIR(
 [include/libfdatetime.h.in])

AM_INIT_AUTOMAKE([gnu 1.6 tar-ustar])

AC_CONFIG_MACRO_DIR([m4])

dnl Check for host type
AC_CANONICAL_HOST

dnl Check for large file support
AC_SYS_LARGEFILE

dnl Check for libtool DLL support
AC_LIBTOOL_WIN32_DLL

dnl Checks for programs
AC_PROG_CC
AC_PROG_GCC_TRADITIONAL
AC_PROG_MAKE_SET
AC_PROG_INSTALL

dnl Check for libtool
AC_PROG_LIBTOOL
AC_SUBST(LIBTOOL_DEPS)

dnl Check for pkg-config
AC_PATH_PROG(PKGCONFIG,[pkg-config])

dnl Support of internationalization (i18n)
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.18.1])

dnl Check for compiler language support
AC_C_CONST
AC_C_VOLATILE

dnl Check if WINAPI support should be enabled
AX_COMMON_CHECK_ENABLE_WINAPI

dnl Check for type definitions
AX_TYPES_CHECK_LOCAL

dnl Checks for libraries and library functions
AX_COMMON_CHECK_LOCAL

dnl Check for enabling libcerror for cross-platform C error functions
AX_LIBCERROR_CHECK_ENABLE

dnl Headers included in various places
AC_CHECK_HEADERS([stdarg.h varargs.h])

AS_IF(
 [test "x$ac_cv_header_stdarg_h" != xyes && test "x$ac_cv_header_varargs_h" != xyes],
 [AC_MSG_FAILURE(
  [Missing headers: stdarg.h and varargs.h],
  [1])
 ])

dnl Check for test function support
AX_TESTS_CHECK_LOCAL

dnl Check if DLL support is needed
AS_IF(
 [test "x$enable_shared" = xyes],
 [AS_CASE(
  [$host],
  [*cygwin* | *mingw*],
  [AC_DEFINE(
   [HAVE_DLLMAIN],
   [1],
   [Define to 1 to enable the DllMain function.])
  AC_SUBST(
   [HAVE_DLLMAIN],
   [1])

  dnl Used in tests
  AC_SUBST(
   [LIBFDATETIME_DLL_IMPORT],
   ["-DLIBFDATETIME_DLL_IMPORT"])
  ])
 ])

dnl Set additional compiler flags
CFLAGS="$CFLAGS -Wall";

dnl Check if requires and build requires should be set in spec file
AS_IF(
 [test "x$ac_cv_libcerror" = xyes],
 [AC_SUBST(
  [libfdatetime_spec_requires],
  [Requires:])
 AC_SUBST(
  [libfdatetime_spec_build_requires],
  [BuildRequires:])
 ])

dnl Set the date for the dpkg files
AC_SUBST(
 [DPKG_DATE],
 [`date -R 2> /dev/null`])

dnl Set the date for the spec file
AC_SUBST(
 [SPEC_DATE],
 [`date +"%a %b %e %Y" 2> /dev/null`])

dnl Set the current working directory for PackageMaker files
AC_SUBST(
 [PWD],
 [`pwd`])

dnl Have configure make the Makefiles
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([include/Makefile])
AC_CONFIG_FILES([common/Makefile])
AC_CONFIG_FILES([libcerror/Makefile])
AC_CONFIG_FILES([libfdatetime/Makefile])
AC_CONFIG_FILES([po/Makefile.in])
AC_CONFIG_FILES([po/Makevars])
AC_CONFIG_FILES([manuals/Makefile])
AC_CONFIG_FILES([tests/Makefile])
AC_CONFIG_FILES([msvscpp/Makefile])
dnl Have configure make the include files
AC_CONFIG_FILES([include/libfdatetime.h])
AC_CONFIG_FILES([include/libfdatetime/definitions.h])
AC_CONFIG_FILES([include/libfdatetime/features.h])
AC_CONFIG_FILES([include/libfdatetime/types.h])
AC_CONFIG_FILES([libfdatetime/libfdatetime_definitions.h])
dnl Have configure make distribution specific files
AC_CONFIG_FILES([common/types.h])
AC_CONFIG_FILES([dpkg/changelog])
AC_CONFIG_FILES([dpkg/copyright])
AC_CONFIG_FILES([libfdatetime/libfdatetime.rc])
AC_CONFIG_FILES([libfdatetime.pc])
AC_CONFIG_FILES([libfdatetime.spec])
dnl Have configure write its configuration
AC_CONFIG_HEADERS([common/config.h])

AC_OUTPUT

dnl Print a summary
AC_MSG_NOTICE([
Building:
   libcerror support:  $ac_cv_libcerror
]);

