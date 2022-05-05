
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

#include <iostream>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void update_window();

    void on_checkBoxBlueLeft_stateChanged(int arg1);

    void on_checkBoxRedLeft_stateChanged(int arg1);

    void on_checkBoxGreenLeft_stateChanged(int arg1);

    void on_brightnessSliderLeft_sliderMoved(int position);

    void on_contrastSliderLeft_sliderMoved(int position);

    void on_openCameras_clicked();

    void on_checkBoxBlueRight_stateChanged(int arg1);

    void on_checkBoxRedRight_stateChanged(int arg1);

    void on_checkBoxGreenRight_stateChanged(int arg1);

    void on_contrastSliderRight_sliderMoved(int position);

    void on_brightnessSliderRight_sliderMoved(int position);

    void on_closeCameras_clicked();

    void on_takePhotoLeft_clicked();

    void on_pushButton_2_clicked();

    void on_distortion_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    VideoCapture cap, cap2;

    Mat frame;
    Mat frame2;

    QImage qt_image;
    QImage qt_image2;

    double Red[2], Green[2], Blue[2];
    double Brightness[2];

    double Contrast[2];
};

#endif // MAINWINDOW_H
