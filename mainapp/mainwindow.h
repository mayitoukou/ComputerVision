#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDir>
#include <QFileInfoList>
#include <QLibrary>
#include <QPluginLoader>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QTranslator>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>
#include <QWaitCondition>

#include "cvplugininterface.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event);
    void changeEvent(QEvent *event);

private slots:
    void onPluginActionTriggered(bool);
    void onLanguageActionTriggered(bool);
    void onThemeActionTriggered(bool);
    void onCurrentPluginUpdateNeeded();
    void onCurrentPluginErrorMessage(QString msg);
    void onCurrentPluginInfoMessage(QString msg);

    void on_actionAboutQt_triggered();

    void on_actionExit_triggered();

    void on_actionOpenImage_triggered();

    void on_viewOriginalCheck_toggled(bool checked);

    void on_actionSaveImage_triggered();

    //void on_action_Camera_triggered();


private:
    Ui::MainWindow *ui;

    void  loadSettings();
    void  saveSettings();

    QString currentThemeFile;
    QString currentLanguageFile;
    QString currentPluginFile;

    void  populatePluginsMenu();
    void  populateLanguagesMenu();
    void  populateThemesMenu();

    QPointer<QPluginLoader> currentPlugin;
    QPointer<QWidget> currentPluginGui;
    QGraphicsScene scene;
    QTranslator translator;
    QGraphicsPixmapItem originalPixmap, processedPixmap;
    cv::Mat originalMat, processMat;
    QImage originalImage, processedImage;

};
#endif // MAINWINDOW_H
