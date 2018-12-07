
// GUI_ProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GUI_Project.h"
#include "GUI_ProjectDlg.h"
#include "afxdialogex.h"
#include "Account_GUI.h"
#include "Bank_Account_GUI.h"
#include "Stock_portfolio_ListNode_Kartik_GUI.h"
#include "Stock_portfolio_List_GUI.h"
#include <fstream>
#include <vector>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGUIProjectDlg dialog



CGUIProjectDlg::CGUIProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUI_PROJECT_DIALOG, pParent)
	, m_instructions(_T(""))
	, m_amount(_T("Enter"))
	, m_result(_T("Result"))
	, amount_update(_T(""))
	, m_sym(_T("Enter Symbol"))
	, m_num(_T(""))
	, m_sp(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGUIProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Instructions, m_instructions);
	DDX_Text(pDX, IDC_EDIT_Amount, m_amount);
	DDX_Text(pDX, IDC_EDIT_Result, m_result);
	DDX_Text(pDX, IDC_EDIT1, m_sym);
	DDX_Text(pDX, IDC_EDIT_num, m_num);
	DDX_Text(pDX, IDC_EDIT_SP, m_sp);
}

BEGIN_MESSAGE_MAP(CGUIProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_Instructions, &CGUIProjectDlg::OnEnChangeEditInstructions)
	ON_BN_CLICKED(IDC_RADIO_SA, &CGUIProjectDlg::OnBnClickedRadioSa)
	ON_BN_CLICKED(IDC_RADIO2, &CGUIProjectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON_1, &CGUIProjectDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_Result, &CGUIProjectDlg::OnEnChangeEditResult)
	ON_EN_CHANGE(IDC_EDIT_Amount, &CGUIProjectDlg::OnEnChangeEditAmount)
	ON_BN_CLICKED(IDC_BUTTON_2, &CGUIProjectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CGUIProjectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CGUIProjectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_SP, &CGUIProjectDlg::OnBnClickedButtonSp)
END_MESSAGE_MAP()


// CGUIProjectDlg message handlers

BOOL CGUIProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGUIProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGUIProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGUIProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGUIProjectDlg::OnEnChangeEditInstructions()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGUIProjectDlg::OnBnClickedRadioSa()
{
	m_instructions = "Welcome to Stock Account!\r\n"
		"1. Display the price for a stock symbol\r\n"
		"2. Display the current portfolio\r\n"
		"3. Buy shares\r\n"
		"4. Sell shares\r\n"
		//"5. View a graph for the portfolio value\r\n"   WILL TRY THIS IF SOMETHING HAPPENS
		"6. View transaction history\r\n"
		"Please enter your option below:";
	UpdateData(false);
}


void CGUIProjectDlg::OnBnClickedRadio2()
{
	m_instructions = "Welcome to Bank Account!\r\n"
		"1. Deposit Money\r\n"
		"2. Withdraw Money\r\n"
		"3. View Account Balance\r\n"
		"4. Print out history\r\n"
		"Please enter your option below:";
	UpdateData(false);
}

Bank_Account_GUI BA;					// a BA object

void CGUIProjectDlg::OnBnClickedButton1()
{
	UpdateData(true);						//recieve value
	m_amount = m_amount;					//uopdate value into the variable, therefore true
	double d = _tstof(m_amount);			//convert it to double
	BA.setCashBalance_new(BA.getCashBalance() + d);			//update the new value of cashbalance
	CString convert;
	
	convert.Format(_T("%g"), BA.getCashBalance());								//copnvert the new value to str
	CString str = _T("The updated balance after deposit is:$");
	m_result = str + convert;
	UpdateData(false);
}
void CGUIProjectDlg::OnBnClickedButton2()
{

	UpdateData(true);						//recieve value
	m_amount = m_amount;					//uopdate value into the variable, therefore true
	double d = _tstof(m_amount);			//convert it to double
	BA.setCashBalance_new(BA.getCashBalance() - d);			//update the new value of cashbalance
	CString convert;
	convert.Format(_T("%g"), BA.getCashBalance());								//copnvert the new value to str
	CString str = _T("The updated balance after withdrawal is:$");
	m_result = str + convert;
	UpdateData(false);
}
void CGUIProjectDlg::OnBnClickedButton3()
{
	double d=BA.getCashBalance();
	CString convert;
	convert.Format(_T("%g"), BA.getCashBalance());								//copnvert the new value to str
	CString str = _T("The current balance is:$");
	m_result = str + convert;
	UpdateData(false);
}

void CGUIProjectDlg::OnBnClickedButton4()
{
	CString display = BA.print_out_history();
	m_result = display;
	UpdateData(false);
}


void CGUIProjectDlg::OnEnChangeEditResult()
{	
}


void CGUIProjectDlg::OnEnChangeEditAmount()
{
}
CString CGUIProjectDlg::return_amount()
{
	CString str = m_amount;
	return str;
}

//XX---------------------------------------STOCK ACCOUNT------------------------------------------------------------------------------------XX
List SA;
void CGUIProjectDlg::OnBnClickedButtonSp()
{
	UpdateData(true);
	m_sym = m_sym;
	CStringA m_sym1(m_sym);
	string send(m_sym1);
	double return_value = SA.return_stockprice(send);
	if (return_value == 0)
	{
		m_result = "Symbol not found";
	}
	else
	{
		CString convert;
		convert.Format(_T("%g"), return_value);
		CString str = _T("The current share price for" + m_sym + " is:$");
		m_result = str + convert;
	}
	UpdateData(false);
}
