#ifndef BUILDSPACE_H
#define BUILDSPACE_H

#include <QWidget>
/*Dan
  no used
*/
namespace Ui {
class BuildSpace;
}

class BuildSpace : public QWidget//No used
{
    Q_OBJECT
    
public:
    explicit BuildSpace(QWidget *parent = 0);
    ~BuildSpace();
    
private:
    Ui::BuildSpace *ui;
};

#endif // BUILDSPACE_H
