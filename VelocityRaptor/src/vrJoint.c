/*
* Copyright (c) 2016 Cormac Grindall (Mithreindeir)
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* vrFreely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/
#include "../include/vrJoint.h"

vrJoint * vrJointAlloc()
{
	return vrAlloc(sizeof(vrJoint));
}

vrJoint * vrJointInit(vrJoint * joint)
{
	joint->A = NULL;
	joint->B = NULL;
	
	joint->preSolve = NULL;
	joint->postSolve = NULL;
	joint->solveVelocity = NULL;
	joint->solvePosition = NULL;
	joint->drawJoint = NULL;
	return joint;
}

void vrJointDestroy(vrJoint * joint)
{
	vrFree(joint->jointData);
	vrFree(joint);
}

vrLocalPoint vrLocalPointInit(vrRigidBody * body, vrVec2 point)
{
	vrLocalPoint localPoint;
	localPoint.body = body;
	localPoint.initialOrientation = body->orientation;
	localPoint.initialPoint = vrSub(point, body->center);
	return localPoint;
}

vrVec2 vrGetLocalPoint(vrLocalPoint * localPoint)
{
	vrFloat newO = localPoint->body->orientation;
	vrFloat rotation = newO - localPoint->initialOrientation;
	if (rotation == 0) return localPoint->initialPoint;
	vrFloat ca = VR_COSINE(rotation);
	vrFloat sa = VR_SINE(rotation);
	vrVec2 p = localPoint->initialPoint;
	p = vrVect(p.x * ca - p.y * sa, p.x * sa + p.y * ca);
	localPoint->initialPoint = p;
	localPoint->initialOrientation = newO;

	return p;
}
