/* FUN_8016747c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016747c  body 0x8016747c..0x80167597  size 284 B
 * body sha256 d345e317770f46750c5a10cf74217c8884574bd034022370b75a89b340222c13
 * provider record sha256 fa7580df452c817b4f380486be19104b8c112bb5db016e40457c2eaba4cb99d9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016747c(int param_1,uint param_2,uint param_3,short *param_4)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar3 = (param_3 & 0xff) * 6;
  sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  iVar4 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  if (((&DAT_80167ff4)[iVar3] & 0x80) == 0) {
    local_20 = *(short *)(iVar4 + 0x4e) + *param_4;
    iVar5 = -0x7ff16fd8;
    local_1e = *(short *)(iVar4 + 0x52) + param_4[1];
    psVar1 = param_4 + 2;
    param_4 = &local_20;
    local_1c = *(short *)(iVar4 + 0x56) + *psVar1;
  }
  else {
    iVar5 = iVar4 + 0x38;
  }
  func_0x80037780(((byte)(&DAT_80167ff4)[iVar3] & 0x7f) << 0x18 |
                  ((uint)(byte)(&DAT_80167ff5)[iVar3] + (uint)*(ushort *)(&DAT_80167ff6 + iVar3)) *
                  0x10000 | (uint)*(ushort *)(&DAT_80167ff8 + iVar3),(int)sVar2,iVar5,param_4);
  return;
}
