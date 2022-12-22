#include <QFileDialog>
#include <QPainter>
#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"
#include "kfc.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
MainFrame::MainFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    _plpImageForm       = new KPtrList<ImageForm*>(10,false,false);
    _q_pFormFocused     = 0;

    //�?�?맴�??? �?기�??


    //get a current directory
    char st[100];
    GetCurrentDirectoryA(100,st);
    //리�?��??�??�창?? ??보�?��?
    ui->listWidget->setVisible(false);
    this->adjustSize();

    //UI ???��?? 갱�??
    UpdateUI();
}

MainFrame::~MainFrame()
{ 
    delete ui;         
    delete _plpImageForm;   
}

void MainFrame::Detach(ImageForm *pForm)
{    
    //ImageForm ?��?��??????
    _plpImageForm->Remove(pForm);

    //???��?? ImageForm �?기�??
    _q_pFormFocused     = 0;

    //UI ???��?? 갱�??
    UpdateUI();
}

void MainFrame::UpdateUI()
{
    if(ui->tabWidget->currentIndex() == 0) // hw 01-02
    {
        //ui->buttonSepiaTone->setEnabled( _q_pFormFocused &&  _q_pFormFocused->ID() == "OPEN" );

    }

}

void MainFrame::OnMousePos(const int &nX, const int &nY, ImageForm* q_pForm)
{
    UpdateUI();
}

void MainFrame::closeEvent(QCloseEvent* event)
{
    //???��?? ImageForm?? ?��????
    for(int i=_plpImageForm->Count()-1; i>=0; i--)
        _plpImageForm->Item(i)->close();
}


void MainFrame::on_buttonOpen_clicked()
{
    //?��?�? ????????
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    //?��?�? �??��?? ???? ImageForm ????   
    ImageForm*              q_pForm   = new ImageForm(q_stFile, "OPEN", this);

    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    //UI ???��?? 갱�??
    UpdateUI();
}

void MainFrame::on_buttonDeleteContents_clicked()
{
    //???��?? ImageForm?? ?��????
    for(int i=_plpImageForm->Count()-1; i>=0; i--)
        _plpImageForm->Item(i)->close();

    //리�?��?��???? ????????
    _plpImageForm->RemoveAll();
}

void MainFrame::on_buttonShowList_clicked()
{
    static int nWidthOld = ui->tabWidget->width();

    if(ui->listWidget->isVisible())
    {
        nWidthOld = ui->listWidget->width();
        ui->listWidget->hide();
        this->adjustSize();
    }
    else
    {        
        ui->listWidget->show();
        QRect q_rcWin = this->geometry();

        this->setGeometry(q_rcWin.left(), q_rcWin.top(), q_rcWin.width()+nWidthOld, q_rcWin.height());
    }
}

/*
 * void MainFrame::on_buttonSepiaTone_clicked()
{
    //?�커???? ImageForm?��?�????????? �??��??
    KImageColor   icMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icMain = _q_pFormFocused->ImageColor();
    else
        return;

    //
    double  dHue = ui->spinHue->value();
    double  dSat = ui->spinSaturation->value();

    //�???????
    KImageColor icSepia(icMain.Row(), icMain.Col());
    //  :
    //  :


    //�??��?? ???? ImageForm ????
    ImageForm*  q_pForm = new ImageForm(icSepia, "Sepia Tone", this);

    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    //UI ???��?? 갱�??
    UpdateUI();
}
*/

void MainFrame::on_pushButton_clicked()
{

    KImageColor     icMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address()&& _q_pFormFocused->ID() == "OPEN" )
         icMain = _q_pFormFocused -> ImageColor();
    else
         return;

    KImageGray img_Hue(icMain.Row(), icMain.Col()),
               img_Sat(icMain.Row(), icMain.Col()),
               img_Val(icMain.Row(), icMain.Col());

    double dHue = ui->spinHue->value();//text().toDouble();
    double dSat = ui->spinSaturation->value();

    double min,max,dif;
    double val;
    double C,m,X;
    double R,G,B;
    double Hu,Sa;

    for(int i = 0;i<(int)icMain.Row();i++){
        for(int j = 0;j<(int)icMain.Col();j++) // 행,열의 갯수까지 반복한다.
        {            
            max = std::max(std::max(icMain[i][j].r,icMain[i][j].g),icMain[i][j].b);
            min = std::min(std::min(icMain[i][j].r,icMain[i][j].g),icMain[i][j].b);
            dif = max - min;

            val = max/255.0;
            img_Val[i][j] = val * 255;

            Sa = dif/max;
        //H값 구하기
            if(max == icMain[i][j].r)
                Hu = 60.0*(icMain[i][j].g - icMain[i][j].b)/dif;
            else if(max == icMain[i][j].g)
                Hu = (60.0*(icMain[i][j].b - icMain[i][j].r)/dif)+120;
            else if(max == icMain[i][j].b)
                Hu = (60.0*(icMain[i][j].r - icMain[i][j].g)/dif)+240;

            if(Hu == 360.0)
                Hu = 0.0;

            img_Hue[i][j] = (Hu/360.0)*255.0;
            img_Sat[i][j] = Sa * 255.0;

            Hu = dHue;
            Sa = dSat;

            C = val * Sa;
            m = val - C;
            X = C*(1-abs(fmod(Hu/60.0,2.0)-1));


            if(Hu>=0 && Hu<60)
            {
                R = C;
                G = X;
                B = 0;
            }

            else if(Hu>=60 && Hu<120)
            {
                R = X;
                G = C;
                B = 0;
            }

            else if(Hu>=120 && Hu<180)
            {
                R = 0;
                G = C;
                B = X;
            }

            else if(Hu>=180 && Hu<240)
            {
                R = 0;
                G = X;
                B = C;
            }

            else if(Hu>=240 && Hu<300)
            {
                R = X;
                G = 0;
                B = C;
            }

            else if(Hu>=300 && Hu<360)
            {
                R = C;
                G = 0;
                B = X;
            }

            icMain[i][j].r = (R+m)*255.0;
            icMain[i][j].g = (G+m)*255.0;
            icMain[i][j].b = (B+m)*255.0;

        }
    }


}


void MainFrame::on_ThresholdImage_clicked()
{
    KImageGray icrice;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice = _q_pFormFocused->ImageGray();
    else
        return;
    KImageGray Th;  //Output Image1
    KHisto Op(icrice);


    int sub1=85,sub2= 170; // sub1 = 256/3 , sub2 = (256/3)*2
    icrice.Threshold(sub1,Th);
    ImageForm*  q_pForm1 = new ImageForm(Th, "User ThersHold1 Image", this);
    _plpImageForm->Add(q_pForm1);
    q_pForm1->show();

    icrice.Threshold(sub2,Th);
    ImageForm*  q_pForm2 = new ImageForm(Th, "User ThersHold2 Image", this);
    _plpImageForm->Add(q_pForm2);
    q_pForm2->show();

    KImageGray Th2;
    Op.Ostu(&icrice,&Th2);
    ImageForm*  q_pForm = new ImageForm(Th2, "OstuThresh Image", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
}



void MainFrame::on_Labeling_clicked()
{
    KImageGray icrice;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice = _q_pFormFocused->ImageGray();
    else
        return;
    KImageGray Th;  //Output Image1
    KHisto Op;
    Op.Ostu(&icrice,&Th);
    KImageGray E1 = Th.BinaryErode(_FOREGROUND);
    KImageGray E5 = Th.BinaryErode5(_FOREGROUND);
    KImageGray D1 = Th.BinaryDilate(_FOREGROUND);
    KImageGray D5 = Th.BinaryDilate5(_FOREGROUND);
    KImageColor Bc(Th.Row(),Th.Col());

    E1.BlobColoring(_WHITE,0,&Bc);
    ImageForm*  q_pFormE1 = new ImageForm(Bc, "Labeled ErodeImage", this);
    _plpImageForm->Add(q_pFormE1);
    q_pFormE1->show();

    E5.BlobColoring(_WHITE,0,&Bc);
    ImageForm*  q_pFormE5 = new ImageForm(Bc, "Labeled Erode5 Image", this);
    _plpImageForm->Add(q_pFormE5);
    q_pFormE5->show();

    D1.BlobColoring(_WHITE,0,&Bc);
    ImageForm*  q_pFormD1 = new ImageForm(Bc, "Labeled Dilated Image", this);
    _plpImageForm->Add(q_pFormD1);
    q_pFormD1->show();

    D5.BlobColoring(_WHITE,0,&Bc);
    ImageForm*  q_pFormD5 = new ImageForm(Bc, "Labeled Dilated5 Image", this);
    _plpImageForm->Add(q_pFormD5);
    q_pFormD5->show();

}


void MainFrame::on_Erosion_clicked()
{
    KImageGray icerode,icrice;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice = _q_pFormFocused->ImageGray();
    else
        return;
    KHisto Op(icrice);
    Op.Ostu(&icrice, &icerode);
    KImageGray Ch = icerode.BinaryErode(_FOREGROUND);
    ImageForm*  q_pFormE = new ImageForm(Ch, "Eroded Image", this);
    _plpImageForm->Add(q_pFormE);
    q_pFormE->show();
}


void MainFrame::on_Dilation_clicked()
{
    KImageGray icDilate,icrice;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice = _q_pFormFocused->ImageGray();
    else
        return;
   KHisto Op(icrice);
   Op.Ostu(&icrice,&icDilate);
   KImageGray Ch = icDilate.BinaryDilate(_FOREGROUND);
   ImageForm*  q_pFormD = new ImageForm(Ch, "Dilated Image", this);
   _plpImageForm->Add(q_pFormD);
   q_pFormD->show();
}


void MainFrame::on_Erosion_2_clicked()
{
    KImageGray icerode5,icrice5;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice5 = _q_pFormFocused->ImageGray();
    else
        return;
    KHisto Op(icrice5);
    Op.Ostu(&icrice5, &icerode5);
    KImageGray Ch = icerode5.BinaryErode5(_FOREGROUND);
    ImageForm*  q_pFormE = new ImageForm(Ch, "5Kernel Eroded Image", this);
    _plpImageForm->Add(q_pFormE);
    q_pFormE->show();
}


void MainFrame::on_Dilation_2_clicked()
{
    KImageGray icdilate5,icrice5;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icrice5 = _q_pFormFocused->ImageGray();
    else
        return;
    KHisto Op(icrice5);
    Op.Ostu(&icrice5, &icdilate5);
    KImageGray Ch = icdilate5.BinaryDilate5(_FOREGROUND);
    ImageForm*  q_pFormD = new ImageForm(Ch, "5Kernel Eroded Image", this);
    _plpImageForm->Add(q_pFormD);
    q_pFormD->show();
    UpdateUI();
}


void MainFrame::on_HistoTransForm_clicked()
{
    KImageColor tar;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
       tar = _q_pFormFocused->ImageColor();
    else
        return;

    KImageGray p,red,gre,blu;
    tar.SplitInto(red,gre,blu);
    red.HistoEqualized();
    gre.HistoEqualized();
    blu.HistoEqualized();
    KImageColor result(tar.Row(),tar.Col());
    for(int i=0,ii=tar.Row(); ii; i++,ii--)
        for(int j=0,jj=tar.Col(); jj; j++,jj--){
            result._ppA[i][j].r = red[i][j];
            result._ppA[i][j].g = gre[i][j];
            result._ppA[i][j].b = blu[i][j];
    }
    ImageForm*  q_pFormg = new ImageForm(result, "Histogram Equalized Image", this);
    _plpImageForm->Add(q_pFormg);
    q_pFormg->show();
    UpdateUI();
}


void MainFrame::on_HistoGramMatching_clicked()
{
    //Load 2 Images
    QFileDialog::Options    q_Options1   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile1    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options1);
    if(q_stFile1.length() == 0)
        return;
    ImageForm*              q_pForm1   = new ImageForm(q_stFile1, "Source", this);
    _plpImageForm->Add(q_pForm1);
    q_pForm1->show();
    KImageColor ti1,ti2;

    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "Source")
       ti1 = _q_pFormFocused->ImageColor();
    else
        return;

    KImageColor result(ti1.Row(),ti1.Col());
    QFileDialog::Options    q_Options2   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile2    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options2);
    if(q_stFile2.length() == 0)
        return;
    ImageForm*              q_pForm2   = new ImageForm(q_stFile2, "Target", this);
    _plpImageForm->Add(q_pForm2);
    q_pForm2->show();

    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "Target")
       ti2 = _q_pFormFocused->ImageColor();
    else
        return;

    KImageGray so_r(ti1.Row(),ti1.Col()),so_g(ti1.Row(),ti1.Col()),so_b(ti1.Row(),ti1.Col());
    KImageGray ta_r(ti2.Row(),ti2.Col()),ta_g(ti2.Row(),ti2.Col()),ta_b(ti2.Row(),ti2.Col());
    for(int i=0; i<ti1.Row();i++){
        for(int j=0; j<ti1.Col();j++){
            so_r[i][j]=ti1._ppA[i][j].r;
            so_g[i][j]=ti1._ppA[i][j].g;
            so_b[i][j]=ti1._ppA[i][j].b;
        }
    }
    for(int i=0; i<ti2.Row();i++){
        for(int j=0; j<ti2.Col();j++){
            ta_r[i][j]=ti2._ppA[i][j].r;
            ta_g[i][j]=ti2._ppA[i][j].g;
            ta_b[i][j]=ti2._ppA[i][j].b;
        }
    }
    KImageGray de;
    ti1.ColorToGray(de);
    so_r.HistoMatching(so_r,ta_r,de);
    so_g.HistoMatching(so_g,ta_g,de);
    so_b.HistoMatching(so_b,ta_b,de);
    for(int i=0,ii=ti1.Row(); ii; i++,ii--)
        for(int j=0,jj=ti1.Col(); jj; j++,jj--){
            result._ppA[i][j].r = so_r[i][j];
            result._ppA[i][j].g = so_g[i][j];
            result._ppA[i][j].b = so_b[i][j];
    }

    ImageForm*  q_pForms = new ImageForm(result, "Histogram Matched Image", this);
    _plpImageForm->Add(q_pForms);
    q_pForms->show();
    UpdateUI();
}




void MainFrame::on_GaussianNoise_clicked()
{
    KImageColor t;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
        t = _q_pFormFocused->ImageColor();
    else
        return;
    KImageGray r,g,b;
    t.SplitInto(r,g,b);
    r.GNoise(r);
    g.GNoise(g);
    b.GNoise(b);
   for(int i=0; i<r.Row();i++){
       for(int j=0; j<r.Col();j++){
           t._ppA[i][j].r =r[i][j];
           t._ppA[i][j].g =g[i][j];
           t._ppA[i][j].b =b[i][j];

       }
   }
    ImageForm*  q_pForm = new ImageForm(t, "Gaussian Noise Picture", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
    UpdateUI();
}


void MainFrame::on_Salt_Pepper_clicked()
{
    KImageColor t;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
        t = _q_pFormFocused->ImageColor();
    else
        return;
    t.SPNoise(t);
    ImageForm*  q_pForm = new ImageForm(t, "Salt-Pepper Noise Picture", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();

}


void MainFrame::on_BoxFilter_clicked()
{
    KImageColor t;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&
            (_q_pFormFocused->ID() == "Gaussian Noise Picture"
             ||_q_pFormFocused->ID() == "Salt-Pepper Noise Picture"))
         //ID -> �̹��� â�� ID�� GaussianNoise�� �̹��� �Ǵ� Salt-Pepper Noise�� �̹����� ����
        t = _q_pFormFocused->ImageColor();
    else
        return;
    double  win = ui->nWindow_2->value();
    t.BoxFilter(t,(int)win);
    ImageForm*  q_pForm = new ImageForm(t, "Boxed Image", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();

}


void MainFrame::on_GaussianFilter_clicked()
{
    KImageColor t;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&
            (_q_pFormFocused->ID() == "Gaussian Noise Picture"
             ||_q_pFormFocused->ID() == "Salt-Pepper Noise Picture"))
        //ID -> �̹��� â�� ID�� GaussianNoise�� �̹��� �Ǵ� Salt-Pepper Noise�� �̹����� ����
        t = _q_pFormFocused->ImageColor();
    else
        return;
    double  sig = ui->Sigma->value();
    t.GaussianSmoothed(sig);
    ImageForm*  q_pForm = new ImageForm(t, "Smoothed Image", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
}


void MainFrame::on_MedianFilter_clicked()
{
     KImageColor t;
     if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&
             (_q_pFormFocused->ID() == "Gaussian Noise Picture"||_q_pFormFocused->ID() == "Salt-Pepper Noise Picture"))
         //ID -> �̹��� â�� ID
         t = _q_pFormFocused->ImageColor();
     else
         return;
     double  win = ui->nWindow->value();
     KImageGray r,g,b;
     t.SplitInto(r,g,b);
     r.MedianFiltered(win);
     g.MedianFiltered(win);
     b.MedianFiltered(win);
     for(int i=0; i<r.Row();i++){
         for(int j=0; j<r.Col();j++){
             t._ppA[i][j].r =r[i][j];
             t._ppA[i][j].g =g[i][j];
             t._ppA[i][j].b =b[i][j];

         }
     }
     ImageForm*  q_pForm = new ImageForm(t, "Medianed Image", this);
     _plpImageForm->Add(q_pForm);
     q_pForm->show();
}






void MainFrame::on_CannyEdge_clicked()
{
    KImageGray t;

    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() && (_q_pFormFocused->ID() == "OPEN"))
        t = _q_pFormFocused->ImageGray();
    else
        return;
    int th,tl;
    double sig;
    tl =ui->EdgeLow->value();
    th =ui->EdgeHigh->value();
    sig = ui->EdgeSigma->value();
    KImageGray out;
    MG p(sig,0,2000);
    p.Canny(tl,th,t,out);
    ImageForm*  q_pForm = new ImageForm(out, "Canny Image", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
}


void MainFrame::on_CoinCircle_clicked()
{

    KImageGray tmp;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() && (_q_pFormFocused->ID() == "OPEN"))
        tmp = _q_pFormFocused->ImageGray();
    else
        return;

    KImageGray out(tmp.Row(),tmp.Col());
    KImageGray Circle(tmp.Row(),tmp.Col());
    CH point(tmp,103);
    point.Canny(20,50,out);
    point.GetPoint();
    point.GetCenter(Circle);
    ImageForm*  q_pForm = new ImageForm(out, "GetCircle EdgePoint", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    ImageForm*  q_pForm1 = new ImageForm(Circle, "CenterCricle Image", this);
    _plpImageForm->Add(q_pForm1);
    q_pForm1->show();
}


void MainFrame::on_GeneralHough_clicked()
{
    std::ifstream readtxt;
    KImageGray tmp;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() && (_q_pFormFocused->ID() == "OPEN"))
        tmp = _q_pFormFocused->ImageGray();
    else
        return;

    KImageGray out(tmp.Row(),tmp.Col());        // 모델
    KImageGray sub(tmp.Row(),tmp.Col());        // 여러번 모델 그리기
    KImageGray result(tmp.Row(),tmp.Col());     // 최종 결과
    int pxarray[100]={0,};                  // 모델의 x좌표
    int pyarray[100]={0,};                  // 모델의 y좌표
    int xsum=0,ysum=0;
    double xmean=0, ymean=0;                // 중심점 변수
    char buf[40];                           // txt buffer
    int count=0;                            // 좌표 개수 측정
    readtxt.open("./data/plug.txt");
    if(readtxt.is_open()){
        while(!readtxt.eof()){
            readtxt.getline(buf,12,' ');
            pyarray[count]=atoi(buf)-60;
            ysum+=pyarray[count];
            readtxt.getline(buf,12,'\n');
            pxarray[count]=atoi(buf);
            xsum+=pxarray[count];
            count++;
        }
    }

    xmean=xsum/(count-1);   // x좌표 중심
    ymean=ysum/(count-1);   // y좌표 중심
    for (int i=0; i<count-1; i++){
        out._ppA[pyarray[i]][pxarray[i]] = 255;
        // 모델 표시
    }
    out._ppA[(int)ymean][(int)xmean]=255;
    int temp=0;
    readtxt.close();
    // 중심점을 기준으로 x축 대칭 이동
    for (int i=0; i<count-1; i++){
        if(xmean<pxarray[i]){
            temp = pxarray[i];
            pxarray[i] =temp - 2*(temp-xmean);
        }
        else if(xmean>pxarray[i]){
            temp = pxarray[i];
            pxarray[i] = temp+ 2*(xmean-temp);
        }
    }


    CH plug(tmp,pxarray,pyarray,xmean,ymean);
    //plug.GetPlugEdge(20,50,out);
    plug.GetPlugEdge(20,50,sub);
    plug.GetPlugPoint();
    plug.GetPlugPicture(result);
    ImageForm*  q_pForm = new ImageForm(out, "Model Image", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
    ImageForm*  q_pForm1 = new ImageForm(sub, "Edge_Model Image", this);
    _plpImageForm->Add(q_pForm1);
    q_pForm1->show();
    ImageForm*  q_pForm2 = new ImageForm(result, "Plug Image", this);
    _plpImageForm->Add(q_pForm2);
    q_pForm2->show();

}

