/* FUN_80167374
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80167374  body 0x80167374..0x8016747b  size 264 B
 * body sha256 05aa08586d50ccc66171547bd863ae84bb9f753829206366d41290b0b76848a0
 * provider record sha256 2253773c82981ac35a817a0d028a51505e68520a66e5c76104a0a206e62f56bf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167374(int param_1,uint param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar2 = (param_3 & 0xff) * 6;
  sVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  iVar3 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  if (((&DAT_80167ff4)[iVar2] & 0x80) == 0) {
    local_18 = *(undefined2 *)(iVar3 + 0x4e);
    local_16 = *(undefined2 *)(iVar3 + 0x52);
    iVar4 = -0x7ff16fd8;
    local_14 = *(undefined2 *)(iVar3 + 0x56);
  }
  else {
    iVar4 = iVar3 + 0x38;
    local_14 = 0;
    local_16 = 0;
    local_18 = 300;
  }
  func_0x80037780(((byte)(&DAT_80167ff4)[iVar2] & 0x7f) << 0x18 |
                  ((uint)(byte)(&DAT_80167ff5)[iVar2] + (uint)*(ushort *)(&DAT_80167ff6 + iVar2)) *
                  0x10000 | (uint)*(ushort *)(&DAT_80167ff8 + iVar2),(int)sVar1,iVar4,&local_18);
  return;
}
