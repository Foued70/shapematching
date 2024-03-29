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
 * Last Updated: (29/11/2007)   
 */

#ifndef _SQUAREDSOFTMARGINLOSS_HPP_
#define _SQUAREDSOFTMARGINLOSS_HPP_

#include "sml.hpp"
#include "binaryclassificationloss.hpp"
#include "model.hpp"

/**  
 * Class to represent binary squared soft margin loss function:
 * loss = 0.5*max(0, margin - y*f(x))^2
 * where f(x) := <w, x> and margin \geq 0. By default margin = 1.
 */
class CSquaredSoftMarginLoss : public CBinaryClassificationLoss 
{
protected:
	void Loss(Scalar& loss, TheMatrix& f);
	void LossAndGrad(Scalar& loss, TheMatrix& f, TheMatrix& l);
	
public:    
	CSquaredSoftMarginLoss(CModel* &model, CVecData* &data)
		: CBinaryClassificationLoss(model, data) {}
	virtual ~CSquaredSoftMarginLoss() {}
	virtual void Usage();
    
};

#endif
