// newform2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "newform2.h"
#include "afxdialogex.h"
#include "MFC_DEMODlg.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// newform2 �Ի���

IMPLEMENT_DYNAMIC(newform2, CDialogEx)

newform2::newform2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	
	, canshu(0)

{

}

newform2::~newform2()
{

}

void newform2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//����ؼ�IDC_EDIT1�ͱ���canshu1֮������ݽ���
	//	DDX_Text(pDX, IDC_EDIT1, canshu1);
	//DDX_Control(pDX, IDC_BUTTON1, m_edit1);
	//DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT1, canshu);

	//DDX_Text(pDX, IDC_EDIT2, zhi);
}


BEGIN_MESSAGE_MAP(newform2, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON1, &newform2::OnBnClickedButton1)

	ON_COMMAND(ID_32793, &newform2::On32793)
	ON_BN_CLICKED(IDC_BUTTON1, &newform2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newform2::OnBnClickedButton2)
END_MESSAGE_MAP()


// newform2 ��Ϣ�������



//Ƶ���˲�
void newform2::On32793()
{
	// TODO: �ڴ���������������
	
}





//ȷ����ť
void newform2::OnBnClickedButton1()
{
	UpdateData(TRUE);
CDialog::OnOK();
}

//ȡ����ť
void newform2::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	newform2::OnCancel();
}


//void newform2::OnCancel()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	DestroyWindow();
//	CDialogEx::OnCancel();
//}
