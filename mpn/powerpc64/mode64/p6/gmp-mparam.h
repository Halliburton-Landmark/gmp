/* gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 1999, 2000, 2001, 2002, 2003, 2009, 2010, 2012 Free
Software Foundation, Inc.

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

#define GMP_LIMB_BITS 64
#define BYTES_PER_MP_LIMB 8

/* 3500 MHz POWER6 (kolga.bibsys.no) */

#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD      MP_SIZE_T_MAX  /* never */
#define MOD_1U_TO_MOD_1_1_THRESHOLD      MP_SIZE_T_MAX
#define MOD_1_1_TO_MOD_1_2_THRESHOLD     MP_SIZE_T_MAX
#define MOD_1_2_TO_MOD_1_4_THRESHOLD     MP_SIZE_T_MAX
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     55
#define USE_PREINV_DIVREM_1                  0
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD        MP_SIZE_T_MAX  /* never */

#define MUL_TOOM22_THRESHOLD                14
#define MUL_TOOM33_THRESHOLD                37
#define MUL_TOOM44_THRESHOLD               160
#define MUL_TOOM6H_THRESHOLD               177
#define MUL_TOOM8H_THRESHOLD               321

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      73
#define MUL_TOOM32_TO_TOOM53_THRESHOLD      86
#define MUL_TOOM42_TO_TOOM53_THRESHOLD     103
#define MUL_TOOM42_TO_TOOM63_THRESHOLD      90

#define SQR_BASECASE_THRESHOLD               5
#define SQR_TOOM2_THRESHOLD                 22
#define SQR_TOOM3_THRESHOLD                 43
#define SQR_TOOM4_THRESHOLD                296
#define SQR_TOOM6_THRESHOLD                309
#define SQR_TOOM8_THRESHOLD                562

#define MULMOD_BNM1_THRESHOLD               12
#define SQRMOD_BNM1_THRESHOLD               14

#define MUL_FFT_MODF_THRESHOLD             272  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    272, 5}, {     13, 6}, {      7, 5}, {     15, 6}, \
    {      8, 5}, {     17, 6}, {      9, 5}, {     19, 6}, \
    {     13, 7}, {      7, 6}, {     17, 7}, {      9, 6}, \
    {     19, 7}, {     17, 8}, {      9, 7}, {     20, 8}, \
    {     11, 7}, {     24, 8}, {     15, 7}, {     31, 8}, \
    {     21, 9}, {     11, 8}, {     25, 9}, {     15, 8}, \
    {     33, 9}, {     19, 8}, {     39, 9}, {     23, 8}, \
    {     47,10}, {     15, 9}, {     39,10}, {     23, 9}, \
    {     47,11}, {     15,10}, {     31, 9}, {     63,10}, \
    {     47,11}, {     31,10}, {     71, 9}, {    143,10}, \
    {     79,11}, {     47,12}, {     31,11}, {     63,10}, \
    {    127, 9}, {    255, 8}, {    511,10}, {    143,11}, \
    {     79,10}, {    159, 9}, {    319, 8}, {    639,10}, \
    {    175, 9}, {    351,11}, {     95,10}, {    191, 9}, \
    {    383,12}, {     63,11}, {    127,10}, {    255, 9}, \
    {    511,11}, {    143,10}, {    287, 9}, {    575,11}, \
    {    159,10}, {    319, 9}, {    639,11}, {    175,10}, \
    {    351,12}, {     95,11}, {    191,10}, {    383, 9}, \
    {    767,13}, {   8192,14}, {  16384,15}, {  32768,16}, \
    {  65536,17}, { 131072,18}, { 262144,19}, { 524288,20}, \
    {1048576,21}, {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 84
#define MUL_FFT_THRESHOLD                 1856

#define SQR_FFT_MODF_THRESHOLD             216  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    216, 5}, {      7, 4}, {     15, 5}, {     15, 6}, \
    {      8, 5}, {     17, 6}, {     17, 7}, {      9, 6}, \
    {     19, 7}, {     17, 8}, {      9, 7}, {     20, 8}, \
    {     11, 7}, {     23, 8}, {     19, 9}, {     11, 8}, \
    {     25, 9}, {     15, 8}, {     33, 9}, {     19, 8}, \
    {     39, 9}, {     23, 8}, {     47,10}, {     15, 9}, \
    {     39,10}, {     23, 9}, {     47,11}, {     15,10}, \
    {     31, 9}, {     63,10}, {     47,11}, {     31,10}, \
    {     63, 9}, {    127,10}, {     71, 9}, {    143,11}, \
    {     47,12}, {     31,11}, {     63,10}, {    127, 9}, \
    {    255, 8}, {    511,10}, {    143, 9}, {    287,11}, \
    {     79,10}, {    159, 9}, {    319, 8}, {    639,10}, \
    {    175, 9}, {    351, 8}, {    703, 9}, {    383, 8}, \
    {    767,10}, {    207, 9}, {    415,12}, {     63,11}, \
    {    127,10}, {    255, 9}, {    511, 8}, {   1023,11}, \
    {    143,10}, {    287, 9}, {    575,11}, {    159,10}, \
    {    319, 9}, {    639,11}, {    175,10}, {    351, 9}, \
    {    703, 8}, {   1407,12}, {     95,11}, {    191,10}, \
    {    383, 9}, {    767,11}, {    207,10}, {    415,13}, \
    {   8192,14}, {  16384,15}, {  32768,16}, {  65536,17}, \
    { 131072,18}, { 262144,19}, { 524288,20}, {1048576,21}, \
    {2097152,22}, {4194304,23}, {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 87
#define SQR_FFT_THRESHOLD                 1856

#define MULLO_BASECASE_THRESHOLD             3
#define MULLO_DC_THRESHOLD                  37
#define MULLO_MUL_N_THRESHOLD             3574

#define DC_DIV_QR_THRESHOLD                 23
#define DC_DIVAPPR_Q_THRESHOLD              95
#define DC_BDIV_QR_THRESHOLD                41
#define DC_BDIV_Q_THRESHOLD                 90

#define INV_MULMOD_BNM1_THRESHOLD           60
#define INV_NEWTON_THRESHOLD                92
#define INV_APPR_THRESHOLD                  92

#define BINV_NEWTON_THRESHOLD              151
#define REDC_1_TO_REDC_N_THRESHOLD          43

#define MU_DIV_QR_THRESHOLD               1099
#define MU_DIVAPPR_Q_THRESHOLD             748
#define MUPI_DIV_QR_THRESHOLD               42
#define MU_BDIV_QR_THRESHOLD               618
#define MU_BDIV_Q_THRESHOLD                807

#define MATRIX22_STRASSEN_THRESHOLD         10
#define HGCD_THRESHOLD                      77
#define GCD_DC_THRESHOLD                   358
#define GCDEXT_DC_THRESHOLD                241
#define JACOBI_BASE_METHOD                   3

#define GET_STR_DC_THRESHOLD                12
#define GET_STR_PRECOMPUTE_THRESHOLD        25
#define SET_STR_DC_THRESHOLD               552
#define SET_STR_PRECOMPUTE_THRESHOLD      1416
