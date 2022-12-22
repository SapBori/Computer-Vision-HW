#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QDialog>
#include "kfc.h"

namespace Ui {
class MainFrame;

}

class ImageForm;

class MainFrame : public QDialog
{
    Q_OBJECT

private:
    Ui::MainFrame *ui;

    KPtrList<ImageForm*>*   _plpImageForm;
    ImageForm*              _q_pFormFocused;
    ImageForm*              _q_pFormTarget;

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();

    void            ImageFormFocused(ImageForm* q_pImageForm)
                    {   _q_pFormFocused  = q_pImageForm;   //???��???? 창�?? ?��?��?��? ???��??
                        UpdateUI();                        //UI ???��?? 갱�??
                    }
    void            UpdateUI();
    void            Detach(ImageForm* pForm);

public:
    void            OnMousePos(const int& nX, const int& nY, ImageForm* q_pForm);

private slots:
    void on_buttonOpen_clicked();
    void on_buttonDeleteContents_clicked();    
    void on_buttonShowList_clicked();    
    void on_pushButton_clicked();
    void on_ThresholdImage_clicked();
    void on_Labeling_clicked();
    void on_Erosion_clicked();
    void on_Dilation_clicked();
    void on_Erosion_2_clicked();
    void on_Dilation_2_clicked();

    void on_HistoTransForm_clicked();

    void on_HistoGramMatching_clicked();

    void on_GaussianNoise_clicked();

    void on_Salt_Pepper_clicked();

    void on_BoxFilter_clicked();

    void on_GaussianFilter_clicked();

    void on_MedianFilter_clicked();


    void on_CannyEdge_clicked();

    void on_CoinCircle_clicked();

    void on_GeneralHough_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // MAINFRAME_H
