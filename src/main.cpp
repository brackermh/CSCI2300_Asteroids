//Enter main here
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Main window
    QWidget window;
    window.setWindowTitle("Qt Widgets Hello World");
    window.resize(400, 300);

    // Main layout (vertical)
    QVBoxLayout *mainLayout = new QVBoxLayout();

    // Title label
    QLabel *title = new QLabel("Welcome to Qt Widgets!");
    title->setAlignment(Qt::AlignCenter);

    // Frame (acts like a panel)
    QFrame *panel = new QFrame();
    panel->setFrameShape(QFrame::Box);
    panel->setLineWidth(2);

    // Layout inside panel
    QVBoxLayout *panelLayout = new QVBoxLayout();

    QLabel *message = new QLabel("Press the button");
    message->setAlignment(Qt::AlignCenter);

    QPushButton *button = new QPushButton("Click Me");

    // Add widgets to panel
    panelLayout->addWidget(message);
    panelLayout->addWidget(button);
    panel->setLayout(panelLayout);

    // Bottom row (horizontal layout)
    QHBoxLayout *bottomLayout = new QHBoxLayout();

    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");

    bottomLayout->addWidget(okButton);
    bottomLayout->addWidget(cancelButton);

    // Add everything to main layout
    mainLayout->addWidget(title);
    mainLayout->addWidget(panel);
    mainLayout->addLayout(bottomLayout);

    window.setLayout(mainLayout);

    // --- Interactions ---
    QObject::connect(button, &QPushButton::clicked, [&]() {
        message->setText("Button Clicked by Matt!");
    });

    QObject::connect(cancelButton, &QPushButton::clicked, [&]() {
        window.close();
    });

    window.show();

    return app.exec();
}
