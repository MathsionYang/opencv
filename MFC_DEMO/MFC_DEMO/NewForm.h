#pragma once
#include "afxwin.h"
#include "cv.h"
#include "highgui.h"
#include "CvvImage.h"

// NewForm �Ի���
//int num1=100;

class NewForm : public CDialogEx
{

//
	// 2018��3��4��20:12:36  
	// ��������ʾ��������һ��int  


private:
	DECLARE_DYNAMIC(NewForm)
	
public:
	int pos;



	NewForm(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~NewForm();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnEnChangeEdit1();
	//int dig();
	//void getNum(int &num2);
	//int pos;
	CScrollBar m_horiScrollbar1;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32787();

	//CString enter1;
	afx_msg void OnEnChangeEdit2();
	//int enter3;
	afx_msg void On32785();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	//virtual void OnCancel();
};
