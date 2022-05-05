
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Red[0] = Green[0] = Blue[0] = 1.0;
    Red[1] = Green[1] = Blue[1] = 1.0;
    Brightness[0] = Brightness[1] = 1.0;
    Contrast[0] = Contrast[1] = 1.0;
    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_window()
{
    ofstream fout;


    if(!cap.isOpened())  // Check if we succeeded
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap_1 is not open" << endl;
        fout.close();
    }
    if(!cap2.isOpened())  // Check if we succeeded
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap_2 is not open" << endl;
        fout.close();
    }




    cap >> frame;

    cap2 >> frame2;



    if (frame.empty()){
        (new QErrorMessage(this))->showMessage("Frame empty!");
        return;
    }
    if (frame2.empty()){
        (new QErrorMessage(this))->showMessage("Frame2 empty!");
        return;
    }

    cvtColor(frame, frame, COLOR_BGR2RGB);
    cvtColor(frame2, frame2, COLOR_BGR2RGB);

    int frameWidth = this->size().width() / 2;
    int frameHeight = this->size().height() / 2;




    cv::resize(frame, frame, Size(frameWidth, frameHeight));
    cv::resize(frame2, frame2, Size(frameWidth, frameHeight));

    Mat channels_1[3];
    Mat channels_2[3];

    for (int y = 0; y < frameHeight; y++){
        for (int x = 0; x < frameWidth; x++){
            for (int c = 0; c < 3; c++){
                frame.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((Brightness[0] * frame.at<Vec3b>(y, x)[c]) + Contrast[0]);
                frame2.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((Brightness[1] * frame2.at<Vec3b>(y, x)[c]) + Contrast[1]);
            }
        }
    }

    split(frame, channels_1);
    split(frame2, channels_2);


    channels_1[0] *= Red[0];
    channels_1[1] *= Green[0];
    channels_1[2] *= Blue[0];

    channels_2[0] *= Red[1];
    channels_2[1] *= Green[1];
    channels_2[2] *= Blue[1];





    merge(channels_1, 3, frame);
    merge(channels_2, 3, frame2);


    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    qt_image2 = QImage((const unsigned char*) (frame2.data), frame2.cols, frame2.rows, QImage::Format_RGB888);


    ui->videoLeft->setPixmap(QPixmap::fromImage(qt_image));
    ui->videoRight->setPixmap(QPixmap::fromImage(qt_image2));



}

void MainWindow::on_checkBoxBlueLeft_stateChanged(int arg1)
{
    if (Blue[0] == 1.0){
        Blue[0] = 0.0;
    }
    else{
        Blue[0] = 1.0;
    }
}


void MainWindow::on_checkBoxRedLeft_stateChanged(int arg1)
{
    if (Red[0] == 1.0){
        Red[0] = 0.0;
    }
    else{
        Red[0] = 1.0;
    }
}


void MainWindow::on_checkBoxGreenLeft_stateChanged(int arg1)
{
    if (Green[0] == 1.0){
        Green[0] = 0.0;
    }
    else{
        Green[0] = 1.0;
    }
}


void MainWindow::on_brightnessSliderLeft_sliderMoved(int position)
{
    Brightness[0] = (double)position * 0.01;
}


void MainWindow::on_contrastSliderLeft_sliderMoved(int position)
{
    Contrast[0] = (double)position;
}


void MainWindow::on_openCameras_clicked()
{
    ofstream fout;

    try {

            Mat image = Mat::zeros(frame.size(),CV_8UC3);
        //cap.open(0);
    } catch (cv::Exception& e) {
        fout << "Exception!\n";
        (new QErrorMessage(this))->showMessage(e.what());
        fout.close();
    }


    if(!cap.isOpened())  // Check if we succeeded
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap #1 is not opened!\n";
        fout.close();
        (new QErrorMessage(this))->showMessage("Cap  #1 is not opened!\n");
        return;
    }
    else
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap #1 is successfully opened!\n";
        fout.close();
        connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        timer->start(20);
    }

    cap2.open(1);

    if(!cap2.isOpened())  // Check if we succeeded
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap #2 is not opened!\n";
        (new QErrorMessage(this))->showMessage("Cap  #2 is not opened!\n");

        fout.close();
        return;
    }
    else
    {
        fout.open("DEBUG.txt", ios::app);
        fout << "Cap #2 is successfully opened!\n";
        fout.close();
        connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        timer->start(20);
    }

}


void MainWindow::on_checkBoxBlueRight_stateChanged(int arg1)
{
    if (Blue[1] == 1.0){
        Blue[1] = 0.0;
    }
    else{
        Blue[1] = 1.0;
    }

}


void MainWindow::on_checkBoxRedRight_stateChanged(int arg1)
{
    if (Red[1] == 1.0){
        Red[1] = 0.0;
    }
    else{
        Red[1] = 1.0;
    }
}


void MainWindow::on_checkBoxGreenRight_stateChanged(int arg1)
{
    if (Green[1] == 1.0){
        Green[1] = 0.0;
    }
    else{
        Green[1] = 1.0;
    }
}


void MainWindow::on_contrastSliderRight_sliderMoved(int position)
{
    Brightness[1] = (double)position * 0.01;
}


void MainWindow::on_brightnessSliderRight_sliderMoved(int position)
{
    Contrast[1] = (double)position;
}


void MainWindow::on_closeCameras_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));

    cvtColor(frame, frame, COLOR_BGR2RGB);
    cvtColor(frame2, frame2, COLOR_BGR2RGB);

    imwrite("cap.jpeg", frame);
    imwrite("cap2.jpeg", frame2);

    cap.release();
    cap2.release();

    Mat image = Mat::zeros(frame.size(),CV_8UC3);

    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

    ui->videoLeft->setPixmap(QPixmap::fromImage(qt_image));
    ui->videoRight->setPixmap(QPixmap::fromImage(qt_image));

    ui->videoLeft->resize(ui->videoLeft->pixmap().size());

    cout << "camera is closed" << endl;
}





void MainWindow::on_takePhotoLeft_clicked()
{
    cvtColor(frame, frame, COLOR_BGR2RGB);
    imwrite("left_camera_image.jpg", frame);
}


void MainWindow::on_pushButton_2_clicked()
{
    cvtColor(frame2, frame2, COLOR_BGR2RGB);
    imwrite("right_camera_image.jpg", frame2);
}


void MainWindow::on_distortion_clicked()
{
    (new QErrorMessage(this))->showMessage("Frame empty!");
}

