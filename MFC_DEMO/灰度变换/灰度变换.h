
// �Ҷȱ任.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�Ҷȱ任App: 
// �йش����ʵ�֣������ �Ҷȱ任.cpp
//

class C�Ҷȱ任App : public CWinApp
{
public:
	C�Ҷȱ任App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�Ҷȱ任App theApp;