#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "clientmodel.h"
#include "clientversion.h"

// Copyright year (2021-this)
// Todo: update this when changing our copyright comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2021;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    // Set current copyright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; ").arg(COPYRIGHT_YEAR) + tr("The Barcoin developers"));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
