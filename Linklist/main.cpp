#include<iostream>//���롢�����ͷ�ļ�
#include<string>//STL�е�string����
typedef bool Status;//�궨��
using namespace std;//ʹ�ñ�׼�����ռ�
class Person//�Զ����������ͣ�����һ���࣬������������
{
public://Ĭ��˽�У�Ϊ�˷��㣬����Ҳ����Ϊ����
	Person()//�޲ι��캯������Ϊд���вι��캯�������������ṩ�޲ι��캯����������Ҫ��дһ��
	{

	}
	Person(string name, int age)//�вι��캯�����ڴ�������ʱֱ��ָ������
	{
		this->m_name = name;//thisָ�룬˭���ã�ָ��˭������Ա���Ը�ֵ
		this->m_age = age;//����Ա���Ը�ֵ
	}
	string m_name;//��Ա���ԣ�ʹ��STL�е�string�����ַ����鷽�㣬���ڹ���
	int m_age;     //��Ա����
};

class LinkNode//�����ڵ���
{
public:
	Person data;   //��������������
	LinkNode* next;//ָ���򣺴����һ�ڵ�ĵ�ַ

};
class LinkList//�������࣬��Ҫ���������Ϊ�����Խ��з�װ
{
public:
	LinkList()//�ڴ����������ʱ���Զ���ʼ��
	{
		this->intiList();
	}
	//��������������ʵ��
	Status intiList();//��ʼ������
	Person getElem(int i);//�������
	LinkNode* searchElemAddress(Person elem);//�������ݣ����ص�ַ
	int searchElemLoction(Person elem);//�������ݣ������߼�λ��
	Status insertElem(int i, Person elem);//ǰ��������
	Status elemDelete(int i);//����ɾ��
	Status createList(int n);//��������
	void printList();//�������
	Status convert_List();//��������
	~LinkList()//���������Զ�����
	{
		if (head->next != NULL)
		{
			delete head;//�ͷ��ڴ�
		}
	}
private://�����������Ϊ˽��
	LinkNode* head;
};

bool operator!=(const Person& p1, const Person& p2)//��ϵ��������أ������������֪�������Զ���������ô�Ƚ�
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)//ֻ������һ�ֹ�ϵ�Ǽ٣�����ȫ�ǲ����
	{
		return false;
	}
	else
	{
		return true;
	}
}
Status LinkList::intiList()//��ü��������򣬵������ĸ���ĳ�Ա��������Ա�������أ�
{
	head = new LinkNode;//����һ���ڵ���󣬲����ص�ַ����ͷָ��
	head->next = NULL;//ͷָ���nextָ����Ԫ�ڵ㣬������Ԫ�ڵ�δ��������ֹ��ΪҰָ�룬���Ϳ�
	return true;//��ʼ���ɹ�������true
}
Person LinkList::getElem(int i)//��ȡ�߼�λ�õ�����
{
	int j = 1;//����ѭ����㣬���߼�λ�ÿ�ʼ����Ԫ�ڵ㣩
	LinkNode* p = head->next;//ͬ�ϣ�����Ԫ�ڵ㿪ʼ
	while(p &&j < i)//������p��ָ��գ����߼�λ���ϴ��ڣ�j<i����ѭ����ֹ����
	{
		p = p->next;//�൱��p++,ÿѭ��һ�Σ��ڵ��ƽ�һ��
		j++;//ҲҪ�ƽ�
	}
	if (p==NULL || j > i)//���pΪ�ջ���j>i(û���ҵ�),ֱ�ӷ���һ��������
	{
		Person p1("0", 0);
		return p1;
	}
	return p->data;//�ҵ��ˣ�����ָ������
}
LinkNode* LinkList::searchElemAddress(Person elem)//�������ݵ�ַ
{
	LinkNode* p = head->next;//����ѭ����㣬ָ����Ԫ�ڵ�
	while (p && p->data != elem)//���� ����Ϊ�գ��Ҳ���������ڵ����ݲ�һ��
	{
		p = p->next;//�ڵ��ƽ�
	}
	return p;//�ҵ��ˣ�����ָ���ڵ�ĵ�ַ
}
int LinkList::searchElemLoction(Person elem)//���������߼�λ��
{
	LinkNode* p = head->next;//����ѭ����㣬ָ����Ԫ�ڵ�
	int j = 1;//����
	while (p && p->data != elem)// ���� ����Ϊ�գ��Ҳ���������ڵ����ݲ�һ��
	{
		p = p->next;//�ڵ��ƽ�
		j++;//��������
	}
	if (p)
	{
		return j;//�����߼�λ��
	}
	else
	{
		return 0;//û���ҵ�������0
	}
}
Status LinkList::insertElem(int i, Person elem)//�ڵڼ���λ�ã�ǰ��������
{
	int j = 0;//ָ�� Ŀ����߼�λ��ǰһλ��
	LinkNode* p=head;//ָ�� Ŀ��ڵ��ǰһ���ڵ�
	while (p && j < i - 1)//���� ����Ϊ���Ҵ������һ���ڵ�ǰһ��λ��
	{
		p = p->next;//�ڵ��ƽ�
		j++;//ͬ��
	}
	if (!p || j > i - 1)//�ж����� �������Ϊ�ջ��߲������ݲ�����ֱ�ӷ���false
	{
		return false;
	}
	LinkNode* s = new LinkNode;//����һ���½ڵ��ڶ����������½ڵ�ĵ�ַ���ظ�s
	s->next = p->next;//p->next�ǲ���֮ǰ��pָ�����һ�ڵ�ĵ�ַ������Ҫ��ֵ���½ڵ��next
	p->next = s;//��s�ڵ�ĵ�ַ��ֵ�������sǰ�Ľڵ��next
	s->data = elem;//��s�ڵ��������ֵ
	return true;//��ʾ����ɹ�
}
Status LinkList::elemDelete(int i)//ɾ���߼�λ�õ�����
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
	}//����ͬ��
	LinkNode* q = p->next;//��¼һ����Ҫɾ���ݵĵ�ַ����Ϊ�����������в���
	p->next = q->next;//��q->next�ĵ�ַ����p��ָ����
	delete q;//�ͷŵ�ַ
	return true;//ɾ���ɹ�
}
Status LinkList::createList(int n)//�����������
{
	head = new LinkNode;
	LinkNode* L = head;//����һ��ͷ���ĵ�ַ������ֱ�Ӷ�L���в���
	L->next = NULL;//��ʼ��
	for (int i = 1; i <= n; i++)//�����ڵ�ĸ���
	{
		LinkNode* p = new LinkNode;//�����ڵ㣬���׵�ַ����p
		cout << "������� "<< i << "���ڵ������(����������)" << endl;//��ʾ
		cin >> p->data.m_name >> p->data.m_age;//����ÿ���ڵ������
		L->next = p;//ͷ����ָ����ָ��p����Ԫ����
		p->next = NULL;//��Ԫ��ַ��ָ�����Ϳ�
		L = L->next;//�ƽ�
	}
	cout << "�����ɹ�" << endl;
	return true;
}
void LinkList::printList()
{
	LinkNode *p = head->next;//pָ����Ԫ��ַ
	int i = 1;//����
	while (p)
	{
		cout << "��" << i++ << "���ڵ������:       ";//��ʾ
		cout << "������" << p->data.m_name << "  ���䣺" << p->data.m_age << endl;
		p = p->next;//�ƽ�
	}
}
Status LinkList::convert_List()//����
{
	if (head->next == NULL)//������ֱ���˳��ú���
	{
		return false;
	}
	LinkNode* p = head->next;//pָ����Ԫ��ַ
	LinkNode* q = p->next;//qָ����Ԫ��ַ����һ�ڵ㣨��Ԫ�ڵ㣩
	LinkNode* t = NULL;//��ָ��
	while (q!=NULL)//�����ڵ�Ϊһ�飬������ǰ�ƽ����������ڶ����ڵ��ָ����Ϊ��
	{
		t = q->next;//�����ڶ����ڵ��ָ����
		q->next = p;//�ڶ��ڵ��ָ������һ�ڵ�ĵ�ַ
		p = q;//�ƽ�
		q = t;//�ѵ������ڵ�ĵ�ַ���ڶ����ڵ�
	}
	head->next->next = NULL;//���ñ�ͷ
	head->next = p;//������β
	return true;
}
void showMenu()//�˵�
{
	cout << "       ------------------------------------" << endl;
	cout << "       |     1������������                 |" << endl;
	cout << "       |     2�������ʼ��                 |" << endl;
	cout << "       |     3���������                   |" << endl;
	cout << "       |     4���������ݣ����ص�ַ         |" << endl;
	cout << "       |     5���������ݣ������߼�λ��     |" << endl;
	cout << "       |     6��ǰ��������                 |" << endl;
	cout << "       |     7��ɾ������                   |" << endl;
	cout << "       |     8���������                   |" << endl;
	cout << "       |     9����������                   |" << endl;
	cout << "       |     0����    ��                   |" << endl;
	cout << "       ------------------------------------" << endl;
}
int main()
{
	LinkList L;//�����������
	while (true)//�û�ѡ��
	{
		showMenu();//չʾ�˵�
		int select = 0;
		cout << "����������ѡ��:";
		cin >> select;//����ѡ��
		switch (select)//ѡ���֧
		{
		case 1:
			cout << "�����봴���ڵ�����" << endl;
			int ret;
			cin >> ret;
			L.createList(ret);//�������ڳ�Ա����
			system("pause");//��������������г���
			system("cls");//����
			break;
		case 2:
			L.intiList();//�������ڳ�Ա����
			if (L.intiList())
			{
				cout << "��ʼ���ɹ���" << endl;
			}
			else
			{
				cout << "��ʼ��ʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
		{
			cout << "�������ĸ�����,�������߼�λ��" << endl;
			int pos;
			cin >> pos;
			Person p = L.getElem(pos);//�������ڳ�Ա����
			if (p.m_name != "0" && p.m_age != 0)//�ж��Ƿ��������
			{
				cout << "������" << p.m_name << "   ���䣺" << p.m_age << endl;
			}
			else
			{
				cout << "δ�ҵ�" << endl;
			}
			
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			Person p;
			cout << "������Ҫ���ҵ�����(����������)" << endl;
			cin >> p.m_name >> p.m_age;
			LinkNode* address = L.searchElemAddress(p);//�������ڳ�Ա����
			if (address != 0)
			{
				cout << "�ڵ��ַΪ��" << address << endl;
			}
			else
			{
				cout << "δ�ҵ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			Person p;
			cout << "������Ҫ���ҵ�����(����������)" << endl;
			cin >> p.m_name >> p.m_age;
			int loction = L.searchElemLoction(p);//�������ڳ�Ա����
			if (loction != 0)
			{
				cout << "�ڵ���߼�λ�ã�  " << loction << endl;
			}
			else
			{
				cout << "δ�ҵ�" << endl;
			}
			
			system("pause");
			system("cls");
		}
			break;
		case 6:
		{
			Person p;
			cout << "������������ݵ�λ���Լ�����(����������)" << endl;
			int pos;
			cin >> pos >> p.m_name >> p.m_age;
			Status s=L.insertElem(pos, p);//�������ڳ�Ա����
			if (s)
			{
				cout << "����ɹ���" << endl;
			}
			else
			{
				cout << "����ʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 7:
		{
			cout << "����ɾ���ڼ����ڵ�" << endl;
			int pos;
			cin >> pos;
			Status s = L.elemDelete(pos);//�������ڳ�Ա����
			if (s)
			{
				cout << "ɾ���ɹ���"<<endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 8:
			L.printList();//�������ڳ�Ա����
			system("pause");
			system("cls");
			break;
		case 9:
		{
			 Status s=L.convert_List();//�������ڳ�Ա����
			 if (s)
			 {
				 cout << "���óɹ���" << endl;
			 }
			 else
			 {
				 cout << "����ʧ�ܣ�" << endl;
			 }
			system("pause");
			system("cls");
		}
			break;
		default:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		}

	}
	
}