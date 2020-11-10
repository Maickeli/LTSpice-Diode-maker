#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "LTSpice component editor", wxPoint(30, 30), wxSize(800, 800))
{
	dFile_pc = new wxFilePickerCtrl(this, wxID_ANY, "", "", "", wxPoint(350, 30), wxSize(360, 20));

	dName_st = new wxStaticText(this, wxID_ANY, "Diode model:", wxPoint(10, 10), wxSize(400, 20));
	dName_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 30), wxSize(300, 25));

	dIs_st = new wxStaticText(this, wxID_ANY, "Is:", wxPoint(10, 65), wxSize(400, 20));
	dIs_it = new wxTextCtrl(this, wxID_ANY, "2.52n", wxPoint(10, 85), wxSize(300, 25));

	dRs_st = new wxStaticText(this, wxID_ANY, "Rs:", wxPoint(10, 120), wxSize(400, 20));
	dRs_it = new wxTextCtrl(this, wxID_ANY, ".568", wxPoint(10, 140), wxSize(300, 25));

	dN_st = new wxStaticText(this, wxID_ANY, "N:", wxPoint(10, 175), wxSize(400, 20));
	dN_it = new wxTextCtrl(this, wxID_ANY, "1.752", wxPoint(10, 195), wxSize(300, 25));

	dCjo_st = new wxStaticText(this, wxID_ANY, "Total Capacitance:", wxPoint(10, 230), wxSize(400, 20));
	dCjo_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 250), wxSize(300, 25));

	dM_st = new wxStaticText(this, wxID_ANY, "Grading coefficient (.25 - .7):", wxPoint(10, 285), wxSize(400, 20));
	dM_it = new wxTextCtrl(this, wxID_ANY, ".4", wxPoint(10, 305), wxSize(300, 25));

	dTt_st = new wxStaticText(this, wxID_ANY, "Tt (Qrr / If):", wxPoint(10, 340), wxSize(400, 20));
	dTt_it = new wxTextCtrl(this, wxID_ANY, "20n", wxPoint(10, 360), wxSize(300, 25));

	dIave_st = new wxStaticText(this, wxID_ANY, "Average Forward Current:", wxPoint(10, 395), wxSize(400, 20));
	dIave_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 415), wxSize(300, 25));

	dVpk_st = new wxStaticText(this, wxID_ANY, "Breakdown Voltage (min):", wxPoint(10, 450), wxSize(400, 20));
	dVpk_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 470), wxSize(300, 25));

	dMfg_st = new wxStaticText(this, wxID_ANY, "Manufacturer:", wxPoint(10, 505), wxSize(400, 20));
	dMfg_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 525), wxSize(300, 25));

	dType_st = new wxStaticText(this, wxID_ANY, "Type:", wxPoint(10, 560), wxSize(400, 20));
	dType_it = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 580), wxSize(300, 25));



	m_btn1 = new wxButton(this, 10001, "Submit", wxPoint(10, 660), wxSize(150, 50));
}


cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
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

	string path = dFile_pc->GetTextCtrlValue().ToStdString();
	editFile(outStr, path);

	wxMessageBox("Adding component...");
	evt.Skip();
}