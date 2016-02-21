#include "testproject.h"

#include <memory>

#include "../../src/memento/MainWindowMemento.h"

void TestProject::init(){
    project_ = new Model::Project(QString("TestProject"));
}

void TestProject::testGetSetName(){
    QVERIFY(project_->getName() == "TestProject");
    project_->setName("test2");
    QVERIFY(project_->getName() == "test2");
    project_->setName("testSpecialCharacters:!!§$%&/=°eếéẁǜäüö");
    QVERIFY(project_->getName() == "testSpecialCharacters:!!§$%&/=°eếéẁǜäüö");
}

void TestProject::testGetSetPath(){
    project_->setPath("test2");
    QVERIFY(project_->getPath() == "test2");
    project_->setPath("testSpecialCharacters:!!§$%&/=°eếéẁǜäüö");
    QVERIFY(project_->getPath() == "testSpecialCharacters:!!§$%&/=°eếéẁǜäüö");
    project_->setPath("/example/for/a/normal/path.txt");
    QVERIFY(project_->getPath() == "/example/for/a/normal/path.txt");
}

void TestProject::testGetSetMemento(){
    std::unique_ptr<Memento::MainWindowMemento> memo = std::make_unique<Memento::MainWindowMemento>();
    memo->setSelectedTab(1);
    project_->setMemento(std::move(memo));
    Memento::MainWindowMemento* memoNotUnique = &project_->getMemento();
    QVERIFY(memoNotUnique->getSelectedTab() == 1);
    memo = std::make_unique<Memento::MainWindowMemento>();
    memo->setSelectedTab(2);
    project_->setMemento(std::move(memo));
    memo = std::make_unique<Memento::MainWindowMemento>();
    memo->setSelectedTab(3);
    project_->setMemento(std::move(memo));
    memoNotUnique = &project_->getMemento();
    QVERIFY(memoNotUnique->getSelectedTab() == 3);
}
