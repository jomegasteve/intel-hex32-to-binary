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
#include "wxFB_INHX32toH.h"

INHX32toH::INHX32toH( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints(  wxSize( 625,165 ),  wxSize( 625,165 ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 4, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	m_staticText1 = new wxStaticText( m_panel4, wxID_ANY, wxT("Input File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	m_textCtrl_Input = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	fgSizer1->Add( m_textCtrl_Input, 1, wxALL, 5 );
	

	wxString m_choice_InputChoices[] = { wxT("INHX32"),wxT("Binary") };
	int m_choice_InputNChoices = sizeof( m_choice_InputChoices ) / sizeof( wxString );
	m_choice_Input = new wxChoice( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_InputNChoices, m_choice_InputChoices, 0 );
	m_choice_Input->SetSelection( 0 );
	fgSizer1->Add( m_choice_Input, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );

	m_button_Input = new wxButton( m_panel4, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button_Input, 0, wxALL|wxALIGN_RIGHT, 5 );



	m_staticText3 = new wxStaticText( m_panel4, wxID_ANY, wxT("Output File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer1->Add( m_staticText3, 0, wxALL, 5 );
	
	m_textCtrl_Output = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	fgSizer1->Add( m_textCtrl_Output, 1, wxALL, 5 );

	wxString m_choice_OutputChoices[] = { wxT("Include"),wxT("Binary") };
	int m_choice_OutputNChoices = sizeof( m_choice_OutputChoices ) / sizeof( wxString );
	m_choice_Output = new wxChoice( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_OutputNChoices, m_choice_OutputChoices, 0 );
	m_choice_Output->SetSelection( 0 );
	fgSizer1->Add( m_choice_Output, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );

	m_button_Output = new wxButton( m_panel4, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button_Output, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText4 = new wxStaticText( m_panel4, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALL, 5 );
	
	
	
	m_gauge = new wxGauge( m_panel4, wxID_ANY, 100, wxDefaultPosition, wxSize( 300,25 ), wxGA_HORIZONTAL );
	fgSizer1->Add( m_gauge, 0, wxALL, 5 );

		m_staticText5 = new wxStaticText( m_panel4, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALL, 5 );

	m_button_Start = new wxButton( m_panel4, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_button_Start, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel4->SetSizer( fgSizer1 );
	m_panel4->Layout();
	fgSizer1->Fit( m_panel4 );
	bSizer2->Add( m_panel4, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( INHX32toH::OnClose ) );
}

INHX32toH::~INHX32toH()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( INHX32toH::OnClose ) );
	
}

