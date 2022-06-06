#ifndef TEMPLATE_PLUGIN_H
#define TEMPLATE_PLUGIN_H

#include "template_plugin_global.h"
#include "cvplugininterface.h"

namespace Ui {
    class PluginGui;
}

class TEMPLATE_PLUGIN_EXPORT Template_plugin: public QObject, public CvPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.computervision.cvplugininterface")
    Q_INTERFACES(CvPluginInterface)
public:
    Template_plugin();
    ~Template_plugin() override;

    QString title() override;
    QString version() override;
    QString description() override;
    QString help() override;
    void setupUi(QWidget *parent) override;
    void processImage(const cv::Mat &inputImage, cv::Mat &outputImage) override;

signals:
    void  updateNeeded();
    void  errorMessage(QString msg);
    void  infoMessage(QString msg);

private:
    Ui::PluginGui * ui;
};

#endif // TEMPLATE_PLUGIN_H
