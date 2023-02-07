#include <stdio.h>
#include <stdarg.h>
#include <typedef.h>

extern void m_putc(char chr);

void m_putc(char chr)
{

;
}

// ����m^n
unsigned long m_pow_n(unsigned long m, unsigned long n)
{
    unsigned long i = 0, ret = 1;
    if (n < 0) return 0;
    for (i = 0; i < n; i++)
    {
        ret *= m;
    }
    return ret;
}

// ����ֵΪ��ӡ�ַ��ĸ���
// ֧��%d��%o, %x��%s��%c��%f��ֻ��ӡ6λ���֣�
int print(const char* str, ...)
{
    if (str == NULL) return -1;

	unsigned int ret_num = 0;// ���ش�ӡ�ַ��ĸ���
    char* pStr = (char*)str;// ָ��str
    int ArgIntVal = 0;  // ��������
    unsigned long ArgHexVal = 0;// ��ʮ������
    char* ArgStrVal = NULL;  // �����ַ���
    double ArgFloVal = 0.0; // ���ܸ�����
    unsigned long val_seg = 0;   // �����з�
    unsigned long val_temp = 0;  // ��ʱ��������
    int cnt = 0;       // ���ݳ��ȼ���
    int i = 0;
    
    va_list pArgs; // ����va_list����ָ�룬���ڴ洢�����ĵ�ַ
    va_start(pArgs, str); // ��ʼ��pArgs
    while (*pStr != '\0')
    {
        switch (*pStr)
        {
        case ' ':
            m_putc(*pStr); ret_num++; break;
        case '\t':
            m_putc(*pStr); ret_num += 4; break;
        case '\r':
            m_putc(*pStr); ret_num++; break;
        case '\n':
            m_putc(*pStr); ret_num++; break;
        case '%':
            pStr++;
            // % ��ʽ����
            switch (*pStr)
            {
            case '%':
                m_putc('%');// %%�����%
                ret_num++;
                pStr++;
				continue;
            case 'c':
                ArgIntVal = va_arg(pArgs, int);// %c�����char
                m_putc((char)ArgIntVal);
                ret_num++;
                pStr++;
				continue;
            case 'd':
                // ��������
                ArgIntVal = va_arg(pArgs, int);
                if (ArgIntVal < 0)// ���Ϊ������ӡ������
                {
                    ArgIntVal = -ArgIntVal;// ȡ�෴��

                    m_putc('-');
                    ret_num++;
                }
                val_seg = ArgIntVal;// ��ֵ�� val_seg��������
                // ����ArgIntVal����
                if (ArgIntVal)
                {
                    while (val_seg) {
                        cnt++;
                        val_seg /= 10;
                    }
                }
                else cnt = 1;// ����0�ĳ���Ϊ1

                ret_num += cnt;// �ַ��������������ĳ���

                // ������תΪ�����ַ���ӡ
                while (cnt)
                {
                    val_seg = ArgIntVal / m_pow_n(10, cnt - 1);
                    ArgIntVal %= m_pow_n(10, cnt - 1);
                    m_putc((char)val_seg + '0');
                    cnt--;
                }
                pStr++;
                continue;
            case 'o':
                // ��������
                ArgIntVal = va_arg(pArgs, int);
                if (ArgIntVal < 0)// ���Ϊ������ӡ������
                {
                    ArgIntVal = -ArgIntVal;// ȡ�෴��

                    m_putc('-');
                    ret_num++;
                }
                val_seg = ArgIntVal;// ��ֵ�� val_seg��������
                // ����ArgIntVal����
                if (ArgIntVal)
                {
                    while (val_seg) {
                        cnt++;
                        val_seg /= 8;
                    }
                }
                else cnt = 1;// ����0�ĳ���Ϊ1

                ret_num += cnt;// �ַ��������������ĳ���

                // ������תΪ�����ַ���ӡ
                while (cnt)
                {
                    val_seg = ArgIntVal / m_pow_n(8, cnt - 1);
                    ArgIntVal %= m_pow_n(8, cnt - 1);
                    m_putc((char)val_seg + '0');
                    cnt--;
                }
                pStr++;
				continue;
            case 'x':
                // ����16����
                ArgHexVal = va_arg(pArgs, unsigned long);
                val_seg = ArgHexVal;
                // ����ArgIntVal����
                if (ArgHexVal)
                {
                    while (val_seg) {
                        cnt++;
                        val_seg /= 16;
                    }
                }
                else cnt = 1;// ����0�ĳ���Ϊ1

                ret_num += cnt;// �ַ��������������ĳ���
                // ������תΪ�����ַ���ӡ
                while (cnt)
                {
                    val_seg = ArgHexVal / m_pow_n(16, cnt - 1);
                    ArgHexVal %= m_pow_n(16, cnt - 1);
                    if (val_seg <= 9)
                        m_putc((char)val_seg + '0');
                    else
                    {
						//m_putc((char)val_seg - 10 + 'a'); //Сд��ĸ
                        m_putc((char)val_seg - 10 + 'A');
                    }
                    cnt--;
                }
                pStr++;
				continue;
            case 'b':
                // ��������
                ArgIntVal = va_arg(pArgs, int);
                val_seg = ArgIntVal;
                // ����ArgIntVal����
                if (ArgIntVal)
                {
                    while (val_seg) {
                        cnt++;
                        val_seg /= 2;
                    }
                }
                else cnt = 1;// ����0�ĳ���Ϊ1

                ret_num += cnt;// �ַ��������������ĳ���
                // ������תΪ�����ַ���ӡ
                while (cnt)
                {
                    val_seg = ArgIntVal / m_pow_n(2, cnt - 1);
                    ArgIntVal %= m_pow_n(2, cnt - 1);
                    m_putc((char)val_seg + '0');
                    cnt--;
                }
                pStr++;
				continue;
            case 's':
                // �����ַ�
                ArgStrVal = va_arg(pArgs, char*);
                ret_num += (unsigned int)strlen(ArgStrVal);
                while (*ArgStrVal)
                {
                    m_putc(*ArgStrVal);
                    ArgStrVal++;
                }

                pStr++;
				continue;

            case 'f':
                // ���ո����� ����6ΪС��������ȡ��������
                ArgFloVal = va_arg(pArgs, double);
                val_seg = (unsigned long)ArgFloVal;// ȡ��������
                val_temp = val_seg;      // ��ʱ����������������
                ArgFloVal = ArgFloVal - val_seg;// �ó����µ�С������
                // �����������ֳ���
                if (val_seg)
                {
                    while (val_seg) {
                        cnt++;
                        val_seg /= 10;
                    }
                }
                else cnt = 1;// ����0�ĳ���Ϊ1
                ret_num += cnt;// �ַ��������������ĳ���
                // ������תΪ�����ַ���ӡ
                while (cnt)
                {
                    val_seg = val_temp / m_pow_n(10, cnt - 1);
                    val_temp %= m_pow_n(10, cnt - 1);
                    m_putc((char)val_seg + '0');
                    cnt--;
                }
                // ��ӡС����
                m_putc('.');
                ret_num++;
                // ��ʼ���С������
                ArgFloVal *= 1000000;
                // printf("\r\n %f\r\n", ArgFloVal);
                cnt = 6;
                val_temp = (int)ArgFloVal;// ȡ��������
                while (cnt)
                {
                    val_seg = val_temp / m_pow_n(10, cnt - 1);
                    val_temp %= m_pow_n(10, cnt - 1);
                    m_putc((char)val_seg + '0');
                    cnt--;
                }
                ret_num += 6;
                pStr++;
				continue;
            default:// % ƥ�����������ո�
				m_putc(' '); ret_num++;
				continue;
            }


        default:
            m_putc(*pStr); ret_num++;
            break;
        }
        pStr++;
    }
    va_end(pArgs);// ����ȡ����

    return ret_num;
}
