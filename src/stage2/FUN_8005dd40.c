/* FUN_8005dd40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005dd40  body 0x8005dd40..0x8005de7f  size 320 B
 * body sha256 480ef3c3208c406b53a998a9e079120571a1544b7e1ed3319529c456a38b2226
 * provider record sha256 1ba4ebc93d74e5b2bb4783dcb2e6904be846d66de42af77c6355e53b4599aabd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005dd40(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\a')) {
    local_18 = 0x78;
    local_16 = 600;
    local_14 = 0xff76;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a0d00,0,iVar2,&local_18);
    FUN_80037780(0x1000d00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (((cVar1 == '\x03') || (cVar1 == '\x06')) || (cVar1 == '\n')) {
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
