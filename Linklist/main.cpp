#include<iostream>//输入、输出流头文件
#include<string>//STL中的string容器
typedef bool Status;//宏定义
using namespace std;//使用标准命名空间
class Person//自定义数据类型，创建一个类，数据类型是人
{
public://默认私有，为了方便，属性也设置为公共
	Person()//无参构造函数，因为写了有参构造函数，编译器不提供无参构造函数，所以需要手写一个
	{

	}
	Person(string name, int age)//有参构造函数，在创建对象时直接指定属性
	{
		this->m_name = name;//this指针，谁调用，指向谁，给成员属性赋值
		this->m_age = age;//给成员属性赋值
	}
	string m_name;//成员属性，使用STL中的string，比字符数组方便，利于管理
	int m_age;     //成员属性
};

class LinkNode//创建节点类
{
public:
	Person data;   //数据域：数据类型
	LinkNode* next;//指针域：存放下一节点的地址

};
class LinkList//单链表类，主要把链表的行为和属性进行封装
{
public:
	LinkList()//在创建链表对象时，自动初始化
	{
		this->intiList();
	}
	//类内声明，类外实现
	Status intiList();//初始化链表
	Person getElem(int i);//获得数据
	LinkNode* searchElemAddress(Person elem);//查找数据，返回地址
	int searchElemLoction(Person elem);//查找数据，返回逻辑位置
	Status insertElem(int i, Person elem);//前插入数据
	Status elemDelete(int i);//数据删除
	Status createList(int n);//创建链表
	void printList();//输出链表
	Status convert_List();//链表逆序
	~LinkList()//对象被销毁自动调用
	{
		if (head->next != NULL)
		{
			delete head;//释放内存
		}
	}
private://链表的属性设为私有
	LinkNode* head;
};

bool operator!=(const Person& p1, const Person& p2)//关系运算符重载，否则编译器不知道两个自定义数据怎么比较
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)//只存在这一种关系是假，其余全是不相等
	{
		return false;
	}
	else
	{
		return true;
	}
}
Status LinkList::intiList()//最好加上作用域，点明是哪个类的成员函数（成员函数重载）
{
	head = new LinkNode;//创建一个节点对象，并返回地址赋给头指针
	head->next = NULL;//头指针的next指向首元节点，但是首元节点未创建，防止成为野指针，需滞空
	return true;//初始化成功，返回true
}
Person LinkList::getElem(int i)//获取逻辑位置的数据
{
	int j = 1;//设置循环起点，从逻辑位置开始（首元节点）
	LinkNode* p = head->next;//同上，从首元节点开始
	while(p &&j < i)//条件：p不指向空，且逻辑位置上存在，j<i属于循环终止条件
	{
		p = p->next;//相当于p++,每循环一次，节点推进一次
		j++;//也要推进
	}
	if (p==NULL || j > i)//如何p为空或者j>i(没有找到),直接返回一个空数据
	{
		Person p1("0", 0);
		return p1;
	}
	return p->data;//找到了，返回指定数据
}
LinkNode* LinkList::searchElemAddress(Person elem)//返回数据地址
{
	LinkNode* p = head->next;//设置循环起点，指向首元节点
	while (p && p->data != elem)//条件 链表不为空，且查找数据与节点数据不一致
	{
		p = p->next;//节点推进
	}
	return p;//找到了，返回指定节点的地址
}
int LinkList::searchElemLoction(Person elem)//返回数据逻辑位置
{
	LinkNode* p = head->next;//设置循环起点，指向首元节点
	int j = 1;//计数
	while (p && p->data != elem)// 条件 链表不为空，且查找数据与节点数据不一致
	{
		p = p->next;//节点推进
		j++;//计数增加
	}
	if (p)
	{
		return j;//返回逻辑位置
	}
	else
	{
		return 0;//没有找到，返回0
	}
}
Status LinkList::insertElem(int i, Person elem)//在第几个位置，前插入数据
{
	int j = 0;//指定 目标的逻辑位置前一位置
	LinkNode* p=head;//指定 目标节点的前一个节点
	while (p && j < i - 1)//条件 链表不为空且存在最后一个节点前一个位置
	{
		p = p->next;//节点推进
		j++;//同上
	}
	if (!p || j > i - 1)//判断条件 如果链表为空或者插入数据不合理，直接返回false
	{
		return false;
	}
	LinkNode* s = new LinkNode;//创建一个新节点在堆区，并把新节点的地址返回给s
	s->next = p->next;//p->next是插入之前，p指向的下一节点的地址，现在要赋值给新节点的next
	p->next = s;//把s节点的地址赋值给插入后s前的节点的next
	s->data = elem;//给s节点的数据域赋值
	return true;//表示插入成功
}
Status LinkList::elemDelete(int i)//删除逻辑位置的数据
{
	LinkNode* p = head;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
	{
		return false;
	}//内容同上
	LinkNode* q = p->next;//记录一下需要删数据的地址，因为后面会对它进行操作
	p->next = q->next;//把q->next的地址赋给p的指针域
	delete q;//释放地址
	return true;//删除成功
}
Status LinkList::createList(int n)//创建链表个数
{
	head = new LinkNode;
	LinkNode* L = head;//保存一下头结点的地址，下面直接对L进行操作
	L->next = NULL;//初始化
	for (int i = 1; i <= n; i++)//创建节点的个数
	{
		LinkNode* p = new LinkNode;//创建节点，把首地址返回p
		cout << "请输入第 "<< i << "个节点的数据(姓名、年龄)" << endl;//提示
		cin >> p->data.m_name >> p->data.m_age;//输入每个节点的数据
		L->next = p;//头结点的指针域指向p，首元数据
		p->next = NULL;//首元地址的指针域滞空
		L = L->next;//推进
	}
	cout << "创建成功" << endl;
	return true;
}
void LinkList::printList()
{
	LinkNode *p = head->next;//p指向首元地址
	int i = 1;//计数
	while (p)
	{
		cout << "第" << i++ << "个节点的数据:       ";//提示
		cout << "姓名：" << p->data.m_name << "  年龄：" << p->data.m_age << endl;
		p = p->next;//推进
	}
}
Status LinkList::convert_List()//逆置
{
	if (head->next == NULL)//空链表直接退出该函数
	{
		return false;
	}
	LinkNode* p = head->next;//p指向首元地址
	LinkNode* q = p->next;//q指向首元地址的下一节点（次元节点）
	LinkNode* t = NULL;//空指针
	while (q!=NULL)//两个节点为一组，不断向前推进，条件：第二个节点的指针域不为空
	{
		t = q->next;//保留第二个节点的指针域
		q->next = p;//第二节点的指针域存第一节点的地址
		p = q;//推进
		q = t;//把第三个节点的地址给第二个节点
	}
	head->next->next = NULL;//设置表头
	head->next = p;//调整表尾
	return true;
}
void showMenu()//菜单
{
	cout << "       ------------------------------------" << endl;
	cout << "       |     1、创建单链表                 |" << endl;
	cout << "       |     2、链表初始化                 |" << endl;
	cout << "       |     3、获得数据                   |" << endl;
	cout << "       |     4、查找数据，返回地址         |" << endl;
	cout << "       |     5、查找数据，返回逻辑位置     |" << endl;
	cout << "       |     6、前插入数据                 |" << endl;
	cout << "       |     7、删除数据                   |" << endl;
	cout << "       |     8、输出链表                   |" << endl;
	cout << "       |     9、逆置链表                   |" << endl;
	cout << "       |     0、退    出                   |" << endl;
	cout << "       ------------------------------------" << endl;
}
int main()
{
	LinkList L;//创建链表对象
	while (true)//用户选择
	{
		showMenu();//展示菜单
		int select = 0;
		cout << "请输入您的选项:";
		cin >> select;//输入选择
		switch (select)//选择分支
		{
		case 1:
			cout << "请输入创建节点数：" << endl;
			int ret;
			cin >> ret;
			L.createList(ret);//调用类内成员函数
			system("pause");//按任意键继续运行程序
			system("cls");//清屏
			break;
		case 2:
			L.intiList();//调用类内成员函数
			if (L.intiList())
			{
				cout << "初始化成功！" << endl;
			}
			else
			{
				cout << "初始化失败！" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
		{
			cout << "你想获得哪个数据,请输入逻辑位置" << endl;
			int pos;
			cin >> pos;
			Person p = L.getElem(pos);//调用类内成员函数
			if (p.m_name != "0" && p.m_age != 0)//判断是否符号条件
			{
				cout << "姓名：" << p.m_name << "   年龄：" << p.m_age << endl;
			}
			else
			{
				cout << "未找到" << endl;
			}
			
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			Person p;
			cout << "请输入要查找的数据(姓名、年龄)" << endl;
			cin >> p.m_name >> p.m_age;
			LinkNode* address = L.searchElemAddress(p);//调用类内成员函数
			if (address != 0)
			{
				cout << "节点地址为：" << address << endl;
			}
			else
			{
				cout << "未找到" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			Person p;
			cout << "请输入要查找的数据(姓名、年龄)" << endl;
			cin >> p.m_name >> p.m_age;
			int loction = L.searchElemLoction(p);//调用类内成员函数
			if (loction != 0)
			{
				cout << "节点的逻辑位置：  " << loction << endl;
			}
			else
			{
				cout << "未找到" << endl;
			}
			
			system("pause");
			system("cls");
		}
			break;
		case 6:
		{
			Person p;
			cout << "请输入插入数据的位置以及数据(姓名、年龄)" << endl;
			int pos;
			cin >> pos >> p.m_name >> p.m_age;
			Status s=L.insertElem(pos, p);//调用类内成员函数
			if (s)
			{
				cout << "插入成功！" << endl;
			}
			else
			{
				cout << "插入失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 7:
		{
			cout << "你想删除第几个节点" << endl;
			int pos;
			cin >> pos;
			Status s = L.elemDelete(pos);//调用类内成员函数
			if (s)
			{
				cout << "删除成功！"<<endl;
			}
			else
			{
				cout << "删除失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 8:
			L.printList();//调用类内成员函数
			system("pause");
			system("cls");
			break;
		case 9:
		{
			 Status s=L.convert_List();//调用类内成员函数
			 if (s)
			 {
				 cout << "逆置成功！" << endl;
			 }
			 else
			 {
				 cout << "逆置失败！" << endl;
			 }
			system("pause");
			system("cls");
		}
			break;
		default:
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		}

	}
	
}