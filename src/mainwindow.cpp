#include "mainwindow.h"
#include "ui_test.h"
#include <QStackedLayout>
#include <QPainterPath>
#include <QPainter>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent) {

    this->resize(1000, 600);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);

    QWidget *widget1 = new QWidget;
    widget1->setFixedHeight(60);
    widget1->setProperty("class", "container");
    navigationBar(widget1);


    QWidget *widget2 = new QWidget;
    widget2->setFixedHeight(60);
    widget2->setStyleSheet("background: yellow");


    vbox->addWidget(widget1);
    vbox->addWidget(widget2);
    vbox->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));

    return;


    QWidget *widget = new QWidget(this);
    widget->setGeometry(QRect(100, 100, 500, 200));
    widget->setStyleSheet("background: yellow;");


    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->setStretch(0, 0);

    QPushButton *button0 = new QPushButton("Button 0");
    button0->setFixedSize(100, 100);
    button0->setStyleSheet("background-color: gray;");
    layout->addWidget(button0);

    QPushButton *button1 = new QPushButton("Button 1");
    button1->setFixedSize(100, 100);
    button1->setStyleSheet("background-color: red;");
    button1->setLayout(new QStackedLayout()); // 需要一个布局管理器来支持子控件的绝对定位
    layout->addWidget(button1);

    QWidget *widgetBox = new QWidget;
    /*margin-left: 20px;margin-top: 30px;*/
    widgetBox->setStyleSheet("background: rgba(0,0,0,0.5);position: relative;");
    QPushButton *button2 = new QPushButton("Button 2", widgetBox);
    button2->setStyleSheet("background-color: pink;"
                           "width: 40px;"
                           "height: 20px;"
                           "position: absolute;"
                           "left:20px;top:0;"
    );


    button1->layout()->addWidget(widgetBox);












// 使用QRect来设置button2的相对位置
//    QRect rect = button1->geometry();
//    button2->setGeometry(QRect(rect.x() + 50, rect.y() + 50, 50, 50));
////    ui->setupUi(this);
//
//    QWidget *w1 = new QWidget(this);
//    setCentralWidget(w1);  // 设置中心窗口部件
//    w1->setProperty("class", "box");
//    w1->setFixedSize(150, 30);
//
//
//    QHBoxLayout *box = new QHBoxLayout;
//    /*设置边距*/
//    box->setContentsMargins(0, 0, 0, 0);
//    /*设置间距*/
//    box->setSpacing(0);
//    box->setStretch(0, 0);
//    box->setSizeConstraint(QLayout::SetDefaultConstraint);
//
//    QLabel *searchIcon = new QLabel;
//    searchIcon->setProperty("class", "searchIcon");
//    searchIcon->setFixedSize(15, 15);
//
//    QLineEdit *searchInput = new QLineEdit;
//    searchInput->setProperty("class", "searchInput");
//    searchInput->setFixedSize(150, 30);
//    searchInput->setPlaceholderText("搜索");
//
////    box->addWidget(searchIcon);
//    box->addWidget(searchInput);
//
//    w1->setLayout(box);


}

void MainWindow::navigationBar(QWidget *parent) {
    QFile qssFile("./qss/navigationBar.css");
    if (qssFile.open(QFile::ReadOnly)) {
        parent->setStyleSheet(qssFile.readAll());
    }
    qssFile.close();

    QHBoxLayout *layout = new QHBoxLayout(parent);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(navigationBarLeft());
    layout->addWidget(navigationBarRight());
}

QWidget *MainWindow::navigationBarRight() {
    QWidget *w = new QWidget;
    w->setProperty("class", "right-box");
    // w->setGeometry(QRect(0, 0, 500, 60));

    QHBoxLayout *layout = new QHBoxLayout(w);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    QLabel *avator = new QLabel;
    avator->setFixedSize(30, 30);
    avator->setProperty("class", "right-box-avator");

    QPixmap pixmapa("./resource/比卡丘不皮.jpg");
    QPixmap pixmap(30, 30);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, 30, 30);    //绘制椭圆
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, 30, 30, pixmapa);
    avator->setPixmap(pixmap);

    layout->addWidget(avator);

    layout->addSpacerItem(new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *name = new QLabel("逆水行舟xxx");
    name->setProperty("class", "right-box-name");
    layout->addWidget(name);

    layout->addSpacerItem(new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *vip = new QLabel("开通vip");
    vip->setProperty("class", "right-box-vip");
    layout->addWidget(vip);

    layout->addSpacerItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *skin = new QLabel;
    skin->setFixedSize(16, 16);
    skin->setScaledContents(true);
    skin->setProperty("class", "right-box-skin");
    layout->addWidget(skin);

    layout->addSpacerItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *setting = new QLabel;
    setting->setFixedSize(16, 16);
    setting->setProperty("class", "right-box-setting");
    layout->addWidget(setting);

    layout->addSpacerItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));
    QWidget *email = new QWidget;
    email->setProperty("class", "right-box-email");
    email->setFixedSize(40, 40);
    QLabel *emailIcon = new QLabel(email);
    emailIcon->setGeometry(QRect(12, 12, 16, 16));
    emailIcon->setProperty("class", "right-box-email-icon");


    QLabel *emailNumber = new QLabel(email);
    emailNumber->setText("99");
    emailNumber->move(14, 0);
    emailNumber->setProperty("class", "right-box-email-number");

    layout->addWidget(email);



    /*===============*/
    layout->addSpacerItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *share = new QLabel;
    share->setFixedSize(16, 16);
    share->setProperty("class", "right-box-share");
    share->setPixmap(QPixmap("./resource/mini.png"));
    share->setScaledContents(true);
    layout->addWidget(share);

    layout->addSpacerItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *reduce = new QLabel;
    reduce->setFixedSize(16, 16);
    reduce->setProperty("class", "right-box-reduce");
    reduce->setPixmap(QPixmap("./resource/最小化.png"));
    reduce->setScaledContents(true);
    layout->addWidget(reduce);

    layout->addSpacerItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *magnify = new QLabel;
    magnify->setFixedSize(16, 16);
    magnify->setProperty("class", "right-box-magnify");
    magnify->setPixmap(QPixmap("./resource/最大化.png"));
    magnify->setScaledContents(true);
    layout->addWidget(magnify);

    layout->addSpacerItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    QLabel *close = new QLabel;
    close->setFixedSize(16, 16);
    close->setProperty("class", "right-box-close");
    close->setPixmap(QPixmap("./resource/关闭.png"));
    close->setScaledContents(true);
    layout->addWidget(close);
    layout->addSpacerItem(new QSpacerItem(25, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));
    return w;
}

QWidget *MainWindow::navigationBarLeft() {
    QWidget *w = new QWidget/*(parent)*/;
    w->setProperty("class", "left-box");
    // w->setGeometry(QRect(0, 0, 500, 60));


    QHBoxLayout *layout = new QHBoxLayout(w);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);


    QLabel *logoIcon = new QLabel;
    logoIcon->setFixedSize(145, 40);
    logoIcon->setProperty("class", "left-box-logo");


    QWidget *arrowBox = new QWidget;
    arrowBox->setFixedSize(55, 30);
    arrowBox->setProperty("class", "left-box-arrow");

    QHBoxLayout *layout1 = new QHBoxLayout(arrowBox);
    layout1->setContentsMargins(0, 0, 0, 0);
    layout1->setSpacing(0);

    QLabel *arrow1 = new QLabel;
    arrow1->setFixedSize(24, 24);
    arrow1->setProperty("class", "left-box-arrow-left");
    arrow1->setPixmap(QPixmap("./resource/后退.png"));
    arrow1->setScaledContents(true);
    layout1->addWidget(arrow1);
    /*QSizePolicy::Expanding（水平方向上尽可能多的占用空间）*/
    /*QSizePolicy::Minimum（垂直方向上只占用最小的空间）*/
    QSpacerItem *item = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout1->addItem(item);


    QLabel *arrow2 = new QLabel;
    arrow2->setFixedSize(24, 24);
    arrow2->setProperty("class", "left-box-arrow-right");
    arrow2->setPixmap(QPixmap("./resource/前进.png"));
    arrow2->setScaledContents(true);
    layout1->addWidget(arrow2);


    QWidget *box = new QWidget/*(parent)*/;
    box->setFixedSize(170, 30);
    box->setProperty("class", "left-box-search");

    QLineEdit *searchInput = new QLineEdit(box);
    searchInput->setGeometry(QRect(0, 0, 170, 30));
    searchInput->setProperty("class", "left-box-search-input");
    searchInput->setPlaceholderText("搜索");


    QLabel *searchIcon = new QLabel(box);
    searchIcon->setGeometry(QRect(5, 8, 15, 15));
    searchIcon->setProperty("class", "left-box-search-icon");


    QLabel *singIcon = new QLabel;
    singIcon->setFixedSize(21, 23);
    singIcon->setProperty("class", "singIcon");
    singIcon->setPixmap(QPixmap("./resource/voice.png"));
    singIcon->setScaledContents(true);

    /*距离左边距20*/
    layout->addItem(new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    layout->addWidget(logoIcon);

    layout->addItem(new QSpacerItem(40, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    layout->addWidget(arrowBox);

    layout->addItem(new QSpacerItem(5, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    layout->addWidget(box);

    layout->addItem(new QSpacerItem(15, 0, QSizePolicy::Fixed, QSizePolicy::Minimum));

    layout->addWidget(singIcon);

    layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));


    return w;
}

MainWindow::~MainWindow() = default;


