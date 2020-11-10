#pragma once
#include "wx/wx.h"
#include "cMain.h"

class LTSComp : public wxApp
{
public:
	LTSComp();
	~LTSComp();

private:
	cMain* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};

