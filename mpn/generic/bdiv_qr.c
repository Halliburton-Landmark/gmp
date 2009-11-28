/* mpn_bdiv_qr -- Hensel division with precomputed inverse, returning quotient
   and remainder.

   Contributed to the GNU project by Torbjorn Granlund.

   THE FUNCTIONS IN THIS FILE ARE INTERNAL WITH MUTABLE INTERFACES.  IT IS ONLY
   SAFE TO REACH THEM THROUGH DOCUMENTED INTERFACES.  IN FACT, IT IS ALMOST
   GUARANTEED THAT THEY WILL CHANGE OR DISAPPEAR IN A FUTURE GMP RELEASE.

Copyright 2006, 2007, 2009 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.  */

#include "gmp.h"
#include "gmp-impl.h"


/* Computes Q = N / D mod B^n,
	    R = N - QD.	 */

mp_limb_t
mpn_bdiv_qr (mp_ptr qp, mp_ptr rp,
	     mp_srcptr np, mp_size_t nn,
	     mp_srcptr dp, mp_size_t dn,
	     mp_ptr tp)
{
  mp_limb_t di;
  mp_limb_t rh;

  if (BELOW_THRESHOLD (dn, DC_BDIV_QR_THRESHOLD) ||
      BELOW_THRESHOLD (nn - dn, DC_BDIV_QR_THRESHOLD))
    {
      MPN_COPY (tp, np, nn);
      tp[nn] = 0;
      binvert_limb (di, dp[0]);  di = -di;
      rh = mpn_sbpi1_bdiv_qr (qp, tp, nn + 1, dp, dn, di);
      MPN_COPY (rp, tp + nn + 1 - dn, dn);
    }
  else if (BELOW_THRESHOLD (dn, MU_BDIV_QR_THRESHOLD))
    {
      MPN_COPY (tp, np, nn);
      tp[nn] = 0;
      binvert_limb (di, dp[0]);  di = -di;
      rh = mpn_dcpi1_bdiv_qr (qp, tp, nn + 1, dp, dn, di);
      MPN_COPY (rp, tp + nn + 1 - dn, dn);
    }
  else
    {
      mp_size_t itch;
      mp_ptr scratch_out;
      TMP_DECL;
      TMP_MARK;
      itch = mpn_mu_bdiv_qr_itch (nn + 1, dn);
      scratch_out = TMP_BALLOC_LIMBS (itch);
      MPN_COPY (tp, np, nn);
      tp[nn] = 0;
      rh = mpn_mu_bdiv_qr (qp, rp, tp, nn + 1, dp, dn, scratch_out);
      TMP_FREE;
    }

  return rh;
}

mp_size_t
mpn_bdiv_qr_itch (mp_size_t nn, mp_size_t dn)
{
  mp_size_t itch;
  itch = mpn_mu_bdiv_qr_itch (nn, dn);
  itch = MAX (itch, nn + 1);
  return itch;
}