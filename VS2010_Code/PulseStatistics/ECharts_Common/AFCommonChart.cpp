#include "stdafx.h"
#include <QtWebKit\QWebPage>
#include <QtWebKit\QWebFrame>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "rapidjson_fastfunc.h"

#include "CommonFunc.h"

#include "AFCommonChart.h"

struct AFCommonChart_P
{
	AFCommonChart_P()
		:_DataValueArray(rapidjson::kArrayType)
	{
		_DataValueArray.SetArray();
	}

	rapidjson::Value _DataValueArray;
};

AFCommonChart::AFCommonChart(QWidget *parent)
	: AFEventObj(parent)
	,_p(new AFCommonChart_P())
{
	setContextMenuPolicy(Qt::NoContextMenu);
}

AFCommonChart::~AFCommonChart(void)
{
	delete _p;
}

void AFCommonChart::SetTitle_Text(const QString & text )
{
	rapidjson::addRapidjsonParam(param,std::string("title"),std::string("text"),text.toStdString());
}

void AFCommonChart::SetTitle_SubText( const QString & text )
{
	rapidjson::addRapidjsonParam(param,std::string("title"),std::string("subtext"),text.toStdString());
}

void AFCommonChart::SetTitle_SubLink( const QString & text )
{
	rapidjson::addRapidjsonParam(param,std::string("title"),std::string("sublink"),text.toStdString());
}

void AFCommonChart::SetxAxis_Data_Simple( const std::vector<QString> & data )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("scale"),data[0].toStdString());
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("name"),data[1].toStdString());
}

void AFCommonChart::SetyAxis_Data_Simple( const std::vector<QString> & data )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("name"),data[0].toStdString());
}

void AFCommonChart::SetyAxis_Data_Simple( rapidjson::Value & DataObj, const std::vector<QString> & data )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(), std::string("data"), CommonFunc::QStringArrayToStd(data));
}


void AFCommonChart::SetLegend_Data_Simple( const std::vector<QString> & data )
{
	rapidjson::addRapidjsonParam(param,std::string("legend"),std::string("data"),CommonFunc::QStringArrayToStd(data));
}

void AFCommonChart::SetGrid_Left( const QString & Left )
{
	rapidjson::addRapidjsonParam(param,std::string("grid"),std::string("left"),Left.toStdString());
}

void AFCommonChart::SetGrid_Right( const QString & Right )
{
	rapidjson::addRapidjsonParam(param,std::string("grid"),std::string("right"),Right.toStdString());
}

void AFCommonChart::SetGrid_Top( const QString & Top )
{
	rapidjson::addRapidjsonParam(param,std::string("grid"),std::string("top"),Top.toStdString());
}

void AFCommonChart::SetGrid_Bottom( const QString & Bottom )
{
	rapidjson::addRapidjsonParam(param,std::string("grid"),std::string("bottom"),Bottom.toStdString());
}

void AFCommonChart::SetGrid_ContainLabel( const bool & IsContain )
{
	rapidjson::addRapidjsonParam(param,std::string("grid"),std::string("containLabel"),IsContain);
}

void AFCommonChart::SetxAxis_Type( const QString & Type )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("type"),Type.toStdString());
}

void AFCommonChart::SetxAxis_SplitLine_Show( const bool & isShow )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("splitLine"),std::string("show"),isShow);
}

void AFCommonChart::SetyAxis_Type( const QString & Type )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("type"),Type.toStdString());
}

void AFCommonChart::SetyAxis_Type( rapidjson::Value & DataObj, const QString & Type )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(),std::string("type"),Type.toStdString());
}

void AFCommonChart::SetyAxis_SplitLine_Show( const bool & isShow )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("splitLine"),std::string("show"),isShow);
}

void AFCommonChart::SetyAxis_SplitLine_Show( rapidjson::Value & DataObj, const bool & isShow )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("splitLine"),std::string("show"),isShow);
}

void AFCommonChart::SetTooltip_Trigger( const QString & trigger )
{
	rapidjson::addRapidjsonParam(param,std::string("tooltip"),std::string("trigger"),trigger.toStdString());
}

void AFCommonChart::SetTooltip_AxisPointer_Type( const QString & Type )
{
	rapidjson::addRapidjsonParam(param,std::string("tooltip"),std::string("axisPointer"),std::string("type"),Type.toStdString());
}

void AFCommonChart::Initialize()
{
	AFEventObj::Initialize();

	//rapidjson::addRapidjsonParam(pa)
}


rapidjson::Value AFCommonChart::CreateDataObj()
{
	rapidjson::Value valueobj(rapidjson::kObjectType);

	return valueobj;
}

void AFCommonChart::SetSeries_Name(rapidjson::Value & DataObj, const QString & name )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("name"),name.toStdString());
}

void AFCommonChart::SetSeries_Type( rapidjson::Value & DataObj,const QString & type )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("type"),type.toStdString());
}

void AFCommonChart::SetSeries_RenderItem( rapidjson::Value & DataObj,const QString & type )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("renderItem"),type.toStdString());
}

void AFCommonChart::SetSeries_Dimensions( rapidjson::Value & DataObj,const std::vector<QString> & dimensions )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("dimensions"),CommonFunc::QStringArrayToStd(dimensions));
}

void AFCommonChart::SetSeries_Encode( rapidjson::Value & DataObj )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("encode"),std::string("x"),QString("[0,1]"));
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("encode"),std::string("y"),QString("2"));
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("encode"),std::string("tooltip"),QString("[0,1,2]"));
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("encode"),std::string("itemName"),QString("3"));
}

void AFCommonChart::SetSeries_Center( rapidjson::Value & DataObj,const std::vector<QString> & pos )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("center"),CommonFunc::QStringArrayToStd(pos));
}

void AFCommonChart::PushDataToSeries( rapidjson::Value &DataObj )
{
	_p->_DataValueArray.PushBack(DataObj,param.GetAllocator());
}

void AFCommonChart::UpdateSeriesOption()
{
	if (!_p->_DataValueArray.Empty())
	{
		if (param.HasMember("series"))
		{
			if (param["series"].IsArray())
			{
				for (std::size_t Index = 0 ;Index < _p->_DataValueArray.Size();++Index)
				{
					param["series"].PushBack(_p->_DataValueArray[Index],param.GetAllocator());
				}
			}
			
		}
		else
		{
			param.AddMember("series",_p->_DataValueArray,param.GetAllocator());
		}

		_p->_DataValueArray.SetArray();
	}
}

void AFCommonChart::SetTooltip_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("tooltip"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetxAxis_Min( const int & min )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("min"),min);
}

void AFCommonChart::SetxAxis_Min( const QString & min )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("min"),min);
}

void AFCommonChart::SetyAxis_Min( const int & min )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("min"),min);
}

void AFCommonChart::SetyAxis_Min( const QString & min )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("min"),min);
}

void AFCommonChart::SetyAxis_Min( rapidjson::Value & DataObj, const int & min )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("min"),min);
}

void AFCommonChart::SetyAxis_Min( rapidjson::Value & DataObj, const QString & min )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("min"),min.toStdString());
}

void AFCommonChart::SetDataZoom_Inside_Type()
{
	rapidjson::addRapidjsonParam_DataZoom(param,std::string("inside"),std::string("type"),std::string("inside"));
}

void AFCommonChart::SetDataZoom_Slider_Type()
{
	rapidjson::addRapidjsonParam_DataZoom(param,std::string("slider"),std::string("type"),std::string("slider"));
}

void AFCommonChart::SetLegend_Orient( const QString & orient )
{
	rapidjson::addRapidjsonParam(param,std::string("legend"),std::string("orient"),orient.toStdString());
}

void AFCommonChart::SetLegend_X( const QString & X )
{
	rapidjson::addRapidjsonParam(param,std::string("legend"),std::string("x"),X.toStdString());
}

void AFCommonChart::SetLegend_Show( const bool & isShow )
{
	rapidjson::addRapidjsonParam(param,std::string("legend"),std::string("show"),isShow);
}

void AFCommonChart::SetEChartsBackgroundImage( const QUrl & imagePath)
{
	page()->mainFrame()->evaluateJavaScript(QString("setEchartsBackgroundImage('%1')").arg(imagePath.toString()));
}

void AFCommonChart::setBackgroundColor_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("backgroundColor"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("axisLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisLine_LineStyle_Color( rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("axisLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisTick_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("axisTick"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisTick_LineStyle_Color( rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(),std::string("axisTick"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisLabel_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("axisLabel"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetyAxis_AxisLabel_Color( rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("axisLabel"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetxAxis_AxisLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("axisLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetxAxis_AxisTick_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("axisTick"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetxAxis_AxisTick_AlignWithLabel( const bool & value )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("axisTick"),std::string("alignWithLabel"),value);
}

void AFCommonChart::SetxAxis_AxisLabel_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("axisLabel"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetTitle_TextStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("title"),std::string("textStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetTitle_SubTextStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("title"),std::string("subTextStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetColor( const std::vector<QString> & color )
{
	rapidjson::addRapidjsonParam(param,std::string("color"),CommonFunc::QStringArrayToStd(color));
}

void AFCommonChart::SetTitle( const QString & title )
{
	SetTitle_Text(title);
}


void AFCommonChart::SetSubTitle( const QString & title )
{
	SetTitle_SubText(title);
}

void AFCommonChart::SetLegend( const std::vector<QString> & Legends )
{
	SetLegend_Data_Simple(Legends);
}


void AFCommonChart::SetXAxisLabels( const std::vector<QString> & Labels )
{
	SetxAxis_Data_Simple(Labels);
}

void AFCommonChart::SetYAxisLabels( const std::vector<QString> & Labels )
{
	SetyAxis_Data_Simple(Labels);
}

void AFCommonChart::SetTitleColor( const QString & color )
{
	SetTitle_TextStyle_Color(color);
}


void AFCommonChart::SetSubTitleColor( const QString & color )
{
	SetTitle_SubTextStyle_Color(color);
}

void AFCommonChart::SetLegendLabelColor( const QString & color )
{
	SetLegend_TextStyle_Color(color);
}

void AFCommonChart::SetLegend_TextStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("legend"),std::string("textStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetSeries_ID( rapidjson::Value & DataObj,const QString & iD )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("id"),iD.toStdString());
}

void AFCommonChart::SetPolar_NullObj()
{
	rapidjson::addRapidjsonParam_NullObj(param,std::string("polar"));
}

void AFCommonChart::SetAngleAxis_StartAngle( const QString & Angle )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("startAngle"),Angle.toStdString());
}

void AFCommonChart::SetAngleAxis_StartAngle( const int & Angle )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("startAngle"),Angle);
}

void AFCommonChart::SetRadiusAxis_NullObj()
{
	rapidjson::addRapidjsonParam_NullObj(param,std::string("radiusAxis"));
}

void AFCommonChart::SetAngleAxis_Type( const QString & type )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("type"),type.toStdString());
}

void AFCommonChart::SetPolar_Center( const std::vector<QString> & center )
{
	rapidjson::addRapidjsonParam(param,std::string("polar"),std::string("center"),CommonFunc::QStringArrayToStd(center));
}

void AFCommonChart::SetRadiusAxis_AxisLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("axisLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetRadiusAxis_SplitLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("splitLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetRadiusAxis_AxisPointer_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("axisPointer"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetRadiusAxis_AxisPointer_Label_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("axisPointer"),std::string("label"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetAngleAxis_AxisLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("axisLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetAngleAxis_SplitLine_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("splitLine"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetAngleAxis_AxisPointer_LineStyle_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("axisPointer"),std::string("lineStyle"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetAngleAxis_AxisPointer_Label_Color( const QString & color )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("axisPointer"),std::string("label"),std::string("color"),color.toStdString());
}

void AFCommonChart::SetxAxis_AxisLabel_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("xAxis"),std::string("axisLabel"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetyAxis_AxisLabel_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("yAxis"),std::string("axisLabel"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetyAxis_AxisLabel_Formatter( rapidjson::Value & DataObj, const QString & formatter )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("axisLabel"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetRadiusAxis_AxisLabel_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("axisLabel"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetAngleAxis_AxisLabel_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("axisLabel"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetRadiusAxis_Min( const QString & min )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("min"),min.toStdString());
}

void AFCommonChart::SetRadiusAxis_Max( const QString & max )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("max"),max.toStdString());
}

void AFCommonChart::SetAngleAxis_Min( const QString & min )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("min"),min.toStdString());
}

void AFCommonChart::SetAngleAxis_Max( const QString & max )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("max"),max.toStdString());
}

void AFCommonChart::SetTooltip_AxisPointer_Label_Precision( const QString & precision )
{
	rapidjson::addRapidjsonParam(param,std::string("tooltip"),std::string("axisPointer"),std::string("label"),std::string("precision"),precision.toStdString());
}

void AFCommonChart::SetAngleAxis_AxisPointer_Label_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("axisPointer"),std::string("label"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetRadiusAxis_AxisPointer_Label_Formatter( const QString & formatter )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("axisPointer"),std::string("label"),std::string("formatter"),formatter.toStdString());
}

void AFCommonChart::SetAngleAxis_SplitNumber( const QString & number )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("splitNumber"),number.toStdString());
}

void AFCommonChart::SetAngleAxis_SplitNumber( const int & number )
{
	rapidjson::addRapidjsonParam(param,std::string("angleAxis"),std::string("splitNumber"),number);
}

void AFCommonChart::SetRadiusAxis_SplitNumber( const QString & number )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("splitNumber"),number.toStdString());
}

void AFCommonChart::SetRadiusAxis_SplitNumber( const int & number )
{
	rapidjson::addRapidjsonParam(param,std::string("radiusAxis"),std::string("splitNumber"),number);
}

void AFCommonChart::SetyAxis_Max( rapidjson::Value & DataObj, const double & max )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(), std::string("max"), max);
}

void AFCommonChart::SetyAxis_Name( rapidjson::Value & DataObj, const QString & name )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(), std::string("name"), name.toStdString());
}

void AFCommonChart::SetyAxis_Inverse( rapidjson::Value & DataObj, const bool & inverse )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(),std::string("inverse"), inverse);
}

void AFCommonChart::SetyAxis_NameLocation( rapidjson::Value & DataObj, const QString & location )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(),std::string("nameLocation"), location.toStdString());
}

void AFCommonChart::SetSeries_yAxisIndex( rapidjson::Value & DataObj, const int & index )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("yAxisIndex"),index);
}

void AFCommonChart::SetyAxis_Id( rapidjson::Value & DataObj, const QString & id )
{
	rapidjson::addRapidjsonParam(DataObj, param.GetAllocator(), std::string("id"), id.toStdString());
}

void AFCommonChart::SetyAxis( rapidjson::Value & DataObjArray )
{
	rapidjson::addRapidjsonParam(param, std::string("yAxis"), DataObjArray);
}

