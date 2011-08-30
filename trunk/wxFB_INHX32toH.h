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
#ifndef __wxFB_INHX32toH__
#define __wxFB_INHX32toH__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/gauge.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/dialog.h>


class INHX32toH : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel4;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl_Input;
		wxButton* m_button_Input;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl_Output;
		wxButton* m_button_Output;
		wxChoice* m_choice_Output;
		wxChoice* m_choice_Input;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxButton* m_button_Start;
		wxGauge* m_gauge;

		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		
	
	public:
		
		INHX32toH( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("INHX32 to H Converter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,137 ), long style = wxDEFAULT_DIALOG_STYLE );
		~INHX32toH();
	
};

#endif //__noname__
