#include <QApplication>
#include <mainWindow.h>
#include <QMessageBox>
static const QString style_sheet="QMenuBar { background-color: #F5F5F5; color: #333333; }"
                                 "QMenuBar::item:selected { background-color: #FFD54F; color: #333333; }"
                                 "QMenuBar::item:pressed { background-color: #BDBDBD; color: #333333; }"
                                 "QToolBar { background-color: #BDBDBD; color: #333333; }"
                                 "QToolBar::handle { background-color: #9E9E9E; }"
                                 "QPushButton { background-color: #4CAF50; color: white; border: none; padding: 8px 16px;border-radius:10px; }"
                                 "QPushButton:hover { background-color: #388E3C; }"
                                 "QPushButton:pressed { background-color: #1B5E20; }"
                                 "QGroupBox { border: 2px solid #BDBDBD; border-radius: 5px; margin-top: 10px; }"
                                 "QGroupBox:title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; background-color: #F5F5F5; }";
void createDirectoryIfNotExists() {
    QDir directory(QString::fromStdString(cache_file_path));
    if (!directory.exists()) {
        if (directory.mkpath(QString::fromStdString(cache_file_path))) {
            qDebug() << "Directory created:" << QString::fromStdString(cache_file_path);
        } else {
            qWarning() << "Failed to create directory:" << QString::fromStdString(cache_file_path);
        }
    } else {
        qDebug() << "Directory already exists:" << QString::fromStdString(cache_file_path);
    }
}
void clearCacheDirectory() {
    QDir directory(QString::fromStdString(cache_file_path));
    QStringList files = directory.entryList(QDir::Files);
            foreach(QString filename, files) {
            if(directory.remove(filename)) {
                qDebug() << "Removed file:" << filename;
            } else {
                qWarning() << "Failed to remove file:" << filename;
            }
        }
}
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    createDirectoryIfNotExists();
    clearCacheDirectory();
    app.setStyleSheet(style_sheet);
    mainWindow window;
    window.setWindowTitle("图像处理实验平台");
    QIcon icon(":/icons/icon.png");
    window.setWindowIcon(icon);
    window.show();
    return app.exec();
}
