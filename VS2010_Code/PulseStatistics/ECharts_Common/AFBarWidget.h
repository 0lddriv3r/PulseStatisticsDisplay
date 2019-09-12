#ifndef __AFBARWIDGET_H__
#define __AFBARWIDGET_H__

#include <QWidget>

#include "AFCommonChart.h"
#include "echartsinqt_global.h"

struct ECHARTS_COMMON_EXPORT DataItem {
	DataItem(){}

	DataItem(std::string start, std::string end, std::string RF, std::string name)
		:_Start(start),
		_End(end),
		_RF(RF),
		_Name(name)
	{}

	std::string _Start;
	std::string _End;
	std::string _RF;
	std::string _Name;
};

struct ECHARTS_COMMON_EXPORT ScatterDataItem {
	ScatterDataItem(){}

	ScatterDataItem(std::string yValue, std::string xValue)
		:_yValue(yValue),
		_xValue(xValue)
	{}

	std::string _yValue;
	std::string _xValue;
};

struct AFBarWidget_P;

class ECHARTS_COMMON_EXPORT AFBarWidget :public AFCommonChart
{
	Q_OBJECT
public:
	AFBarWidget(QWidget *parent=0);
	~AFBarWidget(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a data. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="seriesname">	The seriesname. </param>
	/// <param name="stack">	 	The stack. </param>
	/// <param name="data">		 	The data. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetData(const QString & seriesname ,const QString & stack ,const std::vector<QString> & data);


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Bar Series . </summary>
///
/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series stack. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="stack">  	The stack. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_Stack(rapidjson::Value & DataObj,const QString & stack);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series item style normal border color. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ItemStyle_Normal_BorderColor(rapidjson::Value & DataObj,const QString & color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series item style normal color. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ItemStyle_Normal_Color(rapidjson::Value & DataObj,const QString & color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series item style emphasis border color./ </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ItemStyle_Emphasis_BorderColor(rapidjson::Value & DataObj,const QString & color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series item style emphasis color. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ItemStyle_Emphasis_Color(rapidjson::Value & DataObj,const QString & color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series data simple. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="data">   	The data. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_Data_Simple(rapidjson::Value & DataObj,const std::vector<QString> & data);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series data array. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="data">   	The data. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_DataArray(rapidjson::Value & DataObj,const std::vector<DataItem> & data);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series scatter data array. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="data">   	The data. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ScatterDataArray(rapidjson::Value & DataObj,const std::vector<ScatterDataItem> & data);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series label normal show. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="IsShow"> 	true if is show. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_Label_Normal_Show(rapidjson::Value & DataObj,bool IsShow);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series label normal position. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="Pos">	  	The position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_Label_Normal_Position(rapidjson::Value & DataObj,const QString & Pos);

private:
	AFBarWidget_P *_p;
};
#endif // __AFBARWIDGET_H__


