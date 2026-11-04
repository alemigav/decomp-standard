/* FUN_80162824
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162824  body 0x80162824..0x8016290f  size 236 B
 * body sha256 a709cc8afbc2270d6647d71dd4cbf50e4a1cbb3a2155258a6674ded15ee24ace
 * provider record sha256 27e44f772bcff00b8970a7555729cf6e1c683b6d96119c8de922794607c562d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162824(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x234);
  if (param_2 != 0) {
    puVar4 = (ushort *)(param_6 + 6);
    do {
      param_2 = param_2 + -1;
      iVar2 = *(int *)(puVar4 + 1);
      uVar3 = func_0x80033604();
      uVar1 = *puVar4;
      puVar4 = puVar4 + 6;
      func_0x80037780(param_3 << 0x18 | param_4 << 0x10 | param_5 + (uVar3 & 0xff) * 2,
                      (int)(((uint)*(ushort *)(param_1 + 0x66) + (uint)uVar1) * 0x10000) >> 0x10,
                      iVar5 + iVar2 * 0x178 + 0x38,param_6);
      param_6 = param_6 + 0xc;
    } while (param_2 != 0);
  }
  return;
}
