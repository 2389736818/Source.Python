/**
* =============================================================================
* Source Python
* Copyright (C) 2012-2015 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

#ifndef _MEMORY_TOOLS_H
#define _MEMORY_TOOLS_H

// ============================================================================
// >> INCLUDES
// ============================================================================
#include "memory_pointer.h"
#include "memory_utilities.h"

CPointer* ExtractPointer(object oPtr);


// ============================================================================
// >> GetObjectPointer
// ============================================================================
inline object GetObjectPointer(object obj)
{
	if (!PyObject_HasAttrString(obj.ptr(), GET_PTR_NAME))
		BOOST_RAISE_EXCEPTION(PyExc_ValueError, "Unable to retrieve a pointer of this object.");

	return obj.attr(GET_PTR_NAME)();
}


// ============================================================================
// >> MakeObject
// ============================================================================
inline object MakeObject(object cls, object oPtr)
{
	if (!PyObject_HasAttrString(cls.ptr(), GET_OBJ_NAME))
		BOOST_RAISE_EXCEPTION(PyExc_ValueError, "Unable to make an object using this class.");

	CPointer* pPtr = ExtractPointer(oPtr);
	if (!pPtr->IsValid())
		BOOST_RAISE_EXCEPTION(PyExc_ValueError, "Pointer is NULL.");

	return cls.attr(GET_OBJ_NAME)(pPtr);
}


// ============================================================================
// >> GetSize
// ============================================================================
inline object GetSize(object cls)
{
	if (!PyObject_HasAttrString(cls.ptr(), GET_SIZE_NAME))
		BOOST_RAISE_EXCEPTION(PyExc_ValueError, "Unable to retrieve the size of this class.");

	return cls.attr(GET_SIZE_NAME);
}


#endif // _MEMORY_TOOLS_H
