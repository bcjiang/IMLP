// ****************************************************************************
//
//    Copyright (c) 2014, Seth Billings, Russell Taylor, Johns Hopkins University
//    All rights reserved.
//
//    Redistribution and use in source and binary forms, with or without
//    modification, are permitted provided that the following conditions are
//    met:
//
//    1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
//    3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  
// ****************************************************************************
#ifndef H_cisstTriangleClosestPointSolver
#define H_cisstTriangleClosestPointSolver

#include <stdio.h>
#include <cisstVector.h>
#include <cisstCommon.h>
#include <cisstNumerical.h>


class cisstTriangleClosestPointSolver
{
 protected:
  vctDoubleMat A;
  vctDoubleVec h;
  vctIntVec P;
  double Tau;
  vctDoubleVec g;
  vctDoubleVec b;
  vctDoubleVec x;

  nmrLSSolver LeastSquaresSolver; // not most efficient way
  vctDoubleMat B;

 public:
	 cisstTriangleClosestPointSolver(); 
	
 
  int FindClosestPointOnTriangle(const vct3& a, 
				 const vct3& p,
				 const vct3& q,
				 const vct3& r,
				 double distBound,
				 vct3& ret);

  vct3 ProjectOnSegment(const vct3& c, const vct3& p, const vct3& r);

  void SolveLamMuNu(const vct3& a, 
						  const vct3& p,
						  const vct3& q,
						  const vct3& r,
						  double &lambda,
						  double &mu,
						  double &nu);
};
#endif