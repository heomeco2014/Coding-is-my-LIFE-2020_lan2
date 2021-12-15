#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sFile
{
protected:
    string ten;
public:
    sFile(const string& ten1) : ten(ten1) {}

    virtual int getSize() = 0;
    virtual void xuat(const int& level = 0) = 0;
};

class File : public sFile
{
private:
    int kichThuoc;
public:
    File(const string& name, int size) : sFile(name) {
        kichThuoc = size;
    }

    int getSize() { return kichThuoc; }

    void xuat(const int& level = 0)
    {
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << ten << "    " << kichThuoc << " B" << endl;
    }
};

class Folder : public sFile
{
private:
    vector<sFile*> files;
public:
    Folder(const string& name) : sFile(name) {}

    void addFile(sFile* file)
    {
        files.push_back(file);
    }

    int getSize()
    {
        int size = 0;
        for (auto file : files)
            size += file->getSize();
        return size;
    }

    int count()
    {
        return files.size();
    }

    void xuat(const int& level = 0)
    {
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << "[" << ten << "]" << endl;
        for (int i = 0; i < files.size();i++)
            files[i]->xuat(level + 1);
    }
};

int main()
{
    Folder c("C:");
    Folder baiTap("Bai Tap");
    File bt1doc("BT1.doc", 123456);
    Folder baiTapC("Bai tap C");
    File bt2cpp("BT2.cpp", 1280);
    File bt2xls("BT2.xls", 23456);
    Folder lyThuyet("Ly thuyet");
    File ch1("Ch1.ppt", 34567);

    c.addFile(&baiTap);
    c.addFile(&lyThuyet);

    baiTap.addFile(&bt1doc);
    baiTap.addFile(&baiTapC);
    baiTap.addFile(&bt2xls);

    baiTapC.addFile(&bt2cpp);

    lyThuyet.addFile(&ch1);

    c.xuat(0);
    cout << "Tong so file va thu muc trong C: " << c.count() << endl;

    cout << "Kich thuoc thu muc [Bai tap]: " << baiTap.getSize() << " B" << endl;

    return 0;
}