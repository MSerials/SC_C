#pragma once


// DockPane

class DockPane : public CDockablePane
{
	DECLARE_DYNAMIC(DockPane)

public:
	DockPane();
	virtual ~DockPane();

protected:
	DECLARE_MESSAGE_MAP()
};


