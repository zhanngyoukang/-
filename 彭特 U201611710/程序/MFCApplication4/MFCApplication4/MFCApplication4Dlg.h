
// MFCApplication4Dlg.h: 头文件
//

#pragma once


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float suma;
	float sumb;
	afx_msg void OnEnChangeEdit3();
	float result;
	afx_msg void OnBnClickedButton1();
	float minusa;
	float minusb;
	float result2;
	afx_msg void OnBnClickedButton3();
	float multiplya;
	float multiplyb;
	float result3;
	afx_msg void OnBnClickedButton2();
	float dividea;
	float divideb;
	float result4;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit11();
};
