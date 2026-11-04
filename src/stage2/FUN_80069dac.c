/* FUN_80069dac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069dac  body 0x80069dac..0x80069ebb  size 272 B
 * body sha256 a782e96f297851b1c2bdb2a17581b8f3a1a659e0642687144b4badff2444a946
 * provider record sha256 25fb8bb3dfec965e53aef326b2ecd8bd0e3bcf5ad0c142a238a5e5864246719e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80069dac(int *param_1,int param_2,int param_3,short *param_4)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int in_t0;
  int iVar5;
  
  uVar3 = ((ushort)param_4[5] & 0x30) >> 4;
  if (uVar3 == 1) {
    sVar1 = *param_4;
    iVar4 = *param_1;
LAB_80069e68:
    iVar4 = iVar4 - sVar1;
    iVar5 = (int)((ulonglong)((longlong)iVar4 * -0xd4629b7) >> 0x20);
  }
  else if (uVar3 < 2) {
    iVar4 = param_2 - param_3;
    if (uVar3 != 0) {
      bVar2 = iVar4 < in_t0;
      goto LAB_80069ea4;
    }
    iVar4 = ((int)*param_4 + (uint)(ushort)param_4[2]) - *param_1;
    iVar5 = (int)((ulonglong)((longlong)iVar4 * -0xd4629b7) >> 0x20);
  }
  else {
    if (uVar3 != 2) {
      iVar4 = param_2 - param_3;
      if (uVar3 != 3) {
        bVar2 = iVar4 < in_t0;
        goto LAB_80069ea4;
      }
      sVar1 = param_4[1];
      iVar4 = param_1[2];
      goto LAB_80069e68;
    }
    iVar4 = ((int)param_4[1] + (uint)(ushort)param_4[3]) - param_1[2];
    iVar5 = (int)((ulonglong)((longlong)iVar4 * -0xd4629b7) >> 0x20);
  }
  in_t0 = ((iVar5 + iVar4 >> 9) - (iVar4 >> 0x1f)) * 0x1c2;
  iVar4 = param_2 - param_3;
  bVar2 = iVar4 < in_t0;
LAB_80069ea4:
  if (bVar2) {
    in_t0 = iVar4;
  }
  if (in_t0 < 0) {
    in_t0 = 0;
  }
  return in_t0;
}
