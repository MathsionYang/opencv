// newform1.cpp : ʵ���ļ�
//


#include "stdafx.h"
#include "MFC_DEMO.h"

#include "MFC_DEMODlg.h"
#include "newform1.h"
#include "afxdialogex.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
// newform1 �Ի���

IMPLEMENT_DYNAMIC(newform1, CDialogEx)

newform1::newform1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	//, canshu1(0)
{

}

newform1::~newform1()
{

}

void newform1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, canshu1);
}


BEGIN_MESSAGE_MAP(newform1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &newform1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newform1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &newform1::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &newform1::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &newform1::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &newform1::OnBnClickedButton6)
END_MESSAGE_MAP()


// newform1 ��Ϣ�������


BOOL newform1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	namedWindow("view_1", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view_1");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDD_ABOUTBOX)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	namedWindow("view_2", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND)cvGetWindowHandle("view_2");
	HWND hParent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(IDD_DIALOG2)->m_hWnd);
	::ShowWindow(hParent2, SW_HIDE);

	namedWindow("view_3", WINDOW_AUTOSIZE);
	HWND hWnd3 = (HWND)cvGetWindowHandle("view_3");
	HWND hParent3 = ::GetParent(hWnd3);
	::SetParent(hWnd3, GetDlgItem(IDD_DIALOG4)->m_hWnd);
	::ShowWindow(hParent3, SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void newform1::WndCreate2(LPVOID pParent)

{
	if (NULL == adlg) {
		Create(IDD_DIALOG3);                         //�����Ի���

	//	ShowWindow(SW_SHOW);                         //��ʾ�Ի���
		ShowWindow(SW_SHOW);
		adlg = pParent;                         //��������ָ�봫�ݽ���

	}
	
}

void newform1::ShowPic1(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDD_ABOUTBOX)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_1", imagedst);
}
void newform1::ShowPic2(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDD_DIALOG2)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_2", imagedst);
}
void newform1::ShowPic3(Mat input_1)
{
	Mat imagedst;
	CRect rect;
	GetDlgItem(IDD_DIALOG4)->GetClientRect(&rect);
	Rect dst(rect.left, rect.top, rect.right, rect.bottom);
	resize(input_1, imagedst, cv::Size(rect.Width(), rect.Height()));
	imshow("view_3", imagedst);
}

//�����ͨ
void newform1::OnBnClickedButton1()
{

	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
			
														 
	
	Mat out_1= ai->ImageDCT();
	ShowPic1( out_1);
	Mat out_2 = ai->ImageDCT_1();
	 //ai->ImageDCT_1();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_1();
	//imshow("w", ai->out);
	ShowPic3(ai->out);//Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��

}
//�����ͨ
void newform1::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	Mat out_1 = ai->ImageDCT();
	ShowPic1(out_1);
	Mat out_2 = ai->ImageDCT_2();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_2();
	ShowPic3(ai->out);
}

//��˹��ͨ
void newform1::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
					
//Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	Mat out_1 = ai->ImageDCT();
	ShowPic1(out_1);
	Mat out_2 = ai->ImageDCT_3();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_3();
	ShowPic3(ai->out);
}

//��˹��ͨ
void newform1::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	Mat out_1 = ai->ImageDCT();
	ShowPic1(out_1);
	Mat out_2 = ai->ImageDCT_4();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_4();
	ShowPic3(ai->out);
}

//������˹��ͨ
void newform1::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	Mat out_1 = ai->ImageDCT();
	ShowPic1(out_1);
	Mat out_2 = ai->ImageDCT_5();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_5();
	ShowPic3(ai->out);
}

//������˹��ͨ
void newform1::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFC_DEMODlg*ai;
	ai = (CMFC_DEMODlg*)adlg;                            //ǿ�ƽ�LPVOID����ת��
														  //Main = (CProjectDlg*)m_pFather;                            //ǿ�ƽ�LPVOID����ת��
	Mat out_1 = ai->ImageDCT();
	ShowPic1(out_1);
	Mat out_2 = ai->ImageDCT_6();
	ShowPic2(out_2);
	ai->out = ai->ImageLIX_6();
	ShowPic3(ai->out);
}

void newform1::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	DestroyWindow();
	adlg=NULL;
	CDialogEx::OnCancel();
}


//void newform1::PostNcDestroy()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	//delete this;
//	CDialogEx::PostNcDestroy();
//}
