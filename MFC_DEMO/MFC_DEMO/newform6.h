#pragma once
#include "afxwin.h"


// newform6 �Ի���

class newform6 : public CDialogEx
{
	DECLARE_DYNAMIC(newform6)

public:
	newform6(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~newform6();
	int n;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//int neihe;
	virtual BOOL OnInitDialog();
	CComboBox m_comboWeb;
	afx_msg void OnSelchangeIdretry();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
