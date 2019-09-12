#include "AFLineWidget.h"
#include "rapidjson_fastfunc_value.h"

struct AFLineWidget_P
{
	AFLineWidget_P()
	{
	
	}


};


AFLineWidget::AFLineWidget(QWidget *parent)
	: AFCommonChart(parent)
	,_p(new AFLineWidget_P())
{

}

AFLineWidget::~AFLineWidget()
{
	delete _p;
}

void AFLineWidget::Initialize()
{
	AFCommonChart::Initialize();


}

void AFLineWidget::SetSeries_CoordinateSystem( rapidjson::Value & DataObj,const QString & coordinateSystem )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("coordinateSystem"),coordinateSystem.toStdString());
}

void AFLineWidget::SetSeries_ShowSymbol( rapidjson::Value & DataObj,const bool & isShowSymbol )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("showSymbol"),isShowSymbol);
}

void AFLineWidget::SetSeries_SimpleData( rapidjson::Value & DataObj,const std::vector<std::pair<float,float> > & SimpleDatas)
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("data"),SimpleDatas);
}

void AFLineWidget::SetSeries_SimpleData( rapidjson::Value & DataObj,const std::vector<Line_SimpleDataDesPtr > & SimpleDatas )
{
	std::vector<std::pair<float,float> > Datas;

	for (std::size_t Index = 0 ; Index < SimpleDatas.size() ; ++Index)
	{
		if (SimpleDatas[Index])
		{
			Datas.push_back(std::make_pair<float,float>(SimpleDatas[Index]->RCS,SimpleDatas[Index]->Angle));
		}
	}

	SetSeries_SimpleData(DataObj,Datas);
}

void AFLineWidget::SetSeries_SimpleData( rapidjson::Value & DataObj,const std::vector<double> & SimpleDatas )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("data"),SimpleDatas);
}

void AFLineWidget::SetSeries_SimpleData( rapidjson::Value & DataObj,const std::vector<Line_SingleValueDesPtr > & SimpleDatas )
{
	if (!SimpleDatas.empty())
	{
		std::vector<double> Datas;
		for (std::size_t Index = 0; Index < SimpleDatas.size(); ++ Index)
		{
			if (SimpleDatas[Index])
			{
				Datas.push_back(SimpleDatas[Index]->Value);
			}
		}
		SetSeries_SimpleData(DataObj, Datas);
	}
}

void AFLineWidget::SetSeries_LineStyle_Color( rapidjson::Value & DataObj, const QColor & color )
{
	if (color.isValid())
	{
		rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("lineStyle"),std::string("color"),color.name().toStdString());
	}
}

void AFLineWidget::SetSeries_ItemStyle_Color( rapidjson::Value & DataObj, const QColor & color )
{
	if (color.isValid())
	{
		rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("itemStyle"),std::string("color"),color.name().toStdString());
	}
}
