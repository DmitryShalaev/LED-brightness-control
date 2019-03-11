#include "MainWindow.h"

void MainWindow::MotionDetection(bool MotionDetected)
{
    if(ui->RB_TurnOffLight->isChecked()){

        if(MotionDetected){

            BufSend[1] = 0x0E;

            BufSend[2] = static_cast<uint8_t> (0);

            Send();

            MotionTimer->stop();

        }else {

            MotionTimer->start(ui->TE_TurnOffLight->time().minute() * 60000
                               + ui->TE_TurnOffLight->time().second() * 1000);

        }
    }
}

void MainWindow::TurningOffTheLights()
{

    BufSend[1] = 0x0E;

    BufSend[2] = static_cast<uint8_t> (255);

    Send();
}
