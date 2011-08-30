/*
;Copyright (c) 2010, Electrimod LLC
;All rights reserved.
;
;Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following 
;conditions are met:
;
;Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
;Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
;in the documentation and/or other materials provided with the distribution.  Neither the name of the Electrimod LLC nor the 
;names of its contributors may be used to endorse or promote products derived from this software without specific prior written 
;permission.
;THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
;BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
;SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
;DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
;INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
;OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "settings.h"



void Settings::Load()
{
	wxStandardPaths paths;
	wxConfig *config = new wxConfig("INHX32toH");

	config->Read("Window_X",&Window_X,50);
	config->Read("Window_Y",&Window_Y,50);
	config->Read("Window_Width",&Window_Width,640);
	config->Read("Window_Height",&Window_Height,480);
	config->Read("Last_Directory",&Last_Directory,paths.GetDocumentsDir());
	config->Read("InStyle",&InStyle,0);
	config->Read("OutStyle",&OutStyle,0);
	config->Read("IgnoreBlank",&IgnoreBlank,true);
	delete config;

}
		
void Settings::Save()
{
	wxConfig *config = new wxConfig("INHX32toH");

	config->Write("Window_X",Window_X);
	config->Write("Window_Y",Window_Y);
	config->Write("Window_Width",Window_Width);
	config->Write("Window_Height",Window_Height);
	config->Write("Last_Directory",Last_Directory);
	config->Write("InStyle",InStyle);
	config->Write("OutStyle",OutStyle);
	config->Write("IgnoreBlank",IgnoreBlank);

	delete config;

}
