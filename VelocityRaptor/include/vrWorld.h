/*
* Copyright (c) 2006-2009 Cormac Grindall (Mithreindeir)
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef HEADER_VRWORLD
#define HEADER_VRWORLD

#include <time.h>
#include "velocityraptor.h"
#include "vrRigidBody.h"
#include "vrMemoryPool.h"
#include "vrLinkedList.h"
#include "vrArray.h"

typedef struct vrWorld
{
	vrMemoryPool* memoryPool;
	vrLinkedList* memoryList;
	vrArray* bodies;
	int num_bodies;

	/* For Stepper */
	vrFloat lastTime;
	vrFloat accumulator;
	vrFloat timeStep;

	/* Body controls */
	int velIterations;
	int posIterations;
	vrVec2 gravity;
} vrWorld;

vrWorld* vrWorldAlloc();
vrWorld* vrWorldInit(vrWorld* world);
void vrWorldDestroy(vrWorld* world);
void vrWorldStep(vrWorld* world);
void vrWorldAddBody(vrWorld* world, vrRigidBody * body);


#endif
