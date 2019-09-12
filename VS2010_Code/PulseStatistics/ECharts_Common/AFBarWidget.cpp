


#include "rapidjson_fastfunc_value.h"
#include "AFBarWidget.h"
#include "CommonFunc.h"

struct AFBarWidget_P
{
	AFBarWidget_P()
	{

	}
};

AFBarWidget::AFBarWidget(QWidget *parent)
	:AFCommonChart(parent)
	,_p(new AFBarWidget_P())
{

}


AFBarWidget::~AFBarWidget(void)
{
	delete _p;
}

void AFBarWidget::SetSeries_Stack(rapidjson::Value & DataObj, const QString & stack )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("stack"),stack.toStdString());
}

void AFBarWidget::SetSeries_ItemStyle_Normal_BorderColor(rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("itemStyle"),std::string("normal"),std::string("borderColor"),color.toStdString());
}

void AFBarWidget::SetSeries_ItemStyle_Normal_Color(rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("itemStyle"),std::string("normal"),std::string("color"),color.toStdString());
}

void AFBarWidget::SetSeries_ItemStyle_Emphasis_BorderColor(rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("itemStyle"),std::string("emphasis"),std::string("borderColor"),color.toStdString());
}

void AFBarWidget::SetSeries_ItemStyle_Emphasis_Color(rapidjson::Value & DataObj, const QString & color )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("itemStyle"),std::string("emphasis"),std::string("color"),color.toStdString());
}

void AFBarWidget::SetSeries_Data_Simple(rapidjson::Value & DataObj, const std::vector<QString> & data )
{
	std::vector<std::string> data_std;
	data_std = CommonFunc::QStringArrayToStd(data);

	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("data"),data_std);
}

void AFBarWidget::SetSeries_DataArray(rapidjson::Value & DataObj, const std::vector<DataItem> & data )
{
	rapidjson::Document::AllocatorType &allocator = param.GetAllocator(); //获取分配器

	if (DataObj.HasMember("data"))
	{
// 		jsonobj[key0.c_str()].SetArray();
// 		jsonobj[key0.c_str()].SetString(Param.c_str(),allocator);
	}
	else
	{
		rapidjson::Value key0Value(rapidjson::kArrayType);
		for (int i = 0; i < data.size(); ++i)
		{
			rapidjson::Value key0ValueMember(rapidjson::kArrayType);
			rapidjson::Value start_str(rapidjson::kStringType);
			start_str.SetString(data.at(i)._Start.c_str(),allocator);
			rapidjson::Value end_str(rapidjson::kStringType);
			end_str.SetString(data.at(i)._End.c_str(),allocator);
			rapidjson::Value rf_str(rapidjson::kStringType);
			rf_str.SetString(data.at(i)._RF.c_str(),allocator);
			rapidjson::Value name_str(rapidjson::kStringType);
			std::string name = data.at(i)._Name;
			name_str.SetString(data.at(i)._Name.c_str(),allocator);

			key0ValueMember.PushBack(start_str,allocator);
			key0ValueMember.PushBack(end_str,allocator);
			key0ValueMember.PushBack(rf_str,allocator);
			key0ValueMember.PushBack(name_str,allocator);

			key0Value.PushBack(key0ValueMember,allocator);
		}
		
		DataObj.AddMember("data",key0Value,allocator);
	}
}
//TODO: template funcion: the attribute of data is different
void AFBarWidget::SetSeries_ScatterDataArray(rapidjson::Value & DataObj, const std::vector<ScatterDataItem> & data )
{
	rapidjson::Document::AllocatorType &allocator = param.GetAllocator(); //获取分配器

	if (DataObj.HasMember("data"))
	{
		// 		jsonobj[key0.c_str()].SetArray();
		// 		jsonobj[key0.c_str()].SetString(Param.c_str(),allocator);
	}
	else
	{
		rapidjson::Value key0Value(rapidjson::kArrayType);
		for (int i = 0; i < data.size(); ++i)
		{
			rapidjson::Value key0ValueMember(rapidjson::kArrayType);
			rapidjson::Value rf_str(rapidjson::kStringType);
			rf_str.SetString(data.at(i)._yValue.c_str(),allocator);
			rapidjson::Value toa_str(rapidjson::kStringType);
			toa_str.SetString(data.at(i)._xValue.c_str(),allocator);

			key0ValueMember.PushBack(toa_str,allocator);
			key0ValueMember.PushBack(rf_str,allocator);

			key0Value.PushBack(key0ValueMember,allocator);
		}

		DataObj.AddMember("data",key0Value,allocator);
	}
}

void AFBarWidget::SetSeries_Label_Normal_Show( rapidjson::Value & DataObj,bool IsShow )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("label"),std::string("normal"),std::string("show"),true);
}

void AFBarWidget::SetSeries_Label_Normal_Position( rapidjson::Value & DataObj,const QString & Pos )
{
	rapidjson::addRapidjsonParam(DataObj,param.GetAllocator(),std::string("label"),std::string("normal"),std::string("position"),Pos.toStdString());
}

void AFBarWidget::Initialize()
{
	AFCommonChart::Initialize();
}

void AFBarWidget::SetData( const QString & seriesname ,const QString & stack ,const std::vector<QString> & data )
{
	rapidjson::Value DataObj =  CreateDataObj();

	SetSeries_Type(DataObj,"bar");
	SetSeries_Name(DataObj,seriesname);
	SetSeries_Stack(DataObj,stack);

	SetSeries_Data_Simple(DataObj,data);

	PushDataToSeries(DataObj);
}
