#pragma once
#include "wx/wx.h"
#include "wx/string.h"
#include "wx/filepicker.h"
#include "EditTextFile.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public: 
	wxButton *m_btn1 = nullptr;

	wxFilePickerCtrl *dFile_pc = nullptr;

	wxTextCtrl *dName_it = nullptr;
	wxStaticText *dName_st = nullptr;

	wxTextCtrl *dIs_it = nullptr;
	wxStaticText *dIs_st = nullptr;

	wxTextCtrl *dRs_it = nullptr;
	wxStaticText *dRs_st = nullptr;

	wxTextCtrl *dN_it = nullptr;
	wxStaticText *dN_st = nullptr;

	wxTextCtrl *dCjo_it = nullptr;
	wxStaticText *dCjo_st = nullptr;

	wxTextCtrl *dM_it = nullptr;
	wxStaticText *dM_st = nullptr;

	wxTextCtrl *dTt_it = nullptr;
	wxStaticText *dTt_st = nullptr;

	wxTextCtrl *dIave_it = nullptr;
	wxStaticText *dIave_st = nullptr;

	wxTextCtrl *dVpk_it = nullptr;
	wxStaticText *dVpk_st = nullptr;

	wxTextCtrl *dMfg_it = nullptr;
	wxStaticText *dMfg_st = nullptr;

	wxTextCtrl *dType_it = nullptr;
	wxStaticText *dType_st = nullptr;

	void OnButtonClicked(wxCommandEvent &evt);


	wxDECLARE_EVENT_TABLE();
};

