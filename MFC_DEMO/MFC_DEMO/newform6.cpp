// newform6.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "newform6.h"
#include "afxdialogex.h"
#include <sstream>
using namespace std;
// newform6 �Ի���

IMPLEMENT_DYNAMIC(newform6, CDialogEx)

newform6::newform6(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	//, neihe(0)
{

}

newform6::~newform6()
{
}

void newform6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_CBIndex(pDX, IDC_COMBO1, neihe);
	//DDV_MinMaxInt(pDX, neihe, 3, 15);
	DDX_Control(pDX, IDRETRY, m_comboWeb);
}


BEGIN_MESSAGE_MAP(newform6, CDialogEx)
	ON_CBN_SELCHANGE(IDRETRY, &newform6::OnSelchangeIdretry)
	ON_BN_CLICKED(IDC_BUTTON1, &newform6::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newform6::OnBnClickedButton2)
END_MESSAGE_MAP()


// newform6 ��Ϣ�������


BOOL newform6::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_comboWeb.AddString(_T("3"));
	// Ϊ��Ͽ�ؼ����б������б���ٶȡ�   
	m_comboWeb.AddString(_T("5"));
	// ����Ͽ�ؼ����б��������Ϊ1��λ�ò����б�����ˡ�   
	m_comboWeb.AddString( _T("7"));
	m_comboWeb.AddString(_T("9"));
	m_comboWeb.AddString(_T("11"));
	m_comboWeb.AddString(_T("21"));
	m_comboWeb.AddString(_T("51"));

	// Ĭ��ѡ���һ��   
	m_comboWeb.SetCurSel(0);
	// �༭����Ĭ����ʾ��һ������֡������ס�   
	//SetDlgItemText(IDC_COMBO1, _T("������"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void newform6::OnSelchangeIdretry()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strWeb;
	int nSel;



	
	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_comboWeb.GetCurSel();
	// ����ѡ����������ȡ�����ַ���   
	m_comboWeb.GetLBText(nSel, strWeb);
	CString strWeb_2 = strWeb;
	CStringA temp(strWeb_2.GetBuffer(0));
	strWeb_2.ReleaseBuffer();
	string ss = temp.GetBuffer(0);
	 n = atoi(ss.c_str());
	// ����Ͽ���ѡ�е��ַ�����ʾ��IDC_SEL_WEB_EDIT�༭����   
	//SetDlgItemText(IDC_SEL_WEB_EDIT, strWeb);
}



//ȷ��
void newform6::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CDialog::OnOK();
}

//ȡ��
void newform6::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	newform6::OnCancel();
}
