/*
 * 复制整行代码：ctrl+d
 * 变量：小写字母、“_” or 全部大写
 * 结构体：
 * 函数：小驼峰，例：getGame
 * 类名：大驼峰、"C"例：CPlayGame
 * 宏常量：全部大写
 * 结构体：大驼峰 or 全部大写
 * 逻辑：与：&&， 或：||，非： !
 */

#include <iostream>
using namespace std;
#define MAX 1000
#include <string.h>

//联系人结构体
struct Person{
    string name="";//姓名
    int sex=0;//性别 男：1，女：2
    int age=0;//年龄
    string phone_number="";//电话号码
    string address="";//家庭地址
};

//通讯录结构体
struct AddressBooks{
    struct Person personArray[MAX];//通讯录中联系人的数组
    int person_size;//通讯录中的人员个数
};

//菜单界面
void showMenu(){
    cout<<"_______________________________________________"<<endl;
    cout<<"____________________1.添加联系人_________________"<<endl;
    cout<<"____________________2.显示联系人_________________"<<endl;
    cout<<"____________________3.删除联系人_________________"<<endl;
    cout<<"____________________4.查找联系人_________________"<<endl;
    cout<<"____________________5.修改联系人_________________"<<endl;
    cout<<"____________________6.清空联系人_________________"<<endl;
    cout<<"____________________0.退出通讯录 ________________"<<endl;
    cout<<"_______________________________________________"<<endl;
}

//1.添加联系人
void addPerson(AddressBooks* abs){
    //判断通讯录是否人数已满
    if(abs->person_size==MAX){
        cout<<"通讯录人数已满，无法添加联系人"<<endl;
    }
    //添加姓名
    else {
        string name = "";
        cout << "请输入联系人姓名：";
        cin >> name;//输入联系人姓名
        abs->personArray[abs->person_size].name = name;//将输入的联系人姓名赋值给通讯录
        //添加性别
        int sex = 0;
        while (true) {
            cout << "数字1代表性别男，数字2代表性别女" << endl;
            cout << "请输入联系人性别：";
            cin >> sex;
            if (sex == 1 || sex == 2)
                break;
            else
                cout << "输入性别错误，请重新输入！" << endl;
        }
        abs->personArray[abs->person_size].sex = sex;
        //添加年龄
        int age = 0;
        cout << "请输入联系人年龄：";
        cin >> age;
        abs->personArray[abs->person_size].age = age;
        //添加电话号码
        string phone_number = "";
        while (true) {
            cout << "请输入联系人电话号码：";
            cin >> phone_number;
            if (phone_number.length() == 11)
                break;
            else
                cout << "输入号码错误，请重新输入！" << endl;
        }
        abs->personArray[abs->person_size].phone_number = phone_number;
        //添加家庭住址
        cout << "请输入联系人家庭住址：";
        string address = "";
        cin >> address;
        abs->personArray[abs->person_size].address = address;
        //添加成功
        abs->person_size++;
        cout << "添加成功！" << endl;
    }
    //关闭界面
    system("pause");
    system("cls");
}

//2.显示联系人
void showPerson(AddressBooks* abs){
    if(abs->person_size==0){
        cout<<"无联系人信息！"<<endl;
        // 这是Clion的终端BUG，如果跨函数了，这样的输出不太能输出到终端上显示，
        // 因此，我们手动刷新一下缓冲区，让想要输出的输出出来
        // setbuf(stdout, nullptr); 这里就是设置输出缓冲区为无缓冲，也就是说，让输出缓冲区变成0，一来数据就马上刷新
    }
    else{
        for(int i=0;i<abs->person_size;i++){
            cout<<abs->personArray[i].name<<"\t";
            cout<<(abs->personArray[i].sex==1?"男":"女")<<"\t";//三目运算符
            cout<<abs->personArray[i].age<<"\t";
            cout<<abs->personArray[i].phone_number<<"\t";
            cout<<abs->personArray[i].address<<"\t"<<endl;
        }
    }
    //关闭界面
    system("pause");
    system("cls");
}

//判断联系人是否存在
//联系人存在，返回数组地址；不存在返回-1
int isExistPerson(AddressBooks* abs,string name){
    for(int i=0;i<abs->person_size;i++){
        if(abs->personArray[i].name==name)
            return i;
    }
    return -1;
}

//3.删除联系人
void delectPerson(AddressBooks* abs){
    cout<<"请输入需要删除联系人的姓名:";
    string name="";
    cin>>name;
    int flag=isExistPerson(abs,name);; //flag代表联系人是否存在，以及存在联系人所在地址
    if(flag==-1) {
        cout << "查无此人" << endl;
    }
    else {
        for (int i = flag; i < abs->person_size; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->person_size--;
        cout << "删除成功" << endl;
    }
    system("cls");
    system("pause");
}

//4.查找联系人
void findPerson(AddressBooks* abs){
    cout<<"请输入需要查找联系人的姓名:";
    string name="";
    cin>>name;
    int flag=isExistPerson(abs,name);; //flag代表联系人是否存在，以及存在联系人所在地址
    if(flag==-1) {
        cout << "查无此人" << endl;
    }
    else {
        int i = flag;
        cout << abs->personArray[i].name << "\t";
        cout << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";//三目运算符
        cout << abs->personArray[i].age << "\t";
        cout << abs->personArray[i].phone_number << "\t";
        cout << abs->personArray[i].address << "\t" << endl;
    }
    system("cls");
    system("pause");
}

//5.修改联系人
void modifyPerson(AddressBooks* abs){
    cout<<"请输入需要修改联系人的姓名:";
    string name="";
    cin>>name;
    int flag=isExistPerson(abs,name);; //flag代表联系人是否存在，以及存在联系人所在地址
    if(flag==-1) {
        cout << "查无此人" << endl;
    }
    else{
        string name = "";
        cout << "请输入联系人姓名：";
        cin >> name;//输入联系人姓名
        abs->personArray[flag].name = name;//将输入的联系人姓名赋值给通讯录
        //性别
        int sex = 0;
        while (true) {
            cout << "数字1代表性别男，数字2代表性别女" << endl;
            cout << "请输入联系人性别：";
            cin >> sex;
            if (sex == 1 || sex == 2)
                break;
            else
                cout << "输入性别错误，请重新输入！" << endl;
        }
        abs->personArray[flag].sex = sex;
        //年龄
        int age = 0;
        cout << "请输入联系人年龄：";
        cin >> age;
        abs->personArray[flag].age = age;
        //电话号码
        string phone_number = "";
        while (true) {
            cout << "请输入联系人电话号码：";
            cin >> phone_number;
            if (phone_number.length() == 11)
                break;
            else
                cout << "输入号码错误，请重新输入！" << endl;
        }
        abs->personArray[flag].phone_number = phone_number;
        //家庭住址
        cout << "请输入联系人家庭住址：";
        string address = "";
        cin >> address;
        abs->personArray[flag].address = address;
        //修改成功
        cout << "修改成功！" << endl;
    }
    system("cls");
    system("pause");
}

void clearPerson(AddressBooks* abs){
    abs->person_size=0;//逻辑清空
    cout << "通讯录已清空" << endl;
    system("cls");
    system("pause");
}

int main(){
    AddressBooks abs;//创建通讯录
    abs.person_size=0;//初始化通讯录中的人员个数
    setbuf(stdout, nullptr); // 一般来说，在程序开始的时候设置一下就行了，然后就是哪里没法输出，哪里就设置
    while(true){
        int select=0;//创建用户选择输入的变量
        showMenu();//菜单界面
        cin>>select;
        switch (select) {
            case 1://1.添加联系人
                addPerson(&abs);//利用地址传递，修饰实参
                break;
            case 2://2.显示联系人
                showPerson(&abs);
                break;
            case 3://3.删除联系人
                delectPerson(&abs);
                break;
            case 4://4.查找联系人
                findPerson(&abs);
                break;
            case 5://5.修改联系人
                modifyPerson(&abs);
                break;
            case 6://6.清空联系人
                clearPerson(&abs);
                break;
            case 0://0.退出通讯录
                cout<<"欢迎您下次使用"<<endl;
                system("pause");
                return 0;//退出程序
                break;
            default:
                break;
        }
    }
    system("pause");//按任意键退出
    return 0;
}
