check_PROGRAMS = test_vectors test_matrices

AM_CFLAGS = -I $(top_srcdir)/src -lm

test_helpers = test_helpers.c test_helpers.h $(top_srcdir)/src/matrices.c

test_vectors_SOURCES = test_vectors.c $(test_helpers)
test_matrices_SOURCES = test_matrices.c $(test_helpers)

TESTS = $(check_PROGRAMS)
