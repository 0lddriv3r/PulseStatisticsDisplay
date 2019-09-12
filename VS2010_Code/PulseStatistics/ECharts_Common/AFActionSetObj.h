#ifndef AFActionSetObj_h__
#define AFActionSetObj_h__

#include "AFChartBaseObj.h"
#include "echartsinqt_global.h"


class ECHARTS_COMMON_EXPORT AFActionSetObj :public AFChartBaseObj
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
	AFActionSetObj(QWidget *parent=0);
	virtual ~AFActionSetObj(void);

	

};


#endif // AFActionSetObj_h__

