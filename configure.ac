#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

m4_define([attyr_major_version], [1])
m4_define([attyr_minor_version], [1])
m4_define([attyr_patch_version], [0])
m4_define([attyr_version], [attyr_major_version.attyr_minor_version.attyr_patch_version])

AC_INIT([attyr], attyr_version)
AC_CONFIG_SRCDIR([src/matrices.c])
AC_CONFIG_HEADERS([config.h])

AC_SUBST(ATTYR_MAJOR_VERSION, attyr_major_version)
AC_SUBST(ATTYR_MINOR_VERSION, attyr_minor_version)
AC_SUBST(ATTYR_PATCH_VERSION, attyr_patch_version)

AC_CONFIG_AUX_DIR([build])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])
AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_AR

AC_CHECK_HEADERS([float.h stdlib.h math.h])

LT_INIT
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile src/version.h])

AC_OUTPUT
