#ifndef MAINWID_HPP
#define MAINWID_HPP

#include <QtGui>
#include <QSystemTrayIcon>
#include <phonon/mediaobject.h>
#include "countdown_setting.hpp"
#include "count_time_data.hpp"
#include "countup_box.hpp"
#include "customCounter.hpp"
#include "version.hpp"

#define COUNT_UP_M 0
#define COUNT_DOWN_M 1
#define CUSTOM_COUNT_M 2

class mainwid : public QWidget
{
    Q_OBJECT
public:
    explicit mainwid(QWidget *parent = 0);

    ctd_d* get_ctd_d(){return &tdata;};

signals:
    void finishCountDown();
    void change_ctd_d(const ctd_d*);
	void change_pause_f(QString);//pause_fの状態が変更されたときemitされる
    
public slots:
    void unsetDisable(){
        setEnabled(true);
    };

	void delete_phonon_object(){
        delete callaudio;
	};

private slots:
    void mode_change(int);
    void refLCD(int,int,int);
    void push_start();
    void push_stop();
    void push_setting();
    void push_pause();
    void takeOneSec();

private:
    void init_mode_Set();
    void init_buttons();

    QLabel *sl;
    QLCDNumber *one,*two,*three;
    QLCDNumber *all_s;
    QComboBox *mode_Set;
    QString current_mode_string;int current_mode;
	QString audioFilePath;
    QPushButton *start,*stop,*pause,*config;
    countup_box *countup_msg;
    QTimer *t;
    ctd_d tdata;
    bool pause_f;
    Phonon::MediaObject *callaudio;

    countdown_setting *countdownSetting;
	
	customCounter *c_counter;

	bool readFromFile(QString&);

};

int HMSToSecond(const int,const int,const int);

#endif // MAINWID_HPP
