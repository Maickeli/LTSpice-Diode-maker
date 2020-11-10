#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
	EVT_SIZE(OnSize)
	EVT_IDLE(OnIdle)
wxEND_EVENT_TABLE()

bool resized;
int leftPos;
int rightPos;

cMain::cMain() : wxFrame(nullptr, 10002, "LTSpice component editor", wxPoint(30, 30), wxSize(1000, 800))
{
	leftPos = 20;
	rightPos = 2;

	//dFile_pc = new wxFilePickerCtrl(this, wxID_ANY, "", "", "", wxPoint(350, 30), wxSize(360, 20));
	dDir_pc = new wxDirPickerCtrl(this, wxID_ANY, "", "", wxPoint(GetClientSize().x / rightPos, 30), wxSize(GetClientSize().x / 3, 30));
	dDir_st = new wxStaticText(this, wxID_ANY, "Path to LTSpice lib folder:", wxPoint(GetClientSize().x / rightPos, 10), wxSize(GetClientSize().x / 3, 20));
	dDir_st->SetToolTip(wxT("e.g. - C:/Users/\"Username\"/Documents/LTspiceXVII/lib")); dDir_pc->SetToolTip(wxT("e.g. - C:/Users/\"Username\"/Documents/LTspiceXVII/lib"));

	dName_st = new wxStaticText(this, wxID_ANY, "Diode model:", wxPoint(GetClientSize().x / leftPos, 10), wxSize(GetClientSize().x / 4, 20));
	dName_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 30), wxSize(GetClientSize().x / 4, 25));
	dName_st->SetToolTip(wxT("e.g. - 1N4001"));

	dIs_st = new wxStaticText(this, wxID_ANY, "Reverse saturation current (Is):", wxPoint(GetClientSize().x / leftPos, 65), wxSize(250, 20));
	dIs_it = new wxTextCtrl(this, wxID_ANY, "2.52n", wxPoint(GetClientSize().x / leftPos, 85), wxSize(300, 25));
	dIs_st->SetToolTip(wxT("e.g. - 2.52n | i(v) = Is^((v/nVt)-1)"));

	dRs_st = new wxStaticText(this, wxID_ANY, "Parasitic resistance (Rs):", wxPoint(GetClientSize().x / leftPos, 120), wxSize(250, 20));
	dRs_it = new wxTextCtrl(this, wxID_ANY, ".568", wxPoint(GetClientSize().x / leftPos, 140), wxSize(300, 25));
	dRs_st->SetToolTip(wxT("e.g. - .568 | Ohm"));

	dN_st = new wxStaticText(this, wxID_ANY, "Emission coefficient (N):", wxPoint(GetClientSize().x / leftPos, 175), wxSize(250, 20));
	dN_it = new wxTextCtrl(this, wxID_ANY, "1.752", wxPoint(GetClientSize().x / leftPos, 195), wxSize(300, 25));
	dN_st->SetToolTip(wxT("e.g. - 1.752 | For silicon around 2, germanium around 1"));

	dCjo_st = new wxStaticText(this, wxID_ANY, "Total Capacitance:", wxPoint(GetClientSize().x / leftPos, 230), wxSize(250, 20));
	dCjo_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 250), wxSize(300, 25));
	dCjo_st->SetToolTip(wxT("e.g. - 4p | Farad"));

	dM_st = new wxStaticText(this, wxID_ANY, "Grading coefficient (.25 - .7):", wxPoint(GetClientSize().x / leftPos, 285), wxSize(250, 20));
	dM_it = new wxTextCtrl(this, wxID_ANY, ".4", wxPoint(GetClientSize().x / leftPos, 305), wxSize(300, 25));
	dM_st->SetToolTip(wxT(".25 - .45 | Low Voltage Zener ~ .25 | Schottky ~ 0.4 - 0.5"));

	dTt_st = new wxStaticText(this, wxID_ANY, "Transit time (Tt):", wxPoint(GetClientSize().x / leftPos, 340), wxSize(250, 20));
	dTt_it = new wxTextCtrl(this, wxID_ANY, "20n", wxPoint(GetClientSize().x / leftPos, 360), wxSize(300, 25));
	dTt_st->SetToolTip(wxT("e.g. - 20n | (Qrr / If)"));

	dIave_st = new wxStaticText(this, wxID_ANY, "Average Forward Current:", wxPoint(GetClientSize().x / leftPos, 395), wxSize(250, 20));
	dIave_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 415), wxSize(300, 25));
	dIave_st->SetToolTip(wxT("e.g. - 200m"));

	dVpk_st = new wxStaticText(this, wxID_ANY, "Breakdown Voltage (min):", wxPoint(10, 450), wxSize(250, 20));
	dVpk_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 470), wxSize(300, 25));
	dVpk_st->SetToolTip(wxT("e.g. - 75"));

	dMfg_st = new wxStaticText(this, wxID_ANY, "Manufacturer:", wxPoint(GetClientSize().x / leftPos, 505), wxSize(250, 20));
	dMfg_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 525), wxSize(300, 25));
	dMfg_st->SetToolTip(wxT("Manufacturer"));

	dType_st = new wxStaticText(this, wxID_ANY, "Type:", wxPoint(GetClientSize().x / leftPos, 560), wxSize(250, 20));
	dType_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(GetClientSize().x / leftPos, 580), wxSize(300, 25));
	dType_st->SetToolTip(wxT("e.g. - silicon | germanium"));



	m_btn1 = new wxButton(this, 10001, "Submit", wxPoint(GetClientSize().x / leftPos, 660), wxSize(GetClientSize().x / 2, 50));
}


cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	if (dName_it->GetValue().ToStdString() == "" || dIs_it->GetValue().ToStdString() == "" || dRs_it->GetValue().ToStdString() == "" || dN_it->GetValue().ToStdString() == "" || dCjo_it->GetValue().ToStdString() == "" || dM_it->GetValue().ToStdString() == "" || dTt_it->GetValue().ToStdString() == "" || dIave_it->GetValue().ToStdString() == "" || dVpk_it->GetValue().ToStdString() == "" || dMfg_it->GetValue().ToStdString() == "" || dType_it->GetValue().ToStdString() == "")
	{
		wxMessageBox("Fill in all values");
		evt.Skip();
		return;
	}

	string outStr = ".model ";
	outStr.append(dName_it->GetValue().ToStdString());

	outStr.append(" D(Is=");
	outStr.append(dIs_it->GetValue().ToStdString());

	outStr.append(" Rs=");
	outStr.append(dRs_it->GetValue().ToStdString());

	outStr.append(" N=");
	outStr.append(dN_it->GetValue().ToStdString());

	outStr.append(" Cjo=");
	outStr.append(dCjo_it->GetValue().ToStdString());

	outStr.append(" M=");
	outStr.append(dM_it->GetValue().ToStdString());

	outStr.append(" tt=");
	outStr.append(dTt_it->GetValue().ToStdString());

	outStr.append(" Iave=");
	outStr.append(dIave_it->GetValue().ToStdString());

	outStr.append(" Vpk=");
	outStr.append(dVpk_it->GetValue().ToStdString());

	outStr.append(" mfg=");
	outStr.append(dMfg_it->GetValue().ToStdString());

	outStr.append(" type=");
	outStr.append(dType_it->GetValue().ToStdString());

	outStr.append(")");

	string path = dDir_pc->GetTextCtrlValue().ToStdString();
	path.append("/cmp/standard.dio");
	
	wxMessageBox(editFile(outStr, path));
	evt.Skip();
}

void cMain::OnSize(wxSizeEvent& event)
{
	resized = true;
	event.Skip();
}


void cMain::OnIdle(wxIdleEvent& event)
{
	
	if (resized) { DrawWindow(); }
	resized = false;
	event.Skip();
}

void cMain::DrawWindow()
{
	dDir_pc->SetPosition(wxPoint(GetClientSize().x / rightPos, 30));
	dDir_st->SetPosition(wxPoint(GetClientSize().x / rightPos, 10));


	dName_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 10));
	dName_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 30));
	dName_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dName_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dIs_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 65));
	dIs_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 85));
	dIs_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dIs_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dRs_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 120));
	dRs_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 140));
	dRs_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dRs_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dN_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 175));
	dN_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 195));
	dN_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dN_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dCjo_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 230));
	dCjo_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 250));
	dCjo_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dCjo_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dM_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 285));
	dM_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 305));
	dM_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dM_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dTt_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 340));
	dTt_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 360));
	dTt_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dTt_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dIave_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 395));
	dIave_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 415));
	dIave_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dIave_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dVpk_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 450));
	dVpk_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 470));
	dVpk_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dVpk_it->SetSize(wxSize(GetClientSize().x / 4, 25));
																  
	dMfg_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 505));
	dMfg_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 525));
	dMfg_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dMfg_it->SetSize(wxSize(GetClientSize().x / 4, 25));

	dType_st->SetPosition(wxPoint(GetClientSize().x / leftPos, 560));
	dType_it->SetPosition(wxPoint(GetClientSize().x / leftPos, 580));
	dType_st->SetSize(wxSize(GetClientSize().x / 4, 20));
	dType_it->SetSize(wxSize(GetClientSize().x / 4, 25));


	m_btn1->SetPosition(wxPoint(GetClientSize().x / 4, 660));
	m_btn1->SetSize(wxSize(GetClientSize().x / 2, 50));
}