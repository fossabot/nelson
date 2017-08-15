//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "InverseFft.hpp"
#include "FftHelpers.hpp"
#include "Exception.hpp"
#include "ClassName.hpp"
//=============================================================================
namespace Nelson {
    //=============================================================================
    ArrayOf InverseFft(ArrayOf X, indexType n, indexType dim)
    {
        if (X.isReferenceType() || X.isHandle())
        {
            throw Exception(_("Undefined function 'ifft' for input arguments of type") + " '" + ClassName(X) + "'.");
        }
        if (X.isScalar() || X.isEmpty())
        {
            return ArrayOf(X);
        }
        Class classX = X.getDataClass();
        if (classX <= NLS_SCOMPLEX && classX != NLS_DOUBLE)
        {
            X.promoteType(NLS_SCOMPLEX);
        }
        else
        {
            X.promoteType(NLS_DCOMPLEX);
        }
        ArrayOf res;
        if (X.getDataClass() == NLS_SCOMPLEX)
        {
            res = scomplexFFTW(X, n, dim, true);
        }
        else
        {
            res = dcomplexFFTW(X, n, dim, true);
        }
        return res;
    }
    //=============================================================================
    ArrayOf InverseFft(ArrayOf X, indexType n)
    {
        indexType dim = computeDim(X);
        return InverseFft(X, n, dim);
    }
    //=============================================================================
    ArrayOf InverseFft(ArrayOf X)
    {
        indexType dim = computeDim(X);
        indexType n = X.getDimensionLength((int)dim);
        return InverseFft(X, n, dim);
    }
    //=============================================================================
}
//=============================================================================