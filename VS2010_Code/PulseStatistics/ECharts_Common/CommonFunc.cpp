#include "CommonFunc.h"


std::vector<std::string> CommonFunc::QStringArrayToStd(const std::vector<QString> & Param)
{
	std::vector<std::string> Result;

	for (std::size_t Index = 0 ; Index < Param.size();++Index)
	{
		Result.push_back(Param[Index].toStdString());
	}

	return Result;
}

std::vector<QString> CommonFunc::STDStringArrayToQS(const std::vector<std::string> & Param)
{
	std::vector<QString> Result;

	for (std::size_t Index = 0 ; Index < Param.size();++Index)
	{
		Result.push_back(Param[Index].c_str());
	}

	return Result;
}

rapidjson::Value CommonFunc::STDStringArrayToRPV( const std::vector<std::string> & Param ,rapidjson::Document::AllocatorType &allocator)
{
	rapidjson::Value key0Valye(rapidjson::kArrayType);

	for (std::size_t Index = 0 ; Index < Param.size(); ++Index)
	{
		rapidjson::Value tempValye(rapidjson::kStringType);
		tempValye.SetString(Param[Index].c_str(),allocator);

		key0Valye.PushBack(tempValye,allocator);
	}

	return key0Valye;
}

ECHARTS_COMMON_EXPORT std::vector<std::pair<float,std::string> > CommonFunc::QStringVPairToSTDVec( const std::vector<std::pair<float,QString> > & Param )
{
	std::vector<std::pair<float,std::string> > Result;

	for (std::size_t Index = 0 ; Index < Param.size() ; ++Index)
	{
		Result.push_back(std::pair<float,std::string>(Param[Index].first,Param[Index].second.toStdString()));
	}

	return Result;
}
