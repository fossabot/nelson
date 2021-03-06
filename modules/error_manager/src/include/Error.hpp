//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#pragma once
//=============================================================================
#include "Evaluator.hpp"
#include "Exception.hpp"
#include "Messages.hpp"
#include "nlsError_manager_exports.h"
#include <string>
//=============================================================================
namespace Nelson {
//=============================================================================
NLSERROR_MANAGER_IMPEXP void
Error(Evaluator* eval, const std::wstring& msg);
NLSERROR_MANAGER_IMPEXP void
Error(Evaluator* eval, const std::wstring& msg, const std::wstring& functionname);
NLSERROR_MANAGER_IMPEXP void
Error(Evaluator* eval, const std::string& msg);
NLSERROR_MANAGER_IMPEXP void
Error(Evaluator* eval, const std::string& msg, const std::string& functionname);
NLSERROR_MANAGER_IMPEXP void
updateError(Evaluator* eval, Exception& e);
//=============================================================================
} // namespace Nelson
//=============================================================================
