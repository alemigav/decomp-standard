/* FUN_8005e0f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005e0f8  body 0x8005e0f8..0x8005e2d7  size 480 B
 * body sha256 5130df246c2b2b03b832d5d5d3df7ca3aed7daaa497519a9ecbaece4839dbb4c
 * provider record sha256 271c3033afdba207b0d6487313e3b7aec4aab961651d5accfa73e83933b4545b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005e0f8(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x96;
    local_16 = 0x514;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1001d00,0,iVar2,&local_18);
    FUN_80037780(0x1041000,0,iVar2,&local_18);
    FUN_80037780(0x30c1800,0,iVar2,&local_18);
    local_16 = 0x708;
    FUN_80037780(0x30e1000,0,iVar2,&local_18);
    FUN_80037780(0x1025000,0,iVar2,&local_18);
    local_16 = 0x8fc;
    FUN_80037780(0x30e1d00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x1a') {
    local_18 = 0xb8;
    local_16 = 0x22e;
    local_14 = 0xffb0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080d00,0,iVar2,&local_18);
    FUN_80037780(0x2020900,(int)((DAT_800e1196 + 0x514) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  if (*(char *)(param_1 + 0x1e9) == '\x1b') {
    local_18 = 0xb8;
    local_16 = 0x21a;
    local_14 = 0xffb0;
    FUN_80037780(0x3080d00,0,*(int *)(param_1 + 0x234) + 0x1060,&local_18);
  }
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
