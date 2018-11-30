// NewForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_DEMO.h"
#include "NewForm.h"
#include "afxdialogex.h"


// NewForm �Ի���

IMPLEMENT_DYNAMIC(NewForm, CDialogEx)

NewForm::NewForm(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	
	//, enter1(_T(""))
	//, enter3(0)
{

}

NewForm::~NewForm()
{
}

void NewForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_SCROLLBAR1, m_horiScrollbar1);
	//DDX_Text(pDX, IDC_EDIT2, enter1);
	//DDV_MaxChars(pDX, enter1, 255);
	//DDX_Text(pDX, IDC_EDIT3, enter3);
	//DDV_MinMaxInt(pDX, enter3, 0, 255);
}


BEGIN_MESSAGE_MAP(NewForm, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &NewForm::OnEnChangeEdit1)
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &NewForm::OnNMThemeChangedScrollbar1)
	ON_COMMAND(ID_32787, &NewForm::On32787)
	ON_EN_CHANGE(IDC_EDIT2, &NewForm::OnEnChangeEdit2)
	ON_COMMAND(ID_32785, &NewForm::On32785)
	ON_BN_CLICKED(IDC_BUTTON1, &NewForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &NewForm::OnBnClickedButton2)
END_MESSAGE_MAP()



// �������ܣ����ر���� int  


// NewForm ��Ϣ�������
BOOL NewForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();


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
	//SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	//SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ����ˮƽ�������Ĺ�����ΧΪ1��100   
	m_horiScrollbar1.SetScrollRange(1, 100);
	// ����ˮƽ�������ĳ�ʼλ��Ϊ20   
	m_horiScrollbar1.SetScrollPos(20);
	// �ڱ༭������ʾ20   
	SetDlgItemInt(IDC_EDIT1, 20);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void NewForm::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



void NewForm::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	//int pos = m_horiScrollbar1.GetScrollPos();    // ��ȡˮƽ��������ǰλ��
	
	pos = m_horiScrollbar1.GetScrollPos();
	switch (nSBCode)
	{
		// ����������һ�У���pos��1  
	case SB_LINELEFT:
		pos -= 1;
		break;
		// ������ҹ���һ�У���pos��1  
	case SB_LINERIGHT:
		pos += 1;
		break;
		// ����������һҳ����pos��10  
	case SB_PAGELEFT:
		pos -= 10;
		break;
		// ������ҹ���һҳ����pos��10  
	case SB_PAGERIGHT:
		pos += 10;
		break;
		// �������������ˣ���posΪ1  
	case SB_LEFT:
		pos = 1;
		break;
		// ������������Ҷˣ���posΪ100  
	case SB_RIGHT:
		pos = 100;
		break;
		// ����϶������������ָ��λ�ã���pos��ֵΪnPos��ֵ  
	case SB_THUMBPOSITION:
		pos = nPos;
		break;

		// �����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺���������ȷ��������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭������ʾ��ֵ  
	default:
		SetDlgItemInt(IDC_EDIT1, pos);
		//return pos;
	}

	// ���ù�����λ��  
	m_horiScrollbar1.SetScrollPos(pos);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}








void NewForm::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//IplImage*out = SaveImage();
	UpdateData(TRUE);

	//zhi = canshu;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(FALSE);
	CDialog::OnOK();
	*pResult = 0;
}


void NewForm::On32787()
{

}


void NewForm::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




void NewForm::On32785()
{
	// TODO: �ڴ���������������

	//IplImage*out = SaveImage();
	
}

//ȷ��
void NewForm::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	NewForm::OnOK();
}

//ȡ��
void NewForm::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NewForm::OnCancel();
}


//void NewForm::OnCancel()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	DestroyWindow();
//	CDialogEx::OnCancel();
//}
