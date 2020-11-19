#include "speech.h"

Speech::Speech(QObject *parent) : QObject(parent)
{
}

QString Speech::speechIdentify(QString fileName)
{
    QString accessToken;
    //获取access_token
    QString tokenUrl = QString(baiduTokenUrl).arg(client_id).arg(client_secret);
    QMap<QString,QString> header;
    header.insert(QString("Content-Type"),QString("audio/pcm;rate=16000"));

    QByteArray requestData;//发送具体内容
    QByteArray replyData;//服务器返回内容

    Http m_http;
    bool result = m_http.post_sync(tokenUrl,header,requestData,replyData);
    if(result)
    {
        QString key = "access_token";
        accessToken = getJsonValue(replyData,key);
        //qDebug()<<accessToken;
    }
    else
    {

    }
    //组合URL
    QString speechUrl = QString(baiduSpeechUrl).arg(QHostInfo::localHostName()).arg(accessToken);
    //把文件转化为QByteArray;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly);
    requestData = file.readAll();
    file.close();

    replyData.clear();

    //再次发送请求
    result = m_http.post_sync(speechUrl,header,requestData,replyData);
    if(result)
    {
        QString key = "result";
        QString text = getJsonValue(replyData,key);
        return  text;
        //qDebug()<<accessToken;
    }
    else
    {
        QMessageBox::warning(NULL,"识别提示","识别失败");
    }
    return "";

}

QString Speech::getJsonValue(QByteArray ba, QString key)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba,&parseError);
    if(parseError.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isObject())
        {
            //jsonDocument转化为json对象
            QJsonObject jsonObj = jsonDocument.object();
            if(jsonObj.contains(key))
            {
                QJsonValue jsonVal= jsonObj.value(key);
                if(jsonVal.isString())//说明是个字符串
                {
                    return jsonVal.toString();
                }
                else if(jsonVal.isArray())//数组
                {
                    QJsonArray arr =jsonVal.toArray();//转换成jsonArray
                    QJsonValue jv=arr.at(0);          //获取第一个元素
                    return jv.toString();
                }
            }
        }

    }
    return "";
}
