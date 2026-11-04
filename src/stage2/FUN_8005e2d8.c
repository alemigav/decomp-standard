/* FUN_8005e2d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005e2d8  body 0x8005e2d8..0x8005e52f  size 600 B
 * body sha256 4623b1f8f84f103a6386a97bc6a093b5c3b11fa105c9160e73da3fb121cc2004
 * provider record sha256 ccffe7f4ecbacfb8c59ce652027c0215fe12a9dee3bcfb3fb98f71e19fa1ab52
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005e2d8(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x30c;
    local_16 = 0x532;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1002900,0,iVar2,&local_18);
    FUN_80037780(0x1041600,0,iVar2,&local_18);
    FUN_80037780(0x1054000,0,iVar2,&local_18);
    FUN_80037780(0x30c1600,0,iVar2,&local_18);
    local_18 = 0x3bf;
    local_16 = 0x65e;
    FUN_80037780(0x30e0e00,0,iVar2,&local_18);
    FUN_80037780(0x1041800,0,iVar2,&local_18);
    local_18 = 0x4e5;
    local_16 = 0x852;
    FUN_80037780(0x30e1600,0,iVar2,&local_18);
    FUN_80037780(0x1035900,0,iVar2,&local_18);
    FUN_80037780(0x1041a00,0,iVar2,&local_18);
    local_18 = 0x646;
    local_16 = 0xaaa;
    FUN_80037780(0x30e2000,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x05') {
    local_18 = 0xb8;
    local_16 = 0x22e;
    local_14 = 0xffb0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080d00,0,iVar2,&local_18);
    FUN_80037780(0x2020900,(int)((DAT_800e1196 + 0x514) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  if (*(char *)(param_1 + 0x1e9) == '\x06') {
    local_18 = 0xb8;
    local_16 = 0x21a;
    local_14 = 0xffb0;
    FUN_80037780(0x3080d00,0,*(int *)(param_1 + 0x234) + 0x1060,&local_18);
  }
  DAT_800e110c = DAT_800e110c & 0xffffff7f;
  return;
}
