// MFC_DEMODlg.cpp : ʵ���ļ�
//
#include <opencv2/opencv.hpp>

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "MFC_DEMODlg.h"
#include "afxdialogex.h"
#include "NewForm.h"
#include "newform2.h"
//#include "newform1.h"
#include "newform6.h"
using namespace cv;
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC_DEMODlg �Ի���


CMFC_DEMODlg::CMFC_DEMODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//m_pTipDlg = NULL;
}

void CMFC_DEMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON1, StopButton);
}

BEGIN_MESSAGE_MAP(CMFC_DEMODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_COMMAND(ID_32774, &CMFC_DEMODlg::On32774)
	ON_COMMAND(ID_32789, &CMFC_DEMODlg::On32789)
	ON_COMMAND(ID_32790, &CMFC_DEMODlg::On32790)
	ON_COMMAND(ID_32794, &CMFC_DEMODlg::On32794)
	ON_COMMAND(ID_32795, &CMFC_DEMODlg::On32795)
	ON_COMMAND(ID_32796, &CMFC_DEMODlg::On32796)
	ON_COMMAND(ID_32798, &CMFC_DEMODlg::On32798)
	//ON_COMMAND(ID_32801, &CMFC_DEMODlg::On32801)
	ON_STN_CLICKED(IDCANCEL, &CMFC_DEMODlg::OnStnClickedCancel)
//	ON_COMMAND(ID_Menu32802, &CMFC_DEMODlg::OnMenu32802)
	ON_COMMAND(ID_32799, &CMFC_DEMODlg::On32799)
	//ON_COMMAND(ID_32791, &CMFC_DEMODlg::On32791)
	ON_COMMAND(ID_32793, &CMFC_DEMODlg::On32793)
	ON_COMMAND(ID_32807, &CMFC_DEMODlg::On32807)
	//ON_COMMAND(ID_32808, &CMFC_DEMODlg::On32808)
	ON_COMMAND(ID_32809, &CMFC_DEMODlg::On32809)
	ON_COMMAND(ID_32810, &CMFC_DEMODlg::On32810)
	ON_COMMAND(ID_32775, &CMFC_DEMODlg::On32775)
	ON_COMMAND(ID_32811, &CMFC_DEMODlg::On32811)
	ON_COMMAND(ID_32812, &CMFC_DEMODlg::On32812)
	ON_COMMAND(ID_32813, &CMFC_DEMODlg::On32813)
	ON_COMMAND(ID_32814, &CMFC_DEMODlg::On32814)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMFC_DEMODlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC_DEMODlg ��Ϣ�������

BOOL CMFC_DEMODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMenu menu;
	//menu.LoadMenuA(IDR_MENU2);  //IDR_MENU1Ϊ�˵���ID��  
	menu.LoadMenuA(IDR_MENU2);
	SetMenu(&menu);

	//m_Menu.LoadMenu(IDR_MENU1);
	//SetMenu(&m_Menu);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	namedWindow("view", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	namedWindow("view2", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND)cvGetWindowHandle("view2");
	HWND hParent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(IDD_DIALOG1)->m_hWnd);
	::ShowWindow(hParent2, SW_HIDE);

	//namedWindow("view3", WINDOW_AUTOSIZE);
	//HWND hWnd3 = (HWND)cvGetWindowHandle("view3");
	//HWND hParent3 = ::GetParent(hWnd3);
	//::SetParent(hWnd3, GetDlgItem(IDCLOSE)->m_hWnd);
	//::ShowWindow(hParent3, SW_HIDE);



	// ����ˮƽ�������Ĺ�����ΧΪ1��100   
    // m_horiScrollbar1.SetScrollRange(1, 100);
	// ����ˮƽ�������ĳ�ʼλ��Ϊ20   
	// m_horiScrollbar1.SetScrollPos(20);
	// �ڱ༭������ʾ20   
	//SetDlgItemInt(IDC_EDIT1, 20);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}




void CMFC_DEMODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_DEMODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_DEMODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





//��ʾ����һ��Pic�ؼ�
void CMFC_DEMODlg::ShowPic_1(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view", imagedst);
}
//��ʾ���ڶ���Pic�ؼ�
void CMFC_DEMODlg::ShowPic_2(Mat input_2)
{
	Mat imagedst;
	CRect rect2;
	GetDlgItem(IDD_DIALOG1)->GetClientRect(&rect2);
	Rect dst2(rect2.left, rect2.top, rect2.right, rect2.bottom);
	resize(input_2, imagedst, cv::Size(rect2.Width(), rect2.Height()));
	imshow("view2", imagedst);
}
//��ʾ��������Pic�ؼ�
//void CMFC_DEMODlg::ShowPic_3(Mat input_3)
//{
//	Mat imagedst;
//
//	CRect rect3;
//	GetDlgItem(IDCLOSE)->GetClientRect(&rect3);
//	Rect dst3(rect3.left, rect3.top, rect3.right, rect3.bottom);
//	resize(input_3, imagedst, cv::Size(rect3.Width(), rect3.Height()));
//	imshow("view3", imagedst);
//}
//��
void CMFC_DEMODlg::On32774()
{
     open2();
	//string ext = strrchr(out.c_str(), '.') + 1;
	//string ext2 = "avi";
	//if (ext == ext2) {
	//	//ShowPic_1(out);
	//	capture.open(out);
	//	while (1) {
	//		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
	//		capture >> frame;  //��ȡ��ǰ֡
	//						   // GaussianBlur(frame,frame, cvSize(3,3), 2, 2, BORDER_DEFAULT);//��˹ƽ��
	//						   // Canny(frame,frame,20,100,3);//��Ե���
	//		Mat imagedst;
	//		ShowPic_1(frame);
	//		waitKey(30);  //��ʱ30ms
	//	}
	//}
	//else
	//{
	//	image = imread(out);
	//	ShowPic_1(image);
	//}

}



//�ҶȻ�
void CMFC_DEMODlg::On32789()
{
	// TODO: �ڴ���������������
	out=ImageGray1();
	ShowPic_2(out);
}

//��ֵ��
void CMFC_DEMODlg::On32790()
{
	// TODO: �ڴ���������������
	
//	NewForm  Dlg;
	//Dlg.DoModal();
	//newform2  Dl;
	
		//out=ImageEZH1();
	ImageEZH1();
			//ShowPic_2(out);
		
}

//��ֵ�˲�
void CMFC_DEMODlg::On32794()
{
	ImageJZ1();
}

//��˹�˲�
void CMFC_DEMODlg::On32795()
{
	// TODO: �ڴ���������������
	 ImageGS1();
}

//������˹�˲�
void CMFC_DEMODlg::On32796()
{
	// TODO: �ڴ���������������
	out = ImageLPLS1();
	ShowPic_2(out);

}

//
//canny����
void CMFC_DEMODlg::On32798()
{
	 ImageCANNY1();
	
}

void CMFC_DEMODlg::OnStnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//sobel����
void CMFC_DEMODlg::On32799()
{
	// TODO: �ڴ���������������
	 ImageSOBEL();
}

//ֱ��ͼ
void CMFC_DEMODlg::On32807()
{
	// TODO: �ڴ���������������
	SonWnd_2.WndCreate(this);
}
//Ƶ���˲�
void CMFC_DEMODlg::On32793()
{
	// TODO: �ڴ���������������
	SonWnd.WndCreate2(this);
	//UpdateData(FALSE);
}



//void CMFC_DEMODlg::OnCancel()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	DestroyWindow();
//	CDialogEx::OnCancel();
//}


//��Ƶ��Ե���
void CMFC_DEMODlg::On32809()
{
	// TODO: �ڴ���������������
	cannyS();
}

//��Ƶ����
void CMFC_DEMODlg::On32810()
{
	// TODO: �ڴ���������������
	videoG();
}

//����
void CMFC_DEMODlg::On32775()
{
	// TODO: �ڴ���������������
	save1();
}

//���Ϊ
void CMFC_DEMODlg::On32811()
{
	// TODO: �ڴ���������������
	save2();
}

//��ɫ����
void CMFC_DEMODlg::On32812()
{
	// TODO: �ڴ���������������
	ImageHUIDU();
}

//�Ҷȷֶ�����
void CMFC_DEMODlg::On32813()
{
	// TODO: �ڴ���������������
	ImageHUIDU_2();
}

//�Ҷȷ�����
void CMFC_DEMODlg::On32814()
{
	// TODO: �ڴ���������������
	ImageHUIDU_3();
}

//��ͣ

//void CMFC_DEMODlg::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CString buttonText;
//	StopButton.GetWindowText(buttonText);
//
//	if (buttonText.Compare(_T("��ͣ")) == 0)
//	{
//		start_event.ResetEvent();
//		StopButton.SetWindowTextA(_T("����"));
//
//	}
//	else
//	{
//		start_event.SetEvent();
//		StopButton.SetWindowText(_T("��ͣ"));
//	}
//}
