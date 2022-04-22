
// MFCRPGSTATUSDlg->h: 헤더 파일
//

#pragma once


// CMFCRPGSTATUSDlg 대화 상자
class CMFCRPGSTATUSDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCRPGSTATUSDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCRPGSTATUS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	class GameManager* m_pGameManager;
public:
	int m_nHP;
	int m_nBonusPoint;
	CString m_strClass;
public:
	CEdit m_editName;
	CComboBox m_comboClass;
	CEdit m_editHP;
	CEdit m_editMP;
	CEdit m_editStr;
	CEdit m_editInt;
	CEdit m_editDef;
	afx_msg void OnDeltaposSpinHP(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinMP(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinStr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinInt(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinDef(NMHDR* pNMHDR, LRESULT* pResult);
	CStatic m_staticBonusPoint;
	afx_msg void OnCbnSelchangeComboClass();
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonResult();
};
