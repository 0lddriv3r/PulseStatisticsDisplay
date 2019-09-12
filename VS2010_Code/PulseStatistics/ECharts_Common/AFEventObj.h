#ifndef AFEventObj_h__
#define AFEventObj_h__

#include "afactionsetobj.h"
#include "echartsinqt_global.h"

class ECHARTS_COMMON_EXPORT AFEventObj :public AFActionSetObj
{
	Q_OBJECT

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	zhuojiaoshou, 2019/9/11. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize();


public:
	AFEventObj(QWidget *parent=0);
	virtual ~AFEventObj(void);

};


#endif // AFEventObj_h__

