#include <afxwin.h>

//initiate application program class
class CHelloApp : public CWinApp
{
public:
  virtual BOOL InitInstance();

};

//initiate main window class
class CMainFrame : public CFrameWnd
{
public:
  CMainFrame();

protected:
  afx_msg void OnPaint();
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  DECLARE_MESSAGE_MAP()
};

CHelloApp theApp;

BOOL CHelloApp::InitInstance()
{
  m_pMainWnd = new CMainFrame;
  m_pMainWnd->ShowWindow(m_nCmdShow);
  return TRUE;
}

//define main window class
CMainFrame::CMainFrame()
{
  Create(NULL, _T("HelloMFC!!!"));
}

void CMainFrame::OnPaint()
{
  CPaintDC dc(this);
  const TCHAR* msg = _T("Hello, MFC!");
  dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
  MessageBox(_T("Clicked Mouse LButton!"), _T("This is Mouse Message!"));
}

//define message map
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
  ON_WM_PAINT()
  ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()