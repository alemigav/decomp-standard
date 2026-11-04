/* FUN_80161f0c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80161f0c  body 0x80161f0c..0x80162113  size 520 B
 * body sha256 d3e94325b30af151564af4a9834de83b5f2c10140aba3db1bec028cd83478f1b
 * provider record sha256 1fc96e2ab083ef79a22907b8ae1c49d94824e5471bcec2a106bf721804ad9270
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80161f0c(int param_1,int param_2,ushort param_3,ushort param_4,int param_5,int param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar5;
  uint uVar4;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  sVar5 = *(short *)(param_1 + 0x2b8);
  sVar1 = *(short *)(param_1 + 0x2ba);
  iVar8 = param_2 * 0x178 + *(int *)(param_1 + 0x234);
  *(undefined2 *)(param_1 + 0x2b8) = *(undefined2 *)(iVar8 + 0x4e);
  *(undefined2 *)(param_1 + 0x2ba) = *(undefined2 *)(iVar8 + 0x56);
  if (param_3 <= *(byte *)(param_1 + 0x1e9)) {
    if (param_4 < *(byte *)(param_1 + 0x1e9)) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x28) - *(int *)(iVar8 + 0x4c);
    iVar3 = *(int *)(param_1 + 0x30) - *(int *)(iVar8 + 0x54);
    iVar2 = func_0x80040bb4(iVar2 * iVar2 + iVar3 * iVar3);
    iVar3 = *(int *)(param_1 + 0x28) - (int)sVar5;
    iVar6 = *(int *)(param_1 + 0x30) - (int)sVar1;
    iVar3 = func_0x80040bb4(iVar3 * iVar3 + iVar6 * iVar6);
    if ((*(short *)(param_1 + 500) == 0) &&
       (*(uint *)(param_1 + 0x28c) < (uint)(iVar2 + iVar3 + param_6 + 500) >> 1)) {
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)sVar5,(int)sVar1);
      iVar2 = (int)sVar5;
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)*(short *)(iVar8 + 0x4e),(int)*(short *)(iVar8 + 0x56));
      iVar3 = (int)sVar5;
      iVar8 = iVar3;
      if (iVar3 < iVar2) {
        iVar8 = iVar2;
        iVar2 = iVar3;
      }
      uVar7 = iVar8 - iVar2 & 0xfff;
      if (uVar7 < 0x800) {
        iVar2 = iVar2 - param_5;
      }
      else {
        iVar2 = uVar7 + iVar2;
        uVar7 = 0x1000 - uVar7;
        iVar2 = (iVar2 + -0x1000) - param_5;
      }
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      uVar4 = sVar5 - iVar2 & 0xfff;
      if ((uVar4 != 0) && ((int)uVar4 < (int)(uVar7 + param_5 * 2))) {
        *(undefined2 *)(param_1 + 500) = 1;
        return 1;
      }
    }
  }
  return 0;
}
