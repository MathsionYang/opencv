// newform5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "newform5.h"
#include "afxdialogex.h"
#include "MFC_DEMODlg.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// newform5 �Ի���

IMPLEMENT_DYNAMIC(newform5, CDialogEx)

newform5::newform5(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

newform5::~newform5()
{
}

void newform5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(newform5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &newform5::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newform5::OnBnClickedButton2)
END_MESSAGE_MAP()


// newform5 ��Ϣ�������


BOOL newform5::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	namedWindow("view_4", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view_4");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDHELP)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	namedWindow("view_5", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND)cvGetWindowHandle("view_5");
	HWND hParent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(IDCANCEL)->m_hWnd);
	::ShowWindow(hParent2, SW_HIDE);

	namedWindow("view_6", WINDOW_AUTOSIZE);
	HWND hWnd3 = (HWND)cvGetWindowHandle("view_6");
	HWND hParent3 = ::GetParent(hWnd3);
	::SetParent(hWnd3, GetDlgItem(IDCLOSE)->m_hWnd);
	::ShowWindow(hParent3, SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
void newform5::WndCreate(LPVOID pParent)

{
	if (adlg == NULL) {
		Create(IDD_DIALOG5);                         //�����Ի���

		ShowWindow(SW_SHOW);                         //��ʾ�Ի���

		adlg = pParent;                         //��������ָ�봫�ݽ���
	}
}


void newform5::ShowPic1(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDHELP)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_4", imagedst);
}
void newform5::ShowPic2(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDCANCEL)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_5", imagedst);
}
void newform5::ShowPic3(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDCLOSE)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_6", imagedst);
}
//��ɫͼ��
void newform5::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ain;
	ain = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	//Mat out1 = ain->ImageJHH1();
	ain->out = ain->ImageJHH1();
	ShowPic1(ain->out);
	Mat out2 = ain->ImageJHH2();
	ShowPic2(out2);
	Mat out3 = ain->ImageJHH3();
	ShowPic3(out3);
	//CMFC_DEMODlg::ImageJHH1();
}

//�Ҷ�ͼ��
void newform5::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ain;
	ain = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	//Mat out1 = ain->ImageZFT1();
	ain->out = ain->ImageZFT1();
	ShowPic1(ain->out);
	Mat out2 = ain->ImageZFT2();
	ShowPic2(out2);
	Mat out3 = ain->ImageZFT3();

	ShowPic3(out3);
}


void newform5::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	DestroyWindow();
	adlg = NULL;
	CDialogEx::OnCancel();
}
