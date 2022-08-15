#include <afxwin.h>

class HelloApplication : public CWinApp
{
public:
    virtual BOOL InitInstance();
};

HelloApplication HelloApp;

class HelloWindow : public CFrameWnd
{
    CButton* m_pHelloButton;
public:
    HelloWindow();
};


BOOL HelloApplication::InitInstance()
{
    m_pMainWnd = new HelloWindow();
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


HelloWindow::HelloWindow()
{
    Create(NULL,
        "Hello World!",
        WS_OVERLAPPEDWINDOW | WS_HSCROLL,
        CRect(0, 0, 140, 80));
    m_pHelloButton = new CButton();
    m_pHelloButton->Create("Hello World!", WS_CHILD | WS_VISIBLE, CRect(20, 20, 120, 40), this, 1);
}