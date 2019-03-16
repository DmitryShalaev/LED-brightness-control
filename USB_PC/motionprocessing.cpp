#include "MainWindow.h"

void MainWindow::MotionDetection(bool MotionDetected)
{
    if(ui->RB_TurnOffLight->isChecked()){

        if(MotionDetected){

            if(!ui->RB_MaintainLuxLevel->isChecked())
                MeanPWM = (PWM1 + PWM2 + PWM3) / 3;

            BufSend[1] = 0x0E;

            BufSend[2] = static_cast<uint8_t> (MeanPWM);

            Send();

            MotionTimer->stop();

            RequestLuxTimer->start(ui->TE_SpeedOnOffLight->time().minute() * 60000 +
                                   ui->TE_SpeedOnOffLight->time().second() * 1000);

        }else {

            MotionTimer->start(ui->TE_TurnOffLight->time().minute() * 60000 +
                               ui->TE_TurnOffLight->time().second() * 1000);
        }
    }
}

void MainWindow::TurningOffTheLights()
{    
    RequestLuxTimer->stop();

    BufSend[1] = 0x0E;

    BufSend[2] = static_cast<uint8_t> (255);

    Send();
}
