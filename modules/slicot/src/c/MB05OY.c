/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
    -lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

/* Table of constant values */

static integer c__1 = 1;

EXPORTSYMBOL /* Subroutine */ int mb05oy_(job, n, low, igh, a, lda, scale, info, job_len) char* job;
integer *n, *low, *igh;
doublereal* a;
integer* lda;
doublereal* scale;
integer* info;
ftnlen job_len;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1;
    doublereal d__1;
    /* Local variables */
    static integer i__, j, k;
    extern /* Subroutine */ int dscal_();
    extern logical lsame_();
    extern /* Subroutine */ int dswap_();
    static integer ii;
    extern /* Subroutine */ int xerbla_();
    /*     SLICOT RELEASE 5.0. */
    /*     Copyright (c) 2002-2010 NICONET e.V. */
    /*     This program is free software: you can redistribute it and/or */
    /*     modify it under the terms of the GNU General Public License as */
    /*     published by the Free Software Foundation, either version 2 of */
    /*     the License, or (at your option) any later version. */
    /*     This program is distributed in the hope that it will be useful, */
    /*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
    /*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
    /*     GNU General Public License for more details. */
    /*     You should have received a copy of the GNU General Public License */
    /*     along with this program.  If not, see */
    /*     <http://www.gnu.org/licenses/>. */
    /*     PURPOSE */
    /*     To restore a matrix after it has been transformed by applying */
    /*     balancing transformations (permutations and scalings), as */
    /*     determined by LAPACK Library routine DGEBAL. */
    /*     ARGUMENTS */
    /*     Mode Parameters */
    /*     JOB     CHARACTER*1 */
    /*             Specifies the type of backward transformation required, */
    /*             as follows: */
    /*             = 'N', do nothing, return immediately; */
    /*             = 'P', do backward transformation for permutation only; */
    /*             = 'S', do backward transformation for scaling only; */
    /*             = 'B', do backward transformations for both permutation */
    /*                    and scaling. */
    /*             JOB must be the same as the argument JOB supplied */
    /*             to DGEBAL. */
    /*     Input/Output Parameters */
    /*     N       (input) INTEGER */
    /*             The order of the matrix A.  N >= 0. */
    /*     LOW     (input) INTEGER */
    /*     IGH     (input) INTEGER */
    /*             The integers LOW and IGH determined by DGEBAL. */
    /*             1 <= LOW <= IGH <= N, if N > 0; LOW=1 and IGH=0, if N=0. */
    /*     A       (input/output) DOUBLE PRECISION array, dimension (LDA,N) */
    /*             On entry, the leading N-by-N part of this array must */
    /*             contain the matrix to be back-transformed. */
    /*             On exit, the leading N-by-N part of this array contains */
    /*             the transformed matrix. */
    /*     LDA     INTEGER */
    /*             The leading dimension of the array A.  LDA >= max(1,N). */
    /*     SCALE   (input) DOUBLE PRECISION array, dimension (N) */
    /*             Details of the permutation and scaling factors, as */
    /*             returned by DGEBAL. */
    /*     Error Indicator */
    /*     INFO    INTEGER */
    /*             = 0:  successful exit; */
    /*             < 0:  if INFO = -i, the i-th argument had an illegal */
    /*                   value. */
    /*     METHOD */
    /*     Let P be a permutation matrix, and D a diagonal matrix of scaling */
    /*     factors, both of order N. The routine computes */
    /*                     -1 */
    /*        A <-- P D A D  P'. */
    /*     where the permutation and scaling factors are encoded in the */
    /*     array SCALE. */
    /*     REFERENCES */
    /*     None. */
    /*     NUMERICAL ASPECTS */
    /*                               2 */
    /*     The algorithm requires O(N ) operations. */
    /*     CONTRIBUTORS */
    /*     Release 3.0: V. Sima, Katholieke Univ. Leuven, Belgium, Apr. 1997. */
    /*     Supersedes Release 2.0 routine MB05CY. */
    /*     REVISIONS */
    /*     - */
    /*     KEYWORDS */
    /*     Elementary matrix operations, matrix algebra, matrix operations. */
    /*     ****************************************************************** */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. External Functions .. */
    /*     .. External Subroutines .. */
    /*     .. Intrinsic Functions .. */
    /*     .. Executable Statements .. */
    /*     Test the input scalar arguments. */
    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    --scale;
    /* Function Body */
    *info = 0;
    if (!lsame_(job, "N", 1L, 1L) && !lsame_(job, "P", 1L, 1L) && !lsame_(job, "S", 1L, 1L)
        && !lsame_(job, "B", 1L, 1L)) {
        *info = -1;
    } else if (*n < 0) {
        *info = -2;
    } else if (*low < 1 || *low > max(1, *n)) {
        *info = -3;
    } else if (*igh < min(*low, *n) || *igh > *n) {
        *info = -4;
    } else if (*lda < max(1, *n)) {
        *info = -6;
    }
    if (*info != 0) {
        i__1 = -(*info);
        xerbla_("MB05OY", &i__1, 6L);
        return 0;
    }
    /*     Quick return if possible. */
    if (*n == 0 || lsame_(job, "N", 1L, 1L)) {
        return 0;
    }
    if (!lsame_(job, "P", 1L, 1L) && *igh != *low) {
        i__1 = *igh;
        for (i__ = *low; i__ <= i__1; ++i__) {
            dscal_(n, &scale[i__], &a[i__ + a_dim1], lda);
            /* L20: */
        }
        i__1 = *igh;
        for (j = *low; j <= i__1; ++j) {
            d__1 = 1. / scale[j];
            dscal_(n, &d__1, &a[j * a_dim1 + 1], &c__1);
            /* L40: */
        }
    }
    if (!lsame_(job, "S", 1L, 1L)) {
        i__1 = *n;
        for (ii = 1; ii <= i__1; ++ii) {
            i__ = ii;
            if (i__ < *low || i__ > *igh) {
                if (i__ < *low) {
                    i__ = *low - ii;
                }
                k = (integer)scale[i__];
                if (k != i__) {
                    dswap_(n, &a[i__ + a_dim1], lda, &a[k + a_dim1], lda);
                    dswap_(n, &a[i__ * a_dim1 + 1], &c__1, &a[k * a_dim1 + 1], &c__1);
                }
            }
            /* L60: */
        }
    }
    return 0;
    /* *** Last line of MB05OY *** */
} /* mb05oy_ */
