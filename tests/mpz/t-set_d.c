/* Test mpz_set_d and mpz_init_set_d.

Copyright 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"
#include "gmp-impl.h"
#include "tests.h"


void
check_data (void)
{
  static const struct {
    double     d;
    mp_size_t  want_size;
    mp_limb_t  want_data[2];
  } data[] = {

    {  0.0,  0 },
    {  1.0,  1, { 1 } },
    { -1.0, -1, { 1 } },

    {  123.0,  1, { 123 } },
    { -123.0, -1, { 123 } },
  };

  mpz_t  z;
  int    i;

  for (i = 0; i < numberof (data); i++)
    {
      mpz_init (z);
      mpz_set_d (z, data[i].d);
      MPZ_CHECK_FORMAT (z);
      if (z->_mp_size != data[i].want_size
          || refmpn_cmp_allowzero (z->_mp_d, data[i].want_data,
                                   ABS (data[i].want_size)) != 0)
        {
          printf ("mpz_set_d wrong on data[%d]\n", i);
        bad:
          printf    ("  got  size %ld\n", (long) z->_mp_size);
          printf    ("  want size %ld\n", (long) data[i].want_size);
          mpn_trace ("  got  d", z->_mp_d, z->_mp_size);
          mpn_trace ("  want d", data[i].want_data, data[i].want_size);
          abort();
        }
      mpz_clear (z);

      mpz_init_set_d (z, data[i].d);
      MPZ_CHECK_FORMAT (z);
      if (z->_mp_size != data[i].want_size
          || refmpn_cmp_allowzero (z->_mp_d, data[i].want_data,
                                   ABS (data[i].want_size)) != 0)
        {
          printf ("mpz_init_set_d wrong on data[%d]\n", i);
          goto bad;
        }
      mpz_clear (z);
    }
}


int
main (void)
{
  tests_start ();

  check_data ();

  tests_end ();
  exit (0);
}