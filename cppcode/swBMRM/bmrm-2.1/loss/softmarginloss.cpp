/* Copyright (c) 2006, National ICT Australia 
 * All rights reserved. 
 * 
 * The contents of this file are subject to the Mozilla Public License 
 * Version 1.1 (the "License"); you may not use this file except in 
 * compliance with the License. You may obtain a copy of the License at 
 * http://www.mozilla.org/MPL/ 
 * 
 * Software distributed under the License is distributed on an "AS IS" 
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the 
 * License for the specific language governing rights and limitations 
 * under the License. 
 * 
 * Authors: Choon Hui Teo (ChoonHui.Teo@anu.edu.au)
 *
 * Created: (02/11/2007) 
 *
 * Last Updated: (13/11/2007)   
 */

#ifndef _SOFTMARGINLOSS_CPP_
#define _SOFTMARGINLOSS_CPP_

#include "softmarginloss.hpp"
#include "sml.hpp"

/**  
 * Display (usage) message.
 */
void CSoftMarginLoss::Usage()
{
  std::cout << "SoftMarginLoss: No special parameters!" << std::endl; 
}



/**  
 *  Compute softmargin loss. CAUTION: f is passed by reference and is
 *  changed within this function. This is done for efficiency reasons,
 *  otherwise we would have had to create a new copy of f. 
 *   
 *  @param loss [write] loss value computed.
 *  @param f [read/write] prediction vector. 
 */
void CSoftMarginLoss::Loss(Scalar& loss, TheMatrix& f)
{
	loss = 0;
	f.ElementWiseMult(_data->labels());
	Scalar* f_array = f.Data();  // pointer to memory location of f (faster element access)
	int len = f.Length();
	for(int i=0; i < len; i++)
		if(f_array[i] < 1.0) loss += (1 - f_array[i]);
}

/**  
 *  Compute loss and partial derivative of softmargin loss w.r.t f
 *   
 *  @param loss [write] loss value computed.
 *  @param f [r/w] = X*w
 *  @param l [write] partial derivative of loss w.r.t. f
 */
void CSoftMarginLoss::LossAndGrad(Scalar& loss, TheMatrix& f, TheMatrix& l)
{
	
	f.ElementWiseMult(_data->labels());
	Scalar* f_array = f.Data();  // pointer to memory location of f (faster element access)
	int len = f.Length();
	
	l.Zero();  // grad := l'*X
	
	for(int i=0; i < len; i++) {
		if(f_array[i] < 1.0) {
			loss += 1 - f_array[i];
            
			l.Set(i, -1);
		}
	}
	l.ElementWiseMult(_data->labels());
}

#endif
