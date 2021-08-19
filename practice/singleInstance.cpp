///////////////////  ��ͨ����ʽʵ�� -- �̲߳���ȫ //////////////////
#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <pthread.h> // pthread_create

class SingleInstance
{

public:
    // ��ȡ��������
    static SingleInstance *GetInstance();

    // �ͷŵ����������˳�ʱ����
    static void deleteInstance();
	
	// ��ӡ������ַ
    void Print();

private:
	// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
    SingleInstance();
    ~SingleInstance();

    // ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
    SingleInstance(const SingleInstance &signal);
    const SingleInstance &operator=(const SingleInstance &signal);

private:
    // Ψһ��������ָ��
    static SingleInstance *m_SingleInstance;
};

//��ʼ����̬��Ա����
SingleInstance *SingleInstance::m_SingleInstance = NULL;

SingleInstance* SingleInstance::GetInstance()
{

	if (m_SingleInstance == NULL)
	{
		m_SingleInstance = new (std::nothrow) SingleInstance;  // û�м������̲߳���ȫ�ģ����̲߳���ʱ�ᴴ�����ʵ��
	}

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{
    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}

void SingleInstance::Print()
{
	std::cout << "�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
}

SingleInstance::SingleInstance()
{
    std::cout << "���캯��" << std::endl;
}

SingleInstance::~SingleInstance()
{
    std::cout << "��������" << std::endl;
}
///////////////////  ��ͨ����ʽʵ�� -- �̲߳���ȫ  //////////////////

// �̺߳���
void *PrintHello(void *threadid)
{
    // ���߳������̷߳��룬�����໥�����棬���߳̽���ͬʱ���̵߳���Դ�Զ�����
    pthread_detach(pthread_self());

    // �Դ���Ĳ�������ǿ������ת������������ָ���Ϊ������ָ�룬Ȼ���ٶ�ȡ
    int tid = *((int *)threadid);

    std::cout << "Hi, �����߳� ID:[" << tid << "]" << std::endl;

    // ��ӡʵ����ַ
    SingleInstance::GetInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 5 // �̸߳���

int main(void)
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0}; // ������������i��ֵ

    int ret = 0;
    int i = 0;

    std::cout << "main() : ��ʼ ... " << std::endl;

    for (i = 0; i < NUM_THREADS; i++)
    {
        std::cout << "main() : �����߳�:[" << i << "]" << std::endl;
        
		indexes[i] = i; //�ȱ���i��ֵ
		
        // �����ʱ�����ǿ��ת��Ϊvoid* ���ͣ���������ָ��
        ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (ret)
        {
            std::cout << "Error:�޷������߳�," << ret << std::endl;
            exit(-1);
        }
    }

    // �ֶ��ͷŵ�ʵ������Դ
    SingleInstance::deleteInstance();
    std::cout << "main() : ����! " << std::endl;
	
    return 0;
}