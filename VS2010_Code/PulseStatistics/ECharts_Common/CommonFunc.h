#ifndef __COMMONFUNC_H__
#define __COMMONFUNC_H__

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <QString>
#include <vector>
#include "echartsinqt_global.h"

namespace CommonFunc
{
	ECHARTS_COMMON_EXPORT std::vector<std::string> QStringArrayToStd(const std::vector<QString> & Param);

	ECHARTS_COMMON_EXPORT std::vector<QString> STDStringArrayToQS(const std::vector<std::string> & Param);

	ECHARTS_COMMON_EXPORT rapidjson::Value STDStringArrayToRPV(const std::vector<std::string> & Param,rapidjson::Document::AllocatorType &allocator);

	ECHARTS_COMMON_EXPORT std::vector<std::pair<float,std::string> > QStringVPairToSTDVec(const std::vector<std::pair<float,QString> > & Param);
}










#endif // __COMMONFUNC_H__

