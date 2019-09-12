#ifndef __RAPIDJSON_FASTFUNC_H__
#define __RAPIDJSON_FASTFUNC_H__

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "rapidjson_fastfunc_value.h"

namespace rapidjson
{

	template<typename KeyType0,typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const KeyType0 & key0,const ParamType &Param ){};
	template<typename KeyType0,typename KeyType1,typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3,typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3,const ParamType & Param ){};

	//Param:ParamType 
	//string - string param:ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const ParamType & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam(jsonobj[key0.c_str()],allocator,key1,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string - string - string ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const std::string & key2,const ParamType & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam(jsonobj[key0.c_str()],allocator,key1,key2,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string - string - string -string  ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const std::string & key2,const std::string & key3,const ParamType & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam(jsonobj[key0.c_str()],allocator,key1,key2,key3,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,key3,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string -string -string -string -string Param: ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const std::string & key2,const std::string & key3,const std::string & key4,const ParamType & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam(jsonobj[key0.c_str()],allocator,key1,key2,key3,key4,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,key3,key4,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	};


//Param:string
	//string param:string
	template<>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::string & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()].SetString(Param.c_str(),allocator);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kStringType);
			key0Value.SetString(Param.c_str(),jsonobj.GetAllocator());

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),jsonobj.GetAllocator());

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param:vector<string>
	//string param:vector<string>
	template<>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const std::vector<std::string> & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()] = CommonFunc::STDStringArrayToRPV(Param,allocator);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kArrayType);

			key0Value = CommonFunc::STDStringArrayToRPV(Param,allocator);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param:int
	//string param:int
	template<>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const int & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()].SetInt(Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kNumberType);
			key0Value.SetInt(Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),jsonobj.GetAllocator());

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}



//Param: bool
	//string  param:bool
	template<>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0,const bool & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()].SetBool(Param);
		}
		else
		{
			rapidjson::Value key0Value;
			key0Value.SetBool(Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}

	//Param: rapidjson::Value
	//string  param:rapidjson::Value
	template<>
	static void addRapidjsonParam(rapidjson::Document &jsonobj,const std::string & key0, const rapidjson::Value & Param )
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()].CopyFrom(Param, allocator);
		}
		else
		{
			rapidjson::Value key0Value;
			key0Value.CopyFrom(Param, allocator);
			
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}

	template<typename KeyType0,typename KeyType1,typename ParamType>
	static void addRapidjsonParam_DataZoom(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename ParamType>
	static void addRapidjsonParam_DataZoom(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3,typename ParamType>
	static void addRapidjsonParam_DataZoom(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3,const ParamType & Param ){};

	template<>
	static void addRapidjsonParam_DataZoom(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const std::string &Param )
	{
		rapidjson::Document::AllocatorType & allocator = jsonobj.GetAllocator();

		if (jsonobj.HasMember("dataZoom"))
		{
			if (jsonobj["dataZoom"].IsArray())
			{
				bool IsFind = false;

				for (std::size_t Index = 0 ; Index < jsonobj["dataZoom"].Size(); ++Index)
				{
					if (jsonobj["dataZoom"][Index].IsObject())
					{
						if (jsonobj["dataZoom"][Index].HasMember("type") && jsonobj["dataZoom"][Index]["type"].GetString() == key0 )
						{
							rapidjson::addRapidjsonParam(jsonobj["dataZoom"][Index],allocator,key1,Param);

							IsFind = true;
						}
					}
				}

				if (!IsFind)
				{
					rapidjson::Value newValue(rapidjson::kObjectType);

					addRapidjsonParam(newValue,allocator,"type",key0);
					addRapidjsonParam(newValue,allocator,key1,Param);
					jsonobj["dataZoom"].PushBack(newValue,allocator);
				}
			}
		}
		else
		{
			rapidjson::Value dataZoomobj(rapidjson::kArrayType);

			rapidjson::Value newValue(rapidjson::kObjectType);

			addRapidjsonParam(newValue,allocator,"type",key0);
			addRapidjsonParam(newValue,allocator,key1,Param);
			dataZoomobj.PushBack(newValue,allocator);

			rapidjson::Value rootKey(rapidjson::kObjectType);
			rootKey.SetString("dataZoom",allocator);

			jsonobj.AddMember(rootKey,dataZoomobj,allocator);
		}
	}


//Param:NullProject
	template<typename KeyType0>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const KeyType0 & key0){};
	template<typename KeyType0,typename KeyType1>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1){};
	template<typename KeyType0,typename KeyType1,typename KeyType2>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3){};


	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const std::string & key0)
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		rapidjson::Value nullObj(rapidjson::kObjectType);

		if (jsonobj.HasMember(key0.c_str()))
		{
			jsonobj[key0.c_str()] = nullObj;
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			jsonobj.AddMember(rp_key0,nullObj,allocator);
		}
	}

	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1)
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam_NullObj(jsonobj[key0.c_str()],allocator,key1);
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam_NullObj(key0Value,allocator,key1);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}

	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Document &jsonobj,const std::string & key0,const std::string & key1,const std::string & key2)
	{
		rapidjson::Document::AllocatorType &allocator = jsonobj.GetAllocator(); //获取分配器

		if (jsonobj.HasMember(key0.c_str()))
		{
			addRapidjsonParam_NullObj(jsonobj[key0.c_str()],allocator,key1,key2);
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam_NullObj(key0Value,allocator,key1,key2);

			jsonobj.AddMember(rp_key0,key0Value,allocator);
		}
	}


}


















#endif // __RAPIDJSON_FASTFUNC_H__

