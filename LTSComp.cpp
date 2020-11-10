#include "LTSComp.h"

wxIMPLEMENT_APP(LTSComp);

LTSComp::LTSComp()
{
}


LTSComp::~LTSComp()
{
}


bool LTSComp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();

	return true;
}