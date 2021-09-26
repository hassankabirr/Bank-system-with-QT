QT       += core gui
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accept_acc_ui.cpp \
    account_request.cpp \
    accountlistoftransactionsdialog.cpp \
    accountwindow.cpp \
    add_user_ui.cpp \
    admin.cpp \
    admin_ui.cpp \
    bank_account.cpp \
    card.cpp \
    card_req_ui.cpp \
    card_request.cpp \
    del_ui.cpp \
    dialog.cpp \
    dialog_add_account.cpp \
    edit_profile_dialog.cpp \
    list_of_account_requests.cpp \
    list_of_bankaccounts.cpp \
    list_of_card_requests.cpp \
    list_of_transactions.cpp \
    list_of_users.cpp \
    login_logout2_ui.cpp \
    login_logout_ui.cpp \
    longterminvestment.cpp \
    main.cpp \
    main_user.cpp \
    mainwindow.cpp \
    moneytransferdialog.cpp \
    paymentgateway.cpp \
    savingsaccount.cpp \
    shortterminvestment.cpp \
    shorttermsharedinvestment.cpp \
    smtp.cpp \
    transaction.cpp \
    transaction_ui.cpp \
    user.cpp \
    users_info_ui.cpp

HEADERS += \
    Global_data_variables.h \
    accept_acc_ui.h \
    account_request.h \
    accountlistoftransactionsdialog.h \
    accountwindow.h \
    add_user_ui.h \
    admin.h \
    admin_ui.h \
    bank_account.h \
    card.h \
    card_req_ui.h \
    card_request.h \
    del_ui.h \
    dialog.h \
    dialog_add_account.h \
    edit_profile_dialog.h \
    list_of_account_requests.h \
    list_of_bankaccounts.h \
    list_of_card_requests.h \
    list_of_transactions.h \
    list_of_users.h \
    login_logout2_ui.h \
    login_logout_ui.h \
    longterminvestment.h \
    main_user.h \
    mainwindow.h \
    moneytransferdialog.h \
    paymentgateway.h \
    savingsaccount.h \
    shortterminvestment.h \
    shorttermsharedinvestment.h \
    smtp.h \
    transaction.h \
    transaction_ui.h \
    user.h \
    users_info_ui.h

FORMS += \
    accept_acc_ui.ui \
    accountlistoftransactionsdialog.ui \
    accountwindow.ui \
    accs_cards_ui.ui \
    add_user_ui.ui \
    admin_ui.ui \
    card_req_ui.ui \
    del_ui.ui \
    dialog.ui \
    dialog_add_account.ui \
    edit_profile_dialog.ui \
    login_logout2_ui.ui \
    login_logout_ui.ui \
    main_user.ui \
    mainwindow.ui \
    moneytransferdialog.ui \
    paymentgateway.ui \
    transaction_ui.ui \
    users_info_ui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../../Desktop/main_User/main_User.pro
