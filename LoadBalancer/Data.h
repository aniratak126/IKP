#pragma once
#include <iostream>
#include <windows.h>
#define BUFFER_SIZE 1024

typedef struct Data
{
	char data[512];
	SOCKET acceptedSocket;

} Data;

typedef struct ClientData
{
	char data[512];
	int len;

} DataClient;

typedef struct CircularBuffer
{
	DataClient* buffer;
	int head;
	int tail;
} circular_buffer;
