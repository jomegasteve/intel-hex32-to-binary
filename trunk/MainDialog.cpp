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
#include "MainDialog.h"
#include "enum.h"


///////////////////////////////////////////////////////////////////////////

MainDialog::MainDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) 
	: INHX32toH( parent, id, title, pos, size, style )
{

	settings.Load();
	in = NULL;
	out = NULL;

	this->SetSize(settings.Window_X,settings.Window_Y,settings.Window_Width,settings.Window_Height,wxSIZE_AUTO);
	this->m_choice_Output->Select(settings.OutStyle);
	this->m_choice_Input->Select(settings.InStyle);

	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainDialog::OnClose ) );
	m_button_Input->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialog::SourceFileDialog ), NULL, this );
	m_button_Output->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialog::OutFileDialog ), NULL, this );
	m_button_Start->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialog::Start ), NULL, this );

}

MainDialog::~MainDialog()
{
	this->GetSize(&settings.Window_Width,&settings.Window_Height);
	this->GetPosition(&settings.Window_X,&settings.Window_Y);
	settings.OutStyle = this->m_choice_Output->GetSelection();
	settings.InStyle = this->m_choice_Output->GetSelection();
	settings.Save();
}

void MainDialog::OnClose(wxCloseEvent& WXUNUSED(event))
{

	Destroy();
}

void MainDialog::SourceFileDialog(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog openFileDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString, 
		_("All Files (*.*)|*.*"),
		wxFD_OPEN, wxDefaultPosition);
	
	openFileDialog.SetDirectory(settings.Last_Directory);
	
	if (openFileDialog.ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
			this->SourceFile =openFileDialog.GetPath();
			settings.Last_Directory = openFileDialog.GetDirectory();
			this->m_textCtrl_Input->SetValue(this->SourceFile);
	}
 
	openFileDialog.Destroy();
}
void MainDialog::OutFileDialog(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog openFileDialog = new wxFileDialog(
		this, _("Save As"), wxEmptyString, wxEmptyString, 
		_("All Files (*.*)|*.*"),
		wxFD_SAVE, wxDefaultPosition);
	
	openFileDialog.SetDirectory(settings.Last_Directory);
	
	if (openFileDialog.ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
			this->OutFile =openFileDialog.GetPath();
			settings.Last_Directory = openFileDialog.GetDirectory();
			this->m_textCtrl_Output->SetValue(this->OutFile);
			this->Name=openFileDialog.GetFilename();
			
			
	}
 
	openFileDialog.Destroy();
}
void MainDialog::Start(wxCommandEvent& WXUNUSED(event))
{
	int inType = this->m_choice_Input->GetSelection();
	int outType = this->m_choice_Output->GetSelection();
	int b;
	char c;
	int count = 0;
	char objectname[64];	
	char InputStream[256];
	char temp[6];
	unsigned long Address;
	unsigned int  RecordLength;
	unsigned int  RecordType;

	
	if(outType == 1 && inType == 1)
	{
		wxMessageBox("No binary to binary conversion.");
		return;
	}

	in = fopen(this->SourceFile,"r");
	if(in == NULL)
	{
		wxMessageBox("Failed to open input file");
		return;
	}
	out = fopen(this->OutFile,"w");
	if(out == NULL)
	{
		fclose(in);
		wxMessageBox("Failed to create output %s",this->OutFile);
		return;
	}

	// make include header string name from filename
	memset(objectname,0,64);
	memcpy(objectname,this->Name.ToAscii(),this->Name.Len());
	for(unsigned int t=0;t<this->Name.Len();t++)
	{
		if( isalnum(objectname[t]==0) || objectname[t]=='-' || objectname[t]=='.')
			objectname[t]='_';
		

	}

	// if it is output an include file start the definition
	if(outType==0)
	{
		fprintf(out,"#ifndef __%s__\r\n",objectname);
		fprintf(out,"#define __%s__\r\n",objectname);
		fprintf(out,"\r\n");
		fprintf(out,"static char %s[] = {",objectname);
	}

	while (feof(in)==0)
	{
		if(inType == 0) 
		{
			if(fgets(InputStream,256,in)!= NULL) 
			{
				if(InputStream[0] != ':')  // Check to make sure we have a colon as the first character.  If not then we have a problem.
				{
					fclose(in);
					fclose(out);
					wxMessageBox("Invalid input file");
					return;
				}
				
				memset(temp,0,6);
				memcpy(temp,&InputStream[1],2);
				RecordLength = atoi(temp);

				memset(temp,0,6);
				memcpy(temp,&InputStream[3],4);
				Address = atol(temp);

				memset(temp,0,6);
				memcpy(temp,&InputStream[7],2);
				RecordType = atoi(temp);
				if(outType == 0)
				{
					if(RecordType==1)
					{
						fprintf(out,"};\r\n");
						// output closing include arguments
						fclose(in);
						fclose(out);
						return;
					}
					if(RecordType==0)
					{
						memset(temp,0,6);
						for(unsigned int t=0;t < RecordLength;t++)
						{
							
							memcpy(temp,&InputStream[9 + (t * 2)],2);
							fprintf(out,"0x%s,",temp);
						}
						fprintf(out,"\r\n");
					}
				}
				if(outType == 1)
				{
					fseek(out,Address,SEEK_SET);
					if(RecordType==0)
					{
						for(unsigned int t=0;t<RecordLength;t++) 
						{
							c = toupper(InputStream[9 + (t * 2)]);
							if(c > 47 && c < 58) 
								b = c - 48;
							if(c >64 && c < 71)
								b = c - 55;
							b = b << 4;

							c = toupper(InputStream[9 + (t * 2) + 1]);
							if(c > 47 && c < 58) 
								b = b + (c - 48);
							if(c >64 && c < 71)
								b = b + (c - 55);
							c = b;
							fputc(c,out);				// Write the converted byte;
						}
					}
					if(RecordType==1)
					{
						fclose(in);
						fclose(out);
						return;
					}
				}
			} else {
				if(outType == 0)
				{
					fprintf(out,"};\r\n");
				}
				fclose(in);
				fclose(out);
				return;

			}
		}
		if(inType == 1)
		{
			b = fgetc(in);
			if(b != EOF) {
				fprintf(out,"0x%X,",b);
				count = count + 1;
				if(count == 8) 
				{
					count = 0;
					fprintf(out,"\r\n");
				}
			} else {
				fprintf(out,"};\r\n");
				fclose(in);
				fclose(out);
				return;
			}
		}
	}

}


