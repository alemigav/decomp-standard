/* FUN_8005dc24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005dc24  body 0x8005dc24..0x8005dd3f  size 284 B
 * body sha256 5953f58137c508eeeabbb68a10d4428a13995196f750d5a3ef881468caa6139f
 * provider record sha256 6124ae20c6c88c5dcd88883536b8ad618557a9c6affc8f99ecbdc8816dda0269
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005dc24(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x8a;
    local_16 = 0x267;
    local_14 = 8;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a0e00,0,iVar2,&local_18);
    FUN_80037780(0x1000e00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x03') {
    local_18 = 0xa0;
    local_16 = 200;
    local_14 = 0x3c;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x2000700,(int)((DAT_800e1196 + 0x514) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  return;
}
