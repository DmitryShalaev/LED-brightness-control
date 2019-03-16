#include "MainWindow.h"

void MainWindow::RequestLuxLevel()
{
    MaintainLux = true;
    on_RB_BH1750_clicked();
}

void MainWindow::MaintainLuxLevel(double value)
{
    MaintainLux = false;

    if(abs(ui->SB_MaintainLuxLevel->value() - value) > 50){

        if((ui->SB_MaintainLuxLevel->value() - value) < 0) {

            if((MeanPWM + MaintainLuxLevelStep) <= 255){

                MeanPWM += MaintainLuxLevelStep;

                BufSend[1] = 0x0E;

                BufSend[2] = MeanPWM;

                Send();
            }

        } else {

            if((MeanPWM - MaintainLuxLevelStep) >= 0){

                MeanPWM -= MaintainLuxLevelStep;

                BufSend[1] = 0x0E;

                BufSend[2] = MeanPWM;

                Send();

            }
        }
    }

    ui->SB_PWM1->setValue((255 - MeanPWM)/2.55); //Test
}


