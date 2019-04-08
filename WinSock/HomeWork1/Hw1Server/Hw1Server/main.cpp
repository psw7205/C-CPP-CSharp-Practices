// 2019�� 1�б� ��Ʈ��ũ���α׷��� ���� 1�� ����
// ����: �ڻ�� �й�: 16013093
// �÷���: VS2017
// �۵��ϴ� ������ ����
// www.naver.com
// www.daum.net
// www.amazon.com
// stackoverflow.com

// Aliases�� ���̰� 50���� �� ������
// www.apple.com
// www.ibm.com
// www.microsoft.com

#define _WINSOCK_DEPRECATED_NO_WARNINGS // �ֽ� VC++ ������ �� ��� ����
#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define SERVERPORT 9000
#define BUFSIZE    512

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

// �����͸� ���� �� ����ϴ� �Լ��Դϴ�.
void sendFixedVariableData(SOCKET client_sock, char *buf, int len)
{
	// ������ ������(���� ����)
	int retval = send(client_sock, (char *)&len, sizeof(int), 0);
	if (retval == SOCKET_ERROR) {
		err_display(const_cast<char*>("send()"));
		return;
	}

	// ������ ������(���� ����)
	retval = send(client_sock, buf, len, 0);
	if (retval == SOCKET_ERROR) {
		err_display(const_cast<char*>("send()"));
		return;
	}
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

	// bind()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = bind(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit(const_cast<char*>("bind()"));

	// listen()
	retval = listen(sock, SOMAXCONN);
	if (retval == SOCKET_ERROR) err_quit(const_cast<char*>("listen()"));

	// ������ ��ſ� ����� ����
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	char buf[BUFSIZE + 1];
	int len;

	bool flag = 0;

	HOSTENT *hostData;

	while (1) {
		// accept()
		addrlen = sizeof(clientaddr);
		client_sock = accept(sock, (SOCKADDR *)&clientaddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			err_display(const_cast<char*>("accept()"));
			break;
		}

		// ������ Ŭ���̾�Ʈ ���� ���
		printf("\n[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		// Ŭ���̾�Ʈ�� ������ ���
		while (1) {
			// ������ �ޱ�(���� ����)
			retval = recvn(client_sock, (char *)&len, sizeof(int), 0);
			if (retval == SOCKET_ERROR) {
				err_display(const_cast<char*>("recv()"));
				break;
			}
			else if (retval == 0)
				break;

			// ������ �ޱ�(���� ����)
			retval = recvn(client_sock, buf, len, 0);
			if (retval == SOCKET_ERROR) {
				err_display(const_cast<char*>("recv()"));
				break;
			}
			else if (retval == 0)
				break;

			// ���� ������ ���
			buf[retval] = '\0';
			printf("\n[TCP/%s:%d] %s\n", inet_ntoa(clientaddr.sin_addr),
				ntohs(clientaddr.sin_port), buf);

			// quit�� �ԷµǸ� ������ ����
			if (!strcmp(buf, "quit"))
			{
				flag = true;
				break;
			}

			// ȣ��Ʈ �̸� ���
			hostData = gethostbyname(buf);

			// ȣ��Ʈ �̸��� ���ų� Ŭ���̾�Ʈ���� �ٷ� return�� ����ó��
			if (hostData == NULL || !strcmp(buf, "")) 
			{
				char *errMsg = const_cast<char*>("�߸��� ȣ��Ʈ �����Դϴ�.");
				printf("%s\n", errMsg);
				sendFixedVariableData(client_sock, errMsg, (int)strlen(errMsg));
			}
			else
			{	
			// ������ ��� �� Ŭ���̾�Ʈ�� ������ ����
				printf("### Domain Name : \t");
				printf("%s\n", buf);
				sendFixedVariableData(client_sock, buf, (int)strlen(buf));

				printf("### Official Name : \t");
				char *ptr1 = hostData->h_name;
				printf("%s\n", ptr1);
				sendFixedVariableData(client_sock, ptr1, (int)strlen(ptr1));

				printf("### Aliases ###\n");
				char **ptr2 = hostData->h_aliases;
				while (*ptr2) {
					printf("%s\n", *ptr2);
					sendFixedVariableData(client_sock, *ptr2, (int)strlen(*ptr2));
					++ptr2;
				}

				printf("### IP addresses ###\n");
				IN_ADDR addr;
				char **ptr3 = hostData->h_addr_list;
				while (*ptr3) {
					memcpy(&addr, *ptr3, hostData->h_length);
					printf("%s\n", inet_ntoa(addr));
					sendFixedVariableData(client_sock, inet_ntoa(addr), (int)strlen(inet_ntoa(addr)));
					++ptr3;
				}

				char *msg = const_cast<char*>("������ ���� �Ϸ�");
				sendFixedVariableData(client_sock, msg, (int)strlen(msg));
			}
			
		}

		// closesocket()
		closesocket(client_sock);
		printf("[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		if (flag == true)
		{
			printf("quit �Է� ���α׷��� �����մϴ�\n");
			break;
		}
	}

	// closesocket()
	closesocket(sock);

	// ���� ����
	WSACleanup();
	return 0;
}
