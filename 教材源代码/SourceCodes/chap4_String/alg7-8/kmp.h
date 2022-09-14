#include <cstdlib>
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int KMPStrMatching(string T, string P,  int *N) {
    int i = 0;							// ģʽ���±����
    int j = 0;							// Ŀ����±����
    int pLen = P. length ( );             		// ģʽ�ĳ���
    int tLen = T.length( );					// Ŀ��ĳ���

    if (tLen < pLen) 				    		// ���Ŀ���ģʽ�̣�ƥ���޷��ɹ�
        return (-1);          			
    while ( i < pLen  &&  j < tLen)  {  		// �����Ƚ϶�Ӧ�ַ�����ʼƥ��
       		if ( i == -1  ||  T[j] == P[i]) 
    			i++,  j++;
    		else i = N[i];
    }
    if ( i >= pLen)
    		return (j - pLen + 1);
    else return (-1);
}


int *findNext(string P) {
	int i = 0; 
    int k = -1; 
    int m = P.length();    					// mΪ�ַ���P�ĳ���
  	assert(m > 0);     					// ��m��0���˳�
  	int *next = new int[m];  				// ��̬�洢��������������
    assert(next != 0);   					// �����ٴ洢����ʧ�ܣ��˳�
  	next[0] = -1;
    while (i < m) { 						// ����i=1..m-1��nextֵ
		while (k >= 0 && P[i] != P[k])  		// �������β�Ӵ�
			k = next[k];		
        i++;
		k++;
		if (i == m) break;
		if (P[i] == P[k] ) 				
			next[i] = next[k];				//  P[i]��P[k]��ȣ��Ż�
		else next[i] = k;					// ����Ҫ�Ż�������λ��i����β�Ӵ�����
    }
    return next;
}

