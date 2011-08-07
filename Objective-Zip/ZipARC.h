//
//  BRArcLogic.h
//
//  Created by Doug Russell on 7/23/11.
//  Copyright Bottle Rocket Apps 2011. All rights reserved.
//	
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  
//  http://www.apache.org/licenses/LICENSE-2.0
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//  

#ifndef ARCLOGIC

/*
* Provides an easier/cleaner way to create a no arc code block:
* NO_ARC - Compiles the code block argument only if ARC is available
* example: NO_ARC([obj release])
* (accepts multi-line arguments)
*
* Provides an easier/cleaner way to put an arc conditional inline:
* IF_ARC - Compiles the one of the code block argument conditionally
* example: id someVar = IF_ARC(myObj, [myObj autorelease])
* (accepts multi-line arguments)
* 
* STRONGRETAIN & WEAKASSIGN can be used to create @property declarations
* that will work both in and out of ARC
* @property (STRONGRETAIN, nonatomic) id foo;
* (Don't forget weak and assign are mostly the same, but weak is self zeroing in iOS 5, and weak can only be used for objects
*/

#define HASARC __has_feature(objc_arc)
#define HASWEAK __has_feature(objc_arc_weak)

#if HASARC
#define STRONGRETAIN strong
#if HASWEAK
#define WEAKASSIGN weak
#else
#define WEAKASSIGN assign
#endif
#define NO_ARC(BLOCK_NO_ARC) ;
#define IF_ARC(BLOCK_ARC, BLOCK_NO_ARC) BLOCK_ARC
#else
#define STRONGRETAIN retain
#define WEAKASSIGN assign
#define NO_ARC(BLOCK_NO_ARC) BLOCK_NO_ARC
#define IF_ARC(BLOCK_ARC, BLOCK_NO_ARC) BLOCK_NO_ARC
#endif

#if HASWEAK // NO_WEAK and IF_WEAK need to be tested
#define NO_WEAK(BLOCK_NO_WEAK) ;
#define IF_WEAK(BLOCK_WEAK, BLOCK_NO_WEAK) BLOCK_WEAK
#else
#define NO_WEAK(BLOCK_NO_WEAK) BLOCK_NO_WEAK
#define IF_WEAK(BLOCK_WEAK, BLOCK_NO_WEAK) BLOCK_NO_WEAK
#endif

#define ARCLOGIC
#endif