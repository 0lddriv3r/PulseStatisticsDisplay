#ifndef AFCHARTBASEOBJ_H
#define AFCHARTBASEOBJ_H


#include <QtWebKit\QWebView>
#include <QtGui\QWidget>
#include <rapidjson\document.h>
#include "echartsinqt_global.h"

enum EChartsType {
	OTHER = 1,
	RF    = 2,
	PRI   = 3,
	PW    = 4,
	DOA   = 5,
	PA    = 6
};

struct AFChartBaseObj_P;

class ECHARTS_COMMON_EXPORT AFChartBaseObj : public QWebView
{
	Q_OBJECT

public:
	AFChartBaseObj(QWidget *parent=0);
	~AFChartBaseObj();

public:
	//��ȡ ECharts ʵ�������Ŀ�ȡ�
	int GetWidth();
	//��ȡ ECharts ʵ�������ĸ߶ȡ�
	int GetHeight();

	/*�ı�ͼ��ߴ磬��������С�����ı�ʱ��Ҫ�ֶ����á�
	width
	����ʽָ��ʵ����ȣ���λΪ���ء��������ֵΪ null/undefined/'auto'�����ʾ�Զ�ȡ dom��ʵ���������Ŀ�ȡ�
	height
	����ʽָ��ʵ���߶ȣ���λΪ���ء��������ֵΪ null/undefined/'auto'�����ʾ�Զ�ȡ dom��ʵ���������ĸ߶ȡ�
	silent
	�Ƿ��ֹ�׳��¼���Ĭ��Ϊ false��*/

	void Resize(int width,int height,bool isSilent);

	
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize();

	void InitEChartsHtml(QString url);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Resets the option. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void ResetOption();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the chart. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="eChartsType">	Type of the charts. </param>
	/// <param name="IsReset">	  	true if is reset. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void UpdateChart(EChartsType eChartsType = OTHER, bool IsReset = false);

protected slots:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads a finished slot. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="Result">	true to result. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void loadFinishedSlot(bool Result);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the new identifier. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <returns>	The new identifier. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	const QString GetNewID();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Lazy initial slot. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void LazyInitialSlot();
public slots:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads the e charts html. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void LoadEChartsHtml();
protected:
	rapidjson::Document param;

private:
	AFChartBaseObj_P*_p;
};

#endif // AFCHARTBASEOBJ_H
