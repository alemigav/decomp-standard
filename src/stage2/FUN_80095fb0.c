/* FUN_80095fb0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80095fb0  body 0x80095fb0..0x800961db  size 556 B
 * body sha256 0725b872af0ecd3e3c93d86d29af6576df763e6b6739e3ca7f0a65e62c296e0d
 * provider record sha256 fac496c969b8b0842aad86d90629c94e55dde43bd68325f7762d6caef710a84c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80095fb0(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((param_4 & 0x7f) == 4) {
    return param_1 + 0x50;
  }
  if (param_2 != 0xff) {
    DAT_8013a3e0 = (char)(param_4 >> 0x10);
    DAT_8013a3e3 = (char)(param_2 / 100);
    DAT_8013a3e2 = (char)((param_2 % 100) / 10);
    DAT_8013a3e1 = (char)(param_2 % 100) + DAT_8013a3e2 * -10;
    if ((param_4 & 0x10) == 0) {
      iVar1 = 4;
      do {
        iVar2 = iVar1 + -1;
        if (((DAT_8013a3e3 != '\0') || ((iVar2 != 3 && ((DAT_8013a3e2 != '\0' || (iVar2 != 2))))))
           && ((DAT_8013a3e0 != '\0' || (iVar2 != 0)))) {
          FUN_800478b8(param_1,(param_3 >> 0x10) + iVar4 & 0xffff,param_3 & 0xffff);
          iVar4 = iVar4 + 7;
          FUN_800478ac(param_1,(uint)*(byte *)(iVar1 + -0x7fec5c21) << 3,0x1a);
          *(ushort *)(param_1 + 10) = (((ushort)param_4 & 0xf) + 2) * 0x20;
          DAT_800df8b4 = FUN_80043988(DAT_800df8b4,param_1,0,0);
        }
        param_1 = param_1 + 0x14;
        iVar1 = iVar2;
      } while (iVar2 != 0);
      return param_1;
    }
  }
  iVar1 = 2;
  sVar3 = 0x50;
  do {
    iVar2 = param_1;
    sVar3 = sVar3 + 8;
    iVar1 = iVar1 + -1;
    FUN_800478b8(iVar2,(param_3 >> 0x10) + iVar4 & 0xffff,param_3 & 0xffff);
    FUN_800478ac(iVar2,sVar3,0x1a);
    *(ushort *)(iVar2 + 10) = (((ushort)param_4 & 0xf) + 2) * 0x20;
    iVar4 = iVar4 + 7;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar2,0,0);
    param_1 = iVar2 + 0x14;
  } while (iVar1 != 0);
  return iVar2 + 0x3c;
}
