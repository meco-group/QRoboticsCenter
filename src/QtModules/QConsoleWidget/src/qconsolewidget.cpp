#include "qconsolewidget.h"
#include "ui_qconsolewidget.h"

QConsoleWidget::QConsoleWidget(QWidget *parent) :
    QWidget(parent),
    _insert_cmd(0),
    ui(new Ui::QConsoleWidget)
{
    ui->setupUi(this);
    ui->commandLabel->setAlignment(Qt::AlignBottom);
    ui->messageLabel->setAlignment(Qt::AlignBottom);

    _send_name = "pc@robot:$";
    _recv_name = "robot@pc:$";

    ui->commandLabel->setText(_send_name);
    ui->messageLabel->setText(_recv_name);
}

QConsoleWidget::~QConsoleWidget()
{
    delete ui;
}

void QConsoleWidget::setSendName(QString name)
{
    _send_name = name;
}

void QConsoleWidget::setReceiveName(QString name)
{
    _recv_name = name;
}

QString QConsoleWidget::sendName()
{
    return _send_name;
}

QString QConsoleWidget::receiveName()
{
    return _recv_name;
}

void QConsoleWidget::addSendMsg(QString msg, bool display_name)
{
    _send_msgs.append(msg);
    QString separator = "\n";

    if(_send_msgs.length()>QCONSOLEWIDGET_MAXLINECOUNT) _send_msgs.removeFirst();
    if(display_name) separator = "\n" + _send_name + ": ";

    ui->commandLabel->setText(separator + _send_msgs.join(separator));
}

void QConsoleWidget::addRecvMsg(QString msg, bool display_name)
{
    _recv_msgs.append(msg);
    QString separator = "\n";

    if(_recv_msgs.length()>QCONSOLEWIDGET_MAXLINECOUNT) _recv_msgs.removeFirst();
    if(display_name) separator = "\n" + _recv_name + ": ";

    ui->messageLabel->setText(separator + _recv_msgs.join(separator));
}

void QConsoleWidget::keyPressEvent(QKeyEvent *e)
{
    if(ui->consoleLineEdit->hasFocus()){
        switch(e->key()){
            case Qt::Key_Up:{
                if(_send_msgs.length()>0){
                    _insert_cmd += 1;
                    if(_insert_cmd > _send_msgs.length()) _insert_cmd = _send_msgs.length();
                    ui->consoleLineEdit->setText(_send_msgs[_send_msgs.length()-_insert_cmd]);
                }
                break;}
            case Qt::Key_Down:{
                if(_send_msgs.length()>0){
                    _insert_cmd -= 1;
                    if(_insert_cmd <= 0){
                        _insert_cmd = 0;
                        ui->consoleLineEdit->setText("");
                    }
                    else{
                        ui->consoleLineEdit->setText(_send_msgs[_send_msgs.length()-_insert_cmd]);
                    }
                }
                break;}
        }
    }
}

void QConsoleWidget::on_consoleLineEdit_returnPressed()
{
    int parse_flag;
    //mavlink_message_t msg;

    //parse_flag = parseCommand(ui->consoleLineEdit->text().toLocal8Bit().data(), &msg, *_ballBotID);
    /*switch(parse_flag){
    case PARSE_FLAG_DON:
        //emit mavlinkMsgSend(msg);
        break;
    case PARSE_FLAG_IDR:
        addSendMsg(QString("Missing identifier (=)."), false);
        break;
    case PARSE_FLAG_CMD:
        addSendMsg(QString("Unknown command."), false);
        break;
    case PARSE_FLAG_FEW:
        addSendMsg(QString("Too few input arguments."), false);
        break;
    case PARSE_FLAG_MUC:
        addSendMsg(QString("Too many input arguments."), false);
        break;
    case PARSE_FLAG_PAR:
        addSendMsg(QString("No matching parentheses or at wrong positions."), false);
        break;
    case PARSE_FLAG_EMT:
        addSendMsg(QString("Empty command."), false);
        break;
    }*/
    addSendMsg(ui->consoleLineEdit->text());
    emit command(ui->consoleLineEdit->text());

    ui->consoleLineEdit->clear();
    _insert_cmd = 0;
}
