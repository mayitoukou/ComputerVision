#ifndef CVPLUGIN_H
#define CVPLUGIN_H

#include <QObject>
#include <QWidget>
#include <QString>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/features2d.hpp"


class CvPluginInterface
{
public:
    virtual ~CvPluginInterface() {}
    virtual QString title() = 0;
    virtual QString version() = 0;
    virtual QString description() = 0;
    virtual QString help() = 0;
    virtual void setupUi(QWidget *parent) = 0;
    virtual void processImage(const cv::Mat &inputImage, cv::Mat &outputImage) = 0;
};

#define CVPLUGININTERFACE_IID "com.computervision.cvplugininterface"
Q_DECLARE_INTERFACE(CvPluginInterface, CVPLUGININTERFACE_IID)

#endif // CVPLUGIN_H
