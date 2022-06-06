#ifndef COPYMAKEBORDER_PLUGIN_H
#define COPYMAKEBORDER_PLUGIN_H

#include "copymakeborder_plugin_global.h"
#include "cvplugininterface.h"

namespace Ui {
    class PluginGui;
}

class COPYMAKEBORDER_PLUGIN_EXPORT CopyMakeBorder_Plugin: public QObject, public CvPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.computervision.cvplugininterface")
    Q_INTERFACES(CvPluginInterface)
public:
    CopyMakeBorder_Plugin();
    ~CopyMakeBorder_Plugin() override;

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

private slots:
    void on_boderTypeComboBox_currentIndexChanged(int index);

private:
    Ui::PluginGui * ui;
};

#endif // COPYMAKEBORDER_PLUGIN_H
