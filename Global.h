#ifndef GLOBAL_H
#define GLOBAL_H

#endif // GLOBAL_H

#include <QObject>

class Globals:public QObject{

    Q_OBJECT

public:
    static Globals& getInstance(){

        static Globals instance;
        return instance;


    }
    QString ID;
    QString name;



private:
    explicit Globals(QObject *parent = nullptr);
    ~Globals() = default;
    Q_DISABLE_COPY(Globals)

};
