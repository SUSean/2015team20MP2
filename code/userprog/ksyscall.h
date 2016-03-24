/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}
void SysPrintInt(int number){
  kernel->interrupt->PrintInt(number);
}
int SysAdd(int op1, int op2)
{
  return op1 + op2;
}
int SysOpen(char *filename)
{
  return kernel->interrupt->OpenFile(filename);
}
int SysWrite(char *buffer, int size, int id)
{
  return  kernel->interrupt->WriteFile(buffer,size,id);
}
int SysRead(char *buffer, int size, int id)
{
  return  kernel->interrupt->ReadFile(buffer,size,id);
}
int SysClose(int id)
{
  return kernel->interrupt->CloseFile(id);
}
int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
