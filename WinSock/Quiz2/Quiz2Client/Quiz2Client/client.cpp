// 2019�� 1�б� ��Ʈ��ũ���α׷��� ���� 2��
// ����: �ڻ�� �й�: 16013093
// �÷���: Visual Studio 2017

#define _WINSOCK_DEPRECATED_NO_WARNINGS // �ֽ� VC++ ������ �� ��� ����
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define SERVERIP   "127.0.0.1"
#define SERVERPORT 9000
#define BUFSIZE    512

typedef struct Nums {
	int first;
	int second;
}Nums;

// ���� �Լ� ���� ��� �� ����
void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

// ���� �Լ� ���� ���
void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

// ����� ���� ������ ���� �Լ�
int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0) {
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}

int main(int argc, char *argv[])
{
	int retval;

	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	// socket()
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit(const_cast<char*>("socket()"));

	// connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit(const_cast<char*>("connect()"));

	// ������ ��ſ� ����� ����
	Nums data;
	int result;

	// ������ ������ ���
	while (1) {
		// ������ �Է�
		printf("\n�� ���� �Է�(���� �Է½� ���α׷� ����) >> ");

		char tmp;
		if (scanf("%d %d", &data.first, &data.second) == NULL)
		{
			printf("�߸��� �� �Է� ���α׷��� �����մϴ�\n");
			break;
		}

		// ���� 2�� �̻� �Է½� 2���� �����ϰ� �Է� ���� ����
		while ((tmp = getchar()) != EOF && tmp != '\n');

		// ������ ������
		retval = send(sock, (char*)&data, sizeof(data), 0);
		if (retval == SOCKET_ERROR) {
			err_display(const_cast<char*>("send()"));
			break;
		}
		printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� ���½��ϴ�.\n", sizeof(data));

		// ������ �ޱ�
		retval = recvn(sock, (char*)&result, sizeof(result), 0);
		if (retval == SOCKET_ERROR) {
			err_display(const_cast<char*>("recv()"));
			break;
		}
		else if (retval == 0)
			break;

		// ���� ������ ���
		// �������� �� ���� ���� ����Ͽ� ����
		printf("[TCP Ŭ���̾�Ʈ] %d����Ʈ�� �޾ҽ��ϴ�.\n", sizeof(result));
		printf("[���� ������] %d\n", result);
	}

	// closesocket()
	closesocket(sock);

	// ���� ����
	WSACleanup();
	return 0;
}
