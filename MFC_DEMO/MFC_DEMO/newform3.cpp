// newform3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "newform3.h"
#include "afxdialogex.h"


// newform3 �Ի���

IMPLEMENT_DYNAMIC(newform3, CDialogEx)

newform3::newform3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, liangdu(0)
	, duibidu(0)
{

}

newform3::~newform3()
{
}

void newform3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, liangdu);
	DDV_MinMaxInt(pDX, liangdu, 0, 1000);
	DDX_Text(pDX, IDC_EDIT2, duibidu);
	DDV_MinMaxInt(pDX, duibidu, 0, 1000);
}


BEGIN_MESSAGE_MAP(newform3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &newform3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newform3::OnBnClickedButton2)
END_MESSAGE_MAP()


// newform3 ��Ϣ�������

//ȷ��
void newform3::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CDialog::OnOK();
}

//ȡ��
void newform3::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	newform3::OnCancel();
}


//void newform3::OnCancel()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	DestroyWindow();
//	CDialogEx::OnCancel();
//}
