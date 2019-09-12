#include <QFile>
#include <QtWebKit\QWebView>
#include <QUrl>
#include <QTimer>
#include <QUuid>
#include <QtWebKit\QWebPage>
#include <QtWebKit\QWebFrame>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "AFChartBaseObj.h"

#include <windows.h>
struct AFChartBaseObj_P
{
	AFChartBaseObj_P()
	{

	}

	QString html_url;
};

AFChartBaseObj::AFChartBaseObj(QWidget *parent)
	: QWebView(parent)
	,_p(new AFChartBaseObj_P())
{
	param.SetObject();

	connect(this,SIGNAL(loadFinished(bool)),this,SLOT(loadFinishedSlot(bool)));

	QTimer::singleShot(1,this,SLOT(LazyInitialSlot()));
}

AFChartBaseObj::~AFChartBaseObj()
{
	delete _p;
}

int AFChartBaseObj::GetWidth()
{
	return 0;
}

int AFChartBaseObj::GetHeight()
{
	return 0;
}

void AFChartBaseObj::Resize(int width,int height,bool isSilent)
{

}

void AFChartBaseObj::InitEChartsHtml(QString url)
{
	_p->html_url = url;
}

void AFChartBaseObj::LoadEChartsHtml()
{
	load(QUrl(_p->html_url));
}

void AFChartBaseObj::ResetOption()
{
	param.SetObject();
}

void AFChartBaseObj::UpdateChart( EChartsType eChartsType /*= OTHER*/, bool IsReset /*= false*/ )
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	param.Accept(writer);
	std::string mstr = buffer.GetString();
	QString qString = mstr.c_str();
	QStringList splitRList = qString.split("\\r");
	QString splitAfterR;
	for (int i = 0; i < splitRList.size(); ++i)
	{
		splitAfterR.append(splitRList.at(i));
	}

	if (IsReset)
	{
		switch (eChartsType)
		{
		case RF : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_RF('%1',true)").arg(splitAfterR.toStdString().c_str()));break;}
		case PRI: {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PRI('%1',true)").arg(splitAfterR.toStdString().c_str()));break;}
		case PW : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PW('%1',true)").arg(splitAfterR.toStdString().c_str()));break;}
		case DOA: {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_DOA('%1',true)").arg(splitAfterR.toStdString().c_str()));break;}
		case PA : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PA('%1',true)").arg(splitAfterR.toStdString().c_str()));break;}
		default : page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption('%1',true)").arg(splitAfterR.toStdString().c_str()));
		}
	}
	else
	{
		switch (eChartsType)
		{
		case RF : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_RF('%1',false)").arg(splitAfterR.toStdString().c_str()));break;}
		case PRI: {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PRI('%1',false)").arg(splitAfterR.toStdString().c_str()));break;}
		case PW : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PW('%1',false)").arg(splitAfterR.toStdString().c_str()));break;}
		case DOA: {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_DOA('%1',false)").arg(splitAfterR.toStdString().c_str()));break;}
		case PA : {page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption_PA('%1',false)").arg(splitAfterR.toStdString().c_str()));break;}
		default : page()->mainFrame()->evaluateJavaScript(QString("setEchartsOption('%1',false)").arg(splitAfterR.toStdString().c_str()));
		}
	}

	param.SetObject();
}

void AFChartBaseObj::Initialize()
{
	
}


void AFChartBaseObj::loadFinishedSlot(bool Result)
{
	Initialize();
}

void AFChartBaseObj::LazyInitialSlot()
{
	if (!_p->html_url.isEmpty())
	{
		LoadEChartsHtml();
	}
}

const QString AFChartBaseObj::GetNewID()
{
	return QUuid::createUuid();
}
