#ifndef __RAPIDJSON_FASTFUNC_VALUE_H__
#define __RAPIDJSON_FASTFUNC_VALUE_H__

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include "CommonFunc.h"


namespace rapidjson
{
	template<typename KeyType0,typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const ParamType &Param ){};
	template<typename KeyType0,typename KeyType1,typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3,typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3,const ParamType & Param ){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3,typename KeyType4,typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3,const KeyType4 & key4,const ParamType & Param ){};


//Param:ParamType 
	//string - string param:ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1,const ParamType & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam(rpvalue[key0.c_str()],allocator,key1,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string - string - string ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1,const std::string & key2,const ParamType & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam(rpvalue[key0.c_str()],allocator,key1,key2,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string - string - string -string  ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1,const std::string & key2,const std::string & key3,const ParamType & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam(rpvalue[key0.c_str()],allocator,key1,key2,key3,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,key3,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}
	//string -string -string -string -string Param: ParamType
	template<typename ParamType>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1,const std::string & key2,const std::string & key3,const std::string & key4,const ParamType & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam(rpvalue[key0.c_str()],allocator,key1,key2,key3,key4,Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam(key0Value,allocator,key1,key2,key3,key4,Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	};


//Param:string
	//string Param:string
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()].SetString(Param.c_str(),allocator);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kStringType);
			key0Value.SetString(Param.c_str(),allocator);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param: std::vector<std::string>
	//string - std::vector<std::string>
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::vector<std::string> & Param )
	{
		rapidjson::Value key0Valye = CommonFunc::STDStringArrayToRPV(Param,allocator);

		rapidjson::Value rp_key0(rapidjson::kStringType);
		rp_key0.SetString(key0.c_str(),allocator);

		rpvalue.AddMember(rp_key0,key0Valye,allocator);
	}

//Param: bool
	//string - param:bool
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const bool & Param )
	{
		rapidjson::Value key0Value;
		key0Value.SetBool(Param);

		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()].SetBool(Param);
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}


//Param: int
	//string Param:int
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const int & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()].SetInt(Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kNumberType);
			key0Value.SetInt(Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param: std::vector<double>
	//string Param: std::vector<double>
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const  std::vector<double> & Param )
	{
		rapidjson::Value key0Value(rapidjson::kArrayType);

		for (std::size_t Index = 0 ; Index < Param.size();++Index)
		{
			rapidjson::Value tempValue(rapidjson::kNumberType);
			tempValue.SetDouble(Param[Index]);

			key0Value.PushBack(tempValue,allocator);
		}

		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()] = key0Value;
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param: double
	//string Param:double
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const double & Param )
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()].SetInt(Param);
		}
		else
		{
			rapidjson::Value key0Value(rapidjson::kNumberType);
			key0Value.SetDouble(Param);

			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param std::vector<std::pair<int ,std::string> >
	//string param: std::vector<std::pair<int ,std::string>
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::vector<std::pair<float ,std::string> > & Param )
	{
		rapidjson::Value key0Value(rapidjson::kArrayType);

		for (std::size_t Index = 0 ;Index < Param.size() ;++Index)
		{
			rapidjson::Value singleValue(rapidjson::kArrayType);
			
			rapidjson::Value singleObj1(rapidjson::kObjectType);
			singleObj1.SetFloat(Param[Index].first);
			rapidjson::Value singleObj2(rapidjson::kObjectType);
			singleObj2.SetString(Param[Index].second.c_str(),allocator);

			singleValue.PushBack(singleObj1,allocator);
			singleValue.PushBack(singleObj2,allocator);

			key0Value.PushBack(singleValue,allocator);
		}

		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()] = key0Value;
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

//Param std::vector<std::pair<float ,float> >
	//string param: std::vector<std::pair<float ,float> >
	template<>
	static void addRapidjsonParam(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::vector<std::pair<float ,float> > & Param )
	{
		rapidjson::Value key0Value(rapidjson::kArrayType);

		for (std::size_t Index = 0 ;Index < Param.size() ;++Index)
		{
			rapidjson::Value singleValue(rapidjson::kArrayType);

			rapidjson::Value singleObj1(rapidjson::kObjectType);
			singleObj1.SetFloat(Param[Index].first);
			rapidjson::Value singleObj2(rapidjson::kObjectType);
			singleObj2.SetFloat(Param[Index].second);

			singleValue.PushBack(singleObj1,allocator);
			singleValue.PushBack(singleObj2,allocator);

			key0Value.PushBack(singleValue,allocator);
		}

		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()] = key0Value;
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}


	template<typename KeyType0>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0){};
	template<typename KeyType0,typename KeyType1>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1){};
	template<typename KeyType0,typename KeyType1,typename KeyType2>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2){};
	template<typename KeyType0,typename KeyType1,typename KeyType2,typename KeyType3>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const KeyType0 & key0,const KeyType1 & key1,const KeyType2 & key2,const KeyType3 & key3){};


	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0)
	{
		rapidjson::Value nullObj(rapidjson::kObjectType);

		if (rpvalue.HasMember(key0.c_str()))
		{
			rpvalue[key0.c_str()] = nullObj;
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rpvalue.AddMember(rp_key0,nullObj,allocator);
		}
	}

	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1)
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam_NullObj(rpvalue[key0.c_str()],allocator,key1);
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam_NullObj(key0Value,allocator,key1);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}

	template<>
	static void addRapidjsonParam_NullObj(rapidjson::Value &rpvalue,rapidjson::Document::AllocatorType & allocator,const std::string & key0,const std::string & key1,const std::string & key2)
	{
		if (rpvalue.HasMember(key0.c_str()))
		{
			addRapidjsonParam_NullObj(rpvalue[key0.c_str()],allocator,key1,key2);
		}
		else
		{
			rapidjson::Value rp_key0(rapidjson::kStringType);
			rp_key0.SetString(key0.c_str(),allocator);

			rapidjson::Value key0Value(rapidjson::kObjectType);

			addRapidjsonParam_NullObj(key0Value,allocator,key1,key2);

			rpvalue.AddMember(rp_key0,key0Value,allocator);
		}
	}


}










	











#endif // __RAPIDJSON_FASTFUNC_VALUE_H__

