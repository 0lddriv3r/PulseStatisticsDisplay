#ifndef AFLINEWIDGET_H
#define AFLINEWIDGET_H

#include "AFCommonChart.h"
#include "echartsinqt_global.h"

struct AFLineWidget_P;

class ECHARTS_COMMON_EXPORT AFLineWidget : public AFCommonChart
{
	Q_OBJECT

public:
	AFLineWidget(QWidget *parent);
	~AFLineWidget();

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize();


public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series coordinate system. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">		   	[in,out] The data object. </param>
	/// <param name="coordinateSystem">	The coordinate system. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_CoordinateSystem(rapidjson::Value & DataObj,const QString & coordinateSystem);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series show symbol. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	   	[in,out] The data object. </param>
	/// <param name="isShowSymbol">	The is show symbol. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ShowSymbol(rapidjson::Value & DataObj,const bool & isShowSymbol);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series simple data. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	  	[in,out] The data object. </param>
	/// <param name="SimpleDatas">	The simple datas. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_SimpleData(rapidjson::Value & DataObj,const std::vector<std::pair<float,float> > & SimpleDatas);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series simple data. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	  	[in,out] The data object. </param>
	/// <param name="SimpleDatas">	The simple datas. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_SimpleData(rapidjson::Value & DataObj,const std::vector<Line_SimpleDataDesPtr > & SimpleDatas);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series simple data. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	  	[in,out] The data object. </param>
	/// <param name="SimpleDatas">	The simple datas. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_SimpleData(rapidjson::Value & DataObj,const std::vector<double> & SimpleDatas);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series simple data. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	  	[in,out] The data object. </param>
	/// <param name="SimpleDatas">	The simple datas. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_SimpleData(rapidjson::Value & DataObj,const std::vector<Line_SingleValueDesPtr > & SimpleDatas);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series line style color. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_LineStyle_Color(rapidjson::Value & DataObj, const QColor & color);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the series item style color. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	///
	/// <param name="DataObj">	[in,out] The data object. </param>
	/// <param name="color">  	The color. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetSeries_ItemStyle_Color(rapidjson::Value & DataObj, const QColor & color);

private:
	AFLineWidget_P *_p;
};

#endif // AFLINEWIDGET_H
