#ifndef MATERIALSCATALOG_H
#define MATERIALSCATALOG_H
/*Dan
  打印时不同分辨率下材料设定,包括材料选择,曝光强度,曝光时间,粘附时间等
*/
#include <QDialog>
#include <QWidget>
#include <QStyledItemDelegate>
#include <vector>


class MaterialsTableItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MaterialsTableItemDelegate(QObject *parent = 0);
    ~MaterialsTableItemDelegate();

    virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
};

namespace Ui {
class MaterialsCatalog;
}

class MaterialsCatalog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MaterialsCatalog(QWidget *parent = 0);
    ~MaterialsCatalog();
    void closeEvent(QCloseEvent *);
    
    void UpdateByLanguage();
private slots:
    void on_comboBoxMaterial_currentIndexChanged(const QString &arg1);

    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::MaterialsCatalog *ui;
    std::vector<QString> vecName;
    QString language;
};

#endif // MATERIALSCATALOG_H
