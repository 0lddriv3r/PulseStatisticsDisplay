#ifndef __AFCOMMONCHART_DEFINE_H__
#define __AFCOMMONCHART_DEFINE_H__
#include <boost\shared_ptr.hpp>
#include <boost\make_shared.hpp>

struct Option_Legend_Data_TextStyle
{
	Option_Legend_Data_TextStyle()
		:color("")
	{

	}

	QString color;
};

typedef boost::shared_ptr<Option_Legend_Data_TextStyle> Option_Legend_Data_TextStylePtr;

struct Option_Legend_Data
{
	Option_Legend_Data()
		:name("")
		,icon("")
		,textStyle(boost::make_shared<Option_Legend_Data_TextStyle>())
	{
	
	}

	QString name ;

	QString icon;

	Option_Legend_Data_TextStylePtr textStyle;
};

typedef boost::shared_ptr<Option_Legend_Data> Option_Legend_DataPtr;

struct AFPieWidget_SimpleDataDes
{
	AFPieWidget_SimpleDataDes()
		:name("")
		,value(0)
		,isSelected(false)
		,iD("")
		,color("")
	{
		
	}

	QString iD;

	QString color;

	QString name;

	double value;

	bool isSelected;
};

typedef boost::shared_ptr<AFPieWidget_SimpleDataDes> Pie_SimpleDataDesPtr;


struct AFLineWidget_SimpleDataType
{
	AFLineWidget_SimpleDataType()
		:Angle(0)
		,RCS(1)
	{

	}

	float Angle;
	float RCS;
};


typedef boost::shared_ptr<AFLineWidget_SimpleDataType> Line_SimpleDataDesPtr;

struct AFLineWidget_SingleValueType
{
	AFLineWidget_SingleValueType()
		: Value(0.0f)
	{
	
	}
	float Value;
};
typedef boost::shared_ptr<AFLineWidget_SingleValueType> Line_SingleValueDesPtr;




#endif // __AFCOMMONCHART_DEFINE_H__

