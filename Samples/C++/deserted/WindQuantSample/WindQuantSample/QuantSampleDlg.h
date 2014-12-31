
// QuantSampleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
struct tagQuantEvent;
typedef struct tagQuantEvent WQEvent;

// CQuantSampleDlg �Ի���
class CQuantSampleDlg : public CDialog
{
// ����
public:
	CQuantSampleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_QUANTSAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

    static int WINAPI QuantCallback(WQEvent* pEvent, LPVOID pParam);

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
    int m_Func;
    CEdit m_OutputEdit;

public:
    CString m_Windcodes;
    CString m_Indicators;
    CString m_EndTime;
    CString m_Params;
    CString m_Output;
    CString m_Username;
    CString m_Password;
    CString m_BeginTime;
    LONGLONG mCancelID;
    BOOL m_subs;

public:
    afx_msg void OnBnClickedBtnStart();
    afx_msg void OnBnClickedLogin();
    afx_msg void OnBnClickedLogout();
    afx_msg void OnBnClickedBtnExec();
    afx_msg LRESULT OnResponse( WPARAM, LPARAM );
    afx_msg void OnBnClickedRadioWSD();
    afx_msg void OnBnClickedRadioWSS();
    afx_msg void OnBnClickedRadioWSI();
    afx_msg void OnBnClickedRadioWST();
    afx_msg void OnBnClickedRadioWSQ();
    afx_msg void OnBnClickedRadioTDAYSCNT();
    afx_msg void OnBnClickedRadioTDAYSOFF();
    afx_msg void OnBnClickedRadioTDAYS();
    afx_msg void OnBnClickedBtnCancel();
    afx_msg void OnBnClickedRadioWSET();
    afx_msg void OnBnClickedRadioWEQS();
    afx_msg void OnClose();

};
